
int64_t PPCS__CheckValidDID(char* arg1)

{
    if (arg1 == 0)
        return 0xffffffff;
    
    uint32_t x11 = *arg1;
    
    if ((x11 - 0x41) > 0x19)
        return 0xffffffff;
    
    int64_t x10 = 0;
    int32_t x8_1 = 0;
    
    while (true)
    {
        int32_t x12_1 = (x11 & 0xff);
        
        if (x12_1 == 0x2d)
        {
            x8_1 += 1;
            
            if (x10 > 0x3e)
                break;
        }
        else
        {
            if (x12_1 == 0)
                break;
            
            if (((x11 - 0x41) >= 0x1a && (x11 - 0x30) > 9))
                break;
            
            if (x10 > 0x3e)
                break;
        }
        
        x11 = arg1[(1 + x10)];
        x10 += 1;
    }
    
    if (x8_1 != 2)
        return 0xffffffff;
    
    return 0;
}

