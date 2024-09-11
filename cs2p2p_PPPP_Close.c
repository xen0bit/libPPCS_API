
int64_t cs2p2p_PPPP_Close(int32_t arg1)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    if (arg1 <= 0x100)
    {
        void* x28_1 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
        
        if ((*x28_1 & 0x80000000) == 0)
        {
            int64_t x23_1 = arg1;
            pthread_mutex_lock(&data_50d02c);
            void* x21_1 = (cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc"));
            *(x21_1 + 0x57) = 1;
            pthread_mutex_unlock(&data_50d02c);
            int64_t x24_1 = 0;
            
            while (true)
            {
                if (*(((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (x24_1 << 1)) + "p_PPPP_Proto_Send_RlyPortPKciP11…") != 0)
                {
                    while (*(x21_1 + 0x53) == 0)
                    {
                        cs2p2p_mSecSleep(0xa);
                        
                        if (*(((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (x24_1 << 1)) + "p_PPPP_Proto_Send_RlyPortPKciP11…") == 0)
                            break;
                    }
                }
                
                void* x8_8 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (x24_1 << 5));
                
                if (*(x8_8 + 0x1a8) != 0)
                    break;
                
                while ((*(x8_8 + 0x3a8) != 0 || *(x8_8 + 0x2a8) != 0))
                {
                label_16a3c:
                    
                    if (*(x21_1 + 0x53) != 0)
                        break;
                    
                    cs2p2p_mSecSleep(0xa);
                    
                    if (*(x8_8 + 0x1a8) != 0)
                        break;
                }
                
                x24_1 += 1;
                
                if (x24_1 == 8)
                {
                    void* x8_14 = (cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc"));
                    int32_t x1_1 = *(x8_14 + "nAckPKciP11sockaddr_inc");
                    
                    if (x1_1 == 0xffffffff)
                        cs2p2p_PPPP_Proto_Send_Close((x8_14 + 0xe8), *x28_1, ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + 4));
                    else
                    {
                        cs2p2p_PPPP_Proto_TCPSend_Close((x8_14 + 0xe8), x1_1, 0, (x21_1 + 0x53));
                        
                        if (*(x21_1 + 0x53) == 0)
                        {
                            while (*((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + 0x56) != 1)
                            {
                                cs2p2p_mSecSleep(0xa);
                                
                                if (*(x21_1 + 0x53) != 0)
                                    break;
                            }
                        }
                    }
                    
                    pthread_mutex_lock(&data_50d02c);
                    *(x21_1 + 0x53) = 1;
                    pthread_mutex_unlock(&data_50d02c);
                    void* x8_20 = (cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc"));
                    int64_t x0_2 = *(x8_20 + 0x128);
                    
                    if (x0_2 != 0)
                    {
                        pthread_join(x0_2, 0);
                        *(x8_20 + 0x128) = 0;
                    }
                    
                    void* x8_21 = (cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc"));
                    int64_t x0_3 = *(x8_21 + 0x130);
                    
                    if (x0_3 != 0)
                    {
                        pthread_join(x0_3, 0);
                        *(x8_21 + 0x130) = 0;
                    }
                    
                    pthread_mutex_lock(&data_50d02c);
                    
                    for (int64_t i = 0; i != 8; i += 1)
                    {
                        void* x8_22 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                        void* j_5 = *(x8_22 + 0x498);
                        
                        if (j_5 != 0)
                        {
                            void* x8_24 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                            void* j;
                            
                            do
                            {
                                j = *(j_5 + 0x18);
                                *(x8_24 + 0x4a8) -= 1;
                                *(x8_24 + 0x4ac) -= *(j_5 + 4);
                                int64_t x0_4 = *(j_5 + 8);
                                
                                if (x0_4 != 0)
                                    free(x0_4);
                                
                                free(j_5);
                                j_5 = j;
                                *(x8_22 + 0x498) = j;
                            } while (j != 0);
                        }
                        
                        void* x8_30 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                        void* j_6 = *(x8_30 + 0x398);
                        
                        if (j_6 != 0)
                        {
                            void* x8_32 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                            void* j_1;
                            
                            do
                            {
                                j_1 = *(j_6 + 0x18);
                                *(x8_32 + 0x3a8) -= 1;
                                *(x8_32 + 0x3ac) -= *(j_6 + 4);
                                int64_t x0_6 = *(j_6 + 8);
                                
                                if (x0_6 != 0)
                                    free(x0_6);
                                
                                free(j_6);
                                j_6 = j_1;
                                *(x8_30 + 0x398) = j_1;
                            } while (j_1 != 0);
                        }
                        
                        void* x8_38 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                        void* j_7 = *(x8_38 + 0x298);
                        
                        if (j_7 != 0)
                        {
                            void* x8_40 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                            void* j_2;
                            
                            do
                            {
                                j_2 = *(j_7 + 0x18);
                                *(x8_40 + 0x2a8) -= 1;
                                *(x8_40 + 0x2ac) -= *(j_7 + 4);
                                int64_t x0_8 = *(j_7 + 8);
                                
                                if (x0_8 != 0)
                                    free(x0_8);
                                
                                free(j_7);
                                j_7 = j_2;
                                *(x8_38 + 0x298) = j_2;
                            } while (j_2 != 0);
                        }
                        
                        void* x8_46 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                        void* j_8 = *(x8_46 + 0x198);
                        
                        if (j_8 != 0)
                        {
                            void* x8_48 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                            void* j_3;
                            
                            do
                            {
                                j_3 = *(j_8 + 0x18);
                                *(x8_48 + 0x1a8) -= 1;
                                *(x8_48 + 0x1ac) -= *(j_8 + 4);
                                int64_t x0_10 = *(j_8 + 8);
                                
                                if (x0_10 != 0)
                                    free(x0_10);
                                
                                free(j_8);
                                j_8 = j_3;
                                *(x8_46 + 0x198) = j_3;
                            } while (j_3 != 0);
                        }
                        
                        int64_t x8_54 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                        void* j_9 = *(x8_54 + "n");
                        
                        if (j_9 != 0)
                        {
                            int64_t x8_56 = ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 5));
                            void* j_4;
                            
                            do
                            {
                                j_4 = *(j_9 + 0x18);
                                *(x8_56 + "P_Proto_TCPSend_AlivePKcijPc") -= 1;
                                *(x8_56 + "oto_TCPSend_AlivePKcijPc") -= *(j_9 + 4);
                                int64_t x0_12 = *(j_9 + 8);
                                
                                if (x0_12 != 0)
                                    free(x0_12);
                                
                                free(j_9);
                                j_9 = j_4;
                                *(x8_54 + "n") = j_4;
                            } while (j_4 != 0);
                        }
                        
                        sem_destroy((((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + (i << 4)) + 0x68));
                    }
                    
                    pthread_mutex_unlock(&data_50d02c);
                    int32_t x0_15 = *(x8_14 + "nAckPKciP11sockaddr_inc");
                    
                    if (x0_15 != 0xffffffff)
                    {
                        cs2_TCPSkt_Close(x0_15);
                        *(x8_14 + "nAckPKciP11sockaddr_inc") = 0xffffffff;
                    }
                    
                    close(*x28_1);
                    pthread_mutex_lock(&data_50d02c);
                    *x28_1 = 0xffffffff;
                    pthread_mutex_unlock(&data_50d02c);
                    return 0;
                }
            }
            
            goto label_16a3c;
        }
    }
    
    return 0xfffffff5;
}

