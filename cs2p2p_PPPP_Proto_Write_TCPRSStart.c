
int64_t cs2p2p_PPPP_Proto_Write_TCPRSStart(char* arg1, char* arg2, int32_t arg3, char* arg4, int32_t arg5, sockaddr_cs2* arg6)

{
    __builtin_memset(arg1, 0, 0x30);
    strncpy(arg1, arg2, 7);
    strncpy(&arg1[0xc], arg4, 7);
    int32_t temp0 = _byteswap(arg3);
    int32_t temp0_1 = _byteswap(arg5);
    *(arg1 + 8) = temp0;
    *(arg1 + 0x14) = temp0_1;
    /* tailcall */
    return htonAddrCS2(arg6, &arg1[0x18]);
}

