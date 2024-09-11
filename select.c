
int32_t select(int32_t nfds, struct fd_set* readfds, struct fd_set* writefds, struct fd_set* exceptfds, struct timeval* timeout)

{
    /* tailcall */
    return select(nfds, readfds, writefds, exceptfds, timeout);
}

