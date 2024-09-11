
int64_t cs2p2p_GetProfileItem(char* arg1, char* arg2, char* arg3, char* arg4, int64_t arg5, int128_t arg6 @ v0, int128_t arg7 @ v1, int128_t arg8 @ v2, int128_t arg9 @ v3, int128_t arg10 @ v4, int128_t arg11 @ v5, int128_t arg12 @ v6, int128_t arg13 @ v7)

{
    int128_t var_8f0 = arg12;
    int128_t var_8e0 = arg13;
    int128_t var_910 = arg10;
    int128_t var_900 = arg11;
    int128_t var_930 = arg8;
    int128_t var_920 = arg9;
    int128_t var_950 = arg6;
    int128_t var_940 = arg7;
    int64_t x6;
    int64_t var_8c0 = x6;
    int64_t x7;
    int64_t var_8b8 = x7;
    int64_t var_8d0 = arg5;
    int64_t x5;
    int64_t var_8c8 = x5;
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x25 + 0x28);
    FILE* fp = fopen(arg1, "rt");
    int64_t result;
    
    if (fp == 0)
        result = 0xffffffff;
    else
    {
        void buf;
        char* s1 = fgets(&buf, 0x7ff, fp);
        
        if (s1 == 0)
        {
        label_a804:
            fclose(fp);
            result = 0;
        }
        else
        {
            int32_t x26_1 = 0;
            
            while (true)
            {
                uint32_t x8_1 = *s1;
                
                if ((x8_1 != 0x20 && x8_1 != 9))
                {
                    size_t x0_3 = strlen(s1);
                    
                    if (x0_3 >= 1)
                    {
                        x0_3 = x0_3;
                        
                        do
                        {
                            uint64_t x8_3 = s1[(x0_3 - 1)];
                            
                            if (x8_3 > 0x20)
                                break;
                            
                            if (((1 << x8_3) & 0x100002600) == 0)
                                break;
                            
                            x0_3 -= 1;
                        } while ((x0_3 + 1) > 1);
                    }
                    
                    s1[x0_3] = 0;
                    size_t x0_5 = strlen(s1);
                    
                    if (x0_5 > 2)
                    {
                        uint32_t x8_6 = *s1;
                        
                        if (x8_6 != 0x23)
                        {
                            if ((x8_6 == 0x5b && s1[(x0_5 - 1)] == 0x5d))
                            {
                                void* s1_1 = &s1[1];
                                *((s1_1 + strlen(s1_1)) - 1) = 0;
                                
                                while (true)
                                {
                                    uint32_t x8_10 = *s1_1;
                                    
                                    if ((x8_10 != 0x20 && x8_10 != 9))
                                        break;
                                    
                                    s1_1 += 1;
                                    s1 = &s1[1];
                                }
                                
                                int32_t x0_11 = strlen(s1_1);
                                
                                if (x0_11 >= 1)
                                {
                                    int64_t x8_11 = x0_11;
                                    void* x9_1 = &s1[x8_11];
                                    int64_t i = (x8_11 + 1);
                                    
                                    do
                                    {
                                        uint64_t x10_1 = *x9_1;
                                        
                                        if (x10_1 > 0x20)
                                            break;
                                        
                                        if (((1 << x10_1) & 0x100002600) == 0)
                                            break;
                                        
                                        i -= 1;
                                        x9_1 -= 1;
                                    } while (i > 1);
                                    
                                    x0_11 = (i - 1);
                                }
                                
                                *(s1_1 + x0_11) = 0;
                                x26_1 = 0;
                                
                                if (strcasecmp(s1_1, arg2) == 0)
                                {
                                    x26_1 = 1;
                                    s1 = s1_1;
                                label_a774:
                                    char* x0_15 = strchr(s1, 0x3d);
                                    
                                    if (x0_15 != 0)
                                    {
                                        *x0_15 = 0;
                                        
                                        while (true)
                                        {
                                            uint32_t x8_12 = *s1;
                                            
                                            if ((x8_12 != 0x20 && x8_12 != 9))
                                                break;
                                            
                                            s1 = &s1[1];
                                        }
                                        
                                        size_t x0_17 = strlen(s1);
                                        
                                        if (x0_17 >= 1)
                                        {
                                            x0_17 = x0_17;
                                            
                                            do
                                            {
                                                uint64_t x8_14 = s1[(x0_17 - 1)];
                                                
                                                if (x8_14 > 0x20)
                                                    break;
                                                
                                                if (((1 << x8_14) & 0x100002600) == 0)
                                                    break;
                                                
                                                x0_17 -= 1;
                                            } while ((x0_17 + 1) > 1);
                                        }
                                        
                                        s1[x0_17] = 0;
                                        
                                        if (strcasecmp(s1, arg3) == 0)
                                        {
                                            void* string = &x0_15[1];
                                            
                                            while (true)
                                            {
                                                uint32_t x8_18 = *string;
                                                
                                                if ((x8_18 != 0x20 && x8_18 != 9))
                                                    break;
                                                
                                                string += 1;
                                            }
                                            
                                            size_t i_2 = strlen(string);
                                            
                                            if (i_2 >= 1)
                                            {
                                                i_2 = i_2;
                                                size_t i_1;
                                                
                                                do
                                                {
                                                    uint64_t x10_4 = *((string + i_2) - 1);
                                                    
                                                    if (x10_4 > 0x20)
                                                        break;
                                                    
                                                    if (((1 << x10_4) & 0x100002600) == 0)
                                                        break;
                                                    
                                                    i_1 = i_2;
                                                    i_2 -= 1;
                                                } while (i_1 > 1);
                                            }
                                            
                                            *(string + i_2) = 0;
                                            int128_t v0;
                                            int128_t v1;
                                            v0 = fclose(fp);
                                            int32_t var_86c_1 = 0xffffff80;
                                            int32_t var_870_1 = 0xffffffe0;
                                            int128_t var_8b0;
                                            int128_t* var_880_1 = &var_8b0;
                                            var_8b0 = &arg_0;
                                            int128_t var_8a0_1 = &var_8d0;
                                            result = vsscanf(string, arg4);
                                            break;
                                        }
                                    }
                                }
                            }
                            else if (x26_1 != 0)
                                goto label_a774;
                        }
                    }
                    
                    s1 = fgets(&buf, 0x7ff, fp);
                    
                    if (s1 == 0)
                        goto label_a804;
                    
                    continue;
                }
                
                s1 = &s1[1];
            }
        }
    }
    
    if (*(x25 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

