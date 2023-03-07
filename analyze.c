/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;

static char * funName;
static int preserveLastScope = FALSE;

static void symbolError(TreeNode * t, char * message)
{ 
  fprintf(listing,"Symbol error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

static void insertIOFunc(void)
{ TreeNode *fun;
  TreeNode *typeSpec;
  TreeNode *param;
  TreeNode *compStmt;

  fun = newDeclNode(Fun);
  fun->type = Int;

  compStmt = newStmntNode(Compound);
  compStmt->child[0] = NULL;      // no local var
  compStmt->child[1] = NULL;      // no stmt

  fun->lineno = 0;
  fun->attr.name = "input";
  fun->child[0] = NULL;          // no param
  fun->child[1] = compStmt;

  st_insert("input", -1, addLocation(), fun);

  fun = newDeclNode(Fun);
  fun->type = Void;

  param = newDeclNode(Param);
  param->attr.name = "arg";

  compStmt = newStmntNode(Compound);
  compStmt->child[0] = NULL;      // no local var
  compStmt->child[1] = NULL;      // no stmt

  fun->lineno = 0;
  fun->attr.name = "output";
  fun->child[0] = param;
  fun->child[1] = compStmt;

  st_insert("output", -1, addLocation(), fun);
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t) { 
  switch (t->node_kind) { 
    case Stmnt:
      switch (t->kind.stmnt) { 
        case Compound:
          if (preserveLastScope) preserveLastScope = FALSE;
          else {
            Scope scope = sc_create(funName);
            sc_push(scope);
          }
          t->scope = sc_top();
        default:
          break;
      }
      break;
    case Exp:
      switch (t->kind.exp) { 
        case Id:
        case Call:
        case ArrId:
          if (st_lookup(t->attr.name) == -1)
          /* not yet in table, error */
            symbolError(t, "undeclared symbol");
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            st_add_lineno(t->attr.name,t->lineno);
          break;
        default:
          break;
      }
      break;
    case Decl:
      switch (t->kind.decl) {
        case Fun:
          funName = t->attr.name;
          if (st_lookup_top(funName) >= 0) {
            symbolError(t, "function already declared");
            break;
          }
          st_insert(funName, t->lineno, addLocation(), t);
          sc_push(sc_create(funName));
          preserveLastScope = TRUE;
          break;
        case Var:
          if (t->type == Void) {
            typeError(t, "variable must not be void type");
            break;
          }
          if (st_lookup_top(t->attr.name) == -1) {
            st_insert(t->attr.name, t->lineno, addLocation(), t);
            t->type = Int;
          } else symbolError(t, "symbol already declared for current scope");
          break;
        case Param:
          if (t->type == Void && t->attr.name != NULL) {
            typeError(t, "param must not be void type");
            break;
          }
          if (t->attr.name != NULL) {
            if (st_lookup_top(t->attr.name) == -1) {
              st_insert(t->attr.name, t->lineno, addLocation(), t);
              t->type = Int;
            } else symbolError(t, "symbol already declared for current scope");
          } /* else: do nothing, there are no params */
          break;
        default:
          break;
      }
    default:
      break;
  }
}

static void afterInsertNode( TreeNode * t )
{ switch (t->node_kind)
  { case Stmnt:
      switch (t->kind.stmnt)
      { case Compound:
          sc_pop();
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)
{ 
  globalScope = sc_create(NULL);
  sc_push(globalScope);
  insertIOFunc();
  traverse(syntaxTree, insertNode, afterInsertNode);
  sc_pop();
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

static void beforeCheckNode(TreeNode * t)
{ switch (t->node_kind)
  { case Decl:
      switch (t->kind.decl)
      { case Fun:
          funName = t->attr.name;
          break;
        default:
          break;
      }
      break;
    case Stmnt:
      switch (t->kind.stmnt)
      { case Compound:
          sc_push(t->scope);
          break;
        default:
          break;
      }
    default:
      break;
  }
}

/* Procedure checkNode performs
 * type checking at a single tree node
 */
static void checkNode(TreeNode * t)
{ switch (t->node_kind)
  { case Exp:
      switch (t->kind.exp)
      { 
        case Assign:
          if (t->child[0]->type == Array) typeError(t->child[0], "assignment to array variable");
          else if (t->child[0]->type == Void) typeError(t->child[0], "assignment of void value");
          else t->type = t->child[0]->type;
          break;
        case Op:
          ExpType leftType, rightType;
          TokenType op;
          leftType = t->child[0]->type;
          rightType = t->child[1]->type;
          op = t->attr.op;

          if (leftType == Void || rightType == Void) typeError(t, "both operands must not be void");
          else if (leftType == Array || rightType == Array) typeError(t, "both operands must not be arrays");
          else t->type = Int;
          break;
        case Const:
          t->type = Int;
          break;
        case Id:
        case ArrId:
          char* symbolName = t->attr.name;
          const BucketList bucket = st_bucket(symbolName);
          TreeNode *symbolDecl = NULL;
          if (bucket == NULL) break;
          symbolDecl = bucket->tree;
          if (t->kind.exp == ArrId) {
            if (symbolDecl->kind.decl != Var && symbolDecl->kind.decl != Param) {
              typeError(t, "expected array symbol");
            } else if (t->child[0]->type != Int) {
              typeError(t, "index expression should have integer type");
            } else t->type = Int;
          } else {
            t->type = symbolDecl->type;
          }
          break;
        case Call:
          char *callingFuncName = t->attr.name;
          const TreeNode * funDecl =
              st_bucket(callingFuncName)->tree;
          TreeNode *arg;
          TreeNode *param;

          if (funDecl == NULL)
            break;

          arg = t->child[0];
          param = funDecl->child[0];

          if (funDecl->kind.decl != Fun) {
            typeError(t, "expected function symbol");
            break;
          }
          
          while (arg != NULL) {
            /* the number of arguments does not match the number of parameters */
            if (param == NULL) typeError(arg, "the number of parameters is wrong");
            else if (arg->type == Void) typeError(arg, "void cannot be passed as an argument");
            else {
              arg = arg->sibling;
              param = param->sibling;
              continue;
            }
            /* any problem */
            break;
          }
          if (arg == NULL && param != NULL && param->type != Void) typeError(t->child[0], "the number of arguments is wrong");
          t->type = funDecl->type;
          break;
        default:
          break;
      }
      break;
    case Stmnt:
      switch (t->kind.stmnt) { 
        case Compound:
          sc_pop();
          break;
        case While:
          if (t->child[0]->type == Void) typeError(t->child[0], "while test has void value");
          break;
        case Return:
          const TreeNode* funDecl = st_bucket(funName)->tree;
          const ExpType funType = funDecl->type;
          const TreeNode* expr = t->child[0];
          if (funType == Void && (expr != NULL && expr->type != Void)) {
            typeError(t, "expected no return value");
          } else if (funType == Int && (expr == NULL || expr->type == Void)) {
            typeError(t,"expected return value");
          }
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}

/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree) { 
  sc_push(globalScope);
  traverse(syntaxTree, beforeCheckNode, checkNode);
  sc_pop();
}
