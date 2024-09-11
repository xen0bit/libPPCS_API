
int32_t pthread_mutex_unlock(union pthread_mutex_t* mutex)

{
    /* tailcall */
    return pthread_mutex_unlock(mutex);
}

