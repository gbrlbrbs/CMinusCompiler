/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "util.h"

char *typeStrings[] = {"void", "int", "int[]"};

/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType token, const char* tokenString ) { 
  switch (token) { 
    case IF:
    case ELSE:
    case WHILE:
    case RETURN:
    case INT:
    case VOID:
      fprintf(listing,
         "reserved word: %s\n",tokenString);
      break;
    case ASSIGN: fprintf(listing,"=\n"); break;
    case LT: fprintf(listing,"<\n"); break;
    case LT_EQ: fprintf(listing,"<=\n"); break;
    case GT: fprintf(listing,">\n"); break;
    case GT_EQ: fprintf(listing,">=\n"); break;
    case EQUALS: fprintf(listing,"==\n"); break;
    case NOT_EQ: fprintf(listing,"!=\n"); break;
    case LPAR: fprintf(listing,"(\n"); break;
    case RPAR: fprintf(listing,")\n"); break;
    case LBRACK: fprintf(listing,"[\n"); break;
    case RBRACK: fprintf(listing,"]\n"); break;
    case LCURLY: fprintf(listing,"{\n"); break;
    case RCURLY: fprintf(listing,"}\n"); break;
    case SEMICOL: fprintf(listing,";\n"); break;
    case COMMA: fprintf(listing,",\n"); break;
    case PLUS: fprintf(listing,"+\n"); break;
    case MINUS: fprintf(listing,"-\n"); break;
    case TIMES: fprintf(listing,"*\n"); break;
    case DIV: fprintf(listing,"/\n"); break;
    case ENDFILE: fprintf(listing,"EOF\n"); break;
    case NUMBER:
      fprintf(listing,
          "NUM, val = %s\n",tokenString);
      break;
    case IDENTIFIER:
      fprintf(listing,
          "ID, name = %s\n",tokenString);
      break;
    case ERROR:
      fprintf(listing,
          "ERROR: %s\n",tokenString);
      break;
    default: /* should never happen */
      fprintf(listing,"Unknown token: %d\n",token);
  }
}

/* Function newStmntNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmntNode(StmntKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->node_kind = Stmnt;
    t->kind.stmnt = kind;
    t->lineno = lineno;
  }
  return t;
}

/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->node_kind = Exp;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

/* Function newDeclNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode * newDeclNode(DeclKind kind) {
  TreeNode* t = (TreeNode*) malloc(sizeof(TreeNode));
  int i;
  if (t == NULL) fprintf(listing, "Out of memory at line %d\n", lineno);
  else {
    for (i = 0; i < MAXCHILDREN; i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->node_kind = Decl;
    t->kind.decl = kind;
    t->lineno = lineno;
  }
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* Variable indentno is used by printTree to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree )
{ 
  int i;
  INDENT;
  
  while (tree != NULL) {
    printSpaces();
    if (tree->node_kind == Stmnt)
    { 
      switch (tree->kind.stmnt) {
        case If:
          fprintf(listing,"If\n");
          break;
        case While:
          fprintf(listing,"While\n");
          break;
        case Compound:
          fprintf(listing,"Compound Statement:\n");
          break;
        case Return:
          fprintf(listing,"Return:\n");
          break;
        default:
          fprintf(listing,"Unknown StmntNode kind\n");
          break;
      }
    } else if (tree->node_kind == Exp) {
      switch (tree->kind.exp) {
        case Op:
          fprintf(listing,"Op: ");
          printToken(tree->attr.op,"\0");
          break;
        case Const:
          fprintf(listing,"Const: %d\n",tree->attr.val);
          break;
        case Id:
          fprintf(listing,"Id: %s\n",tree->attr.name);
          break;
        case ArrId:
          fprintf(listing, "Array Id: %s\n", tree->attr.name);
          break;
        case Call:
          fprintf(listing, "Call: %s\n", tree->attr.name);
          break;
        case Assign:
          fprintf(listing, "Assign: \n");
          break;
        default:
          fprintf(listing,"Unknown ExpNode kind\n");
          break;
      }
    } else if (tree->node_kind == Decl) {
      switch (tree->kind.decl)
      {
        case Var:
          fprintf(listing, "Var Declaration: type = %s, name = %s\n", typeStrings[tree->type], tree->attr.name);
          break;
        case Fun:
          fprintf(listing, "Function Declaration: type = %s, name = %s\n", typeStrings[tree->type], tree->attr.name);
          break;
        case Param:
          fprintf(listing, "Param Declaration: type = %s, name = %s\n", typeStrings[tree->type], tree->attr.name);
          break;
        default:
          fprintf(listing, "Unknown DeclNode kind\n");
          break;
      }
    } else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
         printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}
