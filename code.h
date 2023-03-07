/****************************************************/
/* File: code.h                                     */
/* Code emitting utilities for the TINY compiler    */
/* and interface to the TM machine                  */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _CODE_H_
#define _CODE_H_

#include "globals.h"

void emitFunDecl(char* name);
void emitOp(TreeNode* node);
void emitAssign(TreeNode* node);
void emitCall(TreeNode *node);
int getParams(TreeNode* node);
void emitConstOrId(TreeNode *node);

#endif
