
int128_t htonAddrCS2(int16_t* arg1, uint16_t* arg2)

{
    __builtin_memset(arg2, 0, 0x18);
    *arg2 = (_byteswap(*arg1) >> 0x10);
    arg2[1] = (_byteswap(arg1[1]) >> 0x10);
    *(arg2 + 4) = _byteswap(*(arg1 + 4));
    int128_t result = *(arg1 + 8);
    *(arg2 + 8) = result;
    return result;
}

