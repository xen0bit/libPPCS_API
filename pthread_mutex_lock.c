
int32_t pthread_mutex_lock(union pthread_mutex_t* mutex)

{
    /* tailcall */
    return pthread_mutex_lock(mutex);
}

