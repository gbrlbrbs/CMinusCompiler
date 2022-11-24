/*******************************/
/* cminus.y                    */
/* C- YACC/Bison specification */
/*******************************/
%{

#define YYPARSER

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
//#include "symtab.h"

static char* savedName;
static int savedLineNo;
static TreeNode* savedTree;
static int yylex(void);
int yyerror(char *s);
int scopenum = 0;

%}

%token IF ELSE WHILE RETURN INT VOID
%token ASSIGN
%token EQUALS NOT_EQ GT GT_EQ LT LT_EQ
%token PLUS MINUS TIMES DIV
%token SEMICOL COMMA LPAR RPAR LBRACK RBRACK LCURLY RCURLY
%token NUMBER IDENTIFIER
%token ENDFILE ERROR

%union {
	TreeNode* tnode;
	TokenType tok;
}

%type<tnode> program decl_list decl var_decl
%type<tnode> fun_decl params param_list param cmpnd_stmnt
%type<tnode> loc_decls stmnt_list statement
%type<tnode> exp_stmnt selec_stmnt it_stmnt return_stmnt
%type<tnode> expr var simple_expr
%type<tnode> add_expr term factor call args arg_list type_spec
%type<tok> relop addop mulop

%right ELSE

%%
program : decl_list 
            { 
				savedTree = $1;
				YYACCEPT;
			}
        ;
decl_list : decl_list decl
                {
                    TreeNode* t = $1;
                    if (t != NULL) {
                        while (t->sibling != NULL) t = t->sibling;
                        t->sibling = $2;
                        $$ = $1;
                    } else {
                        $$ = $2;
                    }
                }
            | decl 
                { $$ = $1; }
        ;
decl : var_decl
        { $$ = $1; }
        | fun_decl
        { $$ = $1; }
    ;
var_decl : type_spec IDENTIFIER SEMICOL
            {
                $$ = $1;
                $$->attr.name = copyString(lastId);                
            }
            | type_spec IDENTIFIER LBRACK NUMBER
            {
                $<tnode>$ = $1;
				$<tnode>$->type = Array;
                $<tnode>$->attr.name = copyString(lastId);
                $<tnode>$->child[0] = newExpNode(Const);
                $<tnode>$->child[0]->attr.val = atoi(tokenString);
                
            }
            RBRACK SEMICOL
            {
                $$ = $<tnode>5;
            }
        ;
type_spec : INT 
            {
                $$ = newDeclNode(Var);
				$$->type = Int;
            }
            | VOID
            {
                $$ = newDeclNode(Var);
				$$->type = Void;
            }
        ;
fun_decl : type_spec IDENTIFIER
			{ 
                $<tnode>$ = $1;
				$<tnode>$->kind.decl = Fun;
			    $<tnode>$->attr.name = copyString(lastId);
			}
			LPAR params RPAR cmpnd_stmnt
			{ 
                $$ = $<tnode>3;
			    $$->child[0] = $5;
			    $$->child[1] = $7;
      		}
		;
params	: param_list
			{ 
                $$ = $1;
			}
			| VOID
			{ 
				$$ = newDeclNode(Param);
                $$->type = Void;
			}
		;
param_list : param_list COMMA param
			{ 
                TreeNode* t = $1;
                if (t != NULL) {
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = $3;
                    $$ = $1;
			    } else $$ = $3;
			}
			| param
			{ 
                $$ = $1; 
            }
        ;
param : type_spec IDENTIFIER
			{ 
                $$ = $1;
			    $$->kind.decl = Param;
			    $$->attr.name = copyString(lastId);
			}
			| type_spec IDENTIFIER LBRACK RBRACK
			{ 
                $<tnode>$ = $1;
				$<tnode>$->kind.decl = Param;
				$<tnode>$->type = Array;
			    $<tnode>$->attr.name = copyString(lastId);
				$<tnode>$->child[0] = newExpNode(Const);
                $<tnode>$->child[0]->attr.val = 0;
			}
			;
cmpnd_stmnt	: LCURLY loc_decls stmnt_list RCURLY
			{
			    $$ = newStmntNode(Compound);
				$$->child[0] = $2;
				$$->child[1] = $3;
			}
			;
loc_decls : loc_decls var_decl
			{ 
                TreeNode* t = $1;
                if (t != NULL) {
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = $2;
                    $$ = $1;
			    } else $$ = $2;
			}
			|  // epsilon
			  { $$ = NULL; }
			;
stmnt_list : stmnt_list statement
			{ 
                TreeNode* t = $1;
                if (t != NULL){
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = $2;
                    $$ = $1;
			    } else $$ = $2;
			}
			|  // epsilon
			  { $$ = NULL; }
			;
