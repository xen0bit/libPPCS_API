
ssize_t recvfrom(int32_t fd, void* buf, size_t len, int32_t flags, union __SOCKADDR_ARG addr, socklen_t* addrlen)

{
    /* tailcall */
    return recvfrom(fd, buf, len, flags, addr, addrlen);
}

