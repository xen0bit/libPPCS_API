
char* cs2p2p_PPPP_Proto_Write_SDevLgn(char* arg1, char* arg2, int32_t arg3, char* arg4)

{
    __builtin_memset(arg1, 0, 0x14);
    strncpy(arg1, arg2, 7);
    char* result = strncpy(&arg1[0xc], arg4, 7);
    *(arg1 + 8) = _byteswap(arg3);
    return result;
}

