
int64_t cs2p2p_PPPP_DecodeString(int64_t arg1, char* arg2, int32_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    void var_868;
    memset(&var_868, 0, 0x800);
    strcpy(&var_868, arg1);
    char* x0_3 = strchr(&var_868, 0x3a);
    
    if (x0_3 != 0)
        *x0_3 = 0;
    
    int64_t result;
    
    if (strlen(&var_868) < 2)
    {
    label_b614:
        result = 0;
    }
    else
    {
        int64_t x23_1 = 0;
        
        while (true)
        {
            int32_t x10_1 = 0x39;
            
            if (x23_1 != 0)
            {
                int64_t x9_3;
                
                if (x23_1 != 1)
                {
                    int32_t x10_2 = 0;
                    int64_t i_1 = (x23_1 & 0xfffffffffffffffe);
                    x9_3 = (x23_1 & 0xfffffffffffffffe);
                    int32_t x12_1 = 0x39;
                    void* x13_1 = &arg2[1];
                    int64_t i;
                    
                    do
                    {
                        uint32_t x14_1 = *(x13_1 - 1);
                        uint32_t x15_1 = *x13_1;
                        x13_1 += 2;
                        i = i_1;
                        i_1 -= 2;
                        x12_1 ^= x14_1;
                        x10_2 ^= x15_1;
                    } while (i != 2);
                    x10_1 = (x10_2 ^ x12_1);
                    
                    if (x23_1 != x9_3)
                        goto label_b5c8;
                }
                else
                {
                    x9_3 = 0;
                label_b5c8:
                    
                    do
                    {
                        uint32_t x11_1 = arg2[x9_3];
                        x9_3 += 1;
                        x10_1 ^= x11_1;
                    } while (x23_1 != x9_3);
                }
            }
            
            char x8_6 = ((x10_1 ^ ((*(&var_868 + (1 | ((0x7fffffffffffffff & x23_1) << 1))) + (*(&var_868 + (x23_1 << 1)) << 4)) - 0x51)) ^ data_238e3[(x23_1 - (((((x23_1 >> 1) & 0x7fffffff) * 0x4bda12f7) >> 0x23) * 0x36))]);
            arg2[x23_1] = x8_6;
            x23_1 += 1;
            
            if (x23_1 >= arg3)
            {
                result = 0xffffffff;
                break;
            }
            
            int32_t x0_7 = strlen(&var_868);
            int32_t x8_7;
            
            if (x0_7 < 0)
                x8_7 = (x0_7 + 1);
            else
                x8_7 = x0_7;
            
            if (x23_1 >= (x8_7 >> 1))
                goto label_b614;
        }
    }
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

