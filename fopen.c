
FILE* fopen(char const* filename, char const* mode)

{
    /* tailcall */
    return fopen(filename, mode);
}

