
int64_t cs2p2p_PPPP_PktRecv(int32_t arg1, char arg2, int64_t arg3, int32_t* arg4, int32_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t x0 = cs2p2p_CurrentTickCount();
    int64_t result;
    
    if (*cs2p2p_gFlagInitialized == 0)
        result = 0xffffffff;
    else
    {
        result = 0xfffffffb;
        
        if ((arg2 <= 7 && arg3 != 0))
        {
            int32_t x28_1 = *arg4;
            
            if (x28_1 < 1)
                result = 0xfffffffb;
            else
            {
                *arg4 = 0;
                
                if ((arg1 > 0x100 || *(cs2p2p_gSession + (arg1 * 0x4d38)) == 0xffffffff))  {  // {"PKciP11sockaddr_inc"}}
                    result = 0xfffffff5;
                else
                {
                    int64_t x24_1 = arg1;
                    
                    if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
                        result = 0xfffffff2;
                    else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
                        result = 0xffffffec;
                    else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
                        result = 0xfffffff3;
                    else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x56) != 1)
                    {
                        int32_t x0_1 = cs2p2p_CurrentTickCount();
                        uint64_t x8_10 = arg2;
                        int64_t x9_4 = (cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc"));
                        int64_t x14_1 = (x9_4 + (x8_10 << 5));
                        char* x9_14;
                        int32_t x23_1;
                        
                        while (true)
                        {
                            x23_1 = (x0_1 - x0);
                            
                            if (x23_1 < arg5)
                            {
                                pthread_mutex_lock(&data_50d02c);
                                int32_t x25_2;
                                
                                if (*(x14_1 + "P_Proto_TCPSend_AlivePKcijPc") == 0)
                                    x25_2 = 0;
                                else
                                {
                                    void* x25_1 = *(x14_1 + "n");
                                    int32_t x8_21;
                                    
                                    if (x25_1 == 0)
                                        x8_21 = 0x10102;
                                    else
                                    {
                                        void* x8_14 = *(x25_1 + 0x20);
                                        void* x8_15;
                                        
                                        if (x8_14 == 0)
                                            x8_15 = &*"n"[x14_1];
                                        else
                                            x8_15 = (x8_14 + 0x18);
                                        
                                        *x8_15 = *(x25_1 + 0x18);
                                        void* x8_16 = *(x25_1 + 0x18);
                                        void* x8_18;
                                        
                                        if (x8_16 == 0)
                                            x8_18 = &*"2p2p_PPPP_Proto_TCPSend_AlivePKc…"[x14_1];
                                        else
                                            x8_18 = (x8_16 + 0x20);
                                        
                                        *x8_18 = *(x25_1 + 0x20);
                                        *(x25_1 + 0x18) = 0;
                                        *(x25_1 + 0x20) = 0;
                                        *(x14_1 + "P_Proto_TCPSend_AlivePKcijPc") -= 1;
                                        x8_21 = *(x25_1 + 4);
                                        *(x14_1 + "oto_TCPSend_AlivePKcijPc") -= x8_21;
                                    }
                                    
                                    int32_t x8_22;
                                    
                                    if (x28_1 > x8_21)
                                        x8_22 = x8_21;
                                    else
                                        x8_22 = x28_1;
                                    
                                    *arg4 = x8_22;
                                    memcpy(arg3, *(x25_1 + 8), x8_22);
                                    
                                    if (x25_1 != 0)
                                    {
                                        int64_t x0_3 = *(x25_1 + 8);
                                        
                                        if (x0_3 != 0)
                                            free(x0_3);
                                        
                                        free(x25_1);
                                    }
                                    
                                    x25_2 = 1;
                                }
                                
                                pthread_mutex_unlock(&data_50d02c);
                                
                                if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x57) != 1)
                                {
                                    x9_14 = ((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x58);
                                    
                                    if (*x9_14 == 1)
                                        break;
                                    
                                    if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
                                        break;
                                    
                                    if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x56) == 1)
                                        break;
                                    
                                    if (*arg4 > 0)
                                        break;
                                    
                                    uint32_t x8_30 = (arg5 - x23_1);
                                    uint32_t x25_3;
                                    
                                    if (x8_30 < 0xa)
                                        x25_3 = x8_30;
                                    else
                                        x25_3 = 0xa;
                                    
                                    int64_t var_78 = 0;
                                    uint64_t var_70_1 = ((x25_3 % 0x3e8) * 0xf4240);
                                    int32_t i;
                                    
                                    do
                                        i = sem_trywait(((x9_4 + (x8_10 << 4)) + 0x68));
                                     while (i == 0);
                                    
                                    if ((sem_timedwait(((x9_4 + (x8_10 << 4)) + 0x68), &var_78) != 0 && *__errno() != 0x6e))
                                        cs2p2p_mSecSleep(x25_3);
                                    
                                    x0_1 = cs2p2p_CurrentTickCount();
                                    
                                    if (x25_2 == 0)
                                        continue;
                                    else
                                        x23_1 = (x0_1 - x0);
                                }
                            }
                            
                            x9_14 = ((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x58);
                            break;
                        }
                        
                        if (x23_1 >= arg5)
                            result = 0xfffffffd;
                        else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
                            result = 0xfffffff3;
                        else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x56) == 1)
                            result = 0xfffffff4;
                        else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
                            result = 0xfffffff2;
                        else if (*x9_14 == 1)
                            result = 0xffffffec;
                        else
                            result = 0;
                    }
                    else
                        result = 0xfffffff4;
                }
            }
        }
    }
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

