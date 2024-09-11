
int64_t cs2_TCPNBSkt_Close(int32_t arg1)

{
    shutdown(arg1, 2);
    /* tailcall */
    return close(arg1);
}

