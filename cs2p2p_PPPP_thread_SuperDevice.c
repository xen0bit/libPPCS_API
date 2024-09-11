
void cs2p2p_PPPP_thread_SuperDevice() __noreturn

{
    *cs2p2p_gSDevInfo = cs2p2p_setup_Socket();
    int32_t var_58c = 1;
    setsockopt();
    void var_588;
    cs2p2p_TryBind(*cs2p2p_gSDevInfo, 0, &var_588);
    srand(time(nullptr));
    int32_t x0_3 = rand();
    int32_t x8_1;
    
    if (x0_3 < 0)
        x8_1 = (x0_3 + 0xff);
    else
        x8_1 = x0_3;
    
    int32_t x0_4 = rand();
    int32_t x8_4;
    
    if (x0_4 < 0)
        x8_4 = (x0_4 + 0xff);
    else
        x8_4 = x0_4;
    
    int32_t x0_5 = rand();
    int32_t x8_8;
    
    if (x0_5 < 0)
        x8_8 = (x0_5 + 0xff);
    else
        x8_8 = x0_5;
    
    int32_t x0_6 = rand();
    uint32_t x8_11 = *(cs2p2p_gSDevInfo + 0x1b8);
    *(cs2p2p_gSDevInfo + 0x34) = ((((x0_3 - (x8_1 & 0xffffff00)) + ((x0_4 - (x8_4 & 0xffff00)) << 8)) + ((x0_5 - (x8_8 & 0xff00)) << 0x10)) + (x0_6 << 0x18));
    void* var_ab8;
    int64_t s2;
    int64_t s2_1;
    sockaddr_in var_578;
    uint16_t var_78;
    uint8_t var_74;
    int128_t var_70;
    void var_568;
    
    if ((x8_11 != 1 || *(cs2p2p_gSDevInfo + 0x60) == 0))
        var_ab8 = &var_568;
    else
    {
        int32_t x25_1 = 0;
        int32_t x26_1 = 0;
        var_ab8 = &var_568;
        
        do
        {
            if ((x25_1 + ((x26_1 / 0x12c) * 0x12c)) == 0)
            {
                cs2p2p_PPPP_Proto_Send_SDevLgn_CRC(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, cs2p2p_gP2PServerAddr, (cs2p2p_gSDevInfo + 0x38), *(cs2p2p_gSDevInfo + 0x48), (cs2p2p_gSDevInfo + 0x40), *cs2p2p_gCRCKey);
                cs2p2p_PPPP_Proto_Send_SDevLgn_CRC(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gP2PServerAddr + 0x10), (cs2p2p_gSDevInfo + 0x38), *(cs2p2p_gSDevInfo + 0x48), (cs2p2p_gSDevInfo + 0x40), *cs2p2p_gCRCKey);
                cs2p2p_PPPP_Proto_Send_SDevLgn_CRC(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gP2PServerAddr + 0x20), (cs2p2p_gSDevInfo + 0x38), *(cs2p2p_gSDevInfo + 0x48), (cs2p2p_gSDevInfo + 0x40), *cs2p2p_gCRCKey);
            }
            
            if (cs2p2p_PPPP_Proto_Recv_ALL(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70, 0x64, &var_74, &var_78, &var_578, 0x500) == 0)
            {
                uint32_t x9_2 = var_74;
                uint64_t x8_12 = (x9_2 - 0x70);
                
                if (x8_12 <= 0x22)
                    switch (x8_12)
                    {
                        case 0:
                        {
                            if (var_78 == 0)
                                cs2p2p_PPPP_Proto_Send_RlyHelloAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70);
                            break;
                        }
                        case 2:
                        {
                            if (var_78 == 0)
                            {
                                cs2p2p_PPPP_Proto_Send_RlyPortAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70, *(cs2p2p_gSDevInfo + 0x34), (_byteswap(*(cs2p2p_gSDevInfo + 0x26)) >> 0x10));
                                cs2p2p_mSecSleep(0xa);
                                cs2p2p_PPPP_Proto_Send_RlyPortAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70, *(cs2p2p_gSDevInfo + 0x34), (_byteswap(*(cs2p2p_gSDevInfo + 0x26)) >> 0x10));
                                cs2p2p_mSecSleep(0xa);
                                cs2p2p_PPPP_Proto_Send_RlyPortAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70, *(cs2p2p_gSDevInfo + 0x34), (_byteswap(*(cs2p2p_gSDevInfo + 0x26)) >> 0x10));
                                cs2p2p_mSecSleep(0xa);
                                cs2p2p_PPPP_Proto_Send_RlyPortAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70, *(cs2p2p_gSDevInfo + 0x34), (_byteswap(*(cs2p2p_gSDevInfo + 0x26)) >> 0x10));
                                *(cs2p2p_gSDevInfo + 0x1b8) = 2;
                            }
                            break;
                        }
                        case 0x21:
                        {
                            cs2p2p_ntohAddr(&var_578, (cs2p2p_gSDevInfo + 0x24));
                            break;
                        }
                        case 0x22:
                        {
                            uint64_t x23_1 = var_78;
                            uint8_t* x0_24 = malloc((x23_1 + 4));
                            
                            if (cs2p2p_PPPP_CRCDec(&var_578, x23_1, x0_24, (x23_1 + 4), *cs2p2p_gCRCKey) != 0xffffffff)
                                cs2p2p_ntohAddr(x0_24, (cs2p2p_gSDevInfo + 0x24));
                            
                            free(x0_24);
                            break;
                        }
                    }
                else if (x9_2 == 2)
                {
                    cs2p2p_ntohAddr(&var_578, &s2);
                    cs2p2p_ntohAddr(var_ab8, &s2_1);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                    cs2p2p_mSecSleep(0xa);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                    cs2p2p_mSecSleep(0xa);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                    cs2p2p_mSecSleep(0xa);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                    cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                }
            }
            
            x8_11 = *(cs2p2p_gSDevInfo + 0x1b8);
            
            if (x8_11 != 1)
                break;
            
            x26_1 += 1;
            x25_1 -= 1;
        } while (*(cs2p2p_gSDevInfo + 0x60) != 0);
    }
    char x19_3 = 0;
    char x22_3 = 0;
    int32_t x23_3 = 0;
