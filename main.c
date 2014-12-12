#include <stdio.h>
#include <stdbool.h>
#include "dyn_str.h"

void process_file(FILE *fp);

int main(void) {
    process_file(stdin);
    return 0;
}

void process_file(FILE *fp) {
    // int length = 0;
    // int word_count = 0;
    // bool last_char_was_whitespace = false;

    DynStr string;
    dyn_str_init(&string);

    while (true) {
        int input_char_int = getc(fp);
        if (input_char_int == EOF) {
            break;
        }

        unsigned char input_char = (unsigned char) input_char_int;
        dyn_str_append(&string, input_char);
    }

    printf(string.content);
    printf("\n");

    dyn_str_free(&string);
}