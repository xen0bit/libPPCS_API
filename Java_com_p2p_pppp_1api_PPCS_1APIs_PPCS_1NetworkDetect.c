
int64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1NetworkDetect(int64_t* arg1, int64_t arg2, int64_t arg3, int32_t arg4)

{
    int0_t tpidr_el0;
    uint64_t x28 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x28 + 0x28);
    int64_t result;
    
    if (arg3 == 0)
        result = 0xffffec78;
    else
    {
        int128_t v0;
        v0 = 0;
        *v0[8] = 0;
        int128_t s;
        __builtin_memset(&s, 0, 0x24);
        result = cs2p2p_PPPP_NetworkDetect(&s, arg4, v0);
        
        if (result == 0)
        {
            int64_t x0_2 = *(*arg1 + 0xf8)(arg1, arg3);
            
            if (x0_2 == 0)
                result = 0xffffec78;
            else
            {
                int64_t x0_4 = *(*arg1 + 0x2f0)(arg1, x0_2, "bFlagInternet", &data_241ee);
                int64_t x0_6 = *(*arg1 + 0x2f0)(arg1, x0_2, "bFlagHostResolved", &data_241ee);
                int64_t x0_8 = *(*arg1 + 0x2f0)(arg1, x0_2, "bFlagServerHello", &data_241ee);
                int64_t x0_10 = *(*arg1 + 0x2f0)(arg1, x0_2, "NAT_Type", &data_241ee);
                int64_t x0_12 = *(*arg1 + 0x2f0)(arg1, x0_2, "MyLanIP", &data_241ed);
                int64_t x0_14 = *(*arg1 + 0x2f0)(arg1, x0_2, "MyWanIP", &data_241ed);
                *(*arg1 + 0x350)(arg1, arg3, x0_4, s);
                *(*arg1 + 0x350)(arg1, arg3, x0_6, *s[1]);
                *(*arg1 + 0x350)(arg1, arg3, x0_8, *s[2]);
                *(*arg1 + 0x350)(arg1, arg3, x0_10, *s[3]);
                int64_t x0_20 = *(*arg1 + 0x2f8)(arg1, arg3, x0_12);
                
                if (x0_20 != 0)
                {
                    int32_t x0_22 = *(*arg1 + 0x558)(arg1, x0_20);
                    int64_t x0_24 = *(*arg1 + 0x5c0)(arg1, x0_20, 0);
                    int64_t x8_29 = x0_22;
                    int64_t x2_5;
                    
                    if (x8_29 < 0x10)
                        x2_5 = x8_29;
                    else
                        x2_5 = 0x10;
                    
                    memcpy(x0_24, (&s | 4), x2_5);
                    *(*arg1 + 0x600)(arg1, x0_20, x0_24, 0);
                }
                
                result = *(*arg1 + 0x2f8)(arg1, arg3, x0_14);
                
                if (result != 0)
                {
                    int32_t x0_28 = *(*arg1 + 0x558)(arg1, result);
                    int64_t x0_30 = *(*arg1 + 0x5c0)(arg1, result, 0);
                    int64_t x8_38 = x0_28;
                    int64_t x2_8;
                    
                    if (x8_38 < 0x10)
                        x2_8 = x8_38;
                    else
                        x2_8 = 0x10;
                    
                    int128_t var_80;
                    memcpy(x0_30, &*var_80[4], x2_8);
                    *(*arg1 + 0x600)(arg1, result, x0_30, 0);
                    result = 0;
                }
            }
        }
    }
    
    if (*(x28 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

