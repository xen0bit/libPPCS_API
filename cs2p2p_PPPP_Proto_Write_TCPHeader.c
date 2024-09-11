
void cs2p2p_PPPP_Proto_Write_TCPHeader(uint16_t* arg1, char* arg2, char* arg3, int32_t arg4)

{
    char x8_3 = *arg2;
    uint16_t x10_1 = (_byteswap(arg4) >> 0x10);
    arg1[2] = x8_3;
    *(arg1 + 5) = arg2[1];
    arg1[3] = *arg3;
    char x8_2 = arg3[1];
    arg1[1] = 0x68;
    *arg1 = x10_1;
    *(arg1 + 7) = x8_2;
}

