#ifndef scute_vm_h
#define scute_vm_h

#include "chunk.h"
#include "value.h"
#include "package.h"

#define STACK_MAX 256
#define PI ((double)3.141592653589793238462)
#define E  ((double)2.718281828459045235360)

typedef struct {
	Chunk* chunk;
	uint8_t* ip;
	Value stack[STACK_MAX];
	int stackSize;
	Value* stackTop;
	HashMap* globals;
	Obj* runtimeObjects;
	ObjClosure* shapes;
	Value* stackBottom;
	ObjClosure* currentClosure;
	int frameIndex;
} VM;

extern VM vm;

void push(Value value);
Value pop();

InterpretResult interpretCompiled(CompilePackage* code, int index);
void runCompiler(CompilePackage* package, char* source);

#endif
