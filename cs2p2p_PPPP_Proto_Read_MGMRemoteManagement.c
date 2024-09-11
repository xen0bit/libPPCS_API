
int64_t cs2p2p_PPPP_Proto_Read_MGMRemoteManagement(char* arg1, char* arg2, char* arg3, char* arg4, char* arg5, uint16_t* arg6)

{
    if (*arg1 != 0xf1)
        return 0xffffffff;
    
    *arg6 = (_byteswap(*(arg1 + 6)) >> 0x10);
    *arg2 = arg1[2];
    *arg3 = arg1[1];
    *arg4 = arg1[4];
    *arg5 = arg1[5];
    return 0;
}

