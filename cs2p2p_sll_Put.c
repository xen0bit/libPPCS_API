
int64_t cs2p2p_sll_Put(int64_t* arg1, int32_t* arg2)

{
    int32_t* x21 = *arg1;
    int32_t x8_1;
    
    if (x21 == 0)
    {
        *(arg2 + 0x18) = 0;
        *(arg2 + 0x20) = 0;
        x8_1 = arg1[2];
        *arg1 = arg2;
        arg1[1] = arg2;
    }
    else
    {
        uint64_t x8 = arg1[3];
        int32_t x9_1 = *arg2;
        int32_t x12_1 = *x21;
        int32_t x10_1 = (x9_1 - x12_1);
        uint32_t x11_2 = ((x8 * 0xaaaaaaab) >> 0x21);
        
        if (x9_1 <= x12_1)
        {
            int32_t x10_3 = (x12_1 - x9_1);
            
            if (x10_3 <= (x8 >> 1))
                x10_1 = -(x10_3);
            else
                x10_1 = ((x9_1 + x8) - x12_1);
        }
        else if (x10_1 > (x8 >> 1))
            x10_1 = -(((x8 - x9_1) + x12_1));
        
        int32_t* x22_1 = arg1[1];
        int32_t x13_1 = *x22_1;
        int32_t x12_2 = (x9_1 - x13_1);
        int32_t x12_4;
        
        if (x9_1 > x13_1)
        {
            if (x12_2 > (x8 >> 1))
            {
                x12_4 = ((x8 - x9_1) + x13_1);
            label_13c7c:
                x12_2 = -(x12_4);
            }
            
            if ((x10_1 > x11_2 || x12_2 < -(x11_2)))
                goto label_13cb8;
            
            goto label_13c98;
        }
        
        x12_4 = (x13_1 - x9_1);
        
        if (x12_4 <= (x8 >> 1))
            goto label_13c7c;
        
        x12_2 = ((x9_1 + x8) - x13_1);
        
        if ((x10_1 > x11_2 || x12_2 < -(x11_2)))
        {
        label_13cb8:
            int64_t x0 = *(arg2 + 8);
            
            if (x0 != 0)
                free(x0);
            
            free(arg2);
            return 0xffffffff;
        }
        
    label_13c98:
        
        if ((x10_1 == 0 || x12_2 == 0))
        {
            int64_t x0_3 = *(arg2 + 8);
            
            if (x0_3 != 0)
                free(x0_3);
            
            free(arg2);
            return 0;
        }
        
        if ((x10_1 & 0x80000000) != 0)
        {
            *(arg2 + 0x18) = x21;
            *(arg2 + 0x20) = 0;
            *(x21 + 0x20) = arg2;
            *arg1 = arg2;
        }
        else if (x12_2 >= 1)
        {
            *(arg2 + 0x18) = 0;
            *(arg2 + 0x20) = x22_1;
            *(x22_1 + 0x18) = arg2;
            arg1[1] = arg2;
        }
        else
        {
            int32_t x8_8;
            
            if ((x12_2 + x10_1) <= 0)
            {
                void* x10_10 = &x21[6];
                int32_t* x11_5 = *x10_10;
                
                if (x11_5 != 0)
                {
                    int32_t x9_5;
                    
                    while (true)
                    {
                        int32_t x13_3 = *x11_5;
                        int32_t x12_7 = (x9_1 - x13_3);
                        
                        if (x9_1 <= x13_3)
                        {
                            int32_t x9_6 = (x13_3 - x9_1);
                            
                            if (x9_6 <= (x8 >> 1))
                            {
                                x12_7 = -(x9_6);
                                
                                if (x12_7 == 0)
                                {
                                label_13e74:
                                    int64_t x0_7 = *(arg2 + 8);
                                    
                                    if (x0_7 != 0)
                                        free(x0_7);
                                    
                                    free(arg2);
                                    x8_8 = 1;
                                    x9_5 = 1;
                                    break;
                                    break;
                                }
                            }
                            else
                            {
                                x12_7 += x8;
                                
                                if (x12_7 == 0)
                                    goto label_13e74;
                            }
                        }
                        else
                        {
                            if (x12_7 > (x8 >> 1))
                                x12_7 = -((x13_3 + (x8 - x9_1)));
                            
                            if (x12_7 == 0)
                                goto label_13e74;
                        }
                        
                        if ((x12_7 & 0x80000000) != 0)
                        {
                            *(arg2 + 0x18) = x11_5;
                            *(arg2 + 0x20) = x21;
                            *(*x10_10 + 0x20) = arg2;
                            x8_8 = 3;
                            *x10_10 = arg2;
                            x9_5 = 3;
                            break;
                        }
                        
                        x21 = x11_5;
                        x10_10 = &x21[6];
                        x11_5 = *x10_10;
                        
                        if (x11_5 == 0)
                            goto label_13cfc;
                        
                        x9_1 = *arg2;
                        x8 = arg1[3];
                    }
                    
                    if ((x9_5 != 3 && x8_8 != 0))
                        return 0;
                }
            }
            else
            {
                void* x10_7 = &x22_1[8];
                int32_t* x11_4 = *x10_7;
                
                if (x11_4 != 0)
                {
                    int32_t x9_3;
                    
                    while (true)
                    {
                        int32_t x13_2 = *x11_4;
                        int32_t x12_6 = (x9_1 - x13_2);
                        
                        if (x9_1 <= x13_2)
                        {
                            int32_t x9_4 = (x13_2 - x9_1);
                            
                            if (x9_4 <= (x8 >> 1))
                            {
                                x12_6 = -(x9_4);
                                
                                if (x12_6 == 0)
                                {
                                label_13dbc:
                                    int64_t x0_5 = *(arg2 + 8);
                                    
                                    if (x0_5 != 0)
                                        free(x0_5);
                                    
                                    free(arg2);
                                    x8_8 = 1;
                                    x9_3 = 1;
                                    break;
                                    break;
                                }
                            }
                            else
                            {
                                x12_6 += x8;
                                
                                if (x12_6 == 0)
                                    goto label_13dbc;
                            }
                        }
                        else
                        {
                            if (x12_6 > (x8 >> 1))
                                x12_6 = -((x13_2 + (x8 - x9_1)));
                            
                            if (x12_6 == 0)
                                goto label_13dbc;
                        }
                        
                        if (x12_6 >= 1)
                        {
                            *(arg2 + 0x18) = x22_1;
                            *(arg2 + 0x20) = x11_4;
                            *(*x10_7 + 0x18) = arg2;
                            x8_8 = 5;
                            *x10_7 = arg2;
                            x9_3 = 5;
                            break;
                        }
                        
                        x22_1 = x11_4;
                        x10_7 = &x22_1[8];
                        x11_4 = *x10_7;
                        
                        if (x11_4 == 0)
                            goto label_13cfc;
                        
                        x9_1 = *arg2;
                        x8 = arg1[3];
                    }
                    
                    if ((x9_3 != 5 && x8_8 != 0))
                        return 0;
                }
            }
        }
        
    label_13cfc:
        x8_1 = arg1[2];
    }
    
    arg1[2] = (x8_1 + 1);
    *(arg1 + 0x14) += arg2[1];
    return 1;
}

