
void cs2p2p_PPPP_Proto_Write_MGMRemoteManagement(char* arg1, char arg2, char arg3, char arg4, char arg5, int32_t arg6)

{
    int32_t temp0 = _byteswap(arg6);
    *arg1 = 0xf1;
    arg1[2] = arg2;
    arg1[1] = arg3;
    arg1[4] = arg4;
    arg1[5] = arg5;
    *(arg1 + 6) = (temp0 >> 0x10);
}

