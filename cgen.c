/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* for the TINY compiler                            */
/* (generates code for the TM machine)              */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/


#include "code.h"
#include "cgen.h"
#include "symtab.h"

#define ofpFO 0
#define retFO -1
#define initFO -2

static int isInFunc = FALSE;

static int globalOffset = 0;
static int localOffset = initFO;

static int label = 0;

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
    for (i=0;i<indentno;i++) fprintf(listing," ");
}

void cGen(TreeNode* syntaxTree);

void genStmnt(TreeNode *tree) {
    TreeNode *c0 = tree->child[0];
    TreeNode *c1 = tree->child[1];
    TreeNode *c2 = tree->child[2];
    switch (tree->kind.stmnt) {
        case Compound:
            cGen(c1);
            break;
        case If:
            tree->firstLabelNum = label++;
            tree->secondLabelNum = label++;
            cGen(c0);
            fprintf(code, "if_true _t%d goto L%d\n", c0->tempOpNum, tree->firstLabelNum);
            if (c2 != NULL) { /* has else */
                cGen(c2);
                if (tree->sibling != NULL) fprintf(code, "goto L%d\n", tree->secondLabelNum);
            }
            fprintf(code, "L%d:\n", tree->firstLabelNum);
            cGen(c1);
            if (tree->sibling != NULL) {
                fprintf(code, "L%d:\n", tree->secondLabelNum);
                cGen(tree->sibling);
            }
            break;
        case While:
            tree->firstLabelNum = label++;
            tree->secondLabelNum = label++;
            fprintf(code, "L%d:\n", tree->firstLabelNum);
            cGen(c0);
            fprintf(code, "if_true !_t%d goto L%d\n", c0->tempOpNum, tree->secondLabelNum);
            cGen(c1);
            fprintf(code, "goto L%d\n", tree->firstLabelNum);

            fprintf(code, "L%d:\n", tree->secondLabelNum);
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        case Return:
            if (c0 != NULL) {
                if (c0->kind.exp != Const && c0->kind.exp != Id) {
                    cGen(c0);
                    fprintf(code, "return _t%d\n", c0->tempOpNum);
                } else {
                    fprintf(code, "return ");
                    emitConstOrId(c0);
                    fprintf(code, "\n");
                }
            } else {
                fprintf(code, "return\n");
            }
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        default:
            break;
    }
}

void genExp(TreeNode* tree) {
    switch (tree->kind.exp) {
        case Assign:
            emitAssign(tree);
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        case Call:
            emitCall(tree);
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        case Op:
            emitOp(tree);
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        case Id:
        case Const:
            emitConstOrId(tree);
            break;
        case ArrId:
            emitArrId(tree);
            break;
        default:
            break;
    }
}

void genDecl(TreeNode* tree) {
    switch (tree->kind.decl) {
        case Fun:
            emitFunDecl(tree->attr.name);
            TreeNode* c1 = tree->child[1];
            cGen(c1);
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        case Var:
            if (tree->sibling != NULL) {
                cGen(tree->sibling);
            }
            break;
        default:
            break;
    }
}

void cGen(TreeNode* syntaxTree) {
    switch (syntaxTree->node_kind) {
        case Stmnt:
            genStmnt(syntaxTree);
            break;
        case Exp:
            genExp(syntaxTree);
            break;
        case Decl:
            genDecl(syntaxTree);
            break;
        default:
            break;
    }
}

/**********************************************/
/* the primary function of the code generator */
/**********************************************/
/* Procedure codeGen generates code to a code
 * file by traversal of the syntax tree. The
 * second parameter (codefile) is the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode* syntaxTree, char* codefile) {
    char *s = malloc(strlen(codefile) + 7);
    strcpy(s, "File: ");
    strcat(s, codefile);
    
    /* generate code for TAC program */
    cGen(syntaxTree);
}