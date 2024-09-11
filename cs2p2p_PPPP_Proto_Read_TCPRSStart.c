
int64_t cs2p2p_PPPP_Proto_Read_TCPRSStart(char* arg1, char* arg2, int32_t* arg3, char* arg4, int32_t* arg5, sockaddr_cs2* arg6)

{
    strncpy(arg2, arg1, 7);
    strncpy(arg4, &arg1[0xc], 7);
    *arg3 = _byteswap(*(arg1 + 8));
    *arg5 = _byteswap(*(arg1 + 0x14));
    /* tailcall */
    return ntohAddrCS2(&arg1[0x18], arg6);
}

