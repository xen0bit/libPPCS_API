
ssize_t recv(int32_t fd, void* buf, size_t len, int32_t flags)

{
    /* tailcall */
    return recv(fd, buf, len, flags);
}

