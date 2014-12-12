#include <stdlib.h>
#include <printf.h>
#include <stdio.h>
#include <wchar.h>
#include "dyn_str.h"

static const unsigned int INITIAL_LENGTH = 10;
static const unsigned int ENLARGE_FACTOR = 2;

void dyn_str_init(DynStr *dyn_str) {
    dyn_str->content = malloc(INITIAL_LENGTH * sizeof(wchar_t));

    if (dyn_str->content == NULL) {
        fwprintf(stderr, L"Allocation error\n");
        exit(1);
    }

    dyn_str->allocated_length = INITIAL_LENGTH;
    dyn_str->length = 0;
    dyn_str->content[0] = 0;
}

void dyn_str_enlarge(DynStr *dyn_str) {
    dyn_str->allocated_length *= ENLARGE_FACTOR;
    dyn_str->content = realloc(dyn_str->content, dyn_str->allocated_length * sizeof(wchar_t));

    if (dyn_str->content == NULL) {
        fwprintf(stderr, L"Allocation error\n");
        exit(1);
    }
}

void dyn_str_free(DynStr *dyn_str) {
    free(dyn_str->content);
}

void dyn_str_append(DynStr *dyn_str, wchar_t c) {
    if (dyn_str->length >= dyn_str->allocated_length - 1) {
        dyn_str_enlarge(dyn_str);
    }

    dyn_str->content[dyn_str->length] = c;
    dyn_str->content[dyn_str->length + 1] = 0;
    dyn_str->length += 1;
}

wchar_t *dyn_str_ptr_to_last_char(DynStr *dyn_str) {
    return dyn_str->content + dyn_str->length - 1;
}

void dyn_str_print_reverse(DynStr *dyn_str, FILE *fp) {
    wchar_t *current_ptr = dyn_str_ptr_to_last_char(dyn_str);

    while (current_ptr >= dyn_str->content) {
        fputwc(*current_ptr, fp);
        current_ptr--;
    }
}