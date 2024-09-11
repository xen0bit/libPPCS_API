
uint32_t cs2p2p_IndexDistance(int16_t arg1, int16_t arg2) __pure

{
    uint32_t x8_2 = arg1;
    uint32_t x9 = arg2;
    uint32_t result = (x8_2 - x9);
    
    if (x8_2 != x9)
    {
        if (x8_2 <= arg2)
        {
            result = (x9 - x8_2);
            
            if (result >= 0x8000)
                return ((x8_2 + (x9 ^ 0xffff)) + 1);
        }
        else if (result >= 0x8000)
            return ((x9 + (x8_2 ^ 0xffff)) + 1);
    }
    
    return result;
}

