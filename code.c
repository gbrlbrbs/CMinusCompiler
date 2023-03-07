/****************************************************/
/* File: code.c                                     */
/* TM Code emitting utilities                       */
/* implementation for the TINY compiler             */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "code.h"

/* Variable indentno is used to
 * store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ 
    int i;
    for (i=0;i<indentno;i++) fprintf(code," ");
}

/* location number for current instruction emission */
static int emitLoc = 0 ;

/* Highest location emitted so far
   For use in conjunction with emitSkip,
   emitBackup, and emitRestore */
static int highEmitLoc = 0;

static int tempVarNum = 0;

void emitConstOrId(TreeNode *node) {
  if (node->kind.exp == Id) fprintf(code, "%s ", node->attr.name);
  if (node->kind.exp == Const) fprintf(code, "%d ", node->attr.val);
}

int isConstOrId(TreeNode *node) {
  return (node->kind.exp == Id || node->kind.exp == Const);
}

void emitFunDecl(char* name) {
  fprintf(code, "%s:\n", name);
}

int getParams(TreeNode* node) {
  TreeNode *aux = node;
  int numParams = 0;
  while (aux != NULL) {
    switch (aux->kind.exp)
    {
    case Id:
      fprintf(code, "param %s\n", aux->attr.name);
      break;
    case Const:
      fprintf(code, "param %d\n", aux->attr.val);
      break;
    case Op:
      emitOp(aux);
      fprintf(code, "param _t%d\n", aux->tempOpNum);
      break;
    case Call:
      emitCall(aux);
      fprintf(code, "param _t%d\n", aux->tempOpNum);
    default:
      break;
    }
    numParams++;
    aux = aux->sibling;
  }
  return numParams;
}

void emitCall(TreeNode *node) {
  node->tempOpNum = tempVarNum++;
  TreeNode *params = node->child[0];
  int numParams = getParams(params);
  fprintf(code, "_t%d = call %s, %d\n", node->tempOpNum, node->attr.name, numParams);
}


void printOp(TokenType op) {
  switch (op)
    {
      case LT: fprintf(code,"< "); break;
      case LT_EQ: fprintf(code,"<= "); break;
      case GT: fprintf(code,"> "); break;
      case GT_EQ: fprintf(code,">= "); break;
      case EQUALS: fprintf(code,"== "); break;
      case NOT_EQ: fprintf(code,"!= "); break;
      case PLUS: fprintf(code,"+ "); break;
      case MINUS: fprintf(code,"- "); break;
      case TIMES: fprintf(code,"* "); break;
      case DIV: fprintf(code,"/ "); break;
      default:
        break;
    }
}

void emitAssign(TreeNode* node) {
  TreeNode *lhs, *rhs;
  lhs = node->child[0];
  rhs = node->child[1];
  if (rhs->node_kind == Exp) {
    if (rhs->kind.exp == Const) {
      fprintf(code, "%s = %d\n", lhs->attr.name, rhs->attr.val);
    }
    if (rhs->kind.exp == Id) {
      fprintf(code, "%s = %s\n", lhs->attr.name, rhs->attr.name);
    }
    if (rhs->kind.exp == Op) {
      emitOp(rhs);
      fprintf(code, "%s = _t%d\n", lhs->attr.name, rhs->tempOpNum);
    }
    if (rhs->kind.exp == Call) {
      emitCall(rhs);
      fprintf(code, "%s = _t%d\n", lhs->attr.name, rhs->tempOpNum);
    }
  }
}

void emitOp(TreeNode* node) {
  TreeNode *lhs, *rhs;
  node->tempOpNum = tempVarNum++;
  lhs = node->child[0];
  rhs = node->child[1];
  if (isConstOrId(lhs) && isConstOrId(rhs)) {
    fprintf(code, "_t%d = ", node->tempOpNum);
    emitConstOrId(lhs);
    printOp(node->attr.op);
    emitConstOrId(rhs);
  }
  if (lhs->kind.exp == Op && isConstOrId(rhs)) {
    emitOp(lhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, lhs->tempOpNum);
    printOp(node->attr.op);
    emitConstOrId(rhs);
  }
  if (isConstOrId(lhs) && rhs->kind.exp == Op) {
    emitOp(rhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, rhs->tempOpNum);
    printOp(node->attr.op);
    emitConstOrId(lhs);
  }
  if (lhs->kind.exp == Call && isConstOrId(rhs)) {
    emitCall(lhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, lhs->tempOpNum);
    printOp(node->attr.op);
    emitConstOrId(rhs);
  }
  if (lhs->kind.exp == Call && rhs->kind.exp == Op) {
    emitCall(lhs);
    emitOp(rhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, lhs->tempOpNum);
    printOp(node->attr.op);
    fprintf(code, "_t%d", rhs->tempOpNum);
  }
  if (isConstOrId(lhs) && rhs->kind.exp == Call) {
    emitCall(rhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, rhs->tempOpNum);
    printOp(node->attr.op);
    emitConstOrId(lhs);
  }
  if (lhs->kind.exp == Op && rhs->kind.exp == Call) {
    emitOp(lhs);
    emitCall(rhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, lhs->tempOpNum);
    printOp(node->attr.op);
    fprintf(code, "_t%d", rhs->tempOpNum);
  }
  if (lhs->kind.exp == Call && rhs->kind.exp == Call) {
    emitCall(lhs);
    emitCall(rhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, lhs->tempOpNum);
    printOp(node->attr.op);
    fprintf(code, "_t%d", rhs->tempOpNum);
  }
  if (lhs->kind.exp == Op && rhs->kind.exp == Op) {
    emitOp(lhs);
    emitOp(rhs);
    fprintf(code, "_t%d = _t%d ", node->tempOpNum, lhs->tempOpNum);
    printOp(node->attr.op);
    fprintf(code, "_t%d", rhs->tempOpNum);
  }
  fprintf(code, "\n");
}
