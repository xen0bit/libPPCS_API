
char* cs2p2p_PPPP_Proto_Write_RSLgn1(char* arg1, char* arg2, int32_t arg3, char* arg4, int32_t arg5, int32_t arg6, int16_t* arg7)

{
    strncpy(arg1, arg2, 7);
    char* result = strncpy(&arg1[0xc], arg4, 7);
    int32_t temp0 = _byteswap(arg3);
    int32_t temp0_1 = _byteswap(arg5);
    int32_t temp0_2 = _byteswap(arg6);
    *(arg1 + 0x24) = 0;
    *(arg1 + 8) = temp0;
    *(arg1 + 0x14) = temp0_1;
    *(arg1 + 0x18) = temp0_2;
    *(arg1 + 0x1c) = 0;
    *(arg1 + 0x1c) = (_byteswap(*arg7) >> 0x10);
    *(arg1 + 0x1e) = (_byteswap(arg7[1]) >> 0x10);
    *(arg1 + 0x20) = _byteswap(*(arg7 + 4));
    return result;
}

