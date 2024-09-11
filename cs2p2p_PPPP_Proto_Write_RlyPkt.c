
char* cs2p2p_PPPP_Proto_Write_RlyPkt(int32_t* arg1, char* arg2, int32_t arg3, char* arg4, char arg5, int32_t arg6)

{
    int32_t temp0 = _byteswap(arg6);
    *(arg1 + 4) = 0;
    *(arg1 + 0xc) = 0;
    *(arg1 + 0x14) = 0;
    *arg1 = temp0;
    strncpy(&arg1[1], arg2, 7);
    char* result = strncpy(&arg1[4], arg4, 7);
    arg1[3] = _byteswap(arg3);
    arg1[6] = arg5;
    return result;
}

