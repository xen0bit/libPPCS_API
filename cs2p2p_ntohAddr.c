
void cs2p2p_ntohAddr(int16_t* arg1, int64_t* arg2)

{
    *arg2 = 0;
    arg2[1] = 0;
    *arg2 = (_byteswap(*arg1) >> 0x10);
    *(arg2 + 2) = (_byteswap(arg1[1]) >> 0x10);
    *(arg2 + 4) = _byteswap(*(arg1 + 4));
}

