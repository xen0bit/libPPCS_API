
uint64_t cs2p2p_PPPP_Listen_Do(char* arg1, int32_t arg2, char* arg3, uint32_t arg4, uint16_t arg5, char arg6, char* arg7, char* arg8)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int32_t x20_1;
    
    if (*cs2p2p_gFlagInitialized == 0)
        x20_1 = -1;
    else if ((arg4 - 0x3c) <= 0x15144)
    {
        if (strnlen(arg1, 8) <= 7)
        {
            x20_1 = -4;
            
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
                    
                    x20_1 = (x11_1 - (x12_2 & 0xffffff00));
                    void* x11_2 = (cs2p2p_gSession + (x20_1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
                    char var_ec_1;
                    
                    if (*x11_2 == 0xffffffff)
                    {
                        var_ec_1 = arg6;
                        x21_1 = x20_1;
                        *x11_2 = 0xfffffffe;
                        *cs2p2p_gLastHandle = x20_1;
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
                                x20_1 = -0x11;
                                break;
                            }
                            
                            x20_1 = x21_1;
                            var_ec_1 = arg6;
                        }
                    }
                    
                    int32_t* x22_1 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                    memset(x22_1, 0, "PKciP11sockaddr_inc");
                    int64_t s = 0;
                    int64_t var_a8_1 = 0;
                    x22_1[0x5e] = 0x101;
                    *(x22_1 + "nAckPKciP11sockaddr_inc") = 0xffffffff;
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 0);
                    sem_init(&x22_1[0x1a], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 1);
                    sem_init(&x22_1[0x1e], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 2);
                    sem_init(&x22_1[0x22], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 3);
                    sem_init(&x22_1[0x26], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 4);
                    sem_init(&x22_1[0x2a], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 5);
                    sem_init(&x22_1[0x2e], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 6);
                    sem_init(&x22_1[0x32], 0, 0);
                    sprintf(&s, "/p2psem03%d02%d", x20_1, 7);
                    sem_init(&x22_1[0x36], 0, 0);
                    *cs2p2p_gFlagUserBreakListen = 0;
                    strncpy(&x22_1[0x3a], cs2p2p_gP2PKeyString, 0x14);
                    strncpy((x22_1 + 0x17b), arg1, 8);
                    x22_1[0x63] = arg2;
                    strncpy((x22_1 + 0x183), arg3, 8);
                    uint32_t x8_6;
                    
                    if (arg4 < 0x19999999)
                        x8_6 = arg4;
                    else
                        x8_6 = 0x19999999;
                    
                    *cs2p2p_gListenTimeOut = x8_6;
                    
                    if (arg8 != 0)
                        strncpy(((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x100), arg8, 0x17);
                    
                    if (DO_APILicenseCheck((x22_1 + 0x17b), x22_1[0x63], arg7) != 0xffffffff)
                    {
                    label_1c76c:
                        time_t x0_35 = time(nullptr);
                        int32_t x0_36;
                        
                        if ((x0_35 - *cs2p2p_gLastNetDetectTime) > 0x15180)
                            x0_36 = cs2p2p_PPPP__DoNetWorkDetect(x0_35, 1, cs2p2p_gNetInfo, arg5, cs2p2p_gServerString, cs2p2p_gP2PServerAddr, (cs2p2p_gP2PServerAddr + 0x10), (cs2p2p_gP2PServerAddr + 0x20));
                        
                        if (((x0_35 - *cs2p2p_gLastNetDetectTime) <= 0x15180 || x0_36 == 0))
                        {
                            *x22_1 = cs2p2p_setup_Socket();
                            int32_t var_b4 = 1;
                            setsockopt();
                            srand(time(nullptr));
                            sockaddr_in var_78;
                            
                            if (cs2p2p_TryBind(*x22_1, arg5, &var_78) == 0xffffffff)
                            {
                                close(*x22_1);
                                pthread_mutex_lock(&data_50d02c);
                                memset(x22_1, 0, "PKciP11sockaddr_inc");
                                x22_1[0x5e] = 1;
                                *(x22_1 + 0x179) = 1;
                                *x22_1 = 0xffffffff;
                                pthread_mutex_unlock(&data_50d02c);
                                x20_1 = -0x12;
                            }
                            else
                            {
                                pthread_mutex_lock(&data_50d02c);
                                void* x19_2 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                *(x19_2 + 0x14) = 2;
                                *(x19_2 + 0x24) = 2;
                                cs2p2p_GetInetAddrByName((cs2p2p_gNetInfo + 4), (x19_2 + 0x18));
                                cs2p2p_GetInetAddrByName((cs2p2p_gNetInfo + 0x14), (x19_2 + 0x28));
                                pthread_mutex_unlock(&data_50d02c);
                                *(x19_2 + 0x54) = 0;
                                int16_t var_76;
                                *(x19_2 + 0x16) = var_76;
                                *(x19_2 + 0x26) = var_76;
                                *(x19_2 + 0x50) = 1;
                                *(x19_2 + 0x52) = 0;
                                sprintf((x19_2 + 0x38), "%s-%06d-%s", (x22_1 + 0x17b), x22_1[0x63], (x22_1 + 0x183));
                                
                                if (pthread_create((x19_2 + 0x118), 0, cs2p2p_PPPP_thread_recv_Proto, x21_1) == 0)
                                {
                                    if (pthread_create(((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x120), 0, cs2p2p_PPPP_thread_recv_LanSearch, x21_1) == 0)
                                    {
                                        *(x22_1 + 0x179) = 1;
                                        time_t x0_56;
                                        int128_t v0_1;
                                        x0_56 = time(nullptr);
                                        int32_t x28_4 = x0_5;
                                        void* x26_3 = (x19_2 + 0x54);
                                        int16_t* var_210;
                                        void* var_208;
                                        uint64_t var_200;
                                        
                                        if ((*cs2p2p_gListenTimeOut * 0xa) != 0)
                                        {
                                            int32_t var_16c_1 = 0;
                                            void* x8_23 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            uint32_t i_3 = 0;
                                            uint32_t i;
                                            
                                            do
                                            {
                                                int32_t x0_57;
                                                x0_57 = cs2p2p_CurrentTickCount();
                                                
                                                if ((x0_57 - x28_4) > (arg4 * 0x3e8))
                                                    break;
                                                
                                                if (i_3 != 0)
                                                {
                                                    if ((((i_3 % 0x12c) != 0 && i_3 != 0x1e) && i_3 != 0xa))
                                                        goto label_1cdc8;
                                                    
                                                    s = 0x104;
                                                    *s[2] = 3;
                                                    
                                                    if (var_ec_1 != 0)
                                                        goto label_1cbe4;
                                                    
                                                    goto label_1cdc8;
                                                }
                                                
                                                if (var_ec_1 == 0)
                                                {
                                                    s = 0x104;
                                                    *s[2] = 3;
                                                label_1cdc8:
                                                    
                                                    if ((*x26_3 == 0 && (*(x22_1 + 0x179) & 0x80000000) == 0))
                                                    {
                                                    label_1ce00:
                                                        i = (i_3 + 1);
                                                        
                                                        if (var_ec_1 != 2)
                                                            cs2p2p_mSecSleep(0x64);
                                                        else
                                                        {
                                                            if (i_3 == 0)
                                                            {
                                                                *(x8_23 + "PPP_Proto_Send_DevLgnAckPKciP11s…") = time(nullptr);
                                                                *(x8_23 + "o_Send_DevLgnAckPKciP11sockaddr_…") = cs2p2p_CurrentTickCount();
                                                                void var_80;
                                                                sprintf(&var_80, "Server%d", 1);
                                                                char* x0_71 = cs2_SA_GetIPString(cs2p2p_gP2PServerAddr, &s, 0x30);
                                                                char* s1 = malloc(0x50);
                                                                
                                                                if (s1 != 0)
                                                                {
                                                                    memset(s1, 0, 0x50);
                                                                    int16_t* x0_74 = malloc(0x100);
                                                                    *(s1 + 0x30) = x0_74;
                                                                    
                                                                    if (x0_74 == 0)
                                                                    {
                                                                        free(s1);
                                                                        s1 = nullptr;
                                                                    }
                                                                    else
                                                                    {
                                                                        *x0_74 = 0;
                                                                        cs2_SA_SetSockAddr(2, x0_71, 0x7d6e, &s1[0xc]);
                                                                        *(s1 + 8) = 0xffffffff;
                                                                        *(s1 + 0x38) = 0x100;
                                                                        strncpy(s1, &var_80, 7);
                                                                    }
                                                                }
                                                                
                                                                *(x8_23 + "PPP_Proto_Send_ByteCountPKciP11s…") = s1;
                                                                sprintf(&var_80, "Server%d", 2);
                                                                char* x0_79 = cs2_SA_GetIPString((cs2p2p_gP2PServerAddr + 0x10), &s, 0x30);
                                                                char* s1_1 = malloc(0x50);
                                                                
                                                                if (s1_1 != 0)
                                                                {
                                                                    memset(s1_1, 0, 0x50);
                                                                    int16_t* x0_82 = malloc(0x100);
                                                                    *(s1_1 + 0x30) = x0_82;
                                                                    
                                                                    if (x0_82 == 0)
                                                                    {
                                                                        free(s1_1);
                                                                        s1_1 = nullptr;
                                                                    }
                                                                    else
                                                                    {
                                                                        *x0_82 = 0;
                                                                        cs2_SA_SetSockAddr(2, x0_79, 0x7d6e, &s1_1[0xc]);
                                                                        *(s1_1 + 8) = 0xffffffff;
                                                                        *(s1_1 + 0x38) = 0x100;
                                                                        strncpy(s1_1, &var_80, 7);
                                                                    }
                                                                }
                                                                
                                                                *(x8_23 + "o_Send_ByteCountPKciP11sockaddr_…") = s1_1;
                                                                sprintf(&var_80, "Server%d", 3);
                                                                char* x0_87 = cs2_SA_GetIPString((cs2p2p_gP2PServerAddr + 0x20), &s, 0x30);
                                                                char* s1_2 = malloc(0x50);
                                                                
                                                                if (s1_2 != 0)
                                                                {
                                                                    memset(s1_2, 0, 0x50);
                                                                    int16_t* x0_90 = malloc(0x100);
                                                                    *(s1_2 + 0x30) = x0_90;
                                                                    
                                                                    if (x0_90 == 0)
                                                                    {
                                                                        free(s1_2);
                                                                        s1_2 = nullptr;
                                                                    }
                                                                    else
                                                                    {
                                                                        *x0_90 = 0;
                                                                        cs2_SA_SetSockAddr(2, x0_87, 0x7d6e, &s1_2[0xc]);
                                                                        *(s1_2 + 8) = 0xffffffff;
                                                                        *(s1_2 + 0x38) = 0x100;
                                                                        strncpy(s1_2, &var_80, 7);
                                                                    }
                                                                }
                                                                
                                                                *(x8_23 + "yteCountPKciP11sockaddr_inj") = s1_2;
                                                            }
                                                            
                                                            if (*(x8_23 + "d_DevLgnAckPKciP11sockaddr_inc") == 0)
                                                            {
                                                                uint64_t x8_58;
                                                                uint64_t x9_14;
                                                                
                                                                if ((cs2p2p_CurrentTickCount() - *(x8_23 + "o_Send_DevLgnAckPKciP11sockaddr_…")) <= 0x7d0)
                                                                {
                                                                    x9_14 = *cs2p2p_gLastSuccessLoginTime;
                                                                    x8_58 = *cs2p2p_gLastHelloAckTime;
                                                                label_1d0c0:
                                                                    uint64_t x10_4 = *cs2p2p_gLastListenStartTime;
                                                                    
                                                                    if ((x10_4 > x9_14 && x10_4 > x8_58))
                                                                        *(x8_23 + "d_DevLgnAckPKciP11sockaddr_inc") = 1;
                                                                }
                                                                else
                                                                {
                                                                    int64_t x10_3 = *(x8_23 + "PPP_Proto_Send_DevLgnAckPKciP11s…");
                                                                    x9_14 = *cs2p2p_gLastSuccessLoginTime;
                                                                    x8_58 = *cs2p2p_gLastHelloAckTime;
                                                                    
                                                                    if ((x10_3 <= x9_14 || x10_3 <= x8_58))
                                                                        goto label_1d0c0;
                                                                    
                                                                    *(x8_23 + "d_DevLgnAckPKciP11sockaddr_inc") = 1;
                                                                }
                                                            }
                                                            
                                                            if ((cs2p2p_CurrentTickCount() - var_16c_1) >= 0xea61)
                                                            {
                                                                var_16c_1 = cs2p2p_CurrentTickCount();
                                                                void* x8_62 = *(x8_23 + "PPP_Proto_Send_ByteCountPKciP11s…");
                                                                
                                                                if (arg8 == 0)
                                                                {
                                                                    *(x8_62 + 0x47) = 1;
                                                                    *(*(x8_23 + "o_Send_ByteCountPKciP11sockaddr_…") + 0x47) = 1;
                                                                    *(*(x8_23 + "yteCountPKciP11sockaddr_inj") + 0x47) = 1;
                                                                }
                                                                else
                                                                {
                                                                    *(x8_62 + 0x46) = 1;
                                                                    *(*(x8_23 + "o_Send_ByteCountPKciP11sockaddr_…") + 0x46) = 1;
                                                                    *(*(x8_23 + "yteCountPKciP11sockaddr_inj") + 0x46) = 1;
                                                                }
                                                            }
                                                            
                                                            int32_t j = -1;
                                                            int32_t x0_96 = cs2p2p_CurrentTickCount();
                                                            
                                                            do
                                                            {
                                                                if (*(x8_23 + "d_DevLgnAckPKciP11sockaddr_inc") == 1)
                                                                {
                                                                    if (arg8 == 0)
                                                                    {
                                                                        cs2p2p_Do_TCPConnect(x20_1, 1);
                                                                        cs2p2p_Do_TCPSendDevLgn(x20_1);
                                                                    }
                                                                    else
                                                                    {
                                                                        cs2p2p_Do_TCPConnect(x20_1, 2);
                                                                        cs2p2p_Do_TCPSendDevLgnDSK(x20_1);
                                                                    }
                                                                    
                                                                    cs2p2p_Do_TCPRecv(x20_1);
                                                                }
                                                                
                                                                if (*(x8_23 + "nd_DevLgnAckPKciP11sockaddr_inc") != 0)
                                                                {
                                                                    cs2p2p_PPPP_TCPRelay_Setup(x20_1);
                                                                    i = (*cs2p2p_gListenTimeOut * 0xa);
                                                                    break;
                                                                }
                                                                
                                                                int32_t x0_102;
                                                                x0_102 = cs2p2p_CurrentTickCount();
                                                                
                                                                if ((x0_102 - x0_96) > 0x63)
                                                                    break;
                                                                
                                                                cs2p2p_mSecSleep(0xa);
                                                                j += 1;
                                                            } while (j < 9);
                                                        }
                                                        
                                                        if ((i % 0xa) == 0)
                                                            *(x8_23 + 0x5b) = 0;
                                                    }
                                                    else
                                                        i = (*cs2p2p_gListenTimeOut * 0xa);
                                                }
                                                else
                                                {
                                                    int32_t* x22_6 = x22_1;
                                                    cs2p2p_PPPP_Proto_Send_Hello(&x22_1[0x3a], *x22_6, cs2p2p_gP2PServerAddr);
                                                    cs2p2p_PPPP_Proto_Send_Hello(&x22_1[0x3a], *x22_6, (cs2p2p_gP2PServerAddr + 0x10));
                                                    cs2p2p_PPPP_Proto_Send_Hello(&x22_1[0x3a], *x22_6, (cs2p2p_gP2PServerAddr + 0x20));
                                                    s = 0x104;
                                                    *s[2] = 3;
                                                label_1cbe4:
                                                    *x22_1;
                                                    x22_1[0x63];
                                                    *(cs2p2p_gNetInfo + 3);
                                                    uint64_t x8_32 = *cs2p2p_gCRCKey;
                                                    
                                                    if (arg8 == 0)
                                                    {
                                                        int16_t* var_210_3 = (x19_2 + 0x14);
                                                        uint64_t var_208_3 = x8_32;
                                                        cs2p2p_PPPP_Proto_Send_DevLgn_CRC();
                                                        *x22_1;
                                                        x22_1[0x63];
                                                        *(cs2p2p_gNetInfo + 3);
                                                        int16_t* var_210_4 = (x19_2 + 0x14);
                                                        uint64_t var_208_4 = *cs2p2p_gCRCKey;
                                                        cs2p2p_PPPP_Proto_Send_DevLgn_CRC();
                                                        *x22_1;
                                                        x22_1[0x63];
                                                        *(cs2p2p_gNetInfo + 3);
                                                        var_210 = (x19_2 + 0x14);
                                                        var_208 = *cs2p2p_gCRCKey;
                                                        cs2p2p_PPPP_Proto_Send_DevLgn_CRC();
                                                    }
                                                    else
                                                    {
                                                        int16_t* var_210_1 = (x19_2 + 0x14);
                                                        void* var_208_1 = (x8_23 + 0x100);
                                                        uint64_t var_200_1 = x8_32;
                                                        cs2p2p_PPPP_Proto_Send_DevLgn_DSK();
                                                        *x22_1;
                                                        x22_1[0x63];
                                                        uint64_t var_200_2 = *cs2p2p_gCRCKey;
                                                        *(cs2p2p_gNetInfo + 3);
                                                        int16_t* var_210_2 = (x19_2 + 0x14);
                                                        void* var_208_2 = (x8_23 + 0x100);
                                                        cs2p2p_PPPP_Proto_Send_DevLgn_DSK();
                                                        *x22_1;
                                                        x22_1[0x63];
                                                        var_200 = *cs2p2p_gCRCKey;
                                                        *(cs2p2p_gNetInfo + 3);
                                                        var_210 = (x19_2 + 0x14);
                                                        var_208 = (x8_23 + 0x100);
                                                        cs2p2p_PPPP_Proto_Send_DevLgn_DSK();
                                                    }
                                                    
                                                    x26_3 = (x19_2 + 0x54);
                                                    x28_4 = x0_5;
                                                    
                                                    if ((*x26_3 == 0 && (*(x22_1 + 0x179) & 0x80000000) == 0))
                                                        goto label_1ce00;
                                                    
                                                    i = (*cs2p2p_gListenTimeOut * 0xa);
                                                }
                                                
                                                i_3 = i;
                                            } while (i < (*cs2p2p_gListenTimeOut * 0xa));
                                        }
                                        
                                        int64_t x8_84 = *(x22_1 + 0x179);
                                        void* x11_4;
                                        int64_t* x23_7;
                                        char x25_5;
                                        int16_t* x26_6;
                                        
                                        if ((x8_84 & 0xffffffff80000000) != 0)
                                        {
                                            x25_5 = var_ec_1;
                                            x11_4 = (x19_2 + 0x52);
                                            x23_7 = ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x120);
                                            
                                            if ((x8_84 & 0xff) <= 0xfb)
                                                x20_1 = 0;
                                            else
                                                x20_1 = *((x8_84 << 2) + &data_2417c);
                                            
                                            x26_6 = (x19_2 + 0x14);
                                        }
                                        else
                                        {
                                            x25_5 = var_ec_1;
                                            x11_4 = (x19_2 + 0x52);
                                            x23_7 = ((cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc")) + 0x120);
                                            uint32_t x8_87;
                                            
                                            if (x25_5 == 2)
                                                x8_87 = *"DevLgnAckPKciP11sockaddr_inc"[(cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"))];
                                            
                                            if ((x25_5 != 2 || x8_87 == 0))
                                            {
                                                x26_6 = (x19_2 + 0x14);
                                                
                                                if (*x26_3 == 0)
                                                {
                                                    if (*cs2p2p_gFlagUserBreakListen == 0)
                                                        x20_1 = -3;
                                                    else
                                                        x20_1 = -0x10;
                                                }
                                            }
                                            else
                                            {
                                                if (x8_87 == 1)
                                                {
                                                    *x26_3 = x8_87;
                                                    void* x8_88 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                                    *(x8_88 + 0x51) = 2;
                                                    *(x8_88 + 4) = *(x8_88 + "P11sockaddr_inj");
                                                }
                                                else if (*cs2p2p_gFlagUserBreakListen == 0)
                                                    x20_1 = -0x18;
                                                else
                                                    x20_1 = -0x10;
                                                
                                                x26_6 = (x19_2 + 0x14);
                                            }
                                        }
                                        
                                        *x11_4 = 1;
                                        int64_t x0_104 = *(x19_2 + 0x118);
                                        
                                        if (x0_104 != 0)
                                        {
                                            pthread_join(x0_104, 0);
                                            *(x19_2 + 0x118) = 0;
                                        }
                                        
                                        int64_t x0_105 = *x23_7;
                                        
                                        if (x0_105 != 0)
                                        {
                                            pthread_join(x0_105, 0);
                                            *x23_7 = 0;
                                        }
                                        
                                        if (x25_5 == 2)
                                        {
                                            int64_t x8_94 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            void* x19_7 = *(x8_94 + "PPP_Proto_Send_ByteCountPKciP11s…");
                                            
                                            if (x19_7 != 0)
                                            {
                                                int32_t x0_106 = *(x19_7 + 8);
                                                
                                                if ((x0_106 & 0x80000000) == 0)
                                                    cs2_TCPNBSkt_Close(x0_106);
                                                
                                                int64_t x0_107 = *(x19_7 + 0x30);
                                                
                                                if (x0_107 != 0)
                                                    free(x0_107);
                                                
                                                free(x19_7);
                                                *(x8_94 + "PPP_Proto_Send_ByteCountPKciP11s…") = 0;
                                            }
                                            
                                            int64_t x8_95 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            void* x19_8 = *(x8_95 + "o_Send_ByteCountPKciP11sockaddr_…");
                                            
                                            if (x19_8 != 0)
                                            {
                                                int32_t x0_109 = *(x19_8 + 8);
                                                
                                                if ((x0_109 & 0x80000000) == 0)
                                                    cs2_TCPNBSkt_Close(x0_109);
                                                
                                                int64_t x0_110 = *(x19_8 + 0x30);
                                                
                                                if (x0_110 != 0)
                                                    free(x0_110);
                                                
                                                free(x19_8);
                                                *(x8_95 + "o_Send_ByteCountPKciP11sockaddr_…") = 0;
                                            }
                                            
                                            int64_t x8_96 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            void* x19_9 = *(x8_96 + "yteCountPKciP11sockaddr_inj");
                                            
                                            if (x19_9 != 0)
                                            {
                                                int32_t x0_112 = *(x19_9 + 8);
                                                
                                                if ((x0_112 & 0x80000000) == 0)
                                                    cs2_TCPNBSkt_Close(x0_112);
                                                
                                                int64_t x0_113 = *(x19_9 + 0x30);
                                                
                                                if (x0_113 != 0)
                                                    free(x0_113);
                                                
                                                free(x19_9);
                                                *(x8_96 + "yteCountPKciP11sockaddr_inj") = 0;
                                            }
                                        }
                                        
                                        int64_t i_4 = 0x100;
                                        void* x19_10 = (cs2p2p_gSession + "PKciP11sockaddr_inc");
                                        int32_t x0_115 = cs2p2p_CurrentTickCount();
                                        int32_t x8_97 = 0;
                                        int32_t x9_18 = 0;
                                        int64_t (* const x11_5)() = cs2p2p_gSession;
                                        int64_t i_1;
                                        
                                        do
                                        {
                                            int32_t x13_1 = *x19_10;
                                            x19_10 += cs2p2p_PPPP_Proto_Send_ReportSessionRdy;
                                            i_1 = i_4;
                                            i_4 -= 2;
                                            x8_97 += ((*x11_5 >> 0x1f) ^ 1);
                                            x9_18 += ((x13_1 >> 0x1f) ^ 1);
                                            x11_5 += cs2p2p_PPPP_Proto_Send_ReportSessionRdy;
                                        } while (i_1 != 2);
                                        *x22_1;
                                        int32_t x9_19 = (x9_18 + x8_97);
                                        void* x23_11 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                        int32_t x12_8 = (x0_115 - x0_5);
                                        void* var_f8_1;
                                        var_f8_1 = x9_19;
                                        void* var_c8_1;
                                        var_c8_1 = x12_8;
                                        char var_1d0_1 = *(x23_11 + 0x64);
                                        char var_1d8_1 = x25_5;
                                        int16_t var_1e0_1 = x12_8;
                                        int16_t* var_1f8_1 = x26_6;
                                        int16_t* var_1f0_1 = (x19_2 + 0x24);
                                        void* var_1e8_1 = (x23_11 + 4);
                                        var_200 = x9_19;
                                        *(x23_11 + 0x51);
                                        var_208 = 0x100;
                                        var_210 = *(x19_2 + 0x50);
                                        cs2p2p_PPPP_Proto_Send_ReportSessionRdy();
                                        *x22_1;
                                        char var_1d0_2 = *(x23_11 + 0x64);
                                        char var_1d8_2 = x25_5;
                                        int16_t* var_1f8_2 = x26_6;
                                        int16_t var_1e0_2 = var_c8_1;
                                        *(x23_11 + 0x51);
                                        int16_t* var_1f0_2 = (x19_2 + 0x24);
                                        void* var_1e8_2 = (x23_11 + 4);
                                        int16_t x25_7 = var_f8_1;
                                        var_208 = 0x100;
                                        var_200 = x25_7;
                                        var_210 = *(x19_2 + 0x50);
                                        cs2p2p_PPPP_Proto_Send_ReportSessionRdy();
                                        char var_1d8_3 = x25_5;
                                        var_200 = x25_7;
                                        char var_1d0_3 = *(x23_11 + 0x64);
                                        *x22_1;
                                        *(x23_11 + 0x51);
                                        int16_t var_1e0_3 = var_c8_1;
                                        void* var_1e8_3 = (x23_11 + 4);
                                        int16_t* var_1f8_3 = (x19_2 + 0x14);
                                        int16_t* var_1f0_3 = (x19_2 + 0x24);
                                        var_208 = 0x100;
                                        var_210 = *(x19_2 + 0x50);
                                        cs2p2p_PPPP_Proto_Send_ReportSessionRdy();
                                        
                                        if ((x20_1 & 0x80000000) != 0)
                                        {
                                            close(*x22_1);
                                            pthread_mutex_lock(&data_50d02c);
                                            memset(x22_1, 0, "PKciP11sockaddr_inc");
                                            x22_1[0x5e] = 1;
                                            *(x22_1 + 0x179) = 1;
                                            *x22_1 = 0xffffffff;
                                            pthread_mutex_unlock(&data_50d02c);
                                        }
                                        else
                                        {
                                            pthread_mutex_lock(&data_50d02c);
                                            void* x22_13 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            *(x22_13 + 0x53) = 0;
                                            pthread_mutex_unlock(&data_50d02c);
                                            
                                            for (int64_t i_2 = 0; i_2 != 0x100; )
                                            {
                                                void* x12_9 = (x22_13 + i_2);
                                                *(x12_9 + 0x4b0) = 0;
                                                *(x12_9 + 0x4b0) = 0x10000;
                                                __builtin_memset((x12_9 + 0x498), 0, 0x18);
                                                int64_t s_1 = ((x22_13 + "n") + i_2);
                                                *(x12_9 + 0x3b0) = 0;
                                                *(x12_9 + 0x3b0) = 0x10000;
                                                __builtin_memset((x12_9 + 0x398), 0, 0x18);
                                                *(x12_9 + 0x2b0) = 0;
                                                *(x12_9 + 0x2b0) = 0x10000;
                                                __builtin_memset((x12_9 + 0x298), 0, 0x18);
                                                *(x12_9 + 0x1a8) = 0;
                                                *(x12_9 + 0x1b0) = 0;
                                                *(x12_9 + 0x1b0) = 0x10000;
                                                *(x12_9 + 0x198) = 0;
                                                *(x12_9 + 0x1a0) = 0;
                                                *((x22_13 + "TCPSend_AlivePKcijPc") + i_2) = 0;
                                                *((x22_13 + "TCPSend_AlivePKcijPc") + i_2) = 0x10000;
                                                i_2 += 0x20;
                                                __builtin_memset(s_1, 0, 0x18);
                                            }
                                            
                                            int64_t x19_12 = (cs2p2p_gSession + (x21_1 * "PKciP11sockaddr_inc"));
                                            pthread_create((x19_12 + 0x128), 0, cs2p2p_PPPP_thread_recv_DRW, x21_1);
                                            pthread_create((x19_12 + 0x130), 0, cs2p2p_PPPP_thread_send_DRW, x21_1);
                                        }
                                        
                                        if (x25_5 == 2)
                                            *cs2p2p_gLastListenStartTime = x0_56;
                                    }
                                    else
                                    {
                                        *(x19_2 + 0x52) = 1;
                                        int64_t x0_53 = *(x19_2 + 0x118);
                                        
                                        if (x0_53 != 0)
                                        {
                                            pthread_join(x0_53, 0);
                                            *(x19_2 + 0x118) = 0;
                                        }
                                        
                                        close(*x22_1);
                                        pthread_mutex_lock(&data_50d02c);
                                        memset(x22_1, 0, "PKciP11sockaddr_inc");
                                        x22_1[0x5e] = 1;
                                        *(x22_1 + 0x179) = 1;
                                        *x22_1 = 0xffffffff;
                                        pthread_mutex_unlock(&data_50d02c);
                                        x20_1 = -0x16;
                                    }
                                }
                                else
                                {
                                    close(*x22_1);
                                    pthread_mutex_lock(&data_50d02c);
                                    memset(x22_1, 0, "PKciP11sockaddr_inc");
                                    x22_1[0x5e] = 1;
                                    *(x22_1 + 0x179) = 1;
                                    *x22_1 = 0xffffffff;
                                    pthread_mutex_unlock(&data_50d02c);
                                    x20_1 = -0x16;
                                }
                            }
                        }
                        else
                        {
                            pthread_mutex_lock(&data_50d02c);
                            memset(x22_1, 0, "PKciP11sockaddr_inc");
                            x22_1[0x5e] = 1;
                            *(x22_1 + 0x179) = 1;
                            *x22_1 = 0xffffffff;
                            pthread_mutex_unlock(&data_50d02c);
                            x20_1 = x0_36;
                        }
                    }
                    else
                    {
                        if (DO_APILicenseCheck_PPPP((x22_1 + 0x17b), x22_1[0x63], arg7) != 0xffffffff)
                            goto label_1c76c;
                        
                        if (DO_APILicenseCheck_RTOS((x22_1 + 0x17b), x22_1[0x63], arg7) != 0xffffffff)
                            goto label_1c76c;
                        
                        if (DO_APILicenseCheck_IoTWIFI((x22_1 + 0x17b), x22_1[0x63], arg7) != 0xffffffff)
                            goto label_1c76c;
                        
                        cs2p2p_mSecSleep(0x1388);
                        x20_1 = -0x15;
                    }
                    
                    break;
                }
            }
        }
        else
            x20_1 = -4;
    }
    else
        x20_1 = -5;
    
    if (*(x24 + 0x28) == x8)
        return x20_1;
    
    __stack_chk_fail();
    /* no return */
}

