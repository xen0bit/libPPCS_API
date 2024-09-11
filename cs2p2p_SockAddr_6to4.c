
void cs2p2p_SockAddr_6to4(void* arg1, int16_t* arg2)

{
    *(arg2 + 0xc) = 0;
    *(arg2 + 4) = 0;
    *arg2 = 2;
    arg2[1] = *(arg1 + 2);
    *(arg2 + 4) = *(arg1 + 0x14);
}

