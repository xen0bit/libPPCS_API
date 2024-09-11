
int64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1Check(int64_t* arg1, int64_t arg2, int32_t arg3, int64_t arg4)

{
    int0_t tpidr_el0;
    uint64_t x27 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x27 + 0x28);
    int32_t result;
    
    if (arg4 == 0)
        result = -0x1388;
    else
    {
        int32_t var_c0;
        memset(&var_c0, 0, 0x54);
        result = cs2p2p_PPPP_Check(arg3, &var_c0);
        
        if (result == 0)
        {
            int64_t x0_3 = *(*arg1 + 0xf8)(arg1, arg4);
            
            if (x0_3 == 0)
                result = -0x1388;
            else
            {
                int64_t x0_5 = *(*arg1 + 0x2f0)(arg1, x0_3, &data_241f8, &data_241fc);
                int64_t x0_7 = *(*arg1 + 0x2f0)(arg1, x0_3, "RemoteIP", &data_241ed);
                int64_t x0_9 = *(*arg1 + 0x2f0)(arg1, x0_3, "RemotePort", &data_241fc);
                int64_t x0_11 = *(*arg1 + 0x2f0)(arg1, x0_3, "MyLocalIP", &data_241ed);
                int64_t x0_13 = *(*arg1 + 0x2f0)(arg1, x0_3, "MyLocalPort", &data_241fc);
                int64_t x0_15 = *(*arg1 + 0x2f0)(arg1, x0_3, "MyWanIP", &data_241ed);
                int64_t x0_17 = *(*arg1 + 0x2f0)(arg1, x0_3, "MyWanPort", &data_241fc);
                int64_t x0_19 = *(*arg1 + 0x2f0)(arg1, x0_3, "ConnectTime", &data_241fc);
                int64_t x0_21 = *(*arg1 + 0x2f0)(arg1, x0_3, &data_2423e, &data_241ed);
                int64_t x0_23 = *(*arg1 + 0x2f0)(arg1, x0_3, "bCorD", &data_241ee);
                int64_t x0_25 = *(*arg1 + 0x2f0)(arg1, x0_3, "bMode", &data_241ee);
                *(*arg1 + 0x368)(arg1, arg4, x0_5, var_c0);
                int64_t x0_28 = *(*arg1 + 0x2f8)(arg1, arg4, x0_7);
                
                if (x0_28 != 0)
                {
                    int32_t x0_30 = *(*arg1 + 0x558)(arg1, x0_28);
                    char* s1 = *(*arg1 + 0x5c0)(arg1, x0_28, 0);
                    struct in_addr in;
                    strncpy(s1, inet_ntoa(in), x0_30);
                    *(*arg1 + 0x600)(arg1, x0_28, s1, 0);
                }
                
                int16_t var_ba;
                *(*arg1 + 0x368)(arg1, arg4, x0_9, (_byteswap(var_ba) >> 0x10));
                int64_t x0_38 = *(*arg1 + 0x2f8)(arg1, arg4, x0_11);
                
                if (x0_38 != 0)
                {
                    int32_t x0_40 = *(*arg1 + 0x558)(arg1, x0_38);
                    char* s1_1 = *(*arg1 + 0x5c0)(arg1, x0_38, 0);
                    struct in_addr in_1;
                    strncpy(s1_1, inet_ntoa(in_1), x0_40);
                    *(*arg1 + 0x600)(arg1, x0_38, s1_1, 0);
                }
                
                int16_t var_aa;
                *(*arg1 + 0x368)(arg1, arg4, x0_13, (_byteswap(var_aa) >> 0x10));
                int64_t x0_48 = *(*arg1 + 0x2f8)(arg1, arg4, x0_15);
                
                if (x0_48 != 0)
                {
                    int32_t x0_50 = *(*arg1 + 0x558)(arg1, x0_48);
                    char* s1_2 = *(*arg1 + 0x5c0)(arg1, x0_48, 0);
                    struct in_addr in_2;
                    strncpy(s1_2, inet_ntoa(in_2), x0_50);
                    *(*arg1 + 0x600)(arg1, x0_48, s1_2, 0);
                }
                
                int16_t var_9a;
                *(*arg1 + 0x368)(arg1, arg4, x0_17, (_byteswap(var_9a) >> 0x10));
                int32_t var_8c;
                *(*arg1 + 0x368)(arg1, arg4, x0_19, var_8c);
                int64_t x0_59 = *(*arg1 + 0x2f8)(arg1, arg4, x0_21);
                
                if (x0_59 != 0)
                {
                    int32_t x0_61 = *(*arg1 + 0x558)(arg1, x0_59);
                    int64_t x0_63 = *(*arg1 + 0x5c0)(arg1, x0_59, 0);
                    int64_t x8_68 = x0_61;
                    int64_t x2_15;
                    
                    if (x8_68 < 0x18)
                        x2_15 = x8_68;
                    else
                        x2_15 = 0x18;
                    
                    void var_88;
                    memcpy(x0_63, &var_88, x2_15);
                    *(*arg1 + 0x600)(arg1, x0_59, x0_63, 0);
                }
                
                char var_70;
                *(*arg1 + 0x350)(arg1, arg4, x0_23, var_70);
                char var_6f;
                *(*arg1 + 0x350)(arg1, arg4, x0_25, var_6f);
                result = 0;
            }
        }
    }
    
    if (*(x27 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

