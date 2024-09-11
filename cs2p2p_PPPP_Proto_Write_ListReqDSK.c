
int64_t cs2p2p_PPPP_Proto_Write_ListReqDSK(char* arg1, char* arg2, int32_t arg3, char* arg4, char* arg5)

{
    __builtin_memset(arg1, 0, 0x2c);
    strncpy(arg1, arg2, 7);
    strncpy(&arg1[0xc], arg4, 7);
    *(arg1 + 8) = _byteswap(arg3);
    /* tailcall */
    return strncpy(&arg1[0x14], arg5, 0x17);
}

