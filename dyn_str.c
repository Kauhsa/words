#include <stdlib.h>
#include <printf.h>
#include <stdio.h>
#include "dyn_str.h"

int INITIAL_LENGTH = 10;

void dyn_str_init(DynStr *dyn_str) {
    dyn_str->content = malloc(INITIAL_LENGTH);

    if (dyn_str->content == NULL) {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }

    dyn_str->allocated_length = INITIAL_LENGTH;
    dyn_str->length = 0;
    dyn_str->content[0] = '\0';
}

void dyn_str_enlarge(DynStr *dyn_str) {
    dyn_str->allocated_length *= 2;
    dyn_str->content = realloc(dyn_str->content, dyn_str->allocated_length);

    if (dyn_str->content == NULL) {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }
}

void dyn_str_free(DynStr *dyn_str) {
    free(dyn_str->content);
}

void dyn_str_append(DynStr *dyn_str, char c) {
    if (dyn_str->length >= dyn_str->allocated_length - 1) {
        dyn_str_enlarge(dyn_str);
    }

    dyn_str->content[dyn_str->length] = c;
    dyn_str->content[dyn_str->length + 1] = '\0';
    dyn_str->length += 1;
}

char *dyn_str_ptr_to_last_char(DynStr *dyn_str) {
    return dyn_str->content + dyn_str->length - 1;
}

void dyn_str_print_reverse(DynStr *dyn_str, FILE *fp) {
    char *current = dyn_str_ptr_to_last_char(dyn_str);
    while (current >= dyn_str->content) {
        fputc(*current, fp);
        current--;
    }
}