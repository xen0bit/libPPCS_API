
int128_t ntohAddrCS2(void* arg1, int16_t* arg2)

{
    __builtin_memset(arg2, 0, 0x18);
    arg2[1] = (_byteswap(*(arg1 + 2)) >> 0x10);
    *(arg2 + 4) = _byteswap(*(arg1 + 4));
    int128_t result = *(arg1 + 8);
    *(arg2 + 8) = result;
    int16_t x8_6;
    
    if (*(arg1 + 4) == 0)
        x8_6 = 0xa;
    else
        x8_6 = 2;
    
    *arg2 = x8_6;
    return result;
}

