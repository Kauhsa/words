#pragma once

typedef struct {
    char *content;
    size_t allocated_length;
    size_t length;
} DynStr;

void dyn_str_init(DynStr *dyn_str);
void dyn_str_enlarge(DynStr *dyn_str);
void dyn_str_free(DynStr *dyn_str);
void dyn_str_append(DynStr *dyn_str, char c);