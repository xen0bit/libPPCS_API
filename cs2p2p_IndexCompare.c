
uint64_t cs2p2p_IndexCompare(int16_t arg1, int16_t arg2) __pure

{
    uint32_t x10 = arg1;
    uint32_t x9 = arg2;
    uint32_t x8 = (x10 - x9);
    
    if (x10 <= x9)
    {
        uint32_t x8_2 = (x9 - x10);
        
        if (x8_2 <= 0x8000)
            x8 = -(x8_2);
        else
            x8 = ((x10 | 0x10000) - x9);
    }
    else if (x8 > 0x8000)
        x8 = -(((0x10000 - x10) + x9));
    
    int32_t x8_4;
    
    if (x8 <= 0)
        x8_4 = -1;
    else
        x8_4 = 1;
    
    if (x8 == 0)
        return 0;
    
    return x8_4;
}

