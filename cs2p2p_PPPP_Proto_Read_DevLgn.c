
char* cs2p2p_PPPP_Proto_Read_DevLgn(char* arg1, char* arg2, int32_t* arg3, char* arg4, char* arg5, char* arg6, int64_t* arg7)

{
    strncpy(arg2, arg1, 7);
    char* result = strncpy(arg4, &arg1[0xc], 7);
    *arg6 = arg1[0x15];
    arg6[1] = arg1[0x16];
    arg6[2] = arg1[0x17];
    *arg3 = _byteswap(*(arg1 + 8));
    *arg5 = arg1[0x14];
    *arg7 = 0;
    arg7[1] = 0;
    *arg7 = (_byteswap(*(arg1 + 0x18)) >> 0x10);
    *(arg7 + 2) = (_byteswap(*(arg1 + 0x1a)) >> 0x10);
    *(arg7 + 4) = _byteswap(*(arg1 + 0x1c));
    return result;
}

