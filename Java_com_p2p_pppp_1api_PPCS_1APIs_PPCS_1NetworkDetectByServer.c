
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1NetworkDetectByServer(int64_t* arg1, int64_t arg2, int64_t arg3, int32_t arg4, int64_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x28 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x28 + 0x28);
    int32_t x22 = -0x1388;
    
    if ((arg3 != 0 && arg5 != 0))
    {
        int128_t v0;
        v0 = 0;
        *v0[8] = 0;
        int128_t s;
        __builtin_memset(&s, 0, 0x24);
        int64_t x0_1 = *(*arg1 + 0x548)(arg1, arg5, 0, v0);
        
        if (x0_1 == 0)
            x22 = -0x1388;
        else
        {
            x22 = cs2p2p_PPPP_NetworkDetectByServer(&s, arg4, x0_1);
            *(*arg1 + 0x550)(arg1, arg5, x0_1);
            
            if (x22 == 0)
            {
                int64_t x0_6 = *(*arg1 + 0xf8)(arg1, arg3);
                
                if (x0_6 == 0)
                    x22 = -0x1388;
                else
                {
                    int64_t x0_8 = *(*arg1 + 0x2f0)(arg1, x0_6, "bFlagInternet", &data_241ee);
                    int64_t x0_10 = *(*arg1 + 0x2f0)(arg1, x0_6, "bFlagHostResolved", &data_241ee);
                    int64_t x0_12 = *(*arg1 + 0x2f0)(arg1, x0_6, "bFlagServerHello", &data_241ee);
                    int64_t x0_14 = *(*arg1 + 0x2f0)(arg1, x0_6, "NAT_Type", &data_241ee);
                    int64_t x0_16 = *(*arg1 + 0x2f0)(arg1, x0_6, "MyLanIP", &data_241ed);
                    int64_t x0_18 = *(*arg1 + 0x2f0)(arg1, x0_6, "MyWanIP", &data_241ed);
                    *(*arg1 + 0x350)(arg1, arg3, x0_8, s);
                    *(*arg1 + 0x350)(arg1, arg3, x0_10, *s[1]);
                    *(*arg1 + 0x350)(arg1, arg3, x0_12, *s[2]);
                    *(*arg1 + 0x350)(arg1, arg3, x0_14, *s[3]);
                    int64_t x0_24 = *(*arg1 + 0x2f8)(arg1, arg3, x0_16);
                    
                    if (x0_24 != 0)
                    {
                        int32_t x0_26 = *(*arg1 + 0x558)(arg1, x0_24);
                        int64_t x0_28 = *(*arg1 + 0x5c0)(arg1, x0_24, 0);
                        int64_t x8_33 = x0_26;
                        int64_t x2_7;
                        
                        if (x8_33 < 0x10)
                            x2_7 = x8_33;
                        else
                            x2_7 = 0x10;
                        
                        memcpy(x0_28, (&s | 4), x2_7);
                        *(*arg1 + 0x600)(arg1, x0_24, x0_28, 0);
                    }
                    
                    int64_t x0_31 = *(*arg1 + 0x2f8)(arg1, arg3, x0_18);
                    
                    if (x0_31 != 0)
                    {
                        int32_t x0_33 = *(*arg1 + 0x558)(arg1, x0_31);
                        int64_t x0_35 = *(*arg1 + 0x5c0)(arg1, x0_31, 0);
                        int64_t x8_42 = x0_33;
                        int64_t x2_10;
                        
                        if (x8_42 < 0x10)
                            x2_10 = x8_42;
                        else
                            x2_10 = 0x10;
                        
                        int128_t var_80;
                        memcpy(x0_35, &*var_80[4], x2_10);
                        *(*arg1 + 0x600)(arg1, x0_31, x0_35, 0);
                    }
                    
                    x22 = 0;
                }
            }
        }
    }
    
    if (*(x28 + 0x28) == x8)
        return x22;
    
    __stack_chk_fail();
    /* no return */
}

