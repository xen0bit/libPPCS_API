
int64_t cs2p2p_RemoveProfileItem(char* arg1, char* arg2, char* arg3)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    FILE* fp = fopen(arg1, "rt");
    FILE* fp_1 = fopen("/etc/~conf.conf", &data_23a97);
    int64_t result;
    
    if (fp_1 == 0)
        result = 0xffffffff;
    else
    {
        FILE* fp_2;
        
        if (fp == 0)
            fp_2 = fp_1;
        else
        {
            void buf;
            char* s1_1 = fgets(&buf, 0x7ff, fp);
            
            if (s1_1 != 0)
            {
                int32_t x25_1 = 0;
                int32_t var_106c_1 = 0;
                
                while (true)
                {
                    if (x25_1 == 0)
                    {
                        void str;
                        strcpy(&str, s1_1);
                        
                        while (true)
                        {
                            uint32_t x8_12 = *s1_1;
                            
                            if ((x8_12 != 0x20 && x8_12 != 9))
                                break;
                            
                            s1_1 = &s1_1[1];
                        }
                        
                        size_t x0_22 = strlen(s1_1);
                        
                        if (x0_22 >= 1)
                        {
                            x0_22 = x0_22;
                            
                            do
                            {
                                uint64_t x8_14 = s1_1[(x0_22 - 1)];
                                
                                if (x8_14 > 0x20)
                                    break;
                                
                                if (((1 << x8_14) & 0x100002600) == 0)
                                    break;
                                
                                x0_22 -= 1;
                            } while ((x0_22 + 1) > 1);
                        }
                        
                        s1_1[x0_22] = 0;
                        size_t x0_24 = strlen(s1_1);
                        uint32_t x8_17;
                        
                        if (x0_24 > 2)
                            x8_17 = *s1_1;
                        
                        if ((x0_24 <= 2 || x8_17 == 0x23))
                            fputs(&str, fp_1);
                        else if ((x8_17 != 0x5b || s1_1[(x0_24 - 1)] != 0x5d))
                        {
                            if (var_106c_1 != 0)
                                goto label_b254;
                            
                        label_b37c:
                            fputs(&str, fp_1);
                            var_106c_1 = 0;
                            x25_1 = 0;
                        }
                        else if (var_106c_1 == 0)
                        {
                            char* s1 = &s1_1[1];
                            *(strlen(s1) + s1_1) = 0;
                            
                            while (true)
                            {
                                uint32_t x8_10 = *s1;
                                
                                if ((x8_10 != 0x20 && x8_10 != 9))
                                    break;
                                
                                s1 = &s1[1];
                                s1_1 = &s1_1[1];
                            }
                            
                            int32_t x0_15 = strlen(s1);
                            
                            if (x0_15 >= 1)
                            {
                                int64_t x8_11 = x0_15;
                                void* x9_1 = &s1_1[x8_11];
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
                                
                                x0_15 = (i - 1);
                            }
                            
                            s1[x0_15] = 0;
                            
                            if (strcasecmp(s1, arg2) != 0)
                                goto label_b37c;
                            
                            s1_1 = s1;
                            var_106c_1 = 1;
                        label_b254:
                            char* x0_6 = strchr(s1_1, 0x3d);
                            int32_t x0_10;
                            
                            if (x0_6 != 0)
                            {
                                *x0_6 = 0;
                                
                                while (true)
                                {
                                    uint32_t x8_5 = *s1_1;
                                    
                                    if ((x8_5 != 0x20 && x8_5 != 9))
                                        break;
                                    
                                    s1_1 = &s1_1[1];
                                }
                                
                                size_t x0_8 = strlen(s1_1);
                                
                                if (x0_8 >= 1)
                                {
                                    x0_8 = x0_8;
                                    
                                    do
                                    {
                                        uint64_t x8_7 = s1_1[(x0_8 - 1)];
                                        
                                        if (x8_7 > 0x20)
                                            break;
                                        
                                        if (((1 << x8_7) & 0x100002600) == 0)
                                            break;
                                        
                                        x0_8 -= 1;
                                    } while ((x0_8 + 1) > 1);
                                }
                                
                                s1_1[x0_8] = 0;
                                x0_10 = strcasecmp(s1_1, arg3);
                            }
                            
                            if ((x0_6 != 0 && x0_10 == 0))
                                x25_1 = 1;
                            else
                            {
                                fputs(&str, fp_1);
                                x25_1 = 0;
                            }
                        }
                        else
                        {
                            fputs(&str, fp_1);
                            s1_1 = fgets(&buf, 0x7ff, fp);
                            x25_1 = 1;
                            
                            if (s1_1 == 0)
                                break;
                            
                            continue;
                        }
                    }
                    else
                        fputs(s1_1, fp_1);
                    
                    s1_1 = fgets(&buf, 0x7ff, fp);
                    
                    if (s1_1 == 0)
                        break;
                }
            }
            
            fclose(fp_1);
            fp_2 = fp;
        }
        
        fclose(fp_2);
        rename("/etc/~conf.conf", arg1);
        result = 0;
    }
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

