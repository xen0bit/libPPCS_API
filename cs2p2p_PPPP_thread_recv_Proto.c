
void cs2p2p_PPPP_thread_recv_Proto(int32_t arg1) __noreturn

{
    if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) == 0)  {  // {"PKciP11sockaddr_inc"}}
    {
        int32_t* x27_1 = (cs2p2p_gSession + (arg1 * "PKciP11sockaddr_inc"));
        char var_a78;
        int64_t x8_2 = (&var_a78 | 4);
        void var_a60;
        void* var_bf0_1 = &var_a60;
        void* s2 = (x27_1 + 0x183);
        void* s2_1 = s2;
        
        while (true)
        {
        label_19600:
            
            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x54) != 0)  {  // {"PKciP11sockaddr_inc"}}
                break;
            
            uint32_t var_aa8;
            int16_t var_aa4;
            int64_t s;
            uint32_t len;
            uint16_t var_578;
            uint8_t var_574;
            int64_t var_560;
            struct in_addr in;
            int64_t var_550;
            
            if (*(x27_1 + "d_DevLgnAckPKciP11sockaddr_inc") != 0)
            {
                for (int64_t i = 0; i != 0x18; i += 8)
                {
                    void* x19_1 = *((x27_1 + "PPP_Proto_Send_ByteCountPKciP11s…") + i);
                    
                    if ((x19_1 != 0 && *(x19_1 + 0x4e) != 0))
                    {
                        uint64_t x22_1 = *(x19_1 + 0x3e);
                        memcpy(&var_560, *(x19_1 + 0x30), x22_1);
                        *(x19_1 + 0x3a) = 0;
                        *(x19_1 + 0x3e) = 0;
                        *(x19_1 + 0x4e) = 0;
                        
                        if (cs2p2p_PPPP_Proto_Read_Header(&var_560, &var_574, &var_578) == 0)
                        {
                            uint64_t x19_2 = var_578;
                            
                            if ((x22_1 - 4) == x19_2)
                            {
                                memcpy(&var_a78, &in, x19_2);
                                uint32_t x8_45 = var_574;
                                
                                if (x8_45 == 0x13)
                                {
                                    uint8_t* x0_7 = malloc((x19_2 + 4));
                                    
                                    if (cs2p2p_PPPP_CRCDec(&var_a78, x19_2, x0_7, (x19_2 + 4), *cs2p2p_gCRCKey) != 0xffffffff)
                                    {
                                        uint32_t x8_52 = *x0_7;
                                        *(x27_1 + 0x179) = x8_52;
                                        
                                        if (x8_52 == 0)
                                            *cs2p2p_gLastSuccessLoginTimeTCP = time(nullptr);
                                    }
                                    
                                    free(x0_7);
                                }
                                else if (x8_45 == 0x55)
                                {
                                    cs2p2p_PPPP_Proto_Read_TCPRlyReqAck(&var_a78, &var_560, &len);
                                    uint32_t x19_3 = var_560;
                                    
                                    if (len == 0)
                                    {
                                        if (x19_3 == 0xfa)
                                        {
                                            if (*(x27_1 + "_DevLgnAckPKciP11sockaddr_inc") == 0)
                                                goto label_197b0;
                                        }
                                        else if ((x19_3 == 0 && *(x27_1 + "_DevLgnAckPKciP11sockaddr_inc") == 0))
                                        {
                                        label_197b0:
                                            *(x27_1 + "_DevLgnAckPKciP11sockaddr_inc") = 1;
                                            size_t x0_13 = strlen(&x27_1[0x40]);
                                            void* x8_56 = *((x27_1 + "PPP_Proto_Send_ByteCountPKciP11s…") + i);
                                            
                                            if (x19_3 == 0)
                                            {
                                                if (x0_13 == 0)
                                                {
                                                    x19_3 = 0;
                                                    *(x8_56 + 0x49) = 1;
                                                }
                                                else
                                                {
                                                    x19_3 = 0;
                                                    *(x8_56 + 0x48) = 1;
                                                }
                                                
                                                goto label_19800;
                                            }
                                            
                                            if (x0_13 == 0)
                                                *(x8_56 + 0x4b) = 1;
                                            else
                                                *(x8_56 + 0x4a) = 1;
                                        }
                                    }
                                    
                                    if ((x19_3 & 0xfe) != 0xfa)
                                    {
                                    label_19800:
                                        uint32_t x8_58 = x27_1[0x5e];
                                        
                                        if ((x8_58 == 0xfe || x8_58 == 1))
                                            x27_1[0x5e] = x19_3;
                                    }
                                    else
                                    {
                                        *(x27_1 + "evLgnAckPKciP11sockaddr_inc") = 1;
                                        x27_1[0x5e] = 0;
                                    }
                                }
                                else if ((x8_45 == 0x52 && x19_2 == 0x30))
                                {
                                    cs2p2p_PPPP_Proto_Read_TCPRSStart(&var_a78, &len, &var_aa4, &s, &var_aa8, &var_560);
                                    int128_t v0_1 = var_560;
                                    uint32_t x9_2 = var_aa8;
                                    *(x27_1 + "_Z32cs2p2p_PPPP_Proto_Send_DevLg…") = var_550;
                                    *(x27_1 + "P11sockaddr_inj") = v0_1;
                                    *(x27_1 + "PKciP11sockaddr_inj") = x9_2;
                                    *(x27_1 + "nd_DevLgnAckPKciP11sockaddr_inc") = 1;
                                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                }
                            }
                        }
                    }
                }
            }
            
            int128_t addr;
            
            if (cs2p2p_PPPP_Proto_Recv_ALL(&x27_1[0x3a], *x27_1, &addr, 0x32, &var_574, &var_578, &var_a78, 0x500) == 0)
            {
                uint64_t x8_62 = (var_574 - 1);
                int32_t var_a70;
                int64_t s_1;
                int16_t var_a64;
                uint16_t var_55e;
                int32_t x1_70;
                sockaddr_in* x2_51;
                char* x3_34;
                uint32_t x4_16;
                
                if (x8_62 <= 0x8f)
                    switch (x8_62)
                    {
                        case 0:
                        {
                            *cs2p2p_gLastHelloAckTime = time(nullptr);
                            cs2p2p_ntohAddr(&var_a78, &x27_1[9]);
                            x27_1[5] = 2;
                            len = 0x10;
                            int32_t fd = cs2p2p_setup_Socket();
                            connect(fd, &addr, len);
                            getsockname(fd, &var_560, &len);
                            strncpy((cs2p2p_gNetInfo + 4), inet_ntoa(in), 0x10);
                            close(fd);
                            getsockname(*x27_1, &var_560, &len);
                            *(x27_1 + 0x16) = var_55e;
                            cs2p2p_GetInetAddrByName((cs2p2p_gNetInfo + 4), &x27_1[6]);
                        label_19b20:
                            
                            if (*(x27_1 + "d_DevLgnAckPKciP11sockaddr_inc") == 1)
                            {
                                *(x27_1 + "d_DevLgnAckPKciP11sockaddr_inc") = 2;
                                
                                if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                    break;
                                
                                continue;
                            }
                            break;
                        }
                        case 0x10:
                        {
                            uint32_t x8_81 = var_a78;
                            *(x27_1 + 0x179) = x8_81;
                            
                            if (x8_81 == 0)
                                *cs2p2p_gLastSuccessLoginTime = time(nullptr);
                            
                            goto label_19b20;
                        }
                        case 0x12:
                        {
                            uint64_t x22_5 = var_578;
                            uint8_t* x0_32 = malloc((x22_5 + 4));
                            
                            if (cs2p2p_PPPP_CRCDec(&var_a78, x22_5, x0_32, (x22_5 + 4), *cs2p2p_gCRCKey) == 0xffffffff)
                            {
                                free(x0_32);
                                
                                if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                    break;
                                
                                continue;
                            }
                            else
                            {
                                uint32_t x8_82 = *x0_32;
                                *(x27_1 + 0x179) = x8_82;
                                
                                if (x8_82 == 0)
                                    *cs2p2p_gLastSuccessLoginTime = time(nullptr);
                                
                                free(x0_32);
                            }
                            
                            goto label_19b20;
                        }
                        case 0x20:
                        {
                            uint32_t x8_84 = x27_1[0x5e];
                            
                            if ((x8_84 == 0xfe || x8_84 == 1))
                                x27_1[0x5e] = var_a78;
                            
                            goto label_19b20;
                        }
                        case 0x38:
                        {
                            uint64_t x19_7 = var_578;
                            __builtin_memset(&s, 0, 0x20);
                            uint8_t* x0_38 = malloc((x19_7 + 4));
                            cs2p2p__P2P_Proprietary_Decrypt("SSD@cs2-network.", &var_a78, x0_38, x19_7);
                            memcpy(&var_a78, x0_38, var_578);
                            free(x0_38);
                            
                            if ((x27_1[0x14] == 0 && *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x54) != 1))  {  // {"PKciP11sockaddr_inc"}}
                            {
                                int64_t x8_92 = var_a78;
                                int32_t x10_4 = x27_1[0x63];
                                uint32_t temp0_2 = _byteswap(var_a70);
                                len = x8_92;
                                s = s_1;
                                
                                if (temp0_2 == x10_4)
                                {
                                    uint32_t x22_7 = var_a64;
                                    
                                    if ((strcmp(&len, (x27_1 + 0x17b)) == 0 && (strcmp(&s, s2_1) == 0 && x22_7 != 0)))
                                    {
                                        void* x22_8 = var_bf0_1;
                                        int64_t x21_2 = 0;
                                        uint64_t x24_2 = _byteswap(x22_7);
                                        
                                        do
                                        {
                                            cs2p2p_ntohAddr(x22_8, &var_560);
                                            cs2p2p_PPPP_Proto_Send_SSDP2PReq(&x27_1[0x3a], *x27_1, &var_560, &len, temp0_2, &s, &x27_1[5]);
                                            x21_2 += 1;
                                            x22_8 += 0x10;
                                        } while (x21_2 < x24_2);
                                    }
                                }
                            }
                            
                            s2 = s2_1;
                            
                            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                break;
                            
                            continue;
                        }
                        case 0x39:
                        {
                            uint64_t x19_9 = var_578;
                            __builtin_memset(&s, 0, 0x20);
                            uint8_t* x0_48 = malloc((x19_9 + 4));
                            cs2p2p__P2P_Proprietary_Decrypt("SSD@cs2-network.", &var_a78, x0_48, x19_9);
                            memcpy(&var_a78, x0_48, var_578);
                            free(x0_48);
                            
                            if ((x27_1[0x14] == 1 && *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x54) != 1))  {  // {"PKciP11sockaddr_inc"}}
                            {
                                int64_t x8_99 = var_a78;
                                int32_t x10_6 = x27_1[0x63];
                                int32_t temp0_4 = _byteswap(var_a70);
                                len = x8_99;
                                s = s_1;
                                
                                if (temp0_4 == x10_6)
                                {
                                    uint32_t x22_10 = var_a64;
                                    
                                    if ((strcmp(&len, (x27_1 + 0x17b)) == 0 && (strcmp(&s, s2_1) == 0 && x22_10 != 0)))
                                    {
                                        void* x22_11 = var_bf0_1;
                                        int64_t x21_3 = 0;
                                        uint64_t x24_3 = _byteswap(x22_10);
                                        
                                        do
                                        {
                                            var_aa4 = 0x104;
                                            char var_aa2_1 = 3;
                                            cs2p2p_ntohAddr(x22_11, &var_560);
                                            *x27_1;
                                            *(cs2p2p_gNetInfo + 3);
                                            sockaddr_in* var_c30_1 = &x27_1[5];
                                            cs2p2p_PPPP_Proto_Send_SSDDevLgn();
                                            x21_3 += 1;
                                            x22_11 += 0x10;
                                        } while (x21_3 < x24_3);
                                    }
                                }
                            }
                            
                            s2 = s2_1;
                            
                            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                break;
                            
                            continue;
                        }
                        case 0x3e:
                        {
                            if (var_578 == 0x14)
                            {
                                uint8_t* x0_57 = malloc(0x18);
                                cs2p2p__P2P_Proprietary_Decrypt("SSD@cs2-network.", &var_a78, x0_57, 0x14);
                                memcpy(&var_a78, x0_57, var_578);
                                free(x0_57);
                                x27_1[0x19] = 1;
                                cs2p2p_ntohAddr(&var_a78, &var_560);
                                
                                if (((in + 1) >= 2 && *(x27_1 + 0x5a) != 1))
                                {
                                    uint32_t x10_12 = var_55e;
                                    uint32_t x9_46 = *s_1[6];
                                    uint32_t x21_6 = (_byteswap(*s_1[4]) >> 0x10);
                                    uint32_t* x8_187 = &x27_1[0x63];
                                    int32_t temp0_10 = _byteswap(x10_12);
                                    int32_t x19_16 = 0;
                                    int32_t x22_16 = 0;
                                    uint32_t x24_8;
                                    
                                    if (x9_46 != 0)
                                        x24_8 = x9_46;
                                    else
                                        x24_8 = 1;
                                    
                                    do
                                    {
                                        int32_t x1_64;
                                        uint32_t x4_24;
                                        uint16_t x8_188;
                                        
                                        if ((*s_1[7] == 0 && x19_16 == 0))
                                        {
                                            x1_64 = *x27_1;
                                            x4_24 = *x8_187;
                                            x8_188 = x10_12;
                                        label_1a7f8:
                                            var_55e = x8_188;
                                            cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], x1_64, &var_560, (x27_1 + 0x17b), x4_24, s2_1);
                                            x8_187 = &x27_1[0x63];
                                        }
                                        else if (x19_16 != 0)
                                        {
                                            if (x19_16 <= temp0_10)
                                            {
                                                int32_t x1_65 = *x27_1;
                                                uint32_t x4_25 = x27_1[0x63];
                                                var_55e = (_byteswap((temp0_10 - x22_16)) >> 0x10);
                                                cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], x1_65, &var_560, (x27_1 + 0x17b), x4_25, s2_1);
                                                x8_187 = &x27_1[0x63];
                                            }
                                            
                                            if ((temp0_10 ^ 0xffff) >= x19_16)
                                            {
                                                x1_64 = *x27_1;
                                                x4_24 = x27_1[0x63];
                                                x8_188 = (_byteswap((x22_16 + temp0_10)) >> 0x10);
                                                goto label_1a7f8;
                                            }
                                        }
                                        x22_16 = (x19_16 + x24_8);
                                        x19_16 = (x22_16 & 0xffff);
                                    } while (x19_16 <= x21_6);
                                }
                            }
                            
                            s2 = s2_1;
                            
                            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                break;
                            
                            continue;
                        }
                        case 0x3f:
                        {
                            cs2p2p_ntohAddr(&var_a78, &var_560);
                            
                            if (((in + 1) >= 2 && *(x27_1 + 0x5a) != 1))
                            {
                                if (*(x27_1 + 0x5b) == 0)
                                {
                                    s = 0x104;
                                    *s[2] = 3;
                                    *(x27_1 + 0x5b) = 1;
                                    int64_t i_1 = 0;
                                    *cs2p2p_gSmartP2PPunchIncrememt = 0;
                                    
                                    do
                                    {
                                        uint32_t x8_114 = x27_1[0x14];
                                        void* x9_16;
                                        
                                        if (x8_114 == 0)
                                            x9_16 = &x27_1[0x4e];
                                        else
                                            x9_16 = cs2p2p_gP2PServerAddr;
                                        
                                        len = *(x9_16 + i_1);
                                        int32_t x1_36 = *x27_1;
                                        *len[2] = (_byteswap((*cs2p2p_gSmartP2PPunchIncrememt + 0x7d65)) >> 0x10);
                                        char* s2_2;
                                        char* x22_12;
                                        
                                        if (x8_114 == 0)
                                        {
                                            x22_12 = (x27_1 + 0x17b);
                                            s2_2 = s2_1;
                                            cs2p2p_PPPP_Proto_Send_P2PReq(&x27_1[0x3a], x1_36, &len, x22_12, x27_1[0x63], s2_2, &x27_1[5]);
                                        }
                                        else
                                        {
                                            x22_12 = (x27_1 + 0x17b);
                                            s2_2 = s2_1;
                                            *(cs2p2p_gNetInfo + 3);
                                            sockaddr_in* var_c30_2 = &x27_1[5];
                                            uint64_t var_c28_1 = *cs2p2p_gCRCKey;
                                            cs2p2p_PPPP_Proto_Send_DevLgn_CRC();
                                        }
                                        
                                        cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], *x27_1, &var_560, x22_12, x27_1[0x63], s2_2);
                                        int32_t x1_38 = *x27_1;
                                        uint32_t x9_23 = x27_1[0x14];
                                        uint32_t x4_13 = x27_1[0x63];
                                        *len[2] = (_byteswap((*cs2p2p_gSmartP2PPunchIncrememt + 0x7d66)) >> 0x10);
                                        
                                        if (x9_23 == 0)
                                            cs2p2p_PPPP_Proto_Send_P2PReq(&x27_1[0x3a], x1_38, &len, x22_12, x4_13, s2_2, &x27_1[5]);
                                        else
                                        {
                                            *(cs2p2p_gNetInfo + 3);
                                            sockaddr_in* var_c30_3 = &x27_1[5];
                                            uint64_t var_c28_2 = *cs2p2p_gCRCKey;
                                            cs2p2p_PPPP_Proto_Send_DevLgn_CRC();
                                        }
                                        
                                        i_1 += 0x10;
                                    } while (i_1 != 0x30);
                                }
                                
                                cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2_1);
                                struct in_addr in_2 = in;
                                uint32_t x8_123 = (_byteswap(var_55e) >> 0x10);
                                int16_t i_4;
                                
                                if (x8_123 > 3)
                                    i_4 = (x8_123 - 3);
                                else
                                    i_4 = 0;
                                
                                uint32_t x19_12;
                                
                                if (x8_123 < 0xfffc)
                                    x19_12 = (x8_123 + 3);
                                else
                                    x19_12 = 0xffff;
                                
                                uint32_t i_2 = i_4;
                                
                                if (x27_1[0xa] != in_2)
                                {
                                    uint32_t i_5 = i_2;
                                    
                                    if (x19_12 >= i_2)
                                    {
                                        do
                                        {
                                            int32_t x1_67 = *x27_1;
                                            uint32_t x4_26 = x27_1[0x63];
                                            var_55e = (_byteswap(i_5) >> 0x10);
                                            cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], x1_67, &var_560, (x27_1 + 0x17b), x4_26, s2_1);
                                            
                                            if (x19_12 == i_5)
                                                break;
                                            
                                            i_5 = (i_5 + 1);
                                        } while (x19_12 >= i_5);
                                    }
                                }
                                else
                                    cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2_1);
                                
                                if (x27_1[0xa] == in)
                                    cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2_1);
                                else if (x19_12 >= i_2)
                                {
                                    uint32_t i_6 = i_2;
                                    
                                    do
                                    {
                                        int32_t x1_69 = *x27_1;
                                        uint32_t x4_28 = x27_1[0x63];
                                        var_55e = (_byteswap(i_6) >> 0x10);
                                        cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], x1_69, &var_560, (x27_1 + 0x17b), x4_28, s2_1);
                                        
                                        if (x19_12 == i_6)
                                            break;
                                        
                                        i_6 = (i_6 + 1);
                                    } while (x19_12 >= i_6);
                                }
                                
                                if (x27_1[0xa] == in)
                                {
                                    s2 = s2_1;
                                    x1_70 = *x27_1;
                                    x3_34 = (x27_1 + 0x17b);
                                    x2_51 = &var_560;
                                    x4_16 = x27_1[0x63];
                                    goto label_1a960;
                                }
                                
                                s2 = s2_1;
                                
                                for (; x19_12 >= i_2; i_2 = (i_2 + 1))
                                {
                                    int32_t x1_71 = *x27_1;
                                    uint32_t x4_29 = x27_1[0x63];
                                    var_55e = (_byteswap(i_2) >> 0x10);
                                    cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], x1_71, &var_560, (x27_1 + 0x17b), x4_29, s2);
                                    
                                    if (x19_12 == i_2)
                                        break;
                                }
                            }
                            break;
                        }
                        case 0x40:
                        {
                            var_560 = 0;
                            len = 0;
                            cs2p2p_PPPP_Proto_Read_PunchPkt(&var_a78, &var_560, &s, &len);
                            
                            if (((*(x27_1 + 0x5a) != 1 && strncmp(&var_560, (x27_1 + 0x17b), 8) == 0) && strncmp(&len, s2, 8) == 0))
                            {
                                x4_16 = s;
                                
                                if (x4_16 == x27_1[0x63])
                                {
                                    if (x27_1[0x14] == 0)
                                    {
                                        x1_70 = *x27_1;
                                        x3_34 = (x27_1 + 0x17b);
                                        x2_51 = &addr;
                                    label_1a960:
                                        cs2p2p_PPPP_Proto_Send_PunchPkt(&x27_1[0x3a], x1_70, x2_51, x3_34, x4_16, s2);
                                        
                                        if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                            break;
                                        
                                        continue;
                                    }
                                    else if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x54) != 1)  {  // {"PKciP11sockaddr_inc"}}
                                    {
                                        cs2p2p_PPPP_Proto_Send_P2PRdy(&x27_1[0x3a], *x27_1, &addr, (x27_1 + 0x17b), x4_16, s2);
                                        cs2p2p_mSecSleep(0xa);
                                        cs2p2p_PPPP_Proto_Send_P2PRdy(&x27_1[0x3a], *x27_1, &addr, (x27_1 + 0x17b), x27_1[0x63], s2);
                                        cs2p2p_mSecSleep(0xa);
                                        cs2p2p_PPPP_Proto_Send_P2PRdy(&x27_1[0x3a], *x27_1, &addr, (x27_1 + 0x17b), x27_1[0x63], s2);
                                        cs2p2p_mSecSleep(0xa);
                                        cs2p2p_PPPP_Proto_Send_P2PRdy(&x27_1[0x3a], *x27_1, &addr, (x27_1 + 0x17b), x27_1[0x63], s2);
                                    label_1a204:
                                        *(x27_1 + 4) = addr;
                                        *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x54) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                        x27_1[0xd] = time(nullptr);
                                        *(x27_1 + 0x51) = 0;
                                        *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                        
                                        if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                            break;
                                        
                                        continue;
                                    }
                                }
                            }
                            break;
                        }
                        case 0x41:
                        {
                            var_560 = 0;
                            len = 0;
                            cs2p2p_PPPP_Proto_Read_P2PRdy(&var_a78, &var_560, &s, &len);
                            
                            if ((*(x27_1 + 0x5a) != 1 && strncmp(&var_560, (x27_1 + 0x17b), 8) == 0))
                            {
                                int32_t x0_82;
                                int128_t v0_4;
                                x0_82 = strncmp(&len, s2, 8);
                                
                                if ((x0_82 == 0 && s == x27_1[0x63]))
                                    goto label_1a204;
                            }
                            break;
                        }
                        case 0x51:
                        {
                            if ((var_578 == 0x30 && *(x27_1 + "PPP_Proto_Send_DevLgnAckPKciP11s…") != 0))
                            {
                                cs2p2p_PPPP_Proto_Read_TCPRSStart(&var_a78, &len, &var_aa4, &s, &var_aa8, &var_560);
                                int128_t v0_2 = var_560;
                                uint32_t x9_6 = var_aa8;
                                *(x27_1 + "_Z32cs2p2p_PPPP_Proto_Send_DevLg…") = var_550;
                                *(x27_1 + "P11sockaddr_inj") = v0_2;
                                *(x27_1 + "PKciP11sockaddr_inj") = x9_6;
                                *(x27_1 + "nd_DevLgnAckPKciP11sockaddr_inc") = 1;
                                *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                
                                if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                    break;
                                
                                continue;
                            }
                            break;
                        }
                        case 0x68:
                        {
                            if (*(x27_1 + "d_DevLgnAckPKciP11sockaddr_inc") == 1)
                                *(x27_1 + "d_DevLgnAckPKciP11sockaddr_inc") = 2;
                            
                            uint32_t x8_142 = *(x27_1 + 0x17a);
                            
                            if (x8_142 == 0xfb)
                            {
                            label_1a26c:
                                uint64_t x8_145 = var_a78;
                                *(x27_1 + 0x17a) = 0xfc;
                                
                                if (x8_145 != 0)
                                {
                                    void* x19_14 = var_bf0_1;
                                    int64_t x24_6 = 0;
                                    uint64_t x22_14 = 1;
                                    int64_t x21_5;
                                    
                                    do
                                    {
                                        x21_5 = (x24_6 + 1);
                                        uint64_t x8_146 = x8_145;
                                        uint64_t x9_29 = x21_5;
                                        
                                        if (x21_5 < x8_146)
                                        {
                                            void* x11_4 = x19_14;
                                            x9_29 = x22_14;
                                            
                                            while (*((x8_2 + (x24_6 << 4)) + 4) != *x11_4)
                                            {
                                                x9_29 += 1;
                                                x11_4 += 0x10;
                                                
                                                if (x9_29 >= x8_146)
                                                    break;
                                            }
                                        }
                                        
                                        if (x9_29 == x8_146)
                                        {
                                            cs2p2p_ntohAddr((x8_2 + (x24_6 << 4)), &var_560);
                                            struct in_addr in_1 = in;
                                            
                                            if ((in_1 != *(x27_1 + "eqPK19st_cs2p2p_TCPRlyReqPcPjS2_…") && (in_1 != *(x27_1 + "TCPRlyReqPcPjS2_S2_PhS2_P12socka…") && (in_1 != *(x27_1 + "S2_PhS2_P12sockaddr_cs2") && in_1 != *(x27_1 + "ddr_cs2")))))
                                            {
                                                if (x24_6 == (var_a78 - 1))
                                                    cs2p2p_PPPP_Proto_Send_RlyHello(&x27_1[0x3a], *x27_1, &var_560);
                                                else if (*(x27_1 + 0x59) == 0)
                                                {
                                                    cs2p2p_PPPP_Proto_Send_RlyHello(&x27_1[0x3a], *x27_1, &var_560);
                                                    cs2p2p_mSecSleep(0xa);
                                                }
                                            }
                                        }
                                        
                                        x8_145 = var_a78;
                                        x22_14 += 1;
                                        x19_14 += 0x10;
                                        x24_6 = x21_5;
                                    } while (x21_5 < x8_145);
                                }
                            }
                            else if ((x8_142 == 0xfc && *(x27_1 + 0x59) != 0))
                                goto label_1a26c;
                            
                            s2 = s2_1;
                            
                            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                break;
                            
                            continue;
                        }
                        case 0x70:
                        {
                            if ((*(x27_1 + 0x17a) + 5) <= 1)
                            {
                                pthread_mutex_lock(&data_50d02c);
                                uint32_t x8_158 = *(x27_1 + "vLgnAckPKciP11sockaddr_inc");
                                
                                if (x8_158 == 0)
                                    *(x27_1 + "vLgnAckPKciP11sockaddr_inc") = 1;
                                else if (x8_158 == 2)
                                {
                                    pthread_mutex_unlock(&data_50d02c);
                                    
                                    if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                        break;
                                    
                                    continue;
                                }
                                
                                pthread_mutex_unlock(&data_50d02c);
                                int128_t addr_1 = addr;
                                *(x27_1 + 0x17a) = 0xfd;
                                *(x27_1 + 0x168) = addr_1;
                                cs2p2p_PPPP_Proto_Send_RlyPort(&x27_1[0x3a], *x27_1, &x27_1[0x5a]);
                                
                                if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                    break;
                                
                                continue;
                            }
                            break;
                        }
                        case 0x72:
                        {
                            if ((*(x27_1 + 0x17a) + 5) <= 2)
                            {
                                *(x27_1 + 0x17a) = 0xfe;
                                cs2p2p_PPPP_Proto_Read_RlyPortAck(&var_a78, &var_560, &len);
                                uint32_t x7_1 = var_560;
                                *(x27_1 + 0x16a) = (_byteswap(len) >> 0x10);
                                x27_1[0x64] = x7_1;
                                cs2p2p_PPPP_Proto_Send_RlyReq(&x27_1[0x3a], *x27_1, &x27_1[0x4e], (x27_1 + 0x17b), x27_1[0x63], s2_1, &x27_1[0x5a], x7_1);
                                cs2p2p_PPPP_Proto_Send_RlyReq(&x27_1[0x3a], *x27_1, &x27_1[0x52], (x27_1 + 0x17b), x27_1[0x63], s2_1, &x27_1[0x5a], x27_1[0x64]);
                                s2 = s2_1;
                                cs2p2p_PPPP_Proto_Send_RlyReq(&x27_1[0x3a], *x27_1, &x27_1[0x56], (x27_1 + 0x17b), x27_1[0x63], s2, &x27_1[0x5a], x27_1[0x64]);
                                
                                if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                    break;
                                
                                continue;
                            }
                            break;
                        }
                        case 0x80:
                        {
                            if (*(x27_1 + 0x17a) == 0xfe)
                            {
                                *(x27_1 + 0x17a) = 0xff;
                                
                                if (*(x27_1 + 0x59) == 0)
                                {
                                    *(x27_1 + 0x59) = 1;
                                    
                                    if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                        break;
                                    
                                    continue;
                                }
                            }
                            break;
                        }
                        case 0x81:
                        {
                            cs2p2p_PPPP_Proto_Read_RlyTo(&var_a78, &var_560, &len);
                            int64_t x11_5 = -1;
                            int64_t (* x10_10)() = (cs2p2p_gSession + 8);
                            
                            while ((*(x10_10 - 8) == 0xffffffff || (*x10_10 != in || *(x10_10 - 2) != var_55e)))
                            {
                                x11_5 += 1;
                                x10_10 += "PKciP11sockaddr_inc";
                                
                                if (x11_5 >= 0xff)
                                {
                                    cs2p2p_PPPP_Proto_Send_RlyPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2, x27_1[0x14], len);
                                    cs2p2p_PPPP_Proto_Send_RlyPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2, x27_1[0x14], len);
                                    cs2p2p_PPPP_Proto_Send_RlyPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2, x27_1[0x14], len);
                                    cs2p2p_PPPP_Proto_Send_RlyPkt(&x27_1[0x3a], *x27_1, &var_560, (x27_1 + 0x17b), x27_1[0x63], s2, x27_1[0x14], len);
                                    
                                    if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) == 0)  {  // {"PKciP11sockaddr_inc"}}
                                        goto label_19600;
                                    
                                    goto label_1a9d8;
                                }
                            }
                            break;
                        }
                        case 0x83:
                        {
                            var_560 = 0;
                            len = 0;
                            cs2p2p_PPPP_Proto_Read_RlyRdy(&var_a78, &var_560, &s, &len);
                            int64_t x11_6 = -1;
                            int64_t (* x10_11)() = (cs2p2p_gSession + 8);
                            int16_t var_56e;
                            int32_t i_3;
                            
                            while ((*(x10_11 - 8) == 0xffffffff || (*x10_11 != i_3 || *(x10_11 - 2) != var_56e)))
                            {
                                x11_6 += 1;
                                x10_11 += "PKciP11sockaddr_inc";
                                
                                if (x11_6 >= 0xff)
                                {
                                    if (strncmp(&var_560, (x27_1 + 0x17b), 8) == 0)
                                    {
                                        int32_t x0_96;
                                        int128_t v0_5;
                                        x0_96 = strncmp(&len, s2, 8);
                                        
                                        if ((x0_96 == 0 && s == x27_1[0x63]))
                                        {
                                            *(x27_1 + 4) = addr;
                                            *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x54) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                            x27_1[0xd] = time(nullptr);
                                            *(x27_1 + 0x51) = 1;
                                            *(x27_1 + 0x17a) = 1;
                                            *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                            
                                            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                                break;
                                            
                                            continue;
                                        }
                                    }
                                    
                                    break;
                                }
                            }
                            break;
                        }
                        case 0x8f:
                        {
                            if ((*(cs2p2p_gSDevInfo + 0x60) != 0 && *(cs2p2p_gSDevInfo + 0x1b8) == 0))
                            {
                                *(cs2p2p_gSDevInfo + 0x1b8) = 1;
                                *(cs2p2p_gSDevInfo + 0x48) = x27_1[0x63];
                                strncpy((cs2p2p_gSDevInfo + 0x38), (x27_1 + 0x17b), 8);
                                strncpy((cs2p2p_gSDevInfo + 0x40), s2, 8);
                                pthread_create((cs2p2p_gSDevInfo + 0x1b0), 0, cs2p2p_PPPP_thread_SuperDevice, 0);
                            }
                            
                            if ((*(cs2p2p_gSDevInfo + 0x61) != 0 && *(cs2p2p_gSDevInfo + 0x62) == 0))
                            {
                                *(cs2p2p_gSDevInfo + 0x62) = 1;
                                pthread_create((cs2p2p_gSDevInfo + 0x1a8), 0, cs2p2p_PPPP_thread_SmartSuperDevice, 0);
                                
                                if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                                    break;
                                
                                continue;
                            }
                            break;
                        }
                    }
            }
            
            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) != 0)  {  // {"PKciP11sockaddr_inc"}}
                break;
        }
    }
    
label_1a9d8:
    pthread_exit(nullptr);
    /* no return */
}

