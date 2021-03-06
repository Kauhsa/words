#pragma once

typedef struct {
    wchar_t *content;
    size_t allocated_length;
    size_t length;
} DynStr;

void dyn_str_init(DynStr *dyn_str);
void dyn_str_enlarge(DynStr *dyn_str);
void dyn_str_free(DynStr *dyn_str);
void dyn_str_append(DynStr *dyn_str, wchar_t c);
void dyn_str_print_reverse(DynStr *dyn_str, FILE *fp);