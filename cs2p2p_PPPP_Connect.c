
int64_t cs2p2p_PPPP_Connect(char* arg1, char arg2, uint16_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int128_t v0;
    v0 = 0;
    *v0[8] = 0;
    int128_t var_138;
    __builtin_memset(&var_138, 0, 0xe0);
    void* x0 = strchr(v0);
    char* x21;
    
    if (x0 == 0)
        x21 = nullptr;
    else
        x21 = (x0 + 1);
    
    int64_t result;
    
    if (arg1 == 0)
        result = 0xfffffffc;
    else
    {
        int128_t s2;
        
        if (strchr(arg1, 0x2e) == 0)
        {
            int64_t x9_2 = 0;
            int32_t x8_2 = 0;
            char x12_2 = 1;
            bool cond:0_1;
            
            do
            {
                uint32_t x13_2 = arg1[x9_2];
                
                if ((x13_2 - 0x30) <= 9)
                {
                    if (x12_2 == 1)
                    {
                        x12_2 = 0;
                        *(&s2 + x8_2) = 0x2d;
                        x8_2 += 1;
                    }
                    
                    *(&s2 + x8_2) = x13_2;
                    x8_2 += 1;
                }
                else if ((x13_2 - 0x61) <= 0x19)
                {
                    if (x12_2 == 0)
                    {
                        *(&s2 + x8_2) = 0x2d;
                        x8_2 += 1;
                        x12_2 = 1;
                    }
                    
                    *(&s2 + x8_2) = (x13_2 + 0xe0);
                    x8_2 += 1;
                }
                else if ((x13_2 - 0x41) <= 0x19)
                {
                    if (x12_2 == 0)
                    {
                        *(&s2 + x8_2) = 0x2d;
                        x8_2 += 1;
                        x12_2 = 1;
                    }
                    
                    *(&s2 + x8_2) = x13_2;
                    x8_2 += 1;
                }
                else if (x13_2 != 0x2d)
                    break;
                
                cond:0_1 = x9_2 < 0x3f;
                x9_2 += 1;
            } while (cond:0_1);
        }
        else
        {
            int128_t var_f8;
            cs2p2p_PPPP__ProbeDID(arg1, &var_f8);
            int64_t x9_1 = 0;
            int32_t x8_1 = 0;
            char x12_1 = 1;
            bool cond:1_1;
            
            do
            {
                uint32_t x13_1 = *(&var_f8 + x9_1);
                
                if ((x13_1 - 0x30) <= 9)
                {
                    if (x12_1 == 1)
                    {
                        x12_1 = 0;
                        *(&s2 + x8_1) = 0x2d;
                        x8_1 += 1;
                    }
                    
                    *(&s2 + x8_1) = x13_1;
                    x8_1 += 1;
                }
                else if ((x13_1 - 0x61) <= 0x19)
                {
                    if (x12_1 == 0)
                    {
                        *(&s2 + x8_1) = 0x2d;
                        x8_1 += 1;
                        x12_1 = 1;
                    }
                    
                    *(&s2 + x8_1) = (x13_1 + 0xe0);
                    x8_1 += 1;
                }
                else if ((x13_1 - 0x41) <= 0x19)
                {
                    if (x12_1 == 0)
                    {
                        *(&s2 + x8_1) = 0x2d;
                        x8_1 += 1;
                        x12_1 = 1;
                    }
                    
                    *(&s2 + x8_1) = x13_1;
                    x8_1 += 1;
                }
                else if (x13_1 != 0x2d)
                    break;
                
                cond:1_1 = x9_1 < 0x3f;
                x9_1 += 1;
            } while (cond:1_1);
        }
        
        uint32_t x11_1 = s2;
        
        if ((x11_1 - 0x41) > 0x19)
            result = 0xfffffffc;
        else
        {
            int64_t x9_3 = 0;
            int32_t x8_4 = 0;
            
            while (true)
            {
                int32_t x12_3 = (x11_1 & 0xff);
                
                if (x12_3 == 0x2d)
                {
                    x8_4 += 1;
                    
                    if (x9_3 > 0x3e)
                        break;
                }
                else
                {
                    if (x12_3 == 0)
                        break;
                    
                    if (((x11_1 - 0x41) >= 0x1a && (x11_1 - 0x30) > 9))
                        break;
                    
                    if (x9_3 > 0x3e)
                        break;
                }
                
                x11_1 = *((&s2 | 1) + x9_3);
                x9_3 += 1;
            }
            
            if (x8_4 != 2)
                result = 0xfffffffc;
            else
            {
                strncpy(&var_138, &s2, 0x40);
                char* x0_6 = strchr(&var_138, 0x2d);
                *x0_6 = 0;
                int128_t s1_1;
                strncpy(&s1_1, &var_138, 0x10);
                char* x0_9 = strchr(&x0_6[1], 0x2d);
                *x0_9 = 0;
                int32_t x0_11 = atoi(&x0_6[1]);
                int128_t s1;
                strncpy(&s1, &x0_9[1], 0x10);
                result = cs2p2p_PPPP_Connect_Do(&s1_1, x0_11, &s1, arg2, arg3, cs2p2p_gServerString, x21);
            }
        }
    }
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

