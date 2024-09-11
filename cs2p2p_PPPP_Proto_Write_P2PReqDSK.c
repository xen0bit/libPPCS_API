
int64_t cs2p2p_PPPP_Proto_Write_P2PReqDSK(char* arg1, char* arg2, int32_t arg3, char* arg4, int16_t* arg5, char arg6, char* arg7, char* arg8)

{
    strncpy(arg1, arg2, 7);
    strncpy(&arg1[0xc], arg4, 7);
    char x8 = *arg7;
    int32_t temp0 = _byteswap(arg3);
    arg1[0x25] = x8;
    arg1[0x26] = arg7[1];
    char x8_2 = arg7[2];
    *(arg1 + 8) = temp0;
    arg1[0x24] = arg6;
    *(arg1 + 0x1c) = 0;
    *(arg1 + 0x14) = 0;
    arg1[0x27] = x8_2;
    *(arg1 + 0x14) = (_byteswap(*arg5) >> 0x10);
    *(arg1 + 0x16) = (_byteswap(arg5[1]) >> 0x10);
    *(arg1 + 0x18) = _byteswap(*(arg5 + 4));
    /* tailcall */
    return strncpy(&arg1[0x28], arg8, 0x17);
}

