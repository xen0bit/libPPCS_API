
int32_t gettimeofday(struct timeval* arg1, void* arg2)

{
    /* tailcall */
    return gettimeofday(arg1, arg2);
}

