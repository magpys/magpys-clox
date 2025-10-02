#include "vm.h"

#include <stdio.h>

#include "debug.h"

// bad practise to use global variables, but convenient for the sake of a tutorialised implementation
// note: the alternative better practise would be passing a pointer for a vm into each of our functions defined below,
// so definition would be something like:
// void initVM(VM* vm);
// implementation would be similar then calling it later you would need something along the lines of:
// VM vm;
// initVM(&vm);
// pointers!
VM vm;

void initVM() {}
void freeVM() {}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT:
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            case OP_RETURN:
                return INTERPRET_OK;
        }
    }

#undef READ_BYTE
#undef READ_CONSTANT
}