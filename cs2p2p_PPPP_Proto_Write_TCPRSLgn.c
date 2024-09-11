
int64_t cs2p2p_PPPP_Proto_Write_TCPRSLgn(char* arg1, char* arg2, int32_t arg3, char* arg4, int32_t arg5, int32_t arg6, int32_t arg7, int32_t arg8, int32_t arg9, sockaddr_cs2* arg10)

{
    *(arg1 + 0x30) = 0;
    __builtin_memset(arg1, 0, 0x20);
    *(arg1 + 0x20) = {0};
    strncpy(arg1, arg2, 7);
    strncpy(&arg1[0xc], arg4, 7);
    int32_t temp0 = _byteswap(arg3);
    int32_t temp0_1 = _byteswap(arg9);
    int32_t temp0_2 = _byteswap(arg5);
    int32_t temp0_3 = _byteswap(arg6);
    int32_t temp0_4 = _byteswap(arg7);
    int32_t temp0_5 = _byteswap(arg8);
    *(arg1 + 8) = temp0;
    *(arg1 + 0x14) = temp0_1;
    *(arg1 + 0x18) = (temp0_2 >> 0x10);
    *(arg1 + 0x1a) = (temp0_3 >> 0x10);
    *(arg1 + 0x1c) = (temp0_4 >> 0x10);
    *(arg1 + 0x1e) = (temp0_5 >> 0x10);
    /* tailcall */
    return htonAddrCS2(arg10, &arg1[0x20]);
}

