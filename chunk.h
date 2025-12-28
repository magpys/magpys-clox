#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    // note: We could (and perhaps should because it would be marginally faster) use specific OpCode instructions for
    // OP_GREATER_EQUAL, OP_LESS_EQUAL and OP_NOT_EQUAL - but we can build these out of a mixture of the others.
    // For example a <= b is equivalent to !(a > b), therefore we can build OP_LESS_EQUAL out of OP_GREATER followed by OP_NOT.
    // (most of the time - there are actually some edge cases for which that may not be true around NaN but what the hell).
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_JUMP,
    OP_JUMP_IF_FALSE,
    OP_PRINT,
    OP_RETURN
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif