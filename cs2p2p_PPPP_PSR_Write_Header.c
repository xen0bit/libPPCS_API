
void cs2p2p_PPPP_PSR_Write_Header(char* arg1, char arg2, int32_t arg3)

{
    int32_t temp0 = _byteswap(arg3);
    *arg1 = 0xd1;
    *(arg1 + 2) = (temp0 >> 0x10);
    arg1[1] = arg2;
}

