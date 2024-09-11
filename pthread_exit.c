
void pthread_exit(void* retval) __noreturn

{
    /* tailcall */
    return pthread_exit(retval);
}

