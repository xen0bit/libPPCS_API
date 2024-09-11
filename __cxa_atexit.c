
int32_t __cxa_atexit(void (* func)(void* retval), void* arg, void* dso_handle)

{
    /* tailcall */
    return __cxa_atexit(func, arg, dso_handle);
}

