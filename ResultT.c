#include <stdio.h>
#include <stdint.h>

typedef enum {
    Ok = 1,
    Err = -1
} Status;

typedef union {
    uint32_t u32;
    uint64_t u64;
    int32_t i32;
    int64_t i64;
    char Char;
    char *String;
    uint8_t None;
} Value;

typedef struct {
    Status status;
    Value value;
} Result;

int main() {
    Result result;
    result.value.i32 = 230;
    result.status = Ok;

    Result result2;
    result2.status = Err;

    switch (result2.status) {
        case Ok:
            printf("Success: Value = %d\n", result.value.i32);
            break;
        case Err:
            printf("Failure: Value = %d\n", result2.value.None);
            break;
    }

    return 0;
}

