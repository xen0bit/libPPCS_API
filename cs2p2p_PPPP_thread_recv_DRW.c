
void cs2p2p_PPPP_thread_recv_DRW(int32_t arg1) __noreturn

{
    time_t var_6f0 = time(nullptr);
    int64_t x23 = arg1;
    
    if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) == 0)  {  // {"PKciP11sockaddr_inc"}}
    {
        int32_t* x21_1 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
        int64_t var_768_1 = x23;
        int16_t x24_1 = 0;
        int32_t* x20_1 = &x21_1[0x17];
        char* x25_1 = &x21_1[0x3a];
        int32_t var_70c_1 = 0;
        int32_t var_708_1 = 3;
        void var_6b4;
        void* var_760_1 = &var_6b4;
        int32_t* var_6e8_1 = x20_1;
        char* var_6e0_1 = x25_1;
        
        while (true)
        {
            int32_t x0_1 = *(x21_1 + "nAckPKciP11sockaddr_inc");
            int32_t var_6c4;
            uint16_t var_6c0;
            st_cs2p2p_DRWAckHeader var_6b8;
            uint16_t var_78;
            uint8_t var_74;
            
            if (x0_1 == 0xffffffff)
            {
                uint32_t x22_2 = (*x20_1 + 1);
                sockaddr_in var_70;
                int32_t x0_16 = cs2p2p_PPPP_Proto_Recv_ALL(x25_1, *x21_1, &var_70, x22_2, &var_74, &var_78, &var_6b8, 0x640);
                int32_t var_6c;
                
                if (x0_16 == 0)
                {
                    int16_t var_6e;
                    
                    if (x21_1[2] != var_6c)
                    {
                        x25_1 = var_6e0_1;
                        
                        if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) != 0)  {  // {"PKciP11sockaddr_inc"}}
                            break;
                        
                        continue;
                    }
                    else if (*(x21_1 + 6) != var_6e)
                    {
                        x25_1 = var_6e0_1;
                        
                        if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) != 0)  {  // {"PKciP11sockaddr_inc"}}
                            break;
                        
                        continue;
                    }
                }
                pthread_mutex_lock(&data_50d02c);
                int32_t x0_17 = cs2p2p_CurrentTickCount();
                
                if ((x0_17 - x21_1[0x18]) >= *x20_1)
                    cs2p2p_DoDRWSend(arg1);
                
                if (x0_16 == 0)
                {
                    uint32_t x9_6 = var_74;
                    uint64_t x8_29 = (x9_6 - 0xd0);
                    
                    if (x8_29 > 0x20)
                    {
                        if ((x9_6 == 0x42 && x21_1[0x14] == 0))
                            cs2p2p_PPPP_Proto_Send_Alive(var_6e0_1, *x21_1, &x21_1[1]);
                        
                        goto label_18110;
                    }
                    
                    switch (x8_29)
                    {
                        case 0:
                        {
                            if (cs2p2p_PPPP_DRW_Read_Header(&var_6b8, &var_6c4, &var_6c0) == 0)
                            {
                                uint64_t x26_2 = var_6c4;
                                
                                if (x26_2 >= 8)
                                {
                                    *(x21_1 + 0x56) = 1;
                                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                }
                                else if (var_78 >= 5)
                                {
                                    if (*(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 << 5)) + 0x4ac) <= 0x20000)
                                    {
                                    label_17ed8:
                                        uint64_t x9_46 = *(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 << 1)) + "ockaddr_inc");
                                        
                                        if (x9_46 <= 0x51)
                                        {
                                            uint32_t x25_5 = var_6c0;
                                            *((((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 * 0xa4)) + (x9_46 << 1)) + "cs2p2p_PPPP_Proto_Send_SDevLgnPK…") = x25_5;
                                            uint16_t x5_2 = (*(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 << 1)) + "ockaddr_inc") + 1);
                                            *(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 << 1)) + "ockaddr_inc") = x5_2;
                                            
                                            if (x5_2 >= 0x11)
                                            {
                                                int64_t x20_6 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
                                                cs2p2p_PPPP_DRWAck_Send(var_6e0_1, *x21_1, &x21_1[1], x26_2, &*"cs2p2p_PPPP_Proto_Send_SDevLgnPK…"[(x20_6 + (x26_2 * 0xa4))], x5_2);
                                                x26_2 = var_6c4;
                                                x25_5 = var_6c0;
                                                x20_1 = var_6e8_1;
                                                *((x20_6 + (x26_2 << 1)) + "ockaddr_inc") = 0;
                                            }
                                            
                                            uint32_t x9_50 = *(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 << 1)) + 0x5a8);
                                            uint32_t x8_95 = (x9_50 - x25_5);
                                            uint32_t x8_97;
                                            
                                            if (x9_50 <= x25_5)
                                            {
                                                x8_97 = (x25_5 - x9_50);
                                                
                                                if (x8_97 <= 0x8000)
                                                    goto label_18044;
                                                
                                                x8_95 = ((x9_50 | 0x10000) - x25_5);
                                            label_18034:
                                                
                                                if (x8_95 <= 0)
                                                    goto label_1804c;
                                            }
                                            else
                                            {
                                                if (x8_95 <= 0x8000)
                                                    goto label_18034;
                                                
                                                x8_97 = ((0x10000 - x9_50) + x25_5);
                                            label_18044:
                                                
                                                if (-(x8_97) <= 0)
                                                {
                                                label_1804c:
                                                    uint32_t x20_8 = var_78;
                                                    uint32_t* s_2 = malloc(0x28);
                                                    
                                                    if (s_2 == 0)
                                                    {
                                                        *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                                        x21_1[0x16] = 1;
                                                    }
                                                    else
                                                    {
                                                        size_t bytes_3 = (x20_8 - 4);
                                                        __builtin_memset(s_2, 0, 0x28);
                                                        int64_t x0_48 = malloc(bytes_3);
                                                        *(s_2 + 8) = x0_48;
                                                        
                                                        if (x0_48 == 0)
                                                        {
                                                            free(s_2);
                                                            *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                                            x21_1[0x16] = 1;
                                                        }
                                                        else
                                                        {
                                                            *s_2 = x25_5;
                                                            s_2[1] = (x20_8 - 4);
                                                            memcpy(x0_48, var_760_1, bytes_3);
                                                            int64_t x20_9 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
                                                            cs2p2p_sll_Put(((x20_9 + (x26_2 << 5)) + 0x498), s_2);
                                                            sem_post(((x20_9 + (var_6c4 << 4)) + 0x68));
                                                        }
                                                    }
                                                    
                                                label_18100:
                                                    x20_1 = var_6e8_1;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        uint32_t x9_13 = var_6c0;
                                        uint32_t x10_1 = *(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x26_2 << 1)) + 0x5a8);
                                        uint32_t x8_45 = (x9_13 - x10_1);
                                        uint32_t x8_47;
                                        
                                        if (x9_13 <= x10_1)
                                        {
                                            x8_47 = (x10_1 - x9_13);
                                            
                                            if (x8_47 <= 0x8000)
                                                goto label_17ebc;
                                            
                                            x8_45 = ((x9_13 | 0x10000) - x10_1);
                                        label_17e8c:
                                            
                                            if (x8_45 <= 0)
                                                goto label_17ed8;
                                        }
                                        else
                                        {
                                            if (x8_45 <= 0x8000)
                                                goto label_17e8c;
                                            
                                            x8_47 = ((0x10000 - x9_13) + x10_1);
                                        label_17ebc:
                                            
                                            if (-(x8_47) <= 0)
                                                goto label_17ed8;
                                        }
                                    }
                                }
                            }
                            
                            var_708_1 = 0;
                            x24_1 = 0;
                            goto label_18110;
                        }
                        case 1:
                        {
                            if (cs2p2p_PPPP_DRWAck_Read_Header(&var_6b8, &var_6c4, &var_6c0) == 0)
                            {
                                uint64_t x8_38 = var_6c4;
                                uint32_t x9_8;
                                
                                if (x8_38 < 8)
                                    x9_8 = var_6c0;
                                
                                if ((x8_38 >= 8 || x9_8 >= 0x52))
                                {
                                    *(x21_1 + 0x56) = 1;
                                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                }
                                else if (x9_8 != 0)
                                {
                                    int64_t i = 0;
                                    
                                    do
                                    {
                                        var_708_1 = i;
                                        uint64_t x10_2 = (x8_38 & 0xff);
                                        uint32_t x22_4 = (_byteswap(*(var_760_1 + (i << 1))) >> 0x10);
                                        void* x0_34 = cs2p2p_sll_Search_ByIndex((((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x10_2 << 5)) + 0x398), x22_4, nullptr);
                                        
                                        if (x0_34 != 0)
                                        {
                                            void* x8_58 = *(x0_34 + 0x20);
                                            cs2p2p___the_SLL* x8_60;
                                            
                                            if (x8_58 == 0)
                                                x8_60 = (((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x10_2 << 5)) + 0x398);
                                            else
                                                x8_60 = (x8_58 + 0x18);
                                            
                                            *x8_60 = *(x0_34 + 0x18);
                                            void* x8_61 = *(x0_34 + 0x18);
                                            void* x9_20 = ((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x10_2 << 5));
                                            int64_t* x8_62;
                                            
                                            if (x8_61 == 0)
                                                x8_62 = (x9_20 + 0x3a0);
                                            else
                                                x8_62 = (x8_61 + 0x20);
                                            
                                            *x8_62 = *(x0_34 + 0x20);
                                            *(x0_34 + 0x18) = 0;
                                            *(x0_34 + 0x20) = 0;
                                            int32_t x10_5 = *(x9_20 + 0x3ac);
                                            *(x9_20 + 0x3a8) -= 1;
                                            *(x9_20 + 0x3ac) = (x10_5 - *(x0_34 + 4));
                                            int32_t x8_67 = *(x0_34 + 0x10);
                                            
                                            if (x8_67 != 0xffffffff)
                                            {
                                                int32_t x8_68 = (x0_17 - x8_67);
                                                
                                                if (*var_6e8_1 > x8_68)
                                                    *var_6e8_1 = (x8_68 + 1);
                                            }
                                            
                                            int64_t x0_35 = *(x0_34 + 8);
                                            
                                            if (x0_35 != 0)
                                                free(x0_35);
                                            
                                            free(x0_34);
                                            x23 = var_768_1;
                                        }
                                        
                                        uint64_t x9_22 = var_6c4;
                                        void* x0_38 = cs2p2p_sll_Search_ByIndex((((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x9_22 << 5)) + 0x298), x22_4, nullptr);
                                        
                                        if (x0_38 != 0)
                                        {
                                            void* x8_72 = *(x0_38 + 0x20);
                                            cs2p2p___the_SLL* x8_74;
                                            
                                            if (x8_72 == 0)
                                                x8_74 = (((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x9_22 << 5)) + 0x298);
                                            else
                                                x8_74 = (x8_72 + 0x18);
                                            
                                            *x8_74 = *(x0_38 + 0x18);
                                            void* x8_75 = *(x0_38 + 0x18);
                                            void* x9_25 = ((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x9_22 << 5));
                                            int64_t* x8_76;
                                            
                                            if (x8_75 == 0)
                                                x8_76 = (x9_25 + 0x2a0);
                                            else
                                                x8_76 = (x8_75 + 0x20);
                                            
                                            *x8_76 = *(x0_38 + 0x20);
                                            *(x0_38 + 0x18) = 0;
                                            *(x0_38 + 0x20) = 0;
                                            int32_t x10_9 = *(x9_25 + 0x2ac);
                                            *(x9_25 + 0x2a8) -= 1;
                                            *(x9_25 + 0x2ac) = (x10_9 - *(x0_38 + 4));
                                            int32_t x8_81 = *(x0_38 + 0x10);
                                            
                                            if (x8_81 != 0xffffffff)
                                            {
                                                int32_t x8_82 = (x0_17 - x8_81);
                                                
                                                if (*var_6e8_1 > x8_82)
                                                    *var_6e8_1 = (x8_82 + 1);
                                            }
                                            
                                            int64_t x0_39 = *(x0_38 + 8);
                                            
                                            if (x0_39 != 0)
                                                free(x0_39);
                                            
                                            free(x0_38);
                                            x23 = var_768_1;
                                        }
                                        
                                        x8_38 = var_6c4;
                                        
                                        while (*(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x8_38 << 5)) + 0x3a8) != 0)
                                        {
                                            void* x9_31 = ((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x8_38 << 5));
                                            int16_t* x1_19 = *(x9_31 + 0x398);
                                            uint32_t x10_11 = *x1_19;
                                            
                                            if (x22_4 <= x10_11)
                                            {
                                                uint32_t x10_13 = (x10_11 - x22_4);
                                                
                                                if ((x10_13 <= 0x8000 && x10_13 > 0))
                                                    break;
                                            }
                                            else if (((x22_4 - x10_11) > 0x8000 && ((0x10000 - x22_4) + x10_11) > 0))
                                                break;
                                            
                                            if (x1_19 != 0)
                                            {
                                                void* x10_14 = *(x1_19 + 0x20);
                                                void* x9_33;
                                                
                                                if (x10_14 == 0)
                                                    x9_33 = (x9_31 + 0x398);
                                                else
                                                    x9_33 = (x10_14 + 0x18);
                                                
                                                *x9_33 = *(x1_19 + 0x18);
                                                void* x10_15 = ((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x8_38 << 5));
                                                void* x9_34 = *(x1_19 + 0x18);
                                                int64_t* x9_35;
                                                
                                                if (x9_34 == 0)
                                                    x9_35 = (x10_15 + 0x3a0);
                                                else
                                                    x9_35 = (x9_34 + 0x20);
                                                
                                                *x9_35 = *(x1_19 + 0x20);
                                                *(x1_19 + 0x18) = 0;
                                                *(x1_19 + 0x20) = 0;
                                                int32_t x11_8 = *(x10_15 + 0x3ac);
                                                *(x10_15 + 0x3a8) -= 1;
                                                *(x10_15 + 0x3ac) = (x11_8 - *(x1_19 + 4));
                                            }
                                            
                                            int64_t x24_5 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
                                            cs2p2p_sll_Put(((x24_5 + (x8_38 << 5)) + 0x298), x1_19);
                                            x8_38 = var_6c4;
                                            uint32_t x10_16 = *((x24_5 + (x8_38 << 1)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…");
                                            
                                            if (x10_16 != 0)
                                                *((x24_5 + (x8_38 << 1)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…") = (x10_16 - 1);
                                        }
                                        
                                        i = (var_708_1 + 1);
                                    } while (i < var_6c0);
                                }
                            }
                            
                            x20_1 = var_6e8_1;
                            x24_1 = 0;
                            var_708_1 = 0;
                            
                            if ((x0_16 != 0xfffffffd && x0_16 >= 0xfffffffd))
                                goto label_1782c;
                            
                            goto label_18110;
                        }
                        case 2:
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 9:
                        case 0xa:
                        case 0xb:
                        case 0xc:
                        case 0xd:
                        case 0xe:
                        case 0xf:
                        case 0x12:
                        case 0x13:
                        case 0x14:
                        case 0x15:
                        case 0x16:
                        case 0x17:
                        case 0x18:
                        case 0x19:
                        case 0x1a:
                        case 0x1b:
                        case 0x1c:
                        case 0x1d:
                        case 0x1e:
                        case 0x1f:
                        {
                            goto label_18110;
                        }
                        case 8:
                        {
                            if (cs2p2p_PPPP_PSR_Read_Header(&var_6b8, &var_6c4, &var_6c0) == 0)
                            {
                                uint64_t x24_2 = var_6c4;
                                
                                if (x24_2 < 8)
                                {
                                    uint32_t x20_4 = var_78;
                                    
                                    if ((x20_4 >= 5 && *(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x24_2 << 5)) + "P_Proto_TCPSend_AlivePKcijPc") <= 0x20))
                                    {
                                        uint32_t x9_14 = *(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x24_2 << 1)) + "t");
                                        uint32_t x25_4 = var_6c0;
                                        uint32_t x8_53 = (x9_14 - x25_4);
                                        uint32_t x8_55;
                                        
                                        if (x9_14 <= x25_4)
                                        {
                                            x8_55 = (x25_4 - x9_14);
                                            
                                            if (x8_55 <= 0x8000)
                                                goto label_17f8c;
                                            
                                            x8_53 = ((x9_14 | 0x10000) - x25_4);
                                        label_17eac:
                                            
                                            if (x8_53 <= 0)
                                                goto label_17f9c;
                                        }
                                        else
                                        {
                                            if (x8_53 <= 0x8000)
                                                goto label_17eac;
                                            
                                            x8_55 = ((0x10000 - x9_14) + x25_4);
                                        label_17f8c:
                                            
                                            if (-(x8_55) <= 0)
                                            {
                                            label_17f9c:
                                                uint32_t* s_1 = malloc(0x28);
                                                
                                                if (s_1 == 0)
                                                {
                                                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                                    x21_1[0x16] = 1;
                                                }
                                                else
                                                {
                                                    size_t bytes_2 = (x20_4 - 4);
                                                    __builtin_memset(s_1, 0, 0x28);
                                                    int64_t x0_44 = malloc(bytes_2);
                                                    *(s_1 + 8) = x0_44;
                                                    
                                                    if (x0_44 == 0)
                                                    {
                                                        free(s_1);
                                                        *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                                        x21_1[0x16] = 1;
                                                    }
                                                    else
                                                    {
                                                        *s_1 = x25_4;
                                                        s_1[1] = (x20_4 - 4);
                                                        memcpy(x0_44, var_760_1, bytes_2);
                                                        int64_t x20_7 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
                                                        cs2p2p_sll_Put(&*"n"[(x20_7 + (x24_2 << 5))], s_1);
                                                        uint64_t x9_51 = var_6c4;
                                                        *((x20_7 + (x9_51 << 1)) + "t") = (var_6c0 + 1);
                                                        sem_post(((x20_7 + (x9_51 << 4)) + 0x68));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    *(x21_1 + 0x56) = 1;
                                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                }
                            }
                            
                            goto label_18100;
                        }
                        case 0x10:
                        {
                            cs2p2p_PPPP_Proto_Send_AliveAck(var_6e0_1, *x21_1, &x21_1[1]);
                        label_17a98:
                            var_708_1 = 0;
                            goto label_18110;
                        }
                        case 0x11:
                        {
                            goto label_17a98;
                        }
                        case 0x20:
                        {
                            *(x21_1 + 0x56) = 1;
                            *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                        label_18110:
                            
                            if (time(nullptr) > (var_6f0 + 1))
                            {
                            label_18130:
                                x25_1 = var_6e0_1;
                                
                                if (var_70c_1 == 0)
                                {
                                    if ((*(x21_1 + 0x51) != 0 || x21_1[0x14] != 1))
                                        var_70c_1 = 0;
                                    else if (var_708_1 == 0)
                                        var_70c_1 = 1;
                                    else
                                    {
                                        cs2p2p_PPPP_Proto_Send_P2PRdy(x25_1, *x21_1, &var_70, (x21_1 + 0x17b), x21_1[0x63], (x21_1 + 0x183));
                                        var_70c_1 = 0;
                                    }
                                }
                                
                                for (int64_t i_1 = 0; i_1 != 0x100; i_1 += 0x20)
                                {
                                    void* x8_118 = (x21_1 + i_1);
                                    cs2p2p___the_SLL_Element* x1_26 = *(x8_118 + 0x398);
                                    
                                    if (x1_26 != 0)
                                    {
                                        void* x9_55 = *(x1_26 + 0x20);
                                        void* x9_56;
                                        
                                        if (x9_55 == 0)
                                            x9_56 = (x8_118 + 0x398);
                                        else
                                            x9_56 = (x9_55 + 0x18);
                                        
                                        *x9_56 = *(x1_26 + 0x18);
                                        void* x9_57 = *(x1_26 + 0x18);
                                        void* x9_58;
                                        
                                        if (x9_57 == 0)
                                            x9_58 = (x8_118 + 0x3a0);
                                        else
                                            x9_58 = (x9_57 + 0x20);
                                        
                                        *x9_58 = *(x1_26 + 0x20);
                                        *(x1_26 + 0x18) = 0;
                                        *(x1_26 + 0x20) = 0;
                                        int32_t x10_24 = *(x8_118 + 0x3ac);
                                        *(x8_118 + 0x3a8) -= 1;
                                        *(x8_118 + 0x3ac) = (x10_24 - *(x1_26 + 4));
                                        cs2p2p_sll_Put((x8_118 + 0x298), x1_26);
                                    }
                                }
                                
                                x20_1 = var_6e8_1;
                                goto label_181fc;
                            }
                            
                            x25_1 = var_6e0_1;
                            break;
                        }
                    }
                }
                else
                {
                    if ((x0_16 == 0xfffffffd || x0_16 < 0xfffffffd))
                        goto label_18110;
                    
                label_1782c:
                    
                    if (x0_16 != 0xfffffffe)
                        goto label_18130;
                    
                    x25_1 = var_6e0_1;
                label_181fc:
                    
                    if (x24_1 >= 0x3e8)
                    {
                        cs2p2p_PPPP_Proto_Send_Alive(x25_1, *x21_1, &x21_1[1]);
                        bool cond:1_1 = (var_708_1 + 1) < 7;
                        var_708_1 += 1;
                        
                        if (cond:1_1)
                            x24_1 = 0;
                        else
                        {
                            x24_1 = 0;
                            *(x21_1 + 0x55) = 1;
                            *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                        }
                    }
                    
                    x24_1 += x22_2;
                    var_6f0 = time(nullptr);
                }
            }
            else
            {
                var_6c4 = 8;
                char* x9_65;
                
                if (cs2_TCPNBSkt_Overtime_Recv(x0_1, &var_6c0, &var_6c4, 0x1770, ((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53)) != 0)  {  // {"PKciP11sockaddr_inc"}}
                {
                label_18288:
                    x9_65 = (x21_1 + 0x55);
                label_18298:
                    *x9_65 = 1;
                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                    break;
                }
                
                uint16_t bytes_4;
                void var_6cc;
                void var_6c8;
                
                if (cs2p2p_PPPP_Proto_Read_TCPHeader(&var_6c0, &var_6c8, &var_6cc, &bytes_4) == 0xffffffff)
                    goto label_18288;
                
                uint64_t bytes = bytes_4;
                
                if (bytes >= 0x501)
                    goto label_18288;
                
                var_6c4 = bytes;
                uint8_t* x0_5 = malloc(bytes);
                
                if (x0_5 == 0)
                {
                    x9_65 = &x21_1[0x16];
                    goto label_18298;
                }
                
                if (cs2_TCPNBSkt_Overtime_Recv(*(x21_1 + "nAckPKciP11sockaddr_inc"), &var_6b8, &var_6c4, 0x1770, ((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53)) != 0)  {  // {"PKciP11sockaddr_inc"}}
                {
                label_18278:
                    *(x21_1 + 0x55) = 1;
                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                    free(x0_5);
                    break;
                }
                
                uint32_t bytes_5 = bytes_4;
                
                if (var_6c4 != bytes_5)
                    goto label_18278;
                
                if (cs2p2p_PPPP_Proto_Read_TCPMSG(x25_1, &var_6c8, &var_6cc, &var_6b8, x0_5, bytes_5) == 0xffffffff)
                    goto label_18278;
                
                if (cs2p2p_PPPP_Proto_Read_Header(x0_5, &var_74, &var_78) != 0)
                    goto label_18278;
                
                size_t x2_6 = var_78;
                
                if ((bytes_4 - 4) != x2_6)
                    goto label_18278;
                
                memcpy(&var_6b8, &x0_5[4], x2_6);
                free(x0_5);
                pthread_mutex_lock(&data_50d02c);
                uint32_t x8_16 = var_74;
                
                if (x8_16 == 0xd0)
                {
                    uint16_t var_6d8;
                    uint8_t var_6d4;
                    cs2p2p_PPPP_DRW_Read_Header(&var_6b8, &var_6d4, &var_6d8);
                    uint64_t x25_3 = var_6d4;
                    
                    if (x25_3 < 8)
                    {
                        uint32_t x20_2 = var_78;
                        
                        if (x20_2 >= 5)
                        {
                            if (*(((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + (x25_3 << 5)) + 0x4a8) < 0xbb9)
                            {
                                uint32_t x26_3 = var_6d8;
                                uint32_t* s = malloc(0x28);
                                
                                if (s == 0)
                                {
                                    x21_1[0x16] = 1;
                                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                }
                                else
                                {
                                    uint64_t bytes_1 = (x20_2 - 4);
                                    __builtin_memset(s, 0, 0x28);
                                    int64_t x0_23 = malloc(bytes_1);
                                    *(s + 8) = x0_23;
                                    
                                    if (x0_23 == 0)
                                    {
                                        free(s);
                                        x21_1[0x16] = 1;
                                        *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                                    }
                                    else
                                    {
                                        *s = x26_3;
                                        s[1] = (x20_2 - 4);
                                        memcpy(x0_23, var_760_1, bytes_1);
                                        int64_t x20_3 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
                                        cs2p2p_sll_Put(((x20_3 + (x25_3 << 5)) + 0x498), s);
                                        sem_post(((x20_3 + (var_6d4 << 4)) + 0x68));
                                    }
                                }
                            }
                            else
                            {
                                x21_1[0x16] = 1;
                                *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                            }
                        }
                    }
                    else
                    {
                        *(x21_1 + 0x56) = 1;
                        *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                    }
                    
                    x20_1 = var_6e8_1;
                    x25_1 = var_6e0_1;
                }
                else if (x8_16 == 0xf0)
                {
                    *(x21_1 + 0x56) = 1;
                    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) = 1;  {  // {"PKciP11sockaddr_inc"}}
                    cs2p2p_PPPP_Proto_TCPSend_Close(x25_1, *(x21_1 + "nAckPKciP11sockaddr_inc"), 0, ((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53));  {  // {"PKciP11sockaddr_inc"}}
                }
            }
            pthread_mutex_unlock(&data_50d02c);
            
            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) != 0)  {  // {"PKciP11sockaddr_inc"}}
                break;
        }
    }
    
    int64_t x26_5 = (cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc"));
    sem_post((x26_5 + 0x68));
    sem_post((x26_5 + 0x78));
    sem_post((x26_5 + 0x88));
    sem_post((x26_5 + 0x98));
    sem_post((x26_5 + 0xa8));
    sem_post((x26_5 + 0xb8));
    sem_post((x26_5 + 0xc8));
    sem_post((x26_5 + 0xd8));
    cs2p2p_mSecSleep(0xa);
    sem_post((x26_5 + 0x68));
    sem_post((x26_5 + 0x78));
    sem_post((x26_5 + 0x88));
    sem_post((x26_5 + 0x98));
    sem_post((x26_5 + 0xa8));
    sem_post((x26_5 + 0xb8));
    sem_post((x26_5 + 0xc8));
    sem_post((x26_5 + 0xd8));
    pthread_exit(nullptr);
    /* no return */
}

