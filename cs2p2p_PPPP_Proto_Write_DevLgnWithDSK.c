
int64_t cs2p2p_PPPP_Proto_Write_DevLgnWithDSK(char* arg1, char* arg2, int32_t arg3, char* arg4, char arg5, char* arg6, int16_t* arg7, char* arg8)

{
    strncpy(arg1, arg2, 7);
    strncpy(&arg1[0xc], arg4, 7);
    char x8 = *arg6;
    int32_t temp0 = _byteswap(arg3);
    arg1[0x15] = x8;
    arg1[0x16] = arg6[1];
    char x8_2 = arg6[2];
    *(arg1 + 8) = temp0;
    arg1[0x14] = arg5;
    *(arg1 + 0x18) = 0;
    *(arg1 + 0x20) = 0;
    arg1[0x17] = x8_2;
    *(arg1 + 0x18) = (_byteswap(*arg7) >> 0x10);
    *(arg1 + 0x1a) = (_byteswap(arg7[1]) >> 0x10);
    *(arg1 + 0x1c) = _byteswap(*(arg7 + 4));
    /* tailcall */
    return strncpy(&arg1[0x28], arg8, 0x17);
}

