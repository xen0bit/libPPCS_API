
char* strncpy(char* s1, char const* s2, size_t n)

{
    /* tailcall */
    return strncpy(s1, s2, n);
}