label_19050:
    
    if (((x8_11 & 0xff) == 2 && *(cs2p2p_gSDevInfo + 0x60) != 0))
    {
        do
        {
            if (cs2p2p_PPPP_Proto_Recv_ALL(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &var_70, 0x64, &var_74, &var_78, &var_578, 0x500) != 0)
            {
                if (x23_3 >= 0x33)
                    *(cs2p2p_gSDevInfo + 0x1b8) = 3;
                
                goto label_1921c;
            }
            
            uint32_t x8_28 = var_74;
            
            if (x8_28 == 0x83)
                goto label_19150;
            
            if (x8_28 == 2)
            {
                cs2p2p_ntohAddr(&var_578, &s2);
                cs2p2p_ntohAddr(var_ab8, &s2_1);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                cs2p2p_mSecSleep(0xa);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                cs2p2p_mSecSleep(0xa);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
                cs2p2p_mSecSleep(0xa);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2);
                cs2p2p_PPPP_Proto_Send_HelloToAck(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2_1);
            label_19150:
                
                if (var_78 == 0x1c)
                {
                    s2 = 0;
                    s2_1 = 0;
                    char var_5ac;
                    uint32_t var_5a8;
                    uint32_t var_5a4;
                    cs2p2p_PPPP_Proto_Read_RlyPkt(&var_578, &s2, &var_5a8, &s2_1, &var_5ac, &var_5a4);
                    int32_t x8_32;
                    
                    if (var_5a4 != *(cs2p2p_gSDevInfo + 0x34))
                        x8_32 = 0;
                    else if (var_5ac == 0)
                    {
                        strncpy((cs2p2p_gSDevInfo + 0x4c), &s2, 8);
                        strncpy((cs2p2p_gSDevInfo + 0x54), &s2_1, 8);
                        int128_t v0_2 = var_70;
                        x8_32 = 1;
                        x22_3 = 1;
                        *(cs2p2p_gSDevInfo + 0x5c) = var_5a8;
                        *(cs2p2p_gSDevInfo + 0x14) = v0_2;
                    }
                    else
                    {
                        x8_32 = 1;
                        x19_3 = 1;
                        *(cs2p2p_gSDevInfo + 4) = var_70;
                    }
                    
                    x23_3 = 0;
                    
                    if ((x8_32 & 1) != 0)
                    {
                    label_1921c:
                        x23_3 += 1;
                    }
                    
                    x8_11 = *(cs2p2p_gSDevInfo + 0x1b8);
                    
                    if (x22_3 == 0)
                        goto label_19050;
                    
                    if (x19_3 == 0)
                        goto label_19050;
                    
                    goto label_19238;
                }
            }
            
            x8_11 = *(cs2p2p_gSDevInfo + 0x1b8);
            
            if (x8_11 != 2)
                break;
            
            x23_3 = 0;
        } while (*(cs2p2p_gSDevInfo + 0x60) != 0);
    }
    
