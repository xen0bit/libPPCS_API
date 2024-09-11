
char* cs2p2p_PPPP_Proto_Read_RSLgn1(char* arg1, char* arg2, int32_t* arg3, char* arg4, int32_t* arg5, int32_t* arg6, int64_t* arg7)

{
    strncpy(arg2, arg1, 7);
    char* result = strncpy(arg4, &arg1[0xc], 7);
    *arg3 = _byteswap(*(arg1 + 8));
    *arg5 = _byteswap(*(arg1 + 0x14));
    *arg6 = _byteswap(*(arg1 + 0x18));
    *arg7 = 0;
    arg7[1] = 0;
    *arg7 = (_byteswap(*(arg1 + 0x1c)) >> 0x10);
    *(arg7 + 2) = (_byteswap(*(arg1 + 0x1e)) >> 0x10);
    *(arg7 + 4) = _byteswap(*(arg1 + 0x20));
    return result;
}

