
int64_t cs2_TCPSkt_Close(int32_t arg1)

{
    fcntl(arg1, 4, (fcntl(arg1, 3, 0) & 0xfffff7ff));
    shutdown(arg1, 2);
    /* tailcall */
    return close(arg1);
}