label_19238:
    
    if ((x8_11 & 0xff) == 2)
    {
        cs2p2p_PPPP_Proto_Send_RlyRdy(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 0x14), (cs2p2p_gSDevInfo + 0x4c), *(cs2p2p_gSDevInfo + 0x5c), (cs2p2p_gSDevInfo + 0x54));
        
        if (*(cs2p2p_gSDevInfo + 0x1b8) == 2)
        {
            cs2p2p_PPPP_Proto_Send_RlyRdy(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 4), (cs2p2p_gSDevInfo + 0x4c), *(cs2p2p_gSDevInfo + 0x5c), (cs2p2p_gSDevInfo + 0x54));
            
            if (*(cs2p2p_gSDevInfo + 0x1b8) == 2)
            {
                char x21_1 = 0;
                char x22_4 = 0;
                int32_t x23_4 = 0;
                
                while (*(cs2p2p_gSDevInfo + 0x60) != 0)
                {
                    int32_t x0_52 = cs2p2p_over_time_receive(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, &s2, 0x500, &s2_1, 0x64);
                    
                    if (x0_52 == 0)
                    {
                        x23_4 += 1;
                        int32_t x25_3 = (x23_4 % 5);
                        
                        if ((x22_4 == 0 && x25_3 == 0))
                            cs2p2p_PPPP_Proto_Send_RlyRdy(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 0x14), (cs2p2p_gSDevInfo + 0x4c), *(cs2p2p_gSDevInfo + 0x5c), (cs2p2p_gSDevInfo + 0x54));
                        
                        if ((x21_1 == 0 && x25_3 == 0))
                            cs2p2p_PPPP_Proto_Send_RlyRdy(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 4), (cs2p2p_gSDevInfo + 0x4c), *(cs2p2p_gSDevInfo + 0x5c), (cs2p2p_gSDevInfo + 0x54));
                        
                        if (x23_4 > 0x32)
                            break;
                    }
                    else
                    {
                        if ((x0_52 & 0x80000000) != 0)
                            break;
                        
                        if ((*s2_1[4] != *(cs2p2p_gSDevInfo + 0x18) || *s2_1[2] != *(cs2p2p_gSDevInfo + 0x16)))
                        {
                            cs2p2p_SendMessage(cs2p2p_gP2PKeyString, &s2, x0_52, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 0x14));
                            x23_4 = 0;
                            x21_1 = 1;
                        }
                        else
                        {
                            cs2p2p_SendMessage(cs2p2p_gP2PKeyString, &s2, x0_52, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 4));
                            x23_4 = 0;
                            x22_4 = 1;
                        }
                    }
                    
                    if (*(cs2p2p_gSDevInfo + 0x1b8) != 2)
                        break;
                }
            }
        }
    }
    
    *(cs2p2p_gSDevInfo + 0x1b8) = 3;
    cs2p2p_PPPP_Proto_Send_Close(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 4));
    cs2p2p_PPPP_Proto_Send_Close(cs2p2p_gP2PKeyString, *cs2p2p_gSDevInfo, (cs2p2p_gSDevInfo + 0x14));
    close(*cs2p2p_gSDevInfo);
    *(cs2p2p_gSDevInfo + 0x1b8) = 0;
    pthread_exit(nullptr);
    /* no return */
}

