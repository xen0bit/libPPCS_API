
uint64_t cs2p2p_TryBind(int32_t arg1, int32_t arg2, int128_t* arg3)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    int32_t result_1 = (arg2 & 0xffff);
    int64_t var_78 = 0;
    int64_t var_70 = 0;
    var_78 = 2;
    int64_t var_98 = 0;
    int64_t var_90 = 0;
    int32_t var_80 = 0;
    var_98 = 0xa;
    *var_78[4] = 0;
    int64_t var_88 = 0;
    uint64_t result;
    int128_t v0_1;
    
    if (result_1 == 0)
    {
        int32_t x0;
        int32_t x8_9;
        
        for (int32_t i = 0x3e9; i > 1; )
        {
            x0 = rand();
            uint32_t x9_2 = *cs2p2p_gbUseIPv6;
            uint16_t x8_8 = (_byteswap(((x0 % 0x4e20) + 0x2710)) >> 0x10);  {  // {"ReqPKciP11sockaddr_inPcjS3_S2_"}}
            int64_t* x1_1;
            int64_t x2_1;
            
            if (x9_2 != 1)
            {
                x1_1 = &var_78;
                x2_1 = 0x10;
                *var_78[2] = x8_8;
            }
            else
            {
                *var_98[2] = x8_8;
                x1_1 = &var_98;
                x2_1 = 0x1c;
            }
            
            int32_t x0_2;
            x0_2 = bind(arg1, x1_1, x2_1);
            
            if (x0_2 == 0)
            {
                x8_9 = (i - 1);
                break;
            }
            
            i -= 1;
            x8_9 = (i - 1);
        }
        
        if (x8_9 >= 0)
            result = (((x0 % 0x4e20) + 0x2710) & 0xffff);  {  // {"ReqPKciP11sockaddr_inPcjS3_S2_"}}
        else
            result = 0xffffffff;
    }
    else
    {
        uint16_t x8_2 = (_byteswap(arg2) >> 0x10);
        int64_t* x1;
        int64_t x2;
        
        if (*cs2p2p_gbUseIPv6 != 1)
        {
            x1 = &var_78;
            x2 = 0x10;
            *var_78[2] = x8_2;
        }
        else
        {
            *var_98[2] = x8_2;
            x1 = &var_98;
            x2 = 0x1c;
        }
        
        int32_t x0_4;
        x0_4 = bind(arg1, x1, x2);
        
        if (x0_4 == 0)
            result = result_1;
        else
            result = 0xffffffff;
    }
    
    if (*cs2p2p_gbUseIPv6 == 1)
        *var_78[2] = *var_98[2];
    
    *arg3 = var_78;
    
    if (*(x21 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

