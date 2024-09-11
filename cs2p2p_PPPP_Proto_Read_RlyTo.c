
void cs2p2p_PPPP_Proto_Read_RlyTo(int16_t* arg1, int64_t* arg2, int32_t* arg3)

{
    *arg3 = _byteswap(*(arg1 + 0x10));
    *arg2 = 0;
    arg2[1] = 0;
    *arg2 = (_byteswap(*arg1) >> 0x10);
    *(arg2 + 2) = (_byteswap(arg1[1]) >> 0x10);
    *(arg2 + 4) = _byteswap(*(arg1 + 4));
}

