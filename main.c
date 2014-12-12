#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "dyn_str.h"

typedef struct {
    unsigned int word_count;
} ProcessResults;

/*
 * Read file as string to *string, while calculating various statistics from it.
 */
ProcessResults process_file(FILE *fp, DynStr *string) {
    ProcessResults res;
    bool last_char_was_whitespace = true;

    while (true) {
        int input_char_int = getc(fp);
        if (input_char_int == EOF) {
            break;
        }

        unsigned char input_char = (unsigned char) input_char_int;
        dyn_str_append(&string, input_char);

        if (last_char_was_whitespace && !isspace(input_char)) {
            res.word_count += 1;
        }

        last_char_was_whitespace = isspace(input_char);
    }

    return res;
}

void print_stats(ProcessResults *results, DynStr *string) {
    printf("Output: ");
    dyn_str_print_reverse(&string, stdout);
    printf("\n");
    printf("Words: %u\n", results->word_count);
    printf("Length: %zd\n", string->length);
}

int main(void) {
    DynStr string;
    dyn_str_init(&string);

    ProcessResults results = process_file(stdin, &string);
    print_stats(&results, &string);

    dyn_str_free(&string);
    return 0;
}