
char* fgets(char* buf, int32_t n, FILE* fp)

{
    /* tailcall */
    return fgets(buf, n, fp);
}

