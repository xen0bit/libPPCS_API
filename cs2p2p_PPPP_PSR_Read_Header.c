
int64_t cs2p2p_PPPP_PSR_Read_Header(char* arg1, char* arg2, uint16_t* arg3)

{
    if (*arg1 != 0xd1)
        return 0xffffffff;
    
    *arg3 = (_byteswap(*(arg1 + 2)) >> 0x10);
    *arg2 = arg1[1];
    return 0;
}

