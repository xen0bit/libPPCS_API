
int64_t PPCS_Listen(void* arg1, uint32_t arg2, uint16_t arg3, char arg4, char* arg5)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int128_t v0;
    v0 = 0;
    *v0[8] = 0;
    int128_t var_108;
    __builtin_memset(&var_108, 0, 0xa0);
    void* x0 = strchr(v0);
    char* x23;
    
    if (x0 == 0)
        x23 = nullptr;
    else
        x23 = (x0 + 1);
    
    int64_t result;
    
    if (arg1 == 0)
        result = 0xfffffffc;
    else if (arg5 == 0)
        result = 0xffffffeb;
    else
    {
        int64_t x9_1 = 0;
        int32_t x8_1 = 0;
        char x12_1 = 1;
        int128_t s2;
        bool cond:0_1;
        
        do
        {
            uint32_t x13_1 = *(arg1 + x9_1);
            
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
            
            cond:0_1 = x9_1 < 0x3f;
            x9_1 += 1;
        } while (cond:0_1);
        uint32_t x11_1 = s2;
        
        if ((x11_1 - 0x41) > 0x19)
            result = 0xfffffffc;
        else
        {
            int64_t x10_1 = 0;
            int32_t x8_3 = 0;
            
            while (true)
            {
                int32_t x12_2 = (x11_1 & 0xff);
                
                if (x12_2 == 0x2d)
                {
                    x8_3 += 1;
                    
                    if (x10_1 > 0x3e)
                        break;
                }
                else
                {
                    if (x12_2 == 0)
                        break;
                    
                    if (((x11_1 - 0x41) >= 0x1a && (x11_1 - 0x30) > 9))
                        break;
                    
                    if (x10_1 > 0x3e)
                        break;
                }
                
                x11_1 = *((&s2 | 1) + x10_1);
                x10_1 += 1;
            }
            
            if (x8_3 != 2)
                result = 0xfffffffc;
            else
            {
                strncpy(&var_108, &s2, 0x40);
                char* x0_3 = strchr(&var_108, 0x2d);
                *x0_3 = 0;
                int128_t s1_1;
                strncpy(&s1_1, &var_108, 0x10);
                char* x0_6 = strchr(&x0_3[1], 0x2d);
                *x0_6 = 0;
                int32_t x0_8 = atoi(&x0_3[1]);
                int128_t s1;
                strncpy(&s1, &x0_6[1], 0x10);
                result = cs2p2p_PPPP_Listen_Do(&s1_1, x0_8, &s1, arg2, arg3, arg4, arg5, x23);
            }
        }
    }
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

