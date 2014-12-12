#include <stdlib.h>
#include "dyn_str.h"

int INITIAL_LENGTH = 10;

void dyn_str_init(DynStr *dyn_str) {
    dyn_str->content = malloc(INITIAL_LENGTH);
    dyn_str->allocated_length = INITIAL_LENGTH;
    dyn_str->length = 0;
    dyn_str->content[0] = '\0';
}

void dyn_str_enlarge(DynStr *dyn_str) {
    dyn_str->allocated_length *= 2;
    dyn_str->content = realloc(dyn_str->content, dyn_str->allocated_length);
}

void dyn_str_free(DynStr *dyn_str) {
    free(dyn_str->content);
}

void dyn_str_append(DynStr *dyn_str, char c) {
    if (dyn_str->length == dyn_str->allocated_length) {
        dyn_str_enlarge(dyn_str);
    }

    dyn_str->content[dyn_str->length] = c;
    dyn_str->content[dyn_str->length + 1] = '\0';
    dyn_str->length += 1;
}