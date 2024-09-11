
uint64_t cs2p2p_PPPP_Connect_Do(char* arg1, int32_t arg2, char* arg3, char arg4, uint16_t arg5, char* arg6, char* arg7)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int32_t x20;
    
    if (*cs2p2p_gFlagInitialized == 0)
        x20 = -1;
    else if (strnlen(arg1, 8) <= 7)
    {
        x20 = -4;
        
        if (((arg2 & 0x80000000) == 0 && strnlen(arg3, 8) <= 7))
        {
            int32_t x0_5 = cs2p2p_CurrentTickCount();
            pthread_mutex_lock(&data_50d02c);
            int64_t x21_1 = 0;
            
            while (true)
            {
                int32_t x11_1 = ((*cs2p2p_gLastHandle + 1) + x21_1);
                int32_t x12_2;
                
                if (x11_1 < 0)
                    x12_2 = (x11_1 + 0xff);
                else
                    x12_2 = x11_1;
                
                x20 = (x11_1 - (x12_2 & 0xffffff00));
                void* x11_2 = (cs2p2p_gSession + (x20 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
                int32_t var_80c_1;
                char* s2;
                
                if (*x11_2 == 0xffffffff)
                {
                    var_80c_1 = arg2;
                    s2 = arg3;
                    x21_1 = x20;
                    *x11_2 = 0xfffffffe;
                    *cs2p2p_gLastHandle = x20;
                    pthread_mutex_unlock(&data_50d02c);
                }
                else
                {
                    x21_1 += 1;
                    
                    if ((x21_1 - 1) < 0xff)
                        continue;
                    else
                    {
                        pthread_mutex_unlock(&data_50d02c);
                        
                        if (x21_1 == 0x100)
                        {
                            x20 = -0x11;
                            break;
                        }
                        
                        x20 = x21_1;
                        var_80c_1 = arg2;
                        s2 = arg3;
                    }
                }
                
                int32_t* x24_1 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                memset(x24_1, 0, "PKciP11sockaddr_inc");
                x24_1[0x5e] = 0x101;
                *(x24_1 + "nAckPKciP11sockaddr_inc") = 0xffffffff;
                int64_t s = 0;
                int64_t var_4b8_1 = 0;
                sprintf(&s, "/p2psem03%d02%d", x20, 0);
                sem_init(&x24_1[0x1a], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 1);
                sem_init(&x24_1[0x1e], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 2);
                sem_init(&x24_1[0x22], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 3);
                sem_init(&x24_1[0x26], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 4);
                sem_init(&x24_1[0x2a], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 5);
                sem_init(&x24_1[0x2e], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 6);
                sem_init(&x24_1[0x32], 0, 0);
                sprintf(&s, "/p2psem03%d02%d", x20, 7);
                sem_init(&x24_1[0x36], 0, 0);
                void* x0_24 = strchr(arg6, 0x3a);
                
                if (x0_24 != 0)
                {
                    __builtin_memset(((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xe8), 0, 0x18);
                    uint32_t x9_4 = *(x0_24 + 1);
                    
                    if ((x9_4 - 0x21) <= 0x5d)
                    {
                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xe8) = x9_4;
                        uint32_t x8_5 = *(x0_24 + 2);
                        
                        if ((x8_5 - 0x21) < 0x5e)
                        {
                            *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xe9) = x8_5;
                            uint32_t x8_6 = *(x0_24 + 3);
                            
                            if ((x8_6 - 0x21) <= 0x5d)
                            {
                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xea) = x8_6;
                                uint32_t x8_7 = *(x0_24 + 4);
                                
                                if ((x8_7 - 0x21) <= 0x5d)
                                {
                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xeb) = x8_7;
                                    uint32_t x8_8 = *(x0_24 + 5);
                                    
                                    if ((x8_8 - 0x21) <= 0x5d)
                                    {
                                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xec) = x8_8;
                                        uint32_t x8_9 = *(x0_24 + 6);
                                        
                                        if ((x8_9 - 0x21) <= 0x5d)
                                        {
                                            *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xed) = x8_9;
                                            uint32_t x8_10 = *(x0_24 + 7);
                                            
                                            if ((x8_10 - 0x21) <= 0x5d)
                                            {
                                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xee) = x8_10;
                                                uint32_t x8_11 = *(x0_24 + 8);
                                                
                                                if ((x8_11 - 0x21) <= 0x5d)
                                                {
                                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xef) = x8_11;
                                                    uint32_t x8_12 = *(x0_24 + 9);
                                                    
                                                    if ((x8_12 - 0x21) <= 0x5d)
                                                    {
                                                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf0) = x8_12;
                                                        uint32_t x8_13 = *(x0_24 + 0xa);
                                                        
                                                        if ((x8_13 - 0x21) <= 0x5d)
                                                        {
                                                            *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf1) = x8_13;
                                                            uint32_t x8_14 = *(x0_24 + 0xb);
                                                            
                                                            if ((x8_14 - 0x21) <= 0x5d)
                                                            {
                                                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf2) = x8_14;
                                                                uint32_t x8_15 = *(x0_24 + 0xc);
                                                                
                                                                if ((x8_15 - 0x21) <= 0x5d)
                                                                {
                                                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf3) = x8_15;
                                                                    uint32_t x8_16 = *(x0_24 + 0xd);
                                                                    
                                                                    if ((x8_16 - 0x21) <= 0x5d)
                                                                    {
                                                                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf4) = x8_16;
                                                                        uint32_t x8_17 = *(x0_24 + 0xe);
                                                                        
                                                                        if ((x8_17 - 0x21) <= 0x5d)
                                                                        {
                                                                            *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf5) = x8_17;
                                                                            uint32_t x8_18 = *(x0_24 + 0xf);
                                                                            
                                                                            if ((x8_18 - 0x21) <= 0x5d)
                                                                            {
                                                                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf6) = x8_18;
                                                                                uint32_t x8_19 = *(x0_24 + 0x10);
                                                                                
                                                                                if ((x8_19 - 0x21) <= 0x5d)
                                                                                {
                                                                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf7) = x8_19;
                                                                                    uint32_t x8_20 = *(x0_24 + 0x11);
                                                                                    
                                                                                    if ((x8_20 - 0x21) <= 0x5d)
                                                                                    {
                                                                                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf8) = x8_20;
                                                                                        uint32_t x8_21 = *(x0_24 + 0x12);
                                                                                        
                                                                                        if ((x8_21 - 0x21) <= 0x5d)
                                                                                        {
                                                                                            *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xf9) = x8_21;
                                                                                            uint32_t x8_22 = *(x0_24 + 0x13);
                                                                                            
                                                                                            if ((x8_22 - 0x21) <= 0x5d)
                                                                                            {
                                                                                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xfa) = x8_22;
                                                                                                uint32_t x8_23 = *(x0_24 + 0x14);
                                                                                                
                                                                                                if ((x8_23 - 0x21) <= 0x5d)
                                                                                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0xfb) = x8_23;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                void* x27_1 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                *cs2p2p_gFlagUserBreakConnect = 0;
                strncpy((x27_1 + 0x17b), arg1, 8);
                *(x27_1 + 0x18c) = var_80c_1;
                strncpy((x27_1 + 0x183), s2, 8);
                
                if (arg7 != 0)
                    strncpy(((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x100), arg7, 0x17);
                
                void* x8_26 = &x24_1[0x5e];
                uint32_t x8_28 = arg4;
                void* x8_29 = (x24_1 + 0x179);
                int128_t var_c0;
                int128_t var_b0;
                int128_t var_a0;
                
                if (x8_28 == 0x3f)
                {
                label_1e064:
                    int32_t x0_32;
                    int128_t v0_1;
                    int128_t v1_1;
                    int128_t v2_1;
                    x0_32 = strncmp(cs2p2p_gServerString, arg6, 0x100);
                    int128_t var_7c0;
                    
                    if (x0_32 == 0)
                    {
                        v1_1 = *(cs2p2p_gP2PServerAddr + 0x10);
                        v2_1 = *(cs2p2p_gP2PServerAddr + 0x20);
                        var_c0 = *cs2p2p_gP2PServerAddr;
                        var_b0 = v1_1;
                        var_a0 = v2_1;
                    label_1e1fc:
                        int32_t x0_46 = cs2p2p_setup_Socket();
                        
                        if ((x0_46 & 0x80000000) != 0)
                        {
                            printf("socket create failed!!, errno=%d…", *__errno());
                            pthread_mutex_lock(&data_50d02c);
                            memset(x24_1, 0, "PKciP11sockaddr_inc");
                            *x8_26 = 1;
                            *x8_29 = 1;
                            *x24_1 = 0xffffffff;
                            pthread_mutex_unlock(&data_50d02c);
                            x20 = -0x12;
                        }
                        else
                        {
                            *x24_1 = x0_46;
                            int32_t var_7dc = 1;
                            setsockopt();
                            sockaddr_in var_7d0;
                            
                            if (cs2p2p_TryBind(*x24_1, arg5, &var_7d0) == 0xffffffff)
                            {
                                close(*x24_1);
                                pthread_mutex_lock(&data_50d02c);
                                memset(x24_1, 0, "PKciP11sockaddr_inc");
                                *x8_26 = 1;
                                *x8_29 = 1;
                                *x24_1 = 0xffffffff;
                                pthread_mutex_unlock(&data_50d02c);
                                x20 = -0x12;
                            }
                            else
                            {
                                pthread_mutex_lock(&data_50d02c);
                                void* x27_2 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                *(x27_2 + 0x14) = 2;
                                cs2p2p_GetInetAddrByName((cs2p2p_gNetInfo + 4), (x27_2 + 0x18));
                                *(x27_2 + 0x24) = 2;
                                uint32_t* x28_1 = (x27_1 + 0x18c);
                                cs2p2p_GetInetAddrByName((cs2p2p_gNetInfo + 0x14), (x27_2 + 0x28));
                                uint32_t s_addr_1 = *(x27_2 + 0x18);
                                pthread_mutex_unlock(&data_50d02c);
                                *(x27_2 + 0x54) = 0;
                                int16_t var_7ce;
                                *(x27_2 + 0x16) = var_7ce;
                                *(x27_2 + 0x26) = var_7ce;
                                *(x27_2 + 0x50) = 0;
                                *(x27_2 + 0x52) = 0;
                                sprintf((x27_2 + 0x38), "%s-%06d-%s", (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183));
                                pthread_create((x27_2 + 0x118), 0, cs2p2p_PPPP_thread_recv_Proto, x21_1);
                                *(x27_2 + 0x138) = var_c0;
                                cs2p2p_PPPP_Proto_Send_Hello((x27_2 + 0xe8), *x24_1, &var_c0);
                                int128_t* var_860_1 = &var_b0;
                                *(x27_2 + 0x148) = var_b0;
                                cs2p2p_PPPP_Proto_Send_Hello((x27_2 + 0xe8), *x24_1, &var_b0);
                                *(x27_2 + 0x158) = var_a0;
                                int128_t* var_858_1 = &var_a0;
                                cs2p2p_PPPP_Proto_Send_Hello((x27_2 + 0xe8), *x24_1, &var_a0);
                                int32_t* var_828_2 = x24_1;
                                uint32_t* var_8a0_1 = x28_1;
                                uint32_t x8_42 = arg4;
                                *x8_26 = 1;
                                int64_t* var_980;
                                char* var_978;
                                int32_t x8_135;
                                uint32_t x9_49;
                                int32_t x9_50;
                                void* x19_4;
                                int32_t x23_1;
                                
                                if ((x8_42 - 0x7a) >= 5)
                                {
                                    if (x8_42 != 0x7f)
                                    {
                                        int32_t x8_131 = ((x8_28 >> 1) & 0xf);
                                        int32_t x25_10;
                                        
                                        if ((x8_28 & 1) != 0)
                                            x25_10 = -0xe;
                                        else
                                            x25_10 = 0;
                                        
                                        int32_t var_878;
                                        int32_t var_868;
                                        int32_t x26_12;
                                        
                                        if (x8_131 == 0)
                                        {
                                            x19_4 = (x27_2 + 0x54);
                                            x26_12 = 0x2d;
                                            
                                            if (x25_10 < 0x2d)
                                            {
                                            label_1f148:
                                                
                                                if (*cs2p2p_gFlagUserBreakConnect == 0)
                                                {
                                                    var_868 = x26_12;
                                                    var_878 = ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x5b);
                                                    
                                                    do
                                                    {
                                                        if (((x8_28 & 1) != 0 && x25_10 < x26_12))
                                                        {
                                                            pthread_mutex_lock(&data_50d02c);
                                                            cs2p2p_PPPP_Proto_Send_LanSerch((x27_2 + 0xe8), *x24_1, 0x7d6c);
                                                            pthread_mutex_unlock(&data_50d02c);
                                                        }
                                                        
                                                        if (((x25_10 & 0x80000000) == 0 && (x25_10 % 0xa) == 0))
                                                        {
                                                            if (arg7 == 0)
                                                            {
                                                                int32_t* x27_11 = x24_1;
                                                                cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x24_1, &var_c0, (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                                                cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x27_11, var_860_1, (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                                                cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x27_11, var_858_1, (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                                            }
                                                            else
                                                            {
                                                                *x24_1;
                                                                *x28_1;
                                                                *(cs2p2p_gNetInfo + 3);
                                                                s = 0x104;
                                                                *s[2] = 3;
                                                                int64_t* var_980_6 = &s;
                                                                char* var_978_6 = arg7;
                                                                cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                                                *x24_1;
                                                                *var_8a0_1;
                                                                *(cs2p2p_gNetInfo + 3);
                                                                int64_t* var_980_7 = &s;
                                                                char* var_978_7 = arg7;
                                                                cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                                                *x24_1;
                                                                *var_8a0_1;
                                                                x28_1 = var_8a0_1;
                                                                *(cs2p2p_gNetInfo + 3);
                                                                var_980 = &s;
                                                                var_978 = arg7;
                                                                cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                                            }
                                                            
                                                            x24_1 = var_828_2;
                                                            *var_878 = 0;
                                                            x19_4 = (x27_2 + 0x54);
                                                            x26_12 = var_868;
                                                        }
                                                        
                                                        if (*x19_4 != 0)
                                                            break;
                                                        
                                                        uint32_t x9_68 = *x8_26;
                                                        int32_t x8_155 = 1;
                                                        
                                                        if (x9_68 > 0xfd)
                                                        {
                                                            if (x9_68 == 0xfe)
                                                                x8_155 = 2;
                                                            else if (x9_68 == 0xff)
                                                                break;
                                                        }
                                                        else if (x9_68 == 0)
                                                            x8_155 = 2;
                                                        else if ((x9_68 - 0xfc) < 2)
                                                            break;
                                                        
                                                        x25_10 += x8_155;
                                                        cs2p2p_mSecSleep(0x64);
                                                        
                                                        if (x25_10 >= x26_12)
                                                            break;
                                                    } while (*cs2p2p_gFlagUserBreakConnect == 0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            x19_4 = (x27_2 + 0x54);
                                            
                                            if (x8_131 != 0xf)
                                            {
                                                x26_12 = (x8_131 * 0xa);
                                                
                                                if (x25_10 < x26_12)
                                                    goto label_1f148;
                                            }
                                            else
                                            {
                                                x26_12 = 0;
                                                
                                                if (x25_10 < 0)
                                                    goto label_1f148;
                                            }
                                        }
                                        int32_t var_87c_1 = 0;
                                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x59) = ((x8_28 >> 6) & 1);
                                        var_878 = ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x17a);
                                        int32_t x13_1 = 0;
                                        int32_t x25_11 = 0x2c;
                                        int32_t x28_11 = 0xfa;
                                        uint32_t x8_163 = 0xfb;
                                        *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x17a) = 0xfb;
                                        
                                        while (true)
                                        {
                                            if ((x8_28 & 0x20) != 0)
                                                goto label_1f7e0;
                                            
                                            if (*cs2p2p_gFlagUserBreakConnect != 0)
                                                goto label_1f7e0;
                                            
                                            x9_49 = *x19_4;
                                            
                                            if (x9_49 != 0)
                                            {
                                            label_1f7f0:
                                                x23_1 = x0_5;
                                                x8_135 = ((x9_49 == 0) ? 1 : 0);
                                                goto label_1f810;
                                            }
                                            
                                            x9_50 = *x8_26;
                                            
                                            if ((x9_50 & 0x80000000) != 0)
                                            {
                                            label_1f884:
                                                x23_1 = x0_5;
                                                break;
                                            }
                                            
                                            uint32_t x9_73 = *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x59);
                                            
                                            if (x9_73 != 0)
                                            {
                                                uint32_t x9_74 = (x9_73 + 1);
                                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x59) = (x9_73 + 1);
                                                
                                                if ((x9_74 != 0 && (x9_74 % 0x14) == 0))
                                                {
                                                    int32_t x9_76 = *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + "cs2p2p_PPPP_Proto_Send_ByteCount…");
                                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + "cs2p2p_PPPP_Proto_Send_ByteCount…") = (x9_76 + 1);
                                                    
                                                    if (x9_76 >= 1)
                                                    {
                                                        int32_t x9_78;
                                                        
                                                        if ((x9_76 - 1) < 0)
                                                            x9_78 = (x9_76 + 2);
                                                        else
                                                            x9_78 = (x9_76 - 1);
                                                        
                                                        *(((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + (((x9_76 - 1) - (x9_78 & 0xfffffffc)) << 4)) + "RlyReqPK19st_cs2p2p_TCPRlyReqPcP…") = *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x168);
                                                    }
                                                    
                                                    x13_1 = 0;
                                                    x8_163 = 0xfb;
                                                    x28_11 = 0xfa;
                                                    var_87c_1 = 0;
                                                    *var_878 = 0xfb;
                                                }
                                            }
                                            
                                            if ((x25_11 <= 0x18 && *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x59) == 0))
                                                *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x59) = 1;
                                            
                                            uint64_t x9_84 = (x8_163 + 5);
                                            
                                            if (x9_84 <= 4)
                                            {
                                                int32_t x9_87;
                                                
                                                switch (x9_84)
                                                {
                                                    case 0:
                                                    {
                                                        if (x13_1 < 5)
                                                        {
                                                            var_868 = x13_1;
                                                            
                                                            if ((x28_11 & 0xff) == 0xfa)
                                                                goto label_1f6a0;
                                                        }
                                                        else
                                                        {
                                                            var_87c_1 = 0;
                                                            var_868 = 0;
                                                            *var_878 = 0xfb;
                                                        label_1f6a0:
                                                            int32_t x1_56 = *x24_1;
                                                            uint32_t x4_31 = *var_8a0_1;
                                                            
                                                            if (arg7 == 0)
                                                            {
                                                                cs2p2p_PPPP_Proto_Send_ListReq1((x27_2 + 0xe8), x1_56, &var_c0, (x27_1 + 0x17b), x4_31, (x27_1 + 0x183));
                                                                cs2p2p_PPPP_Proto_Send_ListReq1((x27_2 + 0xe8), *var_828_2, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183));
                                                                cs2p2p_PPPP_Proto_Send_ListReq1((x27_2 + 0xe8), *var_828_2, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183));
                                                            }
                                                            else
                                                            {
                                                                cs2p2p_PPPP_Proto_Send_ListReq_DSK((x27_2 + 0xe8), x1_56, &var_c0, (x27_1 + 0x17b), x4_31, (x27_1 + 0x183), arg7);
                                                                cs2p2p_PPPP_Proto_Send_ListReq_DSK((x27_2 + 0xe8), *var_828_2, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), arg7);
                                                                cs2p2p_PPPP_Proto_Send_ListReq_DSK((x27_2 + 0xe8), *var_828_2, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), arg7);
                                                            }
                                                            
                                                            x24_1 = var_828_2;
                                                            x19_4 = (x27_2 + 0x54);
                                                            x28_11 = 0xfa;
                                                        }
                                                        
                                                        cs2p2p_mSecSleep(0x64);
                                                        x9_87 = 0xfb;
                                                        break;
                                                    }
                                                    case 1:
                                                    {
                                                        if (x13_1 >= 5)
                                                        {
                                                            x13_1 = 0;
                                                            x28_11 = 0xfa;
                                                            var_87c_1 = 0;
                                                            *var_878 = 0xfb;
                                                        }
                                                        
                                                        var_868 = x13_1;
                                                        cs2p2p_mSecSleep(0x64);
                                                        x9_87 = 0xfc;
                                                        break;
                                                    }
                                                    case 2:
                                                    {
                                                        if (x13_1 >= 5)
                                                        {
                                                            x13_1 = 0;
                                                            x28_11 = 0xfa;
                                                            var_87c_1 = 0;
                                                            *var_878 = 0xfb;
                                                        }
                                                        
                                                        var_868 = x13_1;
                                                        cs2p2p_mSecSleep(0x64);
                                                        x9_87 = 0xfd;
                                                        break;
                                                    }
                                                    case 3:
                                                    {
                                                        var_868 = x13_1;
                                                        
                                                        if ((x28_11 & 0xff) != 0xfe)
                                                        {
                                                            cs2p2p_PPPP_Proto_Send_RlyReq((x27_2 + 0xe8), *x24_1, &var_c0, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x168), *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x190));
                                                            cs2p2p_PPPP_Proto_Send_RlyReq((x27_2 + 0xe8), *var_828_2, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x168), *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x190));
                                                            x19_4 = (x27_2 + 0x54);
                                                            x24_1 = var_828_2;
                                                            cs2p2p_PPPP_Proto_Send_RlyReq((x27_2 + 0xe8), *var_828_2, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x168), *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x190));
                                                            int32_t x8_179;
                                                            
                                                            if ((0xff & !(x28_11)) == 0)
                                                                x8_179 = (var_87c_1 + 1);
                                                            else
                                                                x8_179 = var_87c_1;
                                                            
                                                            var_87c_1 = x8_179;
                                                        }
                                                        
                                                        cs2p2p_mSecSleep(0x64);
                                                        x9_87 = 0xfe;
                                                        break;
                                                    }
                                                    case 4:
                                                    {
                                                        if ((!(x28_11) != 0 || x13_1 == 0))
                                                            var_868 = x13_1;
                                                        else
                                                        {
                                                            char x8_181 = var_87c_1;
                                                            var_87c_1 = 0;
                                                            uint32_t temp1_1 = x8_181;
                                                            char x8_182;
                                                            
                                                            if (temp1_1 == 0)
                                                                x8_182 = -2;
                                                            else
                                                                x8_182 = -5;
                                                            
                                                            if (temp1_1 != 0)
                                                                x28_11 = -6;
                                                            else
                                                                x28_11 = -1;
                                                            
                                                            int32_t x13_2;
                                                            
                                                            if (temp1_1 == 0)
                                                                x13_2 = x13_1;
                                                            else
                                                                x13_2 = 0;
                                                            
                                                            var_868 = x13_2;
                                                            *var_878 = x8_182;
                                                        }
                                                        
                                                        cs2p2p_mSecSleep(0x64);
                                                        x9_87 = 0xff;
                                                        break;
                                                    }
                                                }
                                                
                                                int32_t x10_23 = (x28_11 & 0xff);
                                                x25_11 -= 1;
                                                x8_163 = *var_878;
                                                x28_11 = x9_87;
                                                
                                                if (x10_23 != x8_163)
                                                    x13_1 = 0;
                                                else
                                                    x13_1 = (var_868 + 1);
                                            }
                                            
                                            if (x25_11 <= 0)
                                                goto label_1f7e0;
                                        }
                                        
                                        goto label_1f88c;
                                    }
                                    
                                    *((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x5a) = 1;
                                    
                                    if (arg7 == 0)
                                    {
                                        int32_t* x26_13 = x24_1;
                                        cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x24_1, &var_c0, (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                        cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x26_13, var_860_1, (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                        cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x26_13, var_858_1, (x27_1 + 0x17b), *x28_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                    }
                                    else
                                    {
                                        *x24_1;
                                        *x28_1;
                                        *(cs2p2p_gNetInfo + 3);
                                        s = 0x104;
                                        *s[2] = 3;
                                        int64_t* var_980_3 = &s;
                                        char* var_978_3 = arg7;
                                        cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                        *x24_1;
                                        *x28_1;
                                        *(cs2p2p_gNetInfo + 3);
                                        s = 0x104;
                                        *s[2] = 3;
                                        int64_t* var_980_4 = &s;
                                        char* var_978_4 = arg7;
                                        cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                        *x24_1;
                                        *x28_1;
                                        *(cs2p2p_gNetInfo + 3);
                                        s = 0x104;
                                        *s[2] = 3;
                                        int64_t* var_980_5 = &s;
                                        char* var_978_5 = arg7;
                                        cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                    }
                                    
                                    char x21_4 = *x8_26;
                                    
                                    for (int32_t i = 0x32; i > 0; )
                                    {
                                        uint32_t x9_65 = x21_4;
                                        int32_t x8_136 = -1;
                                        
                                        if (x9_65 <= 0xfd)
                                        {
                                            if ((x9_65 - 0xfc) < 2)
                                                break;
                                            
                                            if (x9_65 == 0)
                                                break;
                                        }
                                        else if (x9_65 == 0xfe)
                                            x8_136 = -2;
                                        else if (x9_65 == 0xff)
                                            break;
                                        
                                        i += x8_136;
                                        cs2p2p_mSecSleep(0x64);
                                        x21_4 = *x8_26;
                                    }
                                    
                                    *(x27_2 + 0x52) = 1;
                                    int64_t x0_118 = *(x27_2 + 0x118);
                                    
                                    if (x0_118 != 0)
                                    {
                                        pthread_join(x0_118, 0);
                                        *(x27_2 + 0x118) = 0;
                                    }
                                    
                                    close(*var_828_2);
                                    pthread_mutex_lock(&data_50d02c);
                                    memset(var_828_2, 0, "PKciP11sockaddr_inc");
                                    *x8_26 = 1;
                                    *x8_29 = 1;
                                    *var_828_2 = 0xffffffff;
                                    pthread_mutex_unlock(&data_50d02c);
                                    x20 = 0;
                                    
                                    if ((x21_4 + 4) < 6)
                                        x20 = *(&data_24190 + ((x21_4 + 4) << 2));
                                }
                                else
                                {
                                    uint32_t var_838_1 = 0;
                                    int32_t var_904_1 = 0;
                                    void* x17_1 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                    x19_4 = (x27_2 + 0x54);
                                    time_t x26_3 = time(nullptr);
                                    int32_t x28_2 = 0;
                                    int32_t x25_3 = 0;
                                    time_t var_8b0_1 = x26_3;
                                    bool cond:11_1;
                                    
                                    do
                                    {
                                        time_t x0_57;
                                        int128_t v0_5;
                                        x0_57 = time(nullptr);
                                        
                                        if ((x0_57 - x26_3) > 0xb)
                                            break;
                                        
                                        if (*cs2p2p_gFlagUserBreakConnect != 0)
                                            break;
                                        
                                        x9_49 = *x19_4;
                                        
                                        if (x9_49 != 0)
                                            goto label_1f7f0;
                                        
                                        x9_50 = *x8_26;
                                        
                                        if (((x9_50 - 0xfc) <= 3 && x9_50 != 0xfe))
                                            goto label_1f884;
                                        
                                        if (arg4 != 0x7c)
                                        {
                                            uint32_t s_addr = (x27_2 + 0x18)->s_addr;
                                            
                                            if (((x28_2 % 0x64) == 0 || s_addr_1 != s_addr))
                                            {
                                                s_addr_1 = s_addr;
                                                
                                                if (arg7 == 0)
                                                {
                                                    int32_t* x27_5 = x24_1;
                                                    cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x24_1, &var_c0, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                                    cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x27_5, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                                    cs2p2p_PPPP_Proto_Send_P2PReq((x27_2 + 0xe8), *x27_5, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), (x27_2 + 0x14));
                                                }
                                                else
                                                {
                                                    *x24_1;
                                                    *var_8a0_1;
                                                    *(cs2p2p_gNetInfo + 3);
                                                    s = 0x104;
                                                    *s[2] = 3;
                                                    int64_t* var_980_1 = &s;
                                                    char* var_978_1 = arg7;
                                                    cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                                    *x24_1;
                                                    *var_8a0_1;
                                                    *(cs2p2p_gNetInfo + 3);
                                                    int64_t* var_980_2 = &s;
                                                    char* var_978_2 = arg7;
                                                    cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                                    *x24_1;
                                                    *var_8a0_1;
                                                    *(cs2p2p_gNetInfo + 3);
                                                    var_980 = &s;
                                                    var_978 = arg7;
                                                    cs2p2p_PPPP_Proto_Send_P2PReq_DSK();
                                                }
                                                
                                                x24_1 = var_828_2;
                                                *(x17_1 + 0x5b) = 0;
                                                x9_50 = *x8_26;
                                                x19_4 = (x27_2 + 0x54);
                                                x26_3 = var_8b0_1;
                                            }
                                        }
                                        
                                        if ((var_838_1 == 0 && x9_50 == 0))
                                        {
                                            uint32_t x8_73 = arg4;
                                            uint32_t x8_74;
                                            
                                            if ((x8_73 == 0x7d || x8_73 == 0x7b))
                                                x8_74 = 0x19;
                                            else
                                                x8_74 = 1;
                                            
                                            var_838_1 = x8_74;
                                        }
                                        else if ((x25_3 == 0 && var_838_1 > 0x18))
                                            x25_3 = 1;
                                        else if (var_838_1 > 0)
                                            var_838_1 += 1;
                                        else
                                            var_838_1 = var_838_1;
                                        
                                        if (arg4 != 0x7c)
                                        {
                                        label_1e794:
                                            
                                            if ((arg4 - 0x7a) <= 2)
                                            {
                                                if (x28_2 != 0)
                                                    goto label_1e9f8;
                                                
                                                goto label_1e7b4;
                                            }
                                        }
                                        else
                                        {
                                            if ((x28_2 % 0xa) == 9)
                                            {
                                                void* x8_82 = *(x17_1 + "PPP_Proto_Send_ByteCountPKciP11s…");
                                                int32_t x8_84;
                                                
                                                if (x8_82 == 0)
                                                    x8_84 = 1;
                                                else if (*(x8_82 + 0x2c) == 0)
                                                    x8_84 = 0;
                                                else
                                                    x8_84 = ((*(x8_82 + 8) == 0xffffffff) ? 1 : 0);
                                                
                                                void* x9_54 = *(x17_1 + "o_Send_ByteCountPKciP11sockaddr_…");
                                                int32_t x9_56;
                                                
                                                if (x9_54 == 0)
                                                    x9_56 = 1;
                                                else if (*(x9_54 + 0x2c) == 0)
                                                    x9_56 = 0;
                                                else
                                                    x9_56 = ((*(x9_54 + 8) == 0xffffffff) ? 1 : 0);
                                                
                                                void* x10_9 = *(x17_1 + "yteCountPKciP11sockaddr_inj");
                                                
                                                if ((x10_9 == 0 || (*(x10_9 + 0x2c) != 0 && *(x10_9 + 8) == 0xffffffff)))
                                                {
                                                    var_838_1 = 0;
                                                    
                                                    if ((x8_84 != 0 && x9_56 != 0))
                                                        break;
                                                }
                                                else
                                                    var_838_1 = 0;
                                                
                                                goto label_1e794;
                                            }
                                            
                                            var_838_1 = 0;
                                            
                                            if (x28_2 == 0)
                                            {
                                            label_1e7b4:
                                                *(x17_1 + "PPP_Proto_Send_DevLgnAckPKciP11s…") = time(nullptr);
                                                int32_t x0_65;
                                                int128_t v0_6;
                                                x0_65 = cs2p2p_CurrentTickCount();
                                                v0_6 = var_c0;
                                                *(x17_1 + "o_Send_DevLgnAckPKciP11sockaddr_…") = x0_65;
                                                var_7c0 = v0_6;
                                                void var_7d8;
                                                sprintf(&var_7d8, "Server%d", 1, v0_6);
                                                char* x0_68 = cs2_SA_GetIPString(&var_7c0, &s, 0x30);
                                                char* s1_3;
                                                int128_t v0_7;
                                                s1_3 = malloc(0x50);
                                                char* s1 = s1_3;
                                                
                                                if (s1 != 0)
                                                {
                                                    memset(s1, 0, 0x50);
                                                    int16_t* x0_70 = malloc(0x100);
                                                    *(s1 + 0x30) = x0_70;
                                                    
                                                    if (x0_70 == 0)
                                                    {
                                                        free(s1);
                                                        s1 = nullptr;
                                                    }
                                                    else
                                                    {
                                                        *x0_70 = 0;
                                                        cs2_SA_SetSockAddr(2, x0_68, 0x7d6e, &s1[0xc]);
                                                        *(s1 + 8) = 0xffffffff;
                                                        *(s1 + 0x38) = 0x100;
                                                        strncpy(s1, &var_7d8, 7);
                                                    }
                                                }
                                                
                                                var_7c0 = *var_860_1;
                                                *(x17_1 + "PPP_Proto_Send_ByteCountPKciP11s…") = s1;
                                                sprintf(&var_7d8, "Server%d", 2);
                                                char* x0_75 = cs2_SA_GetIPString(&var_7c0, &s, 0x30);
                                                char* s1_4;
                                                int128_t v0_8;
                                                s1_4 = malloc(0x50);
                                                char* s1_1 = s1_4;
                                                
                                                if (s1_1 != 0)
                                                {
                                                    memset(s1_1, 0, 0x50);
                                                    int16_t* x0_77 = malloc(0x100);
                                                    *(s1_1 + 0x30) = x0_77;
                                                    
                                                    if (x0_77 == 0)
                                                    {
                                                        free(s1_1);
                                                        s1_1 = nullptr;
                                                    }
                                                    else
                                                    {
                                                        *x0_77 = 0;
                                                        cs2_SA_SetSockAddr(2, x0_75, 0x7d6e, &s1_1[0xc]);
                                                        *(s1_1 + 8) = 0xffffffff;
                                                        *(s1_1 + 0x38) = 0x100;
                                                        strncpy(s1_1, &var_7d8, 7);
                                                    }
                                                }
                                                
                                                var_7c0 = *var_858_1;
                                                *(x17_1 + "o_Send_ByteCountPKciP11sockaddr_…") = s1_1;
                                                sprintf(&var_7d8, "Server%d", 3);
                                                char* x0_82 = cs2_SA_GetIPString(&var_7c0, &s, 0x30);
                                                char* s1_2 = malloc(0x50);
                                                
                                                if (s1_2 != 0)
                                                {
                                                    memset(s1_2, 0, 0x50);
                                                    int16_t* x0_85 = malloc(0x100);
                                                    *(s1_2 + 0x30) = x0_85;
                                                    
                                                    if (x0_85 == 0)
                                                    {
                                                        free(s1_2);
                                                        s1_2 = nullptr;
                                                    }
                                                    else
                                                    {
                                                        *x0_85 = 0;
                                                        cs2_SA_SetSockAddr(2, x0_82, 0x7d6e, &s1_2[0xc]);
                                                        *(s1_2 + 8) = 0xffffffff;
                                                        *(s1_2 + 0x38) = 0x100;
                                                        strncpy(s1_2, &var_7d8, 7);
                                                    }
                                                }
                                                
                                                x26_3 = var_8b0_1;
                                                *(x17_1 + "yteCountPKciP11sockaddr_inj") = s1_2;
                                                goto label_1e9f8;
                                            }
                                            
                                        label_1e9f8:
                                            
                                            if (*(x17_1 + "d_DevLgnAckPKciP11sockaddr_inc") != 0)
                                                goto label_1ea54;
                                            
                                            uint32_t x8_96 = arg4;
                                            
                                            if (x8_96 == 0x7c)
                                            {
                                            label_1ea4c:
                                                *(x17_1 + "d_DevLgnAckPKciP11sockaddr_inc") = 1;
                                            label_1ea54:
                                                
                                                if (arg7 == 0)
                                                {
                                                    cs2p2p_Do_TCPConnect(x20, 3);
                                                    cs2p2p_Do_TCPSendRlyPreReq(x20);
                                                    cs2p2p_Do_TCPSendRlyReq(x20);
                                                }
                                                else
                                                {
                                                    cs2p2p_Do_TCPConnect(x20, 4);
                                                    cs2p2p_Do_TCPSendRlyPreReqDSK(x20);
                                                    cs2p2p_Do_TCPSendRlyReqDSK(x20);
                                                }
                                                
                                                cs2p2p_Do_TCPRecv(x20);
                                            }
                                            else
                                            {
                                                int32_t x0_88;
                                                
                                                if (x8_96 == 0x7b)
                                                    x0_88 = cs2p2p_CurrentTickCount();
                                                
                                                if ((x8_96 == 0x7b && (x0_88 - *(x17_1 + "o_Send_DevLgnAckPKciP11sockaddr_…")) >= 0x65))
                                                    goto label_1ea4c;
                                                
                                                if ((cs2p2p_CurrentTickCount() - *(x17_1 + "o_Send_DevLgnAckPKciP11sockaddr_…")) >= 0x5dd)
                                                    goto label_1ea4c;
                                                
                                                if (*(x17_1 + "d_DevLgnAckPKciP11sockaddr_inc") != 0)
                                                    goto label_1ea54;
                                            }
                                            
                                            if (*(x17_1 + "nd_DevLgnAckPKciP11sockaddr_inc") != 0)
                                            {
                                                *x8_26 = 0;
                                                cs2p2p_PPPP_TCPRelay_Setup(x20);
                                                
                                                if (*x19_4 != 0)
                                                    goto label_1f7e4;
                                                
                                                goto label_1efa4;
                                            }
                                        }
                                        
                                        if ((x28_2 % 0xa) == 0)
                                        {
                                            pthread_mutex_lock(&data_50d02c);
                                            cs2p2p_PPPP_Proto_Send_LanSerch((x27_2 + 0xe8), *x24_1, 0x7d6c);
                                            
                                            if (x25_3 > 0)
                                                x25_3 += 1;
                                            
                                            if ((x25_3 <= 7 && ((1 << x25_3) & 0xa8) != 0))
                                            {
                                                int32_t var_8d8_2 = x28_2;
                                                int32_t var_8d4_2 = x25_3;
                                                bool cond:16_1 = ((var_904_1 + 1) % 0xa) != 1;
                                                var_904_1 += 1;
                                                
                                                if (!(cond:16_1))
                                                {
                                                    int32_t x9_60 = *(x17_1 + "cs2p2p_PPPP_Proto_Send_ByteCount…");
                                                    *(x17_1 + "cs2p2p_PPPP_Proto_Send_ByteCount…") = (x9_60 + 1);
                                                    
                                                    if (x9_60 >= 1)
                                                    {
                                                        int32_t x9_62;
                                                        
                                                        if ((x9_60 - 1) < 0)
                                                            x9_62 = (x9_60 + 2);
                                                        else
                                                            x9_62 = (x9_60 - 1);
                                                        
                                                        *(((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + (((x9_60 - 1) - (x9_62 & 0xfffffffc)) << 4)) + "RlyReqPK19st_cs2p2p_TCPRlyReqPcP…") = *(x17_1 + 0x168);
                                                    }
                                                    
                                                    *(x17_1 + 0x17a) = 0xfb;
                                                    sockaddr_in* x2_20 = &var_c0;
                                                    *(x17_1 + 0x59) = 0;
                                                    int32_t x1_31 = *x24_1;
                                                    uint32_t x4_8 = *var_8a0_1;
                                                    
                                                    if (arg7 == 0)
                                                    {
                                                        cs2p2p_PPPP_Proto_Send_ListReq1((x27_2 + 0xe8), x1_31, x2_20, (x27_1 + 0x17b), x4_8, (x27_1 + 0x183));
                                                        cs2p2p_PPPP_Proto_Send_ListReq1((x27_2 + 0xe8), *x24_1, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183));
                                                        cs2p2p_PPPP_Proto_Send_ListReq1((x27_2 + 0xe8), *x24_1, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183));
                                                    }
                                                    else
                                                    {
                                                        cs2p2p_PPPP_Proto_Send_ListReq_DSK((x27_2 + 0xe8), x1_31, x2_20, (x27_1 + 0x17b), x4_8, (x27_1 + 0x183), arg7);
                                                        cs2p2p_PPPP_Proto_Send_ListReq_DSK((x27_2 + 0xe8), *x24_1, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), arg7);
                                                        x26_3 = var_8b0_1;
                                                        cs2p2p_PPPP_Proto_Send_ListReq_DSK((x27_2 + 0xe8), *x24_1, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), arg7);
                                                    }
                                                    
                                                    x19_4 = (x27_2 + 0x54);
                                                    x28_2 = var_8d8_2;
                                                    x25_3 = var_8d4_2;
                                                }
                                                
                                                if (*(x17_1 + 0x17a) >= 0xfffffffe)
                                                {
                                                    cs2p2p_PPPP_Proto_Send_RlyReq((x27_2 + 0xe8), *x24_1, &var_c0, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), (x17_1 + 0x168), *(x17_1 + 0x190));
                                                    cs2p2p_PPPP_Proto_Send_RlyReq((x27_2 + 0xe8), *var_828_2, var_860_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), (x17_1 + 0x168), *(x17_1 + 0x190));
                                                    x26_3 = var_8b0_1;
                                                    x19_4 = (x27_2 + 0x54);
                                                    x24_1 = var_828_2;
                                                    x28_2 = var_8d8_2;
                                                    x25_3 = var_8d4_2;
                                                    cs2p2p_PPPP_Proto_Send_RlyReq((x27_2 + 0xe8), *var_828_2, var_858_1, (x27_1 + 0x17b), *var_8a0_1, (x27_1 + 0x183), (x17_1 + 0x168), *(x17_1 + 0x190));
                                                }
                                            }
                                            else if (x25_3 == 0xa)
                                                x25_3 = 1;
                                            
                                            pthread_mutex_unlock(&data_50d02c);
                                        }
                                        
                                        cs2p2p_mSecSleep(0xa);
                                        cond:11_1 = x28_2 < 0x3e8;
                                        x28_2 += 1;
                                    } while (cond:11_1);
                                label_1f7e0:
                                    
                                    if (*x19_4 == 0)
                                    {
                                    label_1efa4:
                                        x23_1 = x0_5;
                                        x9_50 = *x8_26;
                                        
                                        if ((x9_50 & 0x80000000) == 0)
                                        {
                                            x8_135 = 1;
                                            goto label_1f810;
                                        }
                                        
                                    label_1f88c:
                                        
                                        if ((x9_50 & 0xff) <= 0xfb)
                                            x20 = 0;
                                        else
                                            x20 = *((x9_50 << 2) + 0x2418c);
                                    }
                                    else
                                    {
                                    label_1f7e4:
                                        x23_1 = x0_5;
                                        x8_135 = 0;
                                    label_1f810:
                                        uint32_t x9_91 = *"DevLgnAckPKciP11sockaddr_inc"[(cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"))];
                                        
                                        if (x9_91 == 0)
                                        {
                                            if (x8_135 != 0)
                                            {
                                                if (*cs2p2p_gFlagUserBreakConnect == 0)
                                                    x20 = -3;
                                                else
                                                    x20 = -0x13;
                                            }
                                        }
                                        else if (x9_91 == 1)
                                        {
                                            *x19_4 = 1;
                                            void* x8_190 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            *(x8_190 + 0x51) = 2;
                                            *(x8_190 + 4) = *(x8_190 + "P11sockaddr_inj");
                                        }
                                        else if (*cs2p2p_gFlagUserBreakConnect == 0)
                                            x20 = -0x18;
                                        else
                                            x20 = -0x13;
                                    }
                                    
                                    *(x27_2 + 0x52) = 1;
                                    int64_t x0_137 = *(x27_2 + 0x118);
                                    
                                    if (x0_137 != 0)
                                    {
                                        pthread_join(x0_137, 0);
                                        *(x27_2 + 0x118) = 0;
                                    }
                                    
                                    if ((arg4 - 0x7a) <= 2)
                                    {
                                        int64_t x8_198 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                        void* x25_12 = *(x8_198 + "PPP_Proto_Send_ByteCountPKciP11s…");
                                        
                                        if (x25_12 != 0)
                                        {
                                            int32_t x0_138 = *(x25_12 + 8);
                                            
                                            if ((x0_138 & 0x80000000) == 0)
                                                cs2_TCPNBSkt_Close(x0_138);
                                            
                                            int64_t x0_139 = *(x25_12 + 0x30);
                                            
                                            if (x0_139 != 0)
                                                free(x0_139);
                                            
                                            free(x25_12);
                                            *(x8_198 + "PPP_Proto_Send_ByteCountPKciP11s…") = 0;
                                        }
                                        
                                        int64_t x8_199 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                        void* x25_13 = *(x8_199 + "o_Send_ByteCountPKciP11sockaddr_…");
                                        
                                        if (x25_13 != 0)
                                        {
                                            int32_t x0_141 = *(x25_13 + 8);
                                            
                                            if ((x0_141 & 0x80000000) == 0)
                                                cs2_TCPNBSkt_Close(x0_141);
                                            
                                            int64_t x0_142 = *(x25_13 + 0x30);
                                            
                                            if (x0_142 != 0)
                                                free(x0_142);
                                            
                                            free(x25_13);
                                            *(x8_199 + "o_Send_ByteCountPKciP11sockaddr_…") = 0;
                                        }
                                        
                                        int64_t x8_200 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                        void* x25_14 = *(x8_200 + "yteCountPKciP11sockaddr_inj");
                                        
                                        if (x25_14 != 0)
                                        {
                                            int32_t x0_144 = *(x25_14 + 8);
                                            
                                            if ((x0_144 & 0x80000000) == 0)
                                                cs2_TCPNBSkt_Close(x0_144);
                                            
                                            int64_t x0_145 = *(x25_14 + 0x30);
                                            
                                            if (x0_145 != 0)
                                                free(x0_145);
                                            
                                            free(x25_14);
                                            *(x8_200 + "yteCountPKciP11sockaddr_inj") = 0;
                                        }
                                    }
                                    
                                    int32_t x0_147 = cs2p2p_CurrentTickCount();
                                    int32_t x9_93 = 0;
                                    int32_t x10_24 = 0;
                                    int64_t i_3 = 0x100;
                                    void* x12_5 = (cs2p2p_gSession + "PKciP11sockaddr_inc");
                                    int64_t (* const x14_1)() = cs2p2p_gSession;
                                    int64_t i_1;
                                    
                                    do
                                    {
                                        int32_t x16_1 = *x12_5;
                                        x12_5 += cs2p2p_PPPP_Proto_Send_ReportSessionRdy;
                                        i_1 = i_3;
                                        i_3 -= 2;
                                        x9_93 += ((*x14_1 >> 0x1f) ^ 1);
                                        x10_24 += ((x16_1 >> 0x1f) ^ 1);
                                        x14_1 += cs2p2p_PPPP_Proto_Send_ReportSessionRdy;
                                    } while (i_1 != 2);
                                    int32_t x12_6 = (x10_24 + x9_93);
                                    int32_t x8_202;
                                    
                                    if (x0_147 < x23_1)
                                        x8_202 = (x23_1 - x0_147);
                                    else
                                        x8_202 = (x0_147 - x23_1);
                                    
                                    char* var_800_1;
                                    var_800_1 = x8_202;
                                    int16_t var_950_1 = x8_202;
                                    void* x19_21 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                    int16_t* var_968_1 = (x27_2 + 0x14);
                                    *x24_1;
                                    *(x19_21 + 0x51);
                                    int16_t* var_960_1 = (x27_2 + 0x24);
                                    void* var_958_1 = (x19_21 + 4);
                                    char var_940_1 = *(x19_21 + 0x64);
                                    char var_948_1 = arg4;
                                    var_838_1 = (x19_21 + 4);
                                    int16_t var_970_1 = x12_6;
                                    char* var_830_1;
                                    var_830_1 = x12_6;
                                    var_978 = 0x100;
                                    var_980 = *(x27_2 + 0x50);
                                    cs2p2p_PPPP_Proto_Send_ReportSessionRdy();
                                    int16_t var_970_2 = x12_6;
                                    char var_940_2 = *(x19_21 + 0x64);
                                    *x24_1;
                                    *(x19_21 + 0x51);
                                    char var_948_2 = arg4;
                                    void* var_958_2 = (x19_21 + 4);
                                    int16_t var_950_2 = var_800_1;
                                    int16_t* var_968_2 = (x27_2 + 0x14);
                                    int16_t* var_960_2 = (x27_2 + 0x24);
                                    var_978 = 0x100;
                                    var_980 = *(x27_2 + 0x50);
                                    cs2p2p_PPPP_Proto_Send_ReportSessionRdy();
                                    *(x19_21 + 0x51);
                                    char var_940_3 = *(x19_21 + 0x64);
                                    *var_828_2;
                                    char var_948_3 = arg4;
                                    int16_t var_950_3 = var_800_1;
                                    int16_t* var_968_3 = (x27_2 + 0x14);
                                    int16_t* var_960_3 = (x27_2 + 0x24);
                                    int64_t var_958_3 = var_838_1;
                                    var_980 = *(x27_2 + 0x50);
                                    int16_t var_970_3 = var_830_1;
                                    var_978 = 0x100;
                                    cs2p2p_PPPP_Proto_Send_ReportSessionRdy();
                                    
                                    if ((x20 & 0x80000000) != 0)
                                    {
                                        close(*var_828_2);
                                        pthread_mutex_lock(&data_50d02c);
                                        memset(var_828_2, 0, "PKciP11sockaddr_inc");
                                        *x8_26 = 1;
                                        *x8_29 = 1;
                                        *var_828_2 = 0xffffffff;
                                        pthread_mutex_unlock(&data_50d02c);
                                    }
                                    else
                                    {
                                        cs2p2p_mSecSleep(0x32);
                                        pthread_mutex_lock(&data_50d02c);
                                        void* x23_9 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                        *(x23_9 + 0x53) = 0;
                                        pthread_mutex_unlock(&data_50d02c);
                                        
                                        for (int64_t i_2 = 0; i_2 != 0x100; )
                                        {
                                            void* x12_7 = (x23_9 + i_2);
                                            *(x12_7 + 0x4b0) = 0;
                                            *(x12_7 + 0x4b0) = 0x10000;
                                            __builtin_memset((x12_7 + 0x498), 0, 0x18);
                                            int64_t s_1 = ((x23_9 + "n") + i_2);
                                            *(x12_7 + 0x3b0) = 0;
                                            *(x12_7 + 0x3b0) = 0x10000;
                                            __builtin_memset((x12_7 + 0x398), 0, 0x18);
                                            *(x12_7 + 0x2b0) = 0;
                                            *(x12_7 + 0x2b0) = 0x10000;
                                            __builtin_memset((x12_7 + 0x298), 0, 0x18);
                                            *(x12_7 + 0x1a8) = 0;
                                            *(x12_7 + 0x1b0) = 0;
                                            *(x12_7 + 0x1b0) = 0x10000;
                                            *(x12_7 + 0x198) = 0;
                                            *(x12_7 + 0x1a0) = 0;
                                            *((x23_9 + "TCPSend_AlivePKcijPc") + i_2) = 0;
                                            *((x23_9 + "TCPSend_AlivePKcijPc") + i_2) = 0x10000;
                                            i_2 += 0x20;
                                            __builtin_memset(s_1, 0, 0x18);
                                        }
                                        
                                        int64_t x19_22 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                        pthread_create((x19_22 + 0x128), 0, cs2p2p_PPPP_thread_recv_DRW, x21_1);
                                        pthread_create((x19_22 + 0x130), 0, cs2p2p_PPPP_thread_send_DRW, x21_1);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        memset(&s, 0, 0x400);
                        memset(&var_7c0, 0, 0x300);
                        cs2p2p_PPPP_DecodeString(arg6, &s, 0x400);
                        int32_t x0_37 = strlen(&s);
                        
                        if (x0_37 >= 1)
                        {
                            int64_t x26_1 = 0;
                            int32_t x8_34 = 0;
                            int32_t x24_2 = 0;
                            uint64_t x19_1 = x0_37;
                            
                            while (true)
                            {
                                if (*(&s + x26_1) != 0x2c)
                                {
                                    x26_1 += 1;
                                    
                                    if (x26_1 == x19_1)
                                        break;
                                }
                                else
                                {
                                    *(&s + x26_1) = 0;
                                    strncpy(&&var_7c0[(x24_2 * 0x10)], (&s + x8_34), 0xff);
                                    x26_1 += 1;
                                    x24_2 += 1;
                                    x8_34 = x26_1;
                                    
                                    if (x26_1 == x19_1)
                                        break;
                                }
                            }
                        }
                        
                        *var_c0[0xc] = 0;
                        *var_c0[4] = 0;
                        var_c0 = 0x647d0002;
                        
                        if (cs2p2p_GetInetAddrByName(&var_7c0, (&var_c0 | 4)) == 0)
                        {
                            *var_b0[0xc] = 0;
                            *var_b0[4] = 0;
                            var_b0 = 0x647d0002;
                            void var_6c0;
                            
                            if (cs2p2p_GetInetAddrByName(&var_6c0, &*var_b0[4]) != 0)
                                goto label_1e194;
                            
                            *var_a0[0xc] = 0;
                            *var_a0[4] = 0;
                            var_a0 = 0x647d0002;
                            void var_5c0;
                            
                            if (cs2p2p_GetInetAddrByName(&var_5c0, &*var_a0[4]) == 0)
                                goto label_1e1fc;
                            
                            goto label_1e194;
                        }
                        
                    label_1e194:
                        pthread_mutex_lock(&data_50d02c);
                        memset(x24_1, 0, "PKciP11sockaddr_inc");
                        *x8_26 = 1;
                        *x8_29 = 1;
                        *x24_1 = 0xffffffff;
                        pthread_mutex_unlock(&data_50d02c);
                        x20 = -7;
                    }
                }
                else
                {
                    time_t x0_28 = time(nullptr);
                    
                    if ((x0_28 - *cs2p2p_gLastNetDetectTime) < 0x15181)
                        goto label_1e064;
                    
                    st_cs2p2p_NetInfo var_90;
                    int32_t x0_29 = cs2p2p_PPPP__DoNetWorkDetect(x0_28, 1, &var_90, arg5, cs2p2p_gServerString, &var_c0, &var_b0, &var_a0);
                    
                    if (x0_29 == 0)
                        goto label_1e064;
                    
                    pthread_mutex_lock(&data_50d02c);
                    memset(x24_1, 0, "PKciP11sockaddr_inc");
                    *x8_26 = 1;
                    *x8_29 = 1;
                    *x24_1 = 0xffffffff;
                    pthread_mutex_unlock(&data_50d02c);
                    x20 = x0_29;
                }
                break;
            }
        }
    }
    else
        x20 = -4;
    
    if (*(x22 + 0x28) == x8)
        return x20;
    
    __stack_chk_fail();
    /* no return */
}

