
uint64_t cs2__AddrIsTheSame(int16_t* arg1, int16_t* arg2)

{
    uint32_t x8_16 = *arg1;
    
    if ((x8_16 == *arg2 && arg1[1] == arg2[1]))
    {
        if (x8_16 == 0xa)
        {
            if ((arg1[4] == arg2[4] && (*(arg1 + 9) == *(arg2 + 9) && (arg1[5] == arg2[5] && (*(arg1 + 0xb) == *(arg2 + 0xb) && (arg1[6] == arg2[6] && (*(arg1 + 0xd) == *(arg2 + 0xd) && (arg1[7] == arg2[7] && (*(arg1 + 0xf) == *(arg2 + 0xf) && (arg1[8] == arg2[8] && (*(arg1 + 0x11) == *(arg2 + 0x11) && (arg1[9] == arg2[9] && (*(arg1 + 0x13) == *(arg2 + 0x13) && (arg1[0xa] == arg2[0xa] && (*(arg1 + 0x15) == *(arg2 + 0x15) && arg1[0xb] == arg2[0xb])))))))))))))))
                return ((*(arg1 + 0x17) == *(arg2 + 0x17)) ? 1 : 0);
        }
        else if (x8_16 == 2)
            return ((*(arg1 + 4) == *(arg2 + 4)) ? 1 : 0);
    }
    
    return 0;
}

