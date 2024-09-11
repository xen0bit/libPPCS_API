
void cs2p2p_PPPP_thread_SmartSuperDevice() __noreturn

{
    int32_t var_58c = 1;
    int32_t x0 = cs2p2p_setup_Socket();
    *(cs2p2p_gSDevInfo + 0x64) = x0;
    setsockopt(x0, 1, 6, &var_58c, 4);
    void var_588;
    cs2p2p_TryBind(*(cs2p2p_gSDevInfo + 0x64), 0, &var_588);
    *(cs2p2p_gSDevInfo + 0x62) = 1;
    int32_t x21 = time(nullptr);
    
    if ((*(cs2p2p_gSDevInfo + 0x62) == 1 && *(cs2p2p_gSDevInfo + 0x61) != 0))
    {
        int32_t x27_1 = 0;
        
        do
        {
            if ((x21 - x27_1) >= 0x1e)
            {
                cs2p2p_PPPP_Proto_Send_SSDLgn_CRC(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), cs2p2p_gP2PServerAddr, (cs2p2p_gSDevInfo + 0x38), *(cs2p2p_gSDevInfo + 0x48), (cs2p2p_gSDevInfo + 0x40), *cs2p2p_gCRCKey);
                cs2p2p_PPPP_Proto_Send_SSDLgn_CRC(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), (cs2p2p_gP2PServerAddr + 0x10), (cs2p2p_gSDevInfo + 0x38), *(cs2p2p_gSDevInfo + 0x48), (cs2p2p_gSDevInfo + 0x40), *cs2p2p_gCRCKey);
                cs2p2p_PPPP_Proto_Send_SSDLgn_CRC(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), (cs2p2p_gP2PServerAddr + 0x20), (cs2p2p_gSDevInfo + 0x38), *(cs2p2p_gSDevInfo + 0x48), (cs2p2p_gSDevInfo + 0x40), *cs2p2p_gCRCKey);
                x27_1 = x21;
            }
            
            void var_578;
            uint16_t var_78;
            uint8_t var_74;
            int128_t var_70;
            int32_t x0_27 = cs2p2p_PPPP_Proto_Recv_ALL(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), &var_70, 0x64, &var_74, &var_78, &var_578, 0x500);
            x21 = time(nullptr);
            
            if (x0_27 == 0)
            {
                uint32_t x8_2 = var_74;
                int128_t var_5a0;
                int32_t var_570;
                int32_t x1_14;
                void* x3_2;
                sockaddr_in* x26_6;
                
                if (x8_2 == 0x3d)
                {
                    if (var_78 == 0x28)
                    {
                        uint8_t* x0_10 = malloc(0x2c);
                        cs2p2p__P2P_Proprietary_Decrypt("SSD@cs2-network.", &var_578, x0_10, 0x28);
                        memcpy(&var_578, x0_10, var_78);
                        free(x0_10);
                        int32_t temp0_1 = _byteswap(var_570);
                        void var_560;
                        int128_t v0_1;
                        int128_t v1_1;
                        v0_1 = cs2p2p_ntohAddr(&var_560, &var_5a0);
                        int64_t x8_13;
                        
                        if ((x21 - *(cs2p2p_gSDevInfo + 0x108)) < 3)
                        {
                            if (*(cs2p2p_gSDevInfo + 0x10c) != temp0_1)
                                goto label_1873c;
                            
                            x8_13 = 0;
                        label_1883c:
                            void* x25_1 = (cs2p2p_gSDevInfo + (x8_13 * 0x28));
                            x26_6 = (x25_1 + 0x110);
                            cs2p2p_PPPP_Proto_Send_SmartPunchTo(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), &var_70, x26_6, 2, 1, 0);
                            x1_14 = *(cs2p2p_gSDevInfo + 0x64);
                            x3_2 = (x25_1 + 0x120);
                        label_188cc:
                            cs2p2p_PPPP_Proto_Send_PunchTo(cs2p2p_gP2PKeyString, x1_14, &var_70, x3_2);
                            cs2p2p_PPPP_Proto_Send_SmartPunchTo(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), x26_6, &var_70, 2, 1, 0);
                            cs2p2p_PPPP_Proto_Send_PunchTo(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), x26_6, &var_5a0);
                        }
                        else
                        {
                            *(cs2p2p_gSDevInfo + 0x10c) = 0xffffffff;
                        label_1873c:
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0x130)) > 2)
                                *(cs2p2p_gSDevInfo + 0x134) = 0xffffffff;
                            else if (*(cs2p2p_gSDevInfo + 0x134) == temp0_1)
                            {
                                x8_13 = 1;
                                goto label_1883c;
                            }
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0x158)) > 2)
                                *(cs2p2p_gSDevInfo + 0x15c) = 0xffffffff;
                            else if (*(cs2p2p_gSDevInfo + 0x15c) == temp0_1)
                            {
                                x8_13 = 2;
                                goto label_1883c;
                            }
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0x180)) > 2)
                                *(cs2p2p_gSDevInfo + 0x184) = 0xffffffff;
                            else if (*(cs2p2p_gSDevInfo + 0x184) == temp0_1)
                            {
                                x8_13 = 3;
                                goto label_1883c;
                            }
                            
                            int32_t x10_1 = *(cs2p2p_gSDevInfo + 0x6c);
                            void* x8_37;
                            int64_t x8_33;
                            
                            if (x10_1 != temp0_1)
                            {
                                int32_t x11_1 = *(cs2p2p_gSDevInfo + 0x94);
                                
                                if (x11_1 == temp0_1)
                                {
                                    x8_33 = 1;
                                    goto label_18980;
                                }
                                
                                int32_t x9_1 = *(cs2p2p_gSDevInfo + 0xbc);
                                
                                if (x9_1 == temp0_1)
                                {
                                    x8_33 = 2;
                                    goto label_18980;
                                }
                                
                                int32_t x8_36 = *(cs2p2p_gSDevInfo + 0xe4);
                                
                                if (x8_36 == temp0_1)
                                {
                                    x8_33 = 3;
                                    goto label_18980;
                                }
                                
                                int32_t x10_3;
                                
                                if (x10_1 != 0xffffffff)
                                    x10_3 = *(cs2p2p_gSDevInfo + 0x68);
                                
                                int32_t x8_40;
                                
                                if ((x10_1 != 0xffffffff && (x21 - x10_3) <= 0x28))
                                {
                                    int32_t x11_3;
                                    
                                    if (x11_1 != 0xffffffff)
                                        x11_3 = *(cs2p2p_gSDevInfo + 0x90);
                                    
                                    if ((x11_1 != 0xffffffff && (x21 - x11_3) <= 0x28))
                                    {
                                        int32_t x9_3;
                                        
                                        if (x9_1 != 0xffffffff)
                                            x9_3 = *(cs2p2p_gSDevInfo + 0xb8);
                                        
                                        if ((x9_1 != 0xffffffff && (x21 - x9_3) <= 0x28))
                                        {
                                            int32_t x9_5;
                                            
                                            if (x9_3 < *((cs2p2p_gSDevInfo + (((x11_3 < x10_3) ? 1 : 0) * 0x28)) + 0x68))
                                                x9_5 = 2;
                                            else
                                                x9_5 = ((x11_3 < x10_3) ? 1 : 0);
                                            
                                            int32_t x8_42;
                                            
                                            if (x8_36 != 0xffffffff)
                                                x8_42 = *(cs2p2p_gSDevInfo + 0xe0);
                                            
                                            if ((x8_36 == 0xffffffff || (x21 - x8_42) > 0x28))
                                                x8_40 = 3;
                                            else if (x8_42 < *((cs2p2p_gSDevInfo + (x9_5 * 0x28)) + 0x68))
                                                x8_40 = 3;
                                            else
                                                x8_40 = x9_5;
                                        }
                                        else
                                            x8_40 = 2;
                                    }
                                    else
                                        x8_40 = 1;
                                }
                                else
                                    x8_40 = 0;
                                
                                v0_1 = var_70;
                                v1_1 = var_5a0;
                                x8_37 = (cs2p2p_gSDevInfo + (x8_40 * 0x28));
                                *(x8_37 + 0x68) = x21;
                                *(x8_37 + 0x6c) = temp0_1;
                            }
                            else
                            {
                                x8_33 = 0;
                            label_18980:
                                v0_1 = var_70;
                                v1_1 = var_5a0;
                                x8_37 = (cs2p2p_gSDevInfo + (x8_33 * 0x28));
                                *(x8_37 + 0x68) = x21;
                            }
                            *(x8_37 + 0x70) = v0_1;
                            *(x8_37 + 0x80) = v1_1;
                        }
                    }
                }
                else
                {
                    sockaddr_in var_564;
                    
                    if (x8_2 == 0x3c)
                    {
                        if (var_78 == 0x24)
                        {
                            uint8_t* x0_14 = malloc(0x28);
                            cs2p2p__P2P_Proprietary_Decrypt("SSD@cs2-network.", &var_578, x0_14, 0x24);
                            memcpy(&var_578, x0_14, var_78);
                            free(x0_14);
                            int32_t temp0_2 = _byteswap(var_570);
                            int128_t v0_2;
                            int128_t v1_2;
                            v0_2 = cs2p2p_ntohAddr(&var_564, &var_5a0);
                            int64_t x8_17;
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0x68)) < 3)
                            {
                                if (*(cs2p2p_gSDevInfo + 0x6c) != temp0_2)
                                    goto label_18764;
                                
                                x8_17 = 0;
                            label_18898:
                                void* x25_2 = (cs2p2p_gSDevInfo + (x8_17 * 0x28));
                                x26_6 = (x25_2 + 0x70);
                                cs2p2p_PPPP_Proto_Send_SmartPunchTo(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), &var_70, x26_6, 2, 1, 0);
                                x1_14 = *(cs2p2p_gSDevInfo + 0x64);
                                x3_2 = (x25_2 + 0x80);
                                goto label_188cc;
                            }
                            
                            *(cs2p2p_gSDevInfo + 0x6c) = 0xffffffff;
                        label_18764:
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0x90)) <= 2)
                            {
                                if (*(cs2p2p_gSDevInfo + 0x94) != temp0_2)
                                    goto label_187bc;
                                
                                x8_17 = 1;
                                goto label_18898;
                            }
                            
                            *(cs2p2p_gSDevInfo + 0x94) = 0xffffffff;
                        label_187bc:
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0xb8)) <= 2)
                            {
                                if (*(cs2p2p_gSDevInfo + 0xbc) != temp0_2)
                                    goto label_18814;
                                
                                x8_17 = 2;
                                goto label_18898;
                            }
                            
                            *(cs2p2p_gSDevInfo + 0xbc) = 0xffffffff;
                        label_18814:
                            
                            if ((x21 - *(cs2p2p_gSDevInfo + 0xe0)) <= 2)
                            {
                                if (*(cs2p2p_gSDevInfo + 0xe4) != temp0_2)
                                    goto label_1890c;
                                
                                x8_17 = 3;
                                goto label_18898;
                            }
                            
                            *(cs2p2p_gSDevInfo + 0xe4) = 0xffffffff;
                        label_1890c:
                            int32_t x10_2 = *(cs2p2p_gSDevInfo + 0x10c);
                            void* x8_39;
                            int64_t x8_35;
                            
                            if (x10_2 != temp0_2)
                            {
                                int32_t x11_2 = *(cs2p2p_gSDevInfo + 0x134);
                                
                                if (x11_2 == temp0_2)
                                {
                                    x8_35 = 1;
                                    goto label_189ac;
                                }
                                
                                int32_t x9_2 = *(cs2p2p_gSDevInfo + 0x15c);
                                
                                if (x9_2 == temp0_2)
                                {
                                    x8_35 = 2;
                                    goto label_189ac;
                                }
                                
                                int32_t x8_38 = *(cs2p2p_gSDevInfo + 0x184);
                                
                                if (x8_38 == temp0_2)
                                {
                                    x8_35 = 3;
                                    goto label_189ac;
                                }
                                
                                int32_t x10_4;
                                
                                if (x10_2 != 0xffffffff)
                                    x10_4 = *(cs2p2p_gSDevInfo + 0x108);
                                
                                int32_t x8_41;
                                
                                if ((x10_2 != 0xffffffff && (x21 - x10_4) <= 0x28))
                                {
                                    int32_t x11_4;
                                    
                                    if (x11_2 != 0xffffffff)
                                        x11_4 = *(cs2p2p_gSDevInfo + 0x130);
                                    
                                    if ((x11_2 != 0xffffffff && (x21 - x11_4) <= 0x28))
                                    {
                                        int32_t x9_4;
                                        
                                        if (x9_2 != 0xffffffff)
                                            x9_4 = *(cs2p2p_gSDevInfo + 0x158);
                                        
                                        if ((x9_2 != 0xffffffff && (x21 - x9_4) <= 0x28))
                                        {
                                            int32_t x9_6;
                                            
                                            if (x9_4 < *((cs2p2p_gSDevInfo + (((x11_4 < x10_4) ? 1 : 0) * 0x28)) + 0x108))
                                                x9_6 = 2;
                                            else
                                                x9_6 = ((x11_4 < x10_4) ? 1 : 0);
                                            
                                            int32_t x8_43;
                                            
                                            if (x8_38 != 0xffffffff)
                                                x8_43 = *(cs2p2p_gSDevInfo + 0x180);
                                            
                                            if ((x8_38 == 0xffffffff || (x21 - x8_43) > 0x28))
                                                x8_41 = 3;
                                            else if (x8_43 < *((cs2p2p_gSDevInfo + (x9_6 * 0x28)) + 0x108))
                                                x8_41 = 3;
                                            else
                                                x8_41 = x9_6;
                                        }
                                        else
                                            x8_41 = 2;
                                    }
                                    else
                                        x8_41 = 1;
                                }
                                else
                                    x8_41 = 0;
                                
                                v0_2 = var_70;
                                v1_2 = var_5a0;
                                x8_39 = (cs2p2p_gSDevInfo + (x8_41 * 0x28));
                                *(x8_39 + 0x10c) = temp0_2;
                            }
                            else
                            {
                                x8_35 = 0;
                            label_189ac:
                                v0_2 = var_70;
                                v1_2 = var_5a0;
                                x8_39 = (cs2p2p_gSDevInfo + (x8_35 * 0x28));
                            }
                            *(x8_39 + 0x108) = x21;
                            *(x8_39 + 0x110) = v0_2;
                            *(x8_39 + 0x120) = v1_2;
                        }
                    }
                    else if ((x8_2 == 0x38 && var_78 == 0x34))
                    {
                        uint8_t* x0_3 = malloc(0x38);
                        cs2p2p__P2P_Proprietary_Decrypt("SSD@cs2-network.", &var_578, x0_3, 0x34);
                        memcpy(&var_578, x0_3, var_78);
                        free(x0_3);
                        cs2p2p_ntohAddr(&var_564, &var_5a0);
                        sockaddr_in var_5b0;
                        void var_554;
                        cs2p2p_ntohAddr(&var_554, &var_5b0);
                        cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), &var_5a0);
                        cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *(cs2p2p_gSDevInfo + 0x64), &var_5b0);
                    }
                }
            }
            
            if (*(cs2p2p_gSDevInfo + 0x62) != 1)
                break;
        } while (*(cs2p2p_gSDevInfo + 0x61) != 0);
    }
    
    close(*(cs2p2p_gSDevInfo + 0x64));
    *(cs2p2p_gSDevInfo + 0x62) = 0;
    pthread_exit(nullptr);
    /* no return */
}

