
void cs2p2p_SockAddr_4to6Local(void* arg1, int16_t* arg2)

{
    __builtin_memset(&arg2[2], 0, 0x18);
    *arg2 = 0xa;
    int16_t x8 = *(arg1 + 2);
    arg2[9] = 0xffff;
    arg2[1] = x8;
    *(arg2 + 0x14) = *(arg1 + 4);
}

