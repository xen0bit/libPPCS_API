
int64_t memcpy(void* arg1, void const* arg2, size_t arg3)

{
    /* tailcall */
    return memcpy(arg1, arg2, arg3);
}

