
int64_t cs2p2p_PPPP_Proto_Read_TCPHeader(int16_t* arg1, char* arg2, char* arg3, uint16_t* arg4)

{
    if (arg1[1] != 0x68)
        return 0xffffffff;
    
    *arg2 = arg1[2];
    arg2[1] = *(arg1 + 5);
    *arg3 = arg1[3];
    arg3[1] = *(arg1 + 7);
    *arg4 = (_byteswap(*arg1) >> 0x10);
    return 0;
}

