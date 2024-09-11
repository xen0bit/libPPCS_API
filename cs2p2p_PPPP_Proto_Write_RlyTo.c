
void cs2p2p_PPPP_Proto_Write_RlyTo(int64_t* arg1, int16_t* arg2, int32_t arg3)

{
    arg1[2] = _byteswap(arg3);
    *arg1 = 0;
    arg1[1] = 0;
    *arg1 = (_byteswap(*arg2) >> 0x10);
    *(arg1 + 2) = (_byteswap(arg2[1]) >> 0x10);
    *(arg1 + 4) = _byteswap(*(arg2 + 4));
}

