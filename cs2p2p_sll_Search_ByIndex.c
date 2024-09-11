
int32_t* cs2p2p_sll_Search_ByIndex(int64_t* arg1, int32_t arg2, int32_t* arg3)

{
    int32_t x9_1 = arg1[2];
    
    if (x9_1 != 0)
    {
        int32_t* x10_1 = *arg1;
        int32_t x8_1 = arg1[3];
        int32_t x12_1 = *x10_1;
        int32_t x11_1 = (x12_1 - arg2);
        int32_t x11_2;
        
        if (x12_1 < arg2)
        {
            x11_2 = (arg2 - x12_1);
            
            if (x11_2 > (x8_1 >> 1))
                x11_2 = -((x12_1 + (x8_1 - arg2)));
        }
        else if (x11_1 <= (x8_1 >> 1))
            x11_2 = -(x11_1);
        else
            x11_2 = ((arg2 - x12_1) + x8_1);
        
        int32_t* x12_2 = arg1[1];
        int32_t x14_1 = *x12_2;
        int32_t x13_1 = (x14_1 - arg2);
        int32_t x13_2;
        
        if (x14_1 >= arg2)
        {
            if (x13_1 <= (x8_1 >> 1))
                goto label_13f70;
            
            x13_2 = ((x8_1 + arg2) - x14_1);
            
            if ((x11_2 & 0x80000000) == 0)
            {
            label_13f7c:
                
                if (x13_2 <= 0)
                {
                    if (x13_2 == 0)
                    {
                        if (arg3 == 0)
                            return x12_2;
                        
                        *arg3 = (x9_1 - 1);
                        return x12_2;
                    }
                    
                    if (x11_2 == 0)
                    {
                        if (arg3 == 0)
                            return x10_1;
                        
                        *arg3 = 0;
                        return x10_1;
                    }
                    
                    if ((x13_2 + x11_2) <= 0)
                    {
                        int32_t* i = *(x10_1 + 0x18);
                        
                        if (i != 0)
                        {
                            uint32_t x11_7 = (x8_1 >> 1);
                            int32_t x10_2 = 1;
                            
                            do
                            {
                                int32_t x14_3 = *i;
                                int32_t x13_8 = (x14_3 - arg2);
                                int32_t x13_9;
                                
                                if (x14_3 >= arg2)
                                {
                                    if (x13_8 <= x11_7)
                                        goto label_14078;
                                    
                                    x13_9 = ((arg2 - x14_3) + x8_1);
                                    
                                    if (x13_9 == 0)
                                    {
                                    label_140c0:
                                        
                                        if (arg3 == 0)
                                            return i;
                                        
                                        *arg3 = x10_2;
                                        return i;
                                    }
                                }
                                else
                                {
                                    x13_9 = (arg2 - x14_3);
                                    
                                    if (x13_9 > x11_7)
                                    {
                                        x13_8 = (x14_3 + (x8_1 - arg2));
                                    label_14078:
                                        x13_9 = -(x13_8);
                                    }
                                    
                                    if (x13_9 == 0)
                                        goto label_140c0;
                                }
                                
                                if ((x13_9 & 0x80000000) != 0)
                                    break;
                                
                                i = *(i + 0x18);
                                x10_2 += 1;
                            } while (i != 0);
                        }
                    }
                    else
                    {
                        int32_t* i_1 = *(x12_2 + 0x20);
                        
                        if (i_1 != 0)
                        {
                            uint32_t x11_6 = (x8_1 >> 1);
                            int32_t x9 = (x9_1 - 2);
                            
                            do
                            {
                                int32_t x14_2 = *i_1;
                                int32_t x13_5 = (x14_2 - arg2);
                                int32_t x13_6;
                                
                                if (x14_2 >= arg2)
                                {
                                    if (x13_5 <= x11_6)
                                        goto label_13fe4;
                                    
                                    x13_6 = ((arg2 - x14_2) + x8_1);
                                    
                                    if (x13_6 == 0)
                                    {
                                    label_140b0:
                                        
                                        if (arg3 == 0)
                                            return i_1;
                                        
                                        *arg3 = x9;
                                        return i_1;
                                    }
                                }
                                else
                                {
                                    x13_6 = (arg2 - x14_2);
                                    
                                    if (x13_6 > x11_6)
                                    {
                                        x13_5 = (x14_2 + (x8_1 - arg2));
                                    label_13fe4:
                                        x13_6 = -(x13_5);
                                    }
                                    
                                    if (x13_6 == 0)
                                        goto label_140b0;
                                }
                                
                                if (x13_6 >= 1)
                                    break;
                                
                                i_1 = *(i_1 + 0x20);
                                x9 -= 1;
                            } while (i_1 != 0);
                        }
                    }
                }
            }
        }
        else
        {
            x13_2 = (arg2 - x14_1);
            
            if (x13_2 > (x8_1 >> 1))
            {
                x13_1 = ((x8_1 - arg2) + x14_1);
            label_13f70:
                x13_2 = -(x13_1);
            }
            
            if ((x11_2 & 0x80000000) == 0)
                goto label_13f7c;
        }
    }
    
    return 0;
}

