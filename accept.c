
int32_t accept(int32_t fd, union __SOCKADDR_ARG addr, socklen_t* len)

{
    /* tailcall */
    return accept(fd, addr, len);
}

