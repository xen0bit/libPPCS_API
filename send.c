
ssize_t send(int32_t fd, void const* buf, size_t len, int32_t flags)

{
    /* tailcall */
    return send(fd, buf, len, flags);
}

