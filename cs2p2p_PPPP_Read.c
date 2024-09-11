
uint64_t cs2p2p_PPPP_Read(int32_t arg1, char arg2, int64_t arg3, int32_t* arg4, int32_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t x24 = cs2p2p_CurrentTickCount();
    int32_t x0_1 = cs2p2p_CurrentTickCount();
    int32_t x28;
    
    if (*cs2p2p_gFlagInitialized == 0)
        x28 = -1;
    else
    {
        x28 = -5;
        
        if ((arg3 != 0 && (arg2 <= 7 && arg4 != 0)))
        {
            if (*arg4 == 0)
                x28 = -5;
            else
            {
                void* x11_1;
                
                if (arg1 < 0x101)
                    x11_1 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
                
                if ((arg1 >= 0x101 || *x11_1 == 0xffffffff))
                {
                    *arg4 = 0;
                    x28 = -0xb;
                }
                else
                {
                    int64_t x9_1 = arg1;
                    
                    if (*((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
                    {
                        *arg4 = 0;
                        x28 = -0xe;
                    }
                    else if (*((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x58) != 1)
                    {
                        pthread_mutex_lock(&data_50d02c);
                        uint64_t x23_1 = arg2;
                        int64_t x8_9 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + (x23_1 << 1));
                        uint64_t x8_10 = *(x8_9 + "d_RlyPortPKciP11sockaddr_in");
                        uint64_t x9_3 = *(x8_9 + "sockaddr_in");
                        uint64_t x12_3 = *arg4;
                        uint64_t x28_1 = (x9_3 - x8_10);
                        int32_t x3;
                        uint64_t x10_5;
                        char* x25_3;
                        
                        if (x28_1 >= x12_3)
                        {
                            int64_t x9_8 = (cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc"));
                            *((x9_8 + (x23_1 << 2)) + "o_Send_RlyHelloPKciP11sockaddr_i…") = 0;
                            memcpy(arg3, (((x9_8 + (x23_1 << 0xa)) + x8_10) + 0x25b8), x12_3);
                            x10_5 = x12_3;
                            x3 = 0;
                            *(x8_9 + "d_RlyPortPKciP11sockaddr_in") += x10_5;
                            x25_3 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57);
                        label_20bec:
                            int32_t x22_2 = x10_5;
                            pthread_mutex_unlock(&data_50d02c);
                            
                            if (*arg4 != x22_2)
                            {
                                *arg4 = x22_2;
                                
                                if ((x24 - x0_1) >= arg5)
                                    x28 = -3;
                                else
                                {
                                    uint32_t x8_84 = x3;
                                    
                                    if ((x8_84 == 1 && *((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x55) == 1))
                                        x28 = -0xd;
                                    else if ((x8_84 == 1 && *((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x56) == 1))
                                        x28 = -0xc;
                                    else if (*x25_3 == 1)
                                        x28 = -0xe;
                                    else if (*((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
                                        x28 = -0x14;
                                    else
                                        x28 = 0;
                                }
                            }
                            else
                                x28 = 0;
                        }
                        else
                        {
                            int64_t var_e0_1;
                            uint64_t x25_2;
                            
                            if (x9_3 <= x8_10)
                            {
                                x28_1 = 0;
                                x25_2 = x12_3;
                                var_e0_1 = arg3;
                            }
                            else
                            {
                                int64_t x9_4 = (cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc"));
                                *((x9_4 + (x23_1 << 2)) + "o_Send_RlyHelloPKciP11sockaddr_i…") = 0;
                                memcpy(arg3, (((x9_4 + (x23_1 << 0xa)) + x8_10) + 0x25b8), x28_1);
                                var_e0_1 = (arg3 + x28_1);
                                x25_2 = (*arg4 - x28_1);
                                *(x8_9 + "d_RlyPortPKciP11sockaddr_in") = *(x8_9 + "sockaddr_in");
                            }
                            
                            x24 = cs2p2p_CurrentTickCount();
                            uint64_t x2_2 = x25_2;
                            x3 = 0;
                            
                            if (x25_2 < 1)
                            {
                                x25_3 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57);
                                x10_5 = x28_1;
                                goto label_20bec;
                            }
                            
                            void* x8_17 = (cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc"));
                            void* x18_2 = (x8_17 + (x23_1 << 5));
                            void* x11_11 = &*"sockaddr_in"[x8_9];
                            x25_3 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57);
                            int32_t* x12_4 = (x18_2 + 0x4a8);
                            void* x13_1 = ((x8_17 + "o_Send_RlyHelloPKciP11sockaddr_i…") + (x23_1 << 2));
                            x10_5 = x28_1;
                            int32_t* var_d8_1 = x12_4;
                            void* var_d0_1 = x13_1;
                            
                            while (true)
                            {
                                int32_t x23_2 = (x24 - x0_1);
                                
                                if (x23_2 >= arg5)
                                    goto label_20bec;
                                
                                int32_t* x28_2;
                                
                                if (*x12_4 != 0)
                                    x28_2 = *(x18_2 + 0x498);
                                
                                if ((*x12_4 == 0 || *x28_2 != *((x8_17 + (x23_1 << 1)) + 0x5a8)))
                                    x3 = 1;
                                else if (x28_2 == 0)
                                    *((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x58) = 1;
                                else
                                {
                                    int32_t var_a0_1 = x2_2;
                                    int32_t var_98_1 = x10_5;
                                    void* x8_27 = *(x28_2 + 0x20);
                                    int64_t* x8_29;
                                    
                                    if (x8_27 == 0)
                                        x8_29 = (x18_2 + 0x498);
                                    else
                                        x8_29 = (x8_27 + 0x18);
                                    
                                    *x8_29 = *(x28_2 + 0x18);
                                    void* x8_30 = *(x28_2 + 0x18);
                                    int64_t* x8_32;
                                    
                                    if (x8_30 == 0)
                                        x8_32 = (x18_2 + 0x4a0);
                                    else
                                        x8_32 = (x8_30 + 0x20);
                                    
                                    *x8_32 = *(x28_2 + 0x20);
                                    *(x28_2 + 0x18) = 0;
                                    *(x28_2 + 0x20) = 0;
                                    *x12_4 -= 1;
                                    uint64_t x2_3 = x28_2[1];
                                    *(x18_2 + 0x4ac) -= x2_3;
                                    *x11_11 = x2_3;
                                    memcpy(((x8_17 + (x23_1 << 0xa)) + 0x25b8), *(x28_2 + 8), x2_3);
                                    int64_t x0_8 = *(x28_2 + 8);
                                    
                                    if (x0_8 != 0)
                                        free(x0_8);
                                    
                                    free(x28_2);
                                    *((x8_17 + (x23_1 << 1)) + 0x5a8) += 1;
                                    uint64_t x28_3 = *(x8_9 + "sockaddr_in");
                                    *var_d0_1 = 0;
                                    int16_t x8_40;
                                    
                                    if (var_a0_1 <= x28_3)
                                    {
                                        memcpy(var_e0_1, ((x8_17 + (x23_1 << 0xa)) + 0x25b8), var_a0_1);
                                        x10_5 = (var_98_1 + var_a0_1);
                                        x8_40 = var_a0_1;
                                        x2_2 = (*arg4 - x10_5);
                                    }
                                    else
                                    {
                                        memcpy(var_e0_1, ((x8_17 + (x23_1 << 0xa)) + 0x25b8), x28_3);
                                        x8_40 = *(x8_9 + "sockaddr_in");
                                        x10_5 = (var_98_1 + x28_3);
                                        x2_2 = (*arg4 - x10_5);
                                    }
                                    
                                    x11_11 = &*"sockaddr_in"[x8_9];
                                    x25_3 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57);
                                    x12_4 = var_d8_1;
                                    x3 = 0;
                                    *(x8_9 + "d_RlyPortPKciP11sockaddr_in") = x8_40;
                                    
                                    if (x2_2 == 0)
                                        goto label_20bec;
                                    
                                    x13_1 = var_d0_1;
                                    var_e0_1 = (arg3 + x10_5);
                                }
                                
                                if (*x25_3 == 1)
                                    goto label_20bec;
                                
                                if (*((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
                                    goto label_20bec;
                                
                                if (((x3 & 0xff) == 1 && (*(x8_17 + 0x55) == 1 || *(x8_17 + 0x56) == 1)))
                                {
                                    x3 = 1;
                                    goto label_20bec;
                                }
                                
                                int32_t var_c4_1;
                                uint64_t var_a0_2;
                                uint64_t var_98_2;
                                int64_t var_78;
                                uint32_t x24_1;
                                
                                if (*x12_4 == 0)
                                {
                                    uint32_t x8_58 = (arg5 - x23_2);
                                    var_c4_1 = x3;
                                    var_a0_2 = x2_2;
                                    var_98_2 = x10_5;
                                    *x13_1 = 0;
                                    
                                    if (x8_58 < 0xa)
                                        x24_1 = x8_58;
                                    else
                                        x24_1 = 0xa;
                                    
                                    pthread_mutex_unlock(&data_50d02c);
                                    var_78 = 0;
                                    uint64_t var_70_1 = ((x24_1 % 0x3e8) * 0xf4240);
                                    int32_t i;
                                    
                                    do
                                        i = sem_trywait(((x8_17 + (x23_1 << 4)) + 0x68));
                                     while (i == 0);
                                label_20b44:
                                    
                                    if ((sem_timedwait(((x8_17 + (x23_1 << 4)) + 0x68), &var_78) != 0 && *__errno() != 0x6e))
                                        cs2p2p_mSecSleep(x24_1);
                                    
                                    pthread_mutex_lock(&data_50d02c);
                                    
                                    if (*x11_1 == 0xffffffff)
                                    {
                                        x28 = -0xb;
                                        *arg4 = 0;
                                    }
                                    else
                                        x28 = 0;
                                    
                                    if (*x25_3 == 1)
                                    {
                                        x28 = -0xe;
                                        *arg4 = 0;
                                    }
                                    
                                    if (*((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
                                    {
                                        *arg4 = 0;
                                        x28 = -0x14;
                                        pthread_mutex_unlock(&data_50d02c);
                                        break;
                                    }
                                    
                                    if (x28 != 0)
                                    {
                                        pthread_mutex_unlock(&data_50d02c);
                                        break;
                                    }
                                    
                                    x11_11 = &*"sockaddr_in"[x8_9];
                                    x2_2 = var_a0_2;
                                    x10_5 = var_98_2;
                                    x3 = var_c4_1;
                                    x12_4 = var_d8_1;
                                    x13_1 = var_d0_1;
                                    x24 = cs2p2p_CurrentTickCount();
                                }
                                else if (**(x18_2 + 0x498) != *((x8_17 + (x23_1 << 1)) + 0x5a8))
                                {
                                    int32_t x28_5 = *x13_1;
                                    var_c4_1 = x3;
                                    var_a0_2 = x2_2;
                                    var_98_2 = x10_5;
                                    int32_t x0_12 = time(nullptr);
                                    
                                    if (x28_5 == 0)
                                    {
                                        *(x8_17 + "o_Send_RlyHelloPKciP11sockaddr_i…") = x0_12;
                                        *(x8_17 + "nd_RlyHelloPKciP11sockaddr_in") = time(nullptr);
                                        *(x8_17 + "lyHelloPKciP11sockaddr_in") = time(nullptr);
                                        *(x8_17 + "lloPKciP11sockaddr_in") = time(nullptr);
                                        *(x8_17 + "KciP11sockaddr_in") = time(nullptr);
                                        *(x8_17 + "11sockaddr_in") = time(nullptr);
                                        *(x8_17 + "ckaddr_in") = time(nullptr);
                                        x25_3 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57);
                                        *(x8_17 + "dr_in") = time(nullptr);
                                    }
                                    else
                                    {
                                        x25_3 = ((cs2p2p_gSession + (x9_1 * "PKciP11sockaddr_inc")) + 0x57);
                                        
                                        if ((x0_12 - *x13_1) >= 6)
                                        {
                                            x10_5 = var_98_2;
                                            x3 = 1;
                                            *(x8_17 + 0x55) = 1;
                                            goto label_20bec;
                                        }
                                    }
                                    
                                    uint32_t x8_71 = (arg5 - x23_2);
                                    
                                    if (x8_71 < 0xa)
                                        x24_1 = x8_71;
                                    else
                                        x24_1 = 0xa;
                                    
                                    pthread_mutex_unlock(&data_50d02c);
                                    var_78 = 0;
                                    uint64_t var_70_2 = ((x24_1 % 0x3e8) * 0xf4240);
                                    int32_t i_1;
                                    
                                    do
                                        i_1 = sem_trywait(((x8_17 + (x23_1 << 4)) + 0x68));
                                     while (i_1 == 0);
                                    goto label_20b44;
                                }
                                
                                if (x2_2 <= 0)
                                    goto label_20bec;
                            }
                        }
                    }
                    else
                    {
                        *arg4 = 0;
                        x28 = -0x14;
                    }
                }
            }
        }
    }
    
    if (*(x26 + 0x28) == x8)
        return x28;
    
    __stack_chk_fail();
    /* no return */
}

