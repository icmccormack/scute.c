#include <stdio.h>
#include "memory.h"
#include "compiler_defs.h"

void addLocal(Compiler* compiler, TK idName){
    if(compiler->localCount + 1 > compiler->scopeCapacity){
        int oldCapacity = compiler->scopeCapacity;
		compiler->scopeCapacity = GROW_CAPACITY(oldCapacity);
		compiler->locals = GROW_ARRAY(compiler->locals, Local, oldCapacity, compiler->scopeCapacity);
    }
    Local* target = &(compiler->locals[compiler->localCount]);
    target->depth = -1;
    target->id = idName;
    ++compiler->localCount;
}


void freeCompiler(Compiler* compiler){
	freeMap(compiler->classes);
	FREE_ARRAY(Local, compiler->locals, compiler->scopeCapacity);
}