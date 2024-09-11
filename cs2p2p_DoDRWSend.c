
uint32_t* cs2p2p_DoDRWSend(int32_t arg1)

{
    uint32_t* s = cs2p2p_CurrentTickCount();
    void* x8 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
    int64_t x28 = arg1;
    int32_t var_6c = s;
    
    if ((*(x8 + "nAckPKciP11sockaddr_inc") == 0xffffffff || (s - *(x8 + "2PReqAckPKciP11sockaddr_inc")) < 0x3e9))
        goto label_1706c;
    
    pthread_mutex_unlock(&data_50d02c);
    void* x8_3 = (cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc"));
    int32_t x0_1 = cs2p2p_PPPP_Proto_TCPSend_Alive((x8_3 + 0xe8), *(x8 + "nAckPKciP11sockaddr_inc"), 0x1770, (x8_3 + 0x53));
    s = pthread_mutex_lock(&data_50d02c);
    
    if (x0_1 == 0)
    {
        *(x8 + "2PReqAckPKciP11sockaddr_inc") = var_6c;
    label_1706c:
        int32_t* x8_6 = (cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc"));
        int64_t var_b0_1 = x28;
        
        for (int64_t i = 0; i != 8; i += 1)
        {
            int16_t x8_12;
            
            if (*(x8 + "nAckPKciP11sockaddr_inc") == 0xffffffff)
                x8_12 = (*(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…") + 1);
            
            if ((*(x8 + "nAckPKciP11sockaddr_inc") != 0xffffffff || x8_12 >= 0x6f))
                x8_12 = 0x6e;
            
            *(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…") = x8_12;
            uint64_t bytes = *(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "p_PPPP_Proto_Send_RlyPortPKciP11…");
            
            if (bytes != 0)
            {
                int64_t x24_1 = (cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc"));
                void* x23_1 = (x24_1 + (i << 1));
                uint32_t x22_2 = *(x23_1 + 0x598);
                s = malloc(0x28);
                
                if (s == 0)
                {
                    *(x8_6 + 0x53) = 1;
                    x8_6[0x16] = 1;
                }
                else
                {
                    __builtin_memset(s, 0, 0x28);
                    int64_t x0_3 = malloc(bytes);
                    *(s + 8) = x0_3;
                    
                    if (x0_3 == 0)
                    {
                        s = free(s);
                        *(x8_6 + 0x53) = 1;
                        x8_6[0x16] = 1;
                    }
                    else
                    {
                        *s = x22_2;
                        s[1] = bytes;
                        memcpy(x0_3, ((x24_1 + (i << 0xa)) + 0x5b8), bytes);
                        s = cs2p2p_sll_Put((((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 5)) + 0x198), s);
                        *(x23_1 + 0x598) += 1;
                        *(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "p_PPPP_Proto_Send_RlyPortPKciP11…") = 0;
                    }
                }
            }
            
            void* x22_3 = ((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 5));
            int32_t x9_11 = *(x22_3 + 0x2a8);
            int32_t x8_21 = *(x22_3 + 0x3a8);
            
            if ((x8_21 + x9_11) <= 0x7f)
            {
                void* x10_3 = ((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 5));
                
                do
                {
                    cs2p2p___the_SLL_Element* x1_4 = *(x22_3 + 0x198);
                    
                    if (x1_4 == 0)
                        break;
                    
                    void* x8_22 = *(x1_4 + 0x20);
                    void* x8_23;
                    
                    if (x8_22 == 0)
                        x8_23 = (x22_3 + 0x198);
                    else
                        x8_23 = (x8_22 + 0x18);
                    
                    *x8_23 = *(x1_4 + 0x18);
                    void* x8_24 = *(x1_4 + 0x18);
                    int64_t* x8_25;
                    
                    if (x8_24 == 0)
                        x8_25 = (x10_3 + 0x1a0);
                    else
                        x8_25 = (x8_24 + 0x20);
                    
                    *x8_25 = *(x1_4 + 0x20);
                    *(x1_4 + 0x18) = 0;
                    *(x1_4 + 0x20) = 0;
                    *(x10_3 + 0x1a8) -= 1;
                    *(x10_3 + 0x1ac) -= *(x1_4 + 4);
                    s = cs2p2p_sll_Put((x22_3 + 0x298), x1_4);
                    x9_11 = *(x22_3 + 0x2a8);
                    x8_21 = *(x22_3 + 0x3a8);
                } while ((x8_21 + x9_11) < 0x80);
            }
            
            if (x9_11 != 0)
            {
                void* x9_16 = ((cs2p2p_gSession + (var_b0_1 * "PKciP11sockaddr_inc")) + (i << 5));
                
                while (true)
                {
                    cs2p2p___the_SLL_Element* x27_2 = *(x22_3 + 0x298);
                    int32_t x28_2 = *x27_2;
                    
                    if (x8_21 != 0)
                    {
                        int32_t x12_1 = (x28_2 & 0xffff);
                        int32_t x8_31 = **(x22_3 + 0x398);
                        int32_t x10_10 = **(x9_16 + 0x3a0);
                        int32_t x9_19 = (x8_31 & 0xffff);
                        int32_t x13_1 = (x12_1 - x9_19);
                        int32_t x11_3;
                        
                        if (x12_1 != x9_19)
                        {
                            if (x12_1 <= x8_31)
                            {
                                x13_1 = (x9_19 - x12_1);
                                
                                if (x13_1 >= 0x8000)
                                    x13_1 = (x12_1 - (x8_31 | 0xffff0000));
                            }
                            else if (x13_1 >= 0x8000)
                                x13_1 = (x9_19 - (x28_2 | 0xffff0000));
                            
                            x11_3 = (*(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…") + 0xa);
                            
                            if (x13_1 > x11_3)
                                break;
                        }
                        else
                            x11_3 = (*(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…") + 0xa);
                        
                        int32_t x14_1 = (x28_2 & 0xffff);
                        int32_t x13_2 = (x10_10 & 0xffff);
                        
                        if (x14_1 != x13_2)
                        {
                            int32_t x14_2;
                            
                            if (x14_1 <= x10_10)
                            {
                                x14_2 = (x13_2 - x12_1);
                                
                                if (x14_2 >= 0x8000)
                                    x14_2 = (x12_1 - (x10_10 | 0xffff0000));
                                
                                goto label_1735c;
                            }
                            
                            x14_2 = (x12_1 - x13_2);
                            
                            if (x14_2 < 0x8000)
                            {
                            label_1735c:
                                
                                if (x14_2 > x11_3)
                                    break;
                            }
                            else if ((x13_2 - (x28_2 | 0xffff0000)) > x11_3)
                                break;
                        }
                        
                        int32_t x12_3 = (x8_31 & 0xffff);
                        uint32_t temp0_1 = x10_10;
                        
                        if (x12_3 != temp0_1)
                        {
                            int32_t x12_4;
                            
                            if (x12_3 <= temp0_1)
                            {
                                x12_4 = (x13_2 - x9_19);
                                
                                if (x12_4 >= 0x8000)
                                    x12_4 = (x9_19 - (x10_10 | 0xffff0000));
                                
                                goto label_173a8;
                            }
                            
                            x12_4 = (x9_19 - x13_2);
                            
                            if (x12_4 < 0x8000)
                            {
                            label_173a8:
                                
                                if (x12_4 > x11_3)
                                    break;
                            }
                            else if ((x13_2 - (x8_31 | 0xffff0000)) > x11_3)
                                break;
                        }
                    }
                    
                    if (x27_2 != 0)
                    {
                        void* x8_34 = *(x27_2 + 0x20);
                        void* x8_35;
                        
                        if (x8_34 == 0)
                            x8_35 = (x22_3 + 0x298);
                        else
                            x8_35 = (x8_34 + 0x18);
                        
                        *x8_35 = *(x27_2 + 0x18);
                        void* x8_36 = *(x27_2 + 0x18);
                        void* x8_38;
                        
                        if (x8_36 == 0)
                            x8_38 = (x9_16 + 0x2a0);
                        else
                            x8_38 = (x8_36 + 0x20);
                        
                        *x8_38 = *(x27_2 + 0x20);
                        *(x27_2 + 0x18) = 0;
                        *(x27_2 + 0x20) = 0;
                        *(x22_3 + 0x2a8) -= 1;
                        *(x9_16 + 0x2ac) -= *(x27_2 + 4);
                    }
                    
                    if (*(x8 + "nAckPKciP11sockaddr_inc") == 0xffffffff)
                    {
                        int32_t x8_46 = *(x27_2 + 0x10);
                        
                        if ((x8_46 == 0 || var_6c == 0))
                        {
                            int32_t x8_47;
                            
                            if (x8_46 == 0)
                                x8_47 = var_6c;
                            else
                                x8_47 = -1;
                            
                            *(x27_2 + 0x10) = x8_47;
                        }
                        
                        cs2p2p_sll_Put((x22_3 + 0x398), x27_2);
                        s = cs2p2p_PPPP_DRW_Send(&x8_6[0x3a], *x8_6, &x8_6[1], i, x28_2, *(x27_2 + 8), *(x27_2 + 4));
                        
                        if (*(x22_3 + 0x2a8) == 0)
                            break;
                    }
                    else
                    {
                        pthread_mutex_unlock(&data_50d02c);
                        int32_t x0_8 = cs2p2p_PPPP_DRW_TCPSend(&x8_6[0x3a], *(x8 + "nAckPKciP11sockaddr_inc"), i, x28_2, *(x27_2 + 8), *(x27_2 + 4), 0x1770, (x8_6 + 0x53));
                        pthread_mutex_lock(&data_50d02c);
                        
                        if (x0_8 != 0)
                        {
                            *(x8_6 + 0x55) = 1;
                            *(x8_6 + 0x53) = 1;
                            int64_t x0_13 = *(x27_2 + 8);
                            
                            if (x0_13 != 0)
                                free(x0_13);
                            
                            s = free(x27_2);
                            break;
                        }
                        
                        *(x8 + "2PReqAckPKciP11sockaddr_inc") = var_6c;
                        int64_t x0_9 = *(x27_2 + 8);
                        
                        if (x0_9 != 0)
                            free(x0_9);
                        
                        s = free(x27_2);
                        
                        if (*(x22_3 + 0x2a8) == 0)
                            break;
                    }
                    
                    x8_21 = *(x22_3 + 0x3a8);
                }
            }
            
            x28 = var_b0_1;
            uint32_t x5_3 = *(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "ockaddr_inc");
            
            if (x5_3 != 0)
            {
                s = cs2p2p_PPPP_DRWAck_Send(&x8_6[0x3a], *x8_6, &x8_6[1], i, &*"cs2p2p_PPPP_Proto_Send_SDevLgnPK…"[((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i * 0xa4))], x5_3);
                *(((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + (i << 1)) + "ockaddr_inc") = 0;
            }
        }
        
        *((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + 0x60) = var_6c;
    }
    else
    {
        *((cs2p2p_gSession + (x28 * "PKciP11sockaddr_inc")) + 0x55) = 1;
        *(x8_3 + 0x53) = 1;
    }
    
    return s;
}

