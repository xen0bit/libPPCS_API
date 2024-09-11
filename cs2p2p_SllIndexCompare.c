
uint64_t cs2p2p_SllIndexCompare(int32_t arg1, int32_t arg2, int32_t arg3) __pure

{
    int32_t result = (arg1 - arg2);
    int32_t x8_1;
    
    if (arg1 <= arg2)
    {
        x8_1 = (arg2 - arg1);
        
        if (x8_1 > (arg3 >> 1))
            return (result + arg3);
    }
    else
    {
        if (result <= (arg3 >> 1))
            return result;
        
        x8_1 = ((arg3 - arg1) + arg2);
    }
    
    return -(x8_1);
}

