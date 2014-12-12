#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "dyn_str.h"

typedef struct {
    unsigned int word_count;
} ProcessResults;

/*
 * Read file as string to *string, while calculating various (well just word count, actually) statistics from it.
 */
ProcessResults process_file(FILE *fp, DynStr *string) {
    ProcessResults res;
    res.word_count = 0;
    bool last_char_was_whitespace = true;

    while (true) {
        wint_t input_char_int = fgetwc(fp);

        if (input_char_int == WEOF) {
            break;
        }

        wchar_t input_char = (wchar_t) input_char_int;
        dyn_str_append(string, input_char);

        if (last_char_was_whitespace && !iswspace(input_char)) {
            res.word_count += 1;
        }

        last_char_was_whitespace = iswspace(input_char);
    }

    return res;
}

void print_stats(ProcessResults *results, DynStr *string) {
    wprintf(L"Reverse: ");
    dyn_str_print_reverse(string, stdout);
    wprintf(L"\n");
    wprintf(L"Words: %u\n", results->word_count);
    wprintf(L"Length: %zd\n", string->length);
}

int main(void) {
    // use whatever locale is on environment variables
    setlocale(LC_CTYPE, "");

    DynStr string;
    dyn_str_init(&string);

    ProcessResults results = process_file(stdin, &string);
    print_stats(&results, &string);

    dyn_str_free(&string);
    return 0;
}