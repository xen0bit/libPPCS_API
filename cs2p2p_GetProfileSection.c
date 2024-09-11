
uint64_t cs2p2p_GetProfileSection(char* arg1, char* arg2, int64_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x27 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x27 + 0x28);
    FILE* fp = fopen(arg1, "rt");
    int32_t x22;
    
    if (fp == 0)
        x22 = -1;
    else
    {
        x22 = 0;
        void buf;
        char* x24_1 = fgets(&buf, 0x7ff, fp);
        
        if (x24_1 != 0)
        {
            int32_t var_c6c_1 = 0;
            int32_t x19_1 = 0;
            
            while (true)
            {
                uint32_t x8_1 = *x24_1;
                
                if ((x8_1 != 0x20 && x8_1 != 9))
                {
                    size_t x0_5 = strlen(x24_1);
                    
                    if (x0_5 >= 1)
                    {
                        x0_5 = x0_5;
                        
                        do
                        {
                            uint64_t x8_3 = x24_1[(x0_5 - 1)];
                            
                            if (x8_3 > 0x20)
                                break;
                            
                            if (((1 << x8_3) & 0x100002600) == 0)
                                break;
                            
                            x0_5 -= 1;
                        } while ((x0_5 + 1) > 1);
                    }
                    
                    x24_1[x0_5] = 0;
                    size_t x0_7 = strlen(x24_1);
                    
                    if (x0_7 > 2)
                    {
                        uint32_t x8_6 = *x24_1;
                        
                        if (x8_6 != 0x23)
                        {
                            if ((x8_6 == 0x5b && x24_1[(x0_7 - 1)] == 0x5d))
                            {
                                void* s1 = &x24_1[1];
                                *((s1 + strlen(s1)) - 1) = 0;
                                
                                while (true)
                                {
                                    uint32_t x8_17 = *s1;
                                    
                                    if ((x8_17 != 0x20 && x8_17 != 9))
                                        break;
                                    
                                    s1 += 1;
                                    x24_1 = &x24_1[1];
                                }
                                
                                int32_t x0_25 = strlen(s1);
                                
                                if (x0_25 >= 1)
                                {
                                    int64_t x8_18 = x0_25;
                                    void* x9_2 = &x24_1[x8_18];
                                    int64_t i = (x8_18 + 1);
                                    
                                    do
                                    {
                                        uint64_t x10_3 = *x9_2;
                                        
                                        if (x10_3 > 0x20)
                                            break;
                                        
                                        if (((1 << x10_3) & 0x100002600) == 0)
                                            break;
                                        
                                        i -= 1;
                                        x9_2 -= 1;
                                    } while (i > 1);
                                    
                                    x0_25 = (i - 1);
                                }
                                
                                *(s1 + x0_25) = 0;
                                
                                if (strcasecmp(s1, arg2) == 0)
                                {
                                    x24_1 = fgets(&buf, 0x7ff, fp);
                                    x22 = 1;
                                    x19_1 = 1;
                                    
                                    if (x24_1 == 0)
                                        break;
                                    
                                    continue;
                                }
                                else
                                    x19_1 = 0;
                            }
                            else if (x19_1 != 0)
                            {
                                char* x25_1 = strchr(x24_1, 0x3d);
                                
                                if (x25_1 != 0)
                                {
                                    *x25_1 = 0;
                                    
                                    while (true)
                                    {
                                        uint32_t x8_9 = *x24_1;
                                        
                                        if ((x8_9 != 0x20 && x8_9 != 9))
                                            break;
                                        
                                        x24_1 = &x24_1[1];
                                    }
                                    
                                    size_t x0_13 = strlen(x24_1);
                                    
                                    if (x0_13 >= 1)
                                    {
                                        x0_13 = x0_13;
                                        
                                        do
                                        {
                                            uint64_t x8_11 = x24_1[(x0_13 - 1)];
                                            
                                            if (x8_11 > 0x20)
                                                break;
                                            
                                            if (((1 << x8_11) & 0x100002600) == 0)
                                                break;
                                            
                                            x0_13 -= 1;
                                        } while ((x0_13 + 1) > 1);
                                    }
                                    
                                    void* x26_1 = &x25_1[1];
                                    x24_1[x0_13] = 0;
                                    
                                    while (true)
                                    {
                                        uint32_t x8_14 = *x26_1;
                                        
                                        if ((x8_14 != 0x20 && x8_14 != 9))
                                            break;
                                        
                                        x26_1 += 1;
                                        x25_1 = &x25_1[1];
                                    }
                                    
                                    int32_t x0_15 = strlen(x26_1);
                                    
                                    if (x0_15 >= 1)
                                    {
                                        int64_t x8_15 = x0_15;
                                        void* x9_1 = &x25_1[x8_15];
                                        int64_t i_1 = (x8_15 + 1);
                                        
                                        do
                                        {
                                            uint64_t x10_1 = *x9_1;
                                            
                                            if (x10_1 > 0x20)
                                                break;
                                            
                                            if (((1 << x10_1) & 0x100002600) == 0)
                                                break;
                                            
                                            i_1 -= 1;
                                            x9_1 -= 1;
                                        } while (i_1 > 1);
                                        
                                        x0_15 = (i_1 - 1);
                                    }
                                    
                                    *(x26_1 + x0_15) = 0;
                                    void s;
                                    sprintf(&s, "%s %s %s\n", arg2, x24_1, x26_1);
                                    memcpy((arg3 + var_c6c_1), &s, (strlen(&s) + 1));
                                    var_c6c_1 += strlen(&s);
                                }
                            }
                        }
                    }
                    
                    x24_1 = fgets(&buf, 0x7ff, fp);
                    
                    if (x24_1 == 0)
                        break;
                    
                    continue;
                }
                
                x24_1 = &x24_1[1];
            }
        }
        
        fclose(fp);
    }
    
    if (*(x27 + 0x28) == x8)
        return x22;
    
    __stack_chk_fail();
    /* no return */
}

