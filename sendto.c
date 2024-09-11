
ssize_t sendto(int32_t fd, void const* buf, size_t len, int32_t flags, union __CONST_SOCKADDR_ARG addr, socklen_t addrlen)

{
    /* tailcall */
    return sendto(fd, buf, len, flags, addr, addrlen);
}