statement : exp_stmnt
			{ $$ = $1; }
			| cmpnd_stmnt
			{ $$ = $1; }
			| selec_stmnt
			{ $$ = $1; }
			| it_stmnt
			{ $$ = $1; }
			| return_stmnt
			{ $$ = $1; }
			;
exp_stmnt : expr SEMICOL
			  { $$ = $1; }
			| SEMICOL
			  { $$ = NULL; }
			;
selec_stmnt	: IF LPAR expr RPAR statement %prec ELSE
			{ 
                $$ = newStmntNode(If);
			    $$->child[0] = $3;
			    $$->child[1] = $5;
			}
			| IF LPAR expr RPAR statement ELSE statement
			{ 
                $$ = newStmntNode(If);
			    $$->child[0] = $3;
			    $$->child[1] = $5;
			    $$->child[2] = $7;
			}
			;
it_stmnt : WHILE LPAR expr RPAR statement
			{ 
                $$ = newStmntNode(While);
			    $$->child[0] = $3;
			    $$->child[1] = $5;
			}
			;
return_stmnt : RETURN SEMICOL
			  { $$ = newStmntNode(Return); }
			| RETURN expr SEMICOL
			{ 
                $$ = newStmntNode(Return);
			    $$->child[0] = $2;
			}
			;
expr : var ASSIGN expr
			{ 
                $$ = newExpNode(Assign);
				$$->attr.op = ASSIGN;
			    $$->child[0] = $1;
			    $$->child[1] = $3;
			}
			| simple_expr
			  { $$ = $1; }
			;
var	: IDENTIFIER
			{ 
                $$ = newExpNode(Id);
			    $$->attr.name = (char *) copyString(lastId);
			}
			| IDENTIFIER
			{ 
                $<tnode>$ = newExpNode(ArrId);
			    $<tnode>$->attr.name = copyString(lastId);
			}
			LBRACK expr RBRACK
			{ 
                $$ = $<tnode>2;
			    $$->child[0] = $4;
			}
			;
simple_expr : add_expr relop add_expr
			{ 
                $$ = newExpNode(Op);
			    $$->attr.op = $2;
			    $$->child[0] = $1;
			    $$->child[1] = $3;
			}
			| add_expr
			{ $$ = $1; }
			;
relop : EQUALS
        { $$ = EQUALS; }
        | NOT_EQ
        { $$ = NOT_EQ; }
        | LT_EQ
        { $$ = LT_EQ; }
        | GT_EQ
        { $$ = GT_EQ; }
        | LT
        { $$ = LT; }
        | GT
        { $$ = GT; }
        ;
add_expr : add_expr addop term
			{ 
                $$ = newExpNode(Op);
			    $$->attr.op = $2;
			    $$->child[0] = $1;
			    $$->child[1] = $3;
			}
			| term
			{ $$ = $1; }
			;
addop : PLUS
		{ $$ = PLUS; }
		| MINUS
		{ $$ = MINUS; }
		;
term : term mulop factor
			{ 
                $$ = newExpNode(Op);
			    $$->attr.op = $2;
			    $$->child[0] = $1;
			    $$->child[1] = $3;
			}
			| factor
			{ $$ = $1; }
		;
mulop : TIMES
		{ $$ = TIMES; }
		| DIV
		{ $$ = DIV; }
	;
factor : LPAR expr RPAR
			{ $$ = $2; }
			| var
			{ $$ = $1; }
			| call
			{ $$ = $1; }
			| NUMBER
			{ 
                $$ = newExpNode(Const);
				$$->type = Int;
			    $$->attr.val = atoi(tokenString);
			}
		;
call : IDENTIFIER
			{ 
                $<tnode>$ = newExpNode(Call);
			    $<tnode>$->attr.name = copyString(lastId);
			}
			LPAR args RPAR
			{ 
                $$ = $<tnode>2;
			    $$->child[0] = $4;
			}
		;
args : arg_list
		{ $$ = $1; }
		|
		{ $$ = NULL; }
	;
arg_list : arg_list COMMA expr
			{ 
                TreeNode * t = $1;
                if (t != NULL) {
			        while (t->sibling != NULL) t = t->sibling;
                    t->sibling = $3;
                    $$ = $1;
			    } else $$ = $3;
			}
			| expr
			{ $$ = $1; }
		;
%%

int yyerror(char * message) {
    fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
	fprintf(listing,"Current token: ");
	printToken(yychar,tokenString);
	Error = TRUE;
	return 0;
}

static int yylex(void) {
	return getToken();
}

TreeNode* parse(void) {
	yyparse();
	return savedTree;
}