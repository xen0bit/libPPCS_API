
int32_t rename(char const* old, char const* new)

{
    /* tailcall */
    return rename(old, new);
}

