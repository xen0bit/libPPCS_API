
int64_t cs2p2p_WriteProfileItem(char* arg1, char* arg2, char* arg3, char* arg4, int64_t arg5, int128_t arg6 @ v0, int128_t arg7 @ v1, int128_t arg8 @ v2, int128_t arg9 @ v3, int128_t arg10 @ v4, int128_t arg11 @ v5, int128_t arg12 @ v6, int128_t arg13 @ v7)

{
    int128_t var_19d0 = arg12;
    int128_t var_19c0 = arg13;
    int128_t var_19f0 = arg10;
    int128_t var_19e0 = arg11;
    int128_t var_1a10 = arg8;
    int128_t var_1a00 = arg9;
    int128_t var_1a30 = arg6;
    int128_t var_1a20 = arg7;
    int64_t x6;
    int64_t var_19a0 = x6;
    int64_t x7;
    int64_t var_1998 = x7;
    int64_t var_19b0 = arg5;
    int64_t x5;
    int64_t var_19a8 = x5;
    int0_t tpidr_el0;
    uint64_t x27 = _ReadStatusReg(tpidr_el0);
    int64_t x9 = *(x27 + 0x28);
    int32_t var_104c = 0xffffff80;
    int32_t var_1050 = 0xffffffe0;
    int128_t var_1990;
    int128_t* var_1060 = &var_1990;
    void* buf = &arg_0;
    int64_t filename;
    int64_t* x23 = &filename;
    char string = 0;
    var_1990 = buf;
    int128_t var_1980 = &var_19b0;
    vsnprintf(&string, 0x800, arg4);
    FILE* fp = fopen(arg1, "rt");
    memcpy(&filename, arg1, (strlen(arg1) + 1));
    int64_t* x8_1 = nullptr;
    int64_t* x9_1 = &filename;
    uint32_t i;
    
    do
    {
        i = *x9_1;
        x9_1 += 1;
        
        if (i == 0x2f)
            x8_1 = x23;
        
        x23 = x9_1;
    } while (i != 0);
    
    if (x8_1 == 0)
        __builtin_strncpy(&filename, "~conf.conf", 0xb);
    else
        __builtin_strncpy((x8_1 + 1), "~conf.conf", 0xb);
    
    FILE* x0_6 = fopen(&filename, &data_23a97);
    int64_t result;
    
    if (x0_6 == 0)
        result = 0xffffffff;
    else
    {
        if (fp == 0)
        {
            fprintf(x0_6, "[%s]\n", arg2);
            fprintf(x0_6, "%s=%s\n", arg3, &string);
        }
        else
        {
            char* s1_1 = fgets(&buf, 0x7ff, fp);
            
            if (s1_1 == 0)
            {
                fprintf(x0_6, "[%s]\n", arg2);
                fprintf(x0_6, "%s=%s\n", arg3, &string);
            }
            else
            {
                int32_t x26_1 = 0;
                int32_t var_1a3c_1 = 0;
                
                while (true)
                {
                    if (x26_1 == 0)
                    {
                        void str;
                        strcpy(&str, s1_1);
                        
                        while (true)
                        {
                            uint32_t x8_13 = *s1_1;
                            
                            if ((x8_13 != 0x20 && x8_13 != 9))
                                break;
                            
                            s1_1 = &s1_1[1];
                        }
                        
                        size_t x0_31 = strlen(s1_1);
                        
                        if (x0_31 >= 1)
                        {
                            x0_31 = x0_31;
                            
                            do
                            {
                                uint64_t x8_15 = s1_1[(x0_31 - 1)];
                                
                                if (x8_15 > 0x20)
                                    break;
                                
                                if (((1 << x8_15) & 0x100002600) == 0)
                                    break;
                                
                                x0_31 -= 1;
                            } while ((x0_31 + 1) > 1);
                        }
                        
                        s1_1[x0_31] = 0;
                        size_t x0_33 = strlen(s1_1);
                        uint32_t x8_18;
                        
                        if (x0_33 > 2)
                            x8_18 = *s1_1;
                        
                        if ((x0_33 <= 2 || x8_18 == 0x23))
                            fputs(&str, x0_6);
                        else if ((x8_18 != 0x5b || s1_1[(x0_33 - 1)] != 0x5d))
                        {
                            if (var_1a3c_1 != 0)
                                goto label_ae98;
                            
                        label_afdc:
                            fputs(&str, x0_6);
                            var_1a3c_1 = 0;
                            x26_1 = 0;
                        }
                        else if (var_1a3c_1 == 0)
                        {
                            char* s1 = &s1_1[1];
                            *(strlen(s1) + s1_1) = 0;
                            
                            while (true)
                            {
                                uint32_t x8_11 = *s1;
                                
                                if ((x8_11 != 0x20 && x8_11 != 9))
                                    break;
                                
                                s1 = &s1[1];
                                s1_1 = &s1_1[1];
                            }
                            
                            int32_t x0_24 = strlen(s1);
                            
                            if (x0_24 >= 1)
                            {
                                int64_t x8_12 = x0_24;
                                void* x9_2 = &s1_1[x8_12];
                                int64_t i_1 = (x8_12 + 1);
                                
                                do
                                {
                                    uint64_t x10_1 = *x9_2;
                                    
                                    if (x10_1 > 0x20)
                                        break;
                                    
                                    if (((1 << x10_1) & 0x100002600) == 0)
                                        break;
                                    
                                    i_1 -= 1;
                                    x9_2 -= 1;
                                } while (i_1 > 1);
                                
                                x0_24 = (i_1 - 1);
                            }
                            
                            s1[x0_24] = 0;
                            
                            if (strcasecmp(s1, arg2) != 0)
                                goto label_afdc;
                            
                            s1_1 = s1;
                            var_1a3c_1 = 1;
                        label_ae98:
                            char* x0_14 = strchr(s1_1, 0x3d);
                            int32_t x0_18;
                            
                            if (x0_14 != 0)
                            {
                                *x0_14 = 0;
                                
                                while (true)
                                {
                                    uint32_t x8_6 = *s1_1;
                                    
                                    if ((x8_6 != 0x20 && x8_6 != 9))
                                        break;
                                    
                                    s1_1 = &s1_1[1];
                                }
                                
                                size_t x0_16 = strlen(s1_1);
                                
                                if (x0_16 >= 1)
                                {
                                    x0_16 = x0_16;
                                    
                                    do
                                    {
                                        uint64_t x8_8 = s1_1[(x0_16 - 1)];
                                        
                                        if (x8_8 > 0x20)
                                            break;
                                        
                                        if (((1 << x8_8) & 0x100002600) == 0)
                                            break;
                                        
                                        x0_16 -= 1;
                                    } while ((x0_16 + 1) > 1);
                                }
                                
                                s1_1[x0_16] = 0;
                                x0_18 = strcasecmp(s1_1, arg3);
                            }
                            
                            if ((x0_14 != 0 && x0_18 == 0))
                            {
                                fprintf(x0_6, "%s=%s\n", arg3, &string);
                                x26_1 = 1;
                            }
                            else
                            {
                                fputs(&str, x0_6);
                                x26_1 = 0;
                            }
                        }
                        else
                        {
                            fprintf(x0_6, "%s=%s\n", arg3, &string);
                            fputs(&str, x0_6);
                            s1_1 = fgets(&buf, 0x7ff, fp);
                            x26_1 = 1;
                            
                            if (s1_1 == 0)
                                goto label_b0f4;
                            
                            continue;
                        }
                    }
                    else
                        fputs(s1_1, x0_6);
                    
                    s1_1 = fgets(&buf, 0x7ff, fp);
                    
                    if (s1_1 == 0)
                        break;
                }
                
                if (x26_1 == 0)
                {
                    if (var_1a3c_1 != 0)
                        fprintf(x0_6, "%s=%s\n", arg3, &string);
                    else
                    {
                        fprintf(x0_6, "[%s]\n", arg2);
                        fprintf(x0_6, "%s=%s\n", arg3, &string);
                    }
                }
            }
        }
        
    label_b0f4:
        fclose(x0_6);
        
        if (fp != 0)
            fclose(fp);
        
        rename(&filename, arg1);
        result = 0;
    }
    
    if (*(x27 + 0x28) == x9)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

