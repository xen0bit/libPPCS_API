
int64_t cs2p2p_PPPP_Proto_Read_TCPRSLgn(char* arg1, char* arg2, int32_t* arg3, char* arg4, uint16_t* arg5, uint16_t* arg6, uint16_t* arg7, uint16_t* arg8, int32_t* arg9, sockaddr_cs2* arg10)

{
    strncpy(arg2, arg1, 7);
    strncpy(arg4, &arg1[0xc], 7);
    *arg3 = _byteswap(*(arg1 + 8));
    *arg9 = _byteswap(*(arg1 + 0x14));
    *arg5 = (_byteswap(*(arg1 + 0x18)) >> 0x10);
    *arg6 = (_byteswap(*(arg1 + 0x1a)) >> 0x10);
    *arg7 = (_byteswap(*(arg1 + 0x1c)) >> 0x10);
    *arg8 = (_byteswap(*(arg1 + 0x1e)) >> 0x10);
    /* tailcall */
    return ntohAddrCS2(&arg1[0x20], arg10);
}

