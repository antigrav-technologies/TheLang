#include <ctype.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#define TAPE_SIZE 30000

const char BF_MOVE_POINTER_LEFT = 0;
const char BF_MOVE_POINTER_RIGHT = 1;
const char BF_INCREMENT_CELL = 2;
const char BF_DECREMENT_CELL = 3;
const char BF_PRINT_CELL = 4;
const char BF_INPUT_CELL = 5;
const char BF_LOOP_START = 6;
const char BF_LOOP_END = 7;
const char BF_PROGRAM_END = 0x7F;

void execute_bf(const char* code_ptr) {
    char tape[TAPE_SIZE] = {};
    char *tape_ptr = tape;
    code_ptr++;

    while (1) {
        switch (*code_ptr) {
            case BF_PROGRAM_END:
                return;
            case BF_MOVE_POINTER_RIGHT:
                tape_ptr++;
                break;
            case BF_MOVE_POINTER_LEFT:
                tape_ptr--;
                break;
            case BF_INCREMENT_CELL:
                (*tape_ptr)++;
                break;
            case BF_DECREMENT_CELL:
                (*tape_ptr)--;
                break;
            case BF_PRINT_CELL:
                printf("%c", *tape_ptr);
                break;
            case BF_INPUT_CELL:
                *tape_ptr = (char)getchar();
                break;
            case BF_LOOP_START:
                if (*tape_ptr != 0) break;
                int b = 1;
                while (b) {
                    switch (*(++code_ptr)) {
                        case BF_LOOP_END: b--; break;
                        case BF_LOOP_START: b++; break;
                        case BF_PROGRAM_END:
                            fprintf(stderr, "Unmatched brackets\n");
                            exit(2);
                        default:
                    }
                }
                break;
            case BF_LOOP_END:
                if (*tape_ptr == 0) break;
                b = 1;
                while (b) {
                    switch (*(--code_ptr)) {
                        case BF_LOOP_END: b++; break;
                        case BF_LOOP_START: b--; break;
                        case BF_PROGRAM_END:
                            fprintf(stderr, "Unmatched brackets\n");
                            exit(2);
                        default:
                    }
                }
                break;
            default:
                exit(0x7f); // shouldn't be possible
        }
        code_ptr++;
    }
}

unsigned char is_not_space_or_EOF(int c) {
    return !(isspace(c) || c == EOF);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No filename provided.\nUsage: ./TheLang <input.the>\n");
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    unsigned long long count = 0;
    char c;
    while ((c = (char)fgetc(file)) != EOF) {
        if (isspace(c)) continue;
        
        if (tolower(c) != 't' ||
            tolower(fgetc(file)) != 'h' ||
            tolower(fgetc(file)) != 'e' ||
            is_not_space_or_EOF(fgetc(file))) {
            fprintf(stderr, "Invalid input. Please enter the\n");
            exit(2);
        }
        count++;
    }
    fclose(file);

    int size = (count == 0) ? 1 : (int)floor(log((double)count) / log(8)) + 1;
    char code[size + 2];

    int i = 1;
    while (count) {
        code[i++] = (char)(count % 8);
        count /= 8;
    }
    code[0] = BF_PROGRAM_END;
    code[i] = BF_PROGRAM_END;
    execute_bf(code);
    printf("\n");
    return 0;
}