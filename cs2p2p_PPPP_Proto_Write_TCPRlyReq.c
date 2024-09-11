
int64_t cs2p2p_PPPP_Proto_Write_TCPRlyReq(char* arg1, char* arg2, int32_t arg3, char* arg4, char arg5, char* arg6, char arg7, sockaddr_cs2* arg8)

{
    __builtin_memset(arg1, 0, 0x34);
    strncpy(arg1, arg2, 7);
    strncpy(&arg1[0xc], arg4, 7);
    int32_t temp0 = _byteswap(arg3);
    arg1[0x2c] = arg5;
    *(arg1 + 8) = temp0;
    arg1[0x2d] = *arg6;
    arg1[0x2e] = arg6[1];
    char x8_3 = arg6[2];
    arg1[0x30] = arg7;
    arg1[0x2f] = x8_3;
    /* tailcall */
    return htonAddrCS2(arg8, &arg1[0x14]);
}

