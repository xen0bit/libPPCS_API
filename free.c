
void free(void* mem)

{
    /* tailcall */
    return free(mem);
}

