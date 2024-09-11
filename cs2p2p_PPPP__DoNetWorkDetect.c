
int64_t cs2p2p_PPPP__DoNetWorkDetect(int64_t arg1, int32_t arg2, int16_t* arg3, int32_t arg4, char* arg5, int128_t* arg6, int128_t* arg7, int128_t* arg8)

{
    int0_t tpidr_el0;
    uint64_t x8 = _ReadStatusReg(tpidr_el0);
    int64_t x8_1 = *(x8 + 0x28);
    int16_t var_cd4 = 0;
    int32_t var_cd8 = 0;
    void var_888;
    memset(&var_888, 0, 0x300);
    int64_t var_8d0;
    __builtin_memset(&var_8d0, 0, 0x18);
    void* x0_2 = strchr(arg5, 0x3a);
    
    if (x0_2 != 0)
    {
        __builtin_memset(&var_8d0, 0, 0x18);
        strncpy(&var_8d0, (x0_2 + 1), 0x14);
    }
    
    arg3[1] = 0;
    *arg3 = 0x100;
    strncpy(&arg3[0xa], "0.0.0.0", 0x10);
    strncpy(&arg3[2], "0.0.0.0", 0x10);
    void var_cd0;
    memset(&var_cd0, 0, 0x400);
    cs2p2p_PPPP_DecodeString(arg5, &var_cd0, 0x400);
    int32_t x0_9 = strlen(&var_cd0);
    
    if (x0_9 >= 1)
    {
        int64_t x25_1 = 0;
        int32_t x8_2 = 0;
        int32_t x19_1 = 0;
        uint64_t x26_1 = x0_9;
        
        while (true)
        {
            if (*(&var_cd0 + x25_1) != 0x2c)
            {
                x25_1 += 1;
                
                if (x25_1 == x26_1)
                    break;
            }
            else
            {
                *(&var_cd0 + x25_1) = 0;
                strncpy((&var_888 + (x19_1 << 8)), (&var_cd0 + x8_2), 0xff);
                x25_1 += 1;
                x19_1 += 1;
                x8_2 = x25_1;
                
                if (x25_1 == x26_1)
                    break;
            }
        }
    }
    
    int32_t var_8ac = 0;
    int32_t var_8b4 = 0;
    int32_t var_8b8 = 0x647d0002;
    int32_t x0_12;
    int128_t v0;
    x0_12 = cs2p2p_GetInetAddrByName(&var_888, (&var_8b8 | 4));
    int32_t var_8a8;
    int64_t var_8a4;
    int128_t var_898;
    
    if (x0_12 != 0)
        *(arg3 + 1) = 0;
    else
    {
        int32_t var_89c_1 = 0;
        var_8a4 = 0;
        var_8a8 = 0x647d0002;
        void var_788;
        int32_t x0_14;
        x0_14 = cs2p2p_GetInetAddrByName(&var_788, &var_8a4);
        
        if (x0_14 != 0)
            *(arg3 + 1) = 0;
        else
        {
            *var_898[0xc] = 0;
            *var_898[4] = 0;
            var_898 = 0x647d0002;
            void var_688;
            int32_t x0_16;
            x0_16 = cs2p2p_GetInetAddrByName(&var_688, &*var_898[4]);
            
            if (x0_16 != 0)
                *(arg3 + 1) = 0;
        }
    }
    
    *arg6 = var_8b8;
    *arg7 = var_8a8;
    *arg8 = var_898;
    int32_t x0_18;
    int128_t v0_1;
    int128_t v1;
    int128_t v2;
    x0_18 = strncmp(cs2p2p_gServerString, arg5, 0x100);
    
    if (x0_18 == 0)
    {
        v1 = var_8a8;
        v2 = var_898;
        *cs2p2p_gP2PServerAddr = var_8b8;
        *(cs2p2p_gP2PServerAddr + 0x10) = v1;
        *(cs2p2p_gP2PServerAddr + 0x20) = v2;
    }
    
    int64_t result;
    
    if (arg2 != 0)
        result = 0;
    else
    {
        int32_t fd = cs2p2p_setup_Socket();
        int32_t var_ce4 = 1;
        setsockopt();
        void var_88;
        
        if (cs2p2p_TryBind(fd, arg4, &var_88) == 0xffffffff)
        {
            close(fd);
            result = 0xffffffee;
        }
        else
        {
            cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_8b8);
            int32_t var_d08;
            var_d08 = (&var_cd8 | 2);
            cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_8a8);
            cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_898);
            int32_t var_d24_1 = 0x1388;
            uint32_t x28_1 = 0;
            uint32_t x27_1 = 0;
            uint32_t x21_1 = 0;
            int32_t var_d10;
            var_d10 = (cs2p2p_gNetInfo + 0x14);
        label_16064:
            uint8_t var_ce0;
            uint16_t var_cdc;
            sockaddr_in var_588;
            sockaddr_in var_78;
            int32_t x0_25 = cs2p2p_PPPP_Proto_Recv_ALL(&var_8d0, fd, &var_78, 0xc8, &var_ce0, &var_cdc, &var_588, 0x500);
            int32_t var_d28;
            int32_t x21_2;
            int32_t x22_1;
            
            if (x0_25 < 0xffffffff)
            {
            label_1628c:
                x21_2 = 0;
                x22_1 = 0;
            }
            else
            {
                while (true)
                {
                    if (x0_25 == 0xffffffff)
                    {
                        int32_t x8_13;
                        
                        if ((x21_1 & 0xffff) == 0)
                            x8_13 = -0xc8;
                        else
                            x8_13 = -0x190;
                        
                        int32_t temp0_2 = (x27_1 & 0xffff);
                        int32_t x10_1;
                        
                        if (temp0_2 != 0)
                            x10_1 = 2;
                        else
                            x10_1 = 1;
                        
                        int32_t x8_14 = (var_d24_1 + x8_13);
                        int32_t x8_15;
                        
                        if (temp0_2 == 0)
                            x8_15 = x8_14;
                        else
                            x8_15 = (x8_14 - 0xc8);
                        
                        int32_t x9_9;
                        
                        if ((x21_1 & 0xffff) == 0)
                            x9_9 = ((temp0_2 != 0) ? 1 : 0);
                        else
                            x9_9 = x10_1;
                        
                        int32_t temp1_1 = (x28_1 & 0xffff);
                        int32_t x8_16;
                        
                        if (temp1_1 == 0)
                            x8_16 = x8_15;
                        else
                            x8_16 = (x8_15 - 0xc8);
                        
                        var_d24_1 = x8_16;
                        int32_t x8_17;
                        
                        if (temp1_1 != 0)
                            x8_17 = (x9_9 + 1);
                        else
                            x8_17 = x9_9;
                        
                        var_d28 = x8_17;
                        
                        if (x8_17 > 1)
                            goto label_1628c;
                        
                        if ((x21_1 & 0xffff) != 0)
                        {
                            if ((x27_1 & 0xffff) == 0)
                                goto label_1625c;
                            
                            goto label_16220;
                        }
                        
                        cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_8b8);
                        
                        if ((x27_1 & 0xffff) != 0)
                        {
                        label_16220:
                            
                            if ((x28_1 & 0xffff) == 0)
                                cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_898);
                        }
                        else
                        {
                        label_1625c:
                            cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_8a8);
                            
                            if ((x28_1 & 0xffff) == 0)
                                cs2p2p_PPPP_Proto_Send_Hello(&var_8d0, fd, &var_898);
                        }
                        
                        if (var_d24_1 > 0)
                            goto label_16064;
                        
                        goto label_1628c;
                    }
                    
                    if ((var_ce0 == 1 && var_cdc == 0x10))
                    {
                        *cs2p2p_gLastHelloAckTime = time(nullptr);
                        cs2p2p_ntohAddr(&var_588, &var_88);
                        struct in_addr in;
                        int32_t var_74;
                        int16_t* x8_9;
                        
                        if (var_74 != var_8b4)
                        {
                            x8_9 = var_d08;
                            
                            if (var_74 == var_8a4)
                                goto label_16104;
                            
                            x8_9 = &var_cd4;
                            
                            if (var_74 == *var_898[4])
                                goto label_16104;
                        }
                        else
                        {
                            x8_9 = &var_cd8;
                        label_16104:
                            int16_t var_86;
                            *x8_9 = (_byteswap(var_86) >> 0x10);
                            
                            if (strncmp(&arg3[0xa], "0.0.0.0", 8) == 0)
                            {
                                strncpy(&arg3[0xa], inet_ntoa(in), 0x10);
                                strncpy(var_d10, &arg3[0xa], 0x10);
                            }
                            
                            *arg3 = 1;
                            arg3[1] = 1;
                        }
                        
                        if (strncmp(&arg3[0xa], inet_ntoa(in), 0x10) != 0)
                        {
                            x22_1 = 0;
                            x21_2 = 1;
                            break;
                        }
                        
                        int16_t var_76;
                        
                        if (var_76 != 0x647d)  {  // {"opt"}}
                        {
                            x21_2 = 0;
                            x22_1 = 1;
                            break;
                        }
                        
                        x21_1 = var_cd8;
                        x27_1 = *var_cd8[2];
                        x28_1 = var_cd4;
                        
                        if ((x21_1 != 0 && (x27_1 != 0 && x28_1 != 0)))
                        {
                            x21_2 = 0;
                            x22_1 = 0;
                            var_d28 = 3;
                            break;
                        }
                    }
                    
                    x0_25 = cs2p2p_PPPP_Proto_Recv_ALL(&var_8d0, fd, &var_78, 0xc8, &var_ce0, &var_cdc, &var_588, 0x500);
                    
                    if (x0_25 <= 0xfffffffe)
                        goto label_1628c;
                }
            }
            
            if (arg3[1] == 1)
            {
                cs2p2p_SockAddr_LocalIPString(&var_78, &arg3[2], 0x10);
                strncpy((cs2p2p_gNetInfo + 4), &arg3[2], 0x10);
            }
            
            char x8_20;
            
            if (x21_2 != 0)
                x8_20 = 4;
            else if (x22_1 != 0)
                x8_20 = 1;
            else if (var_d28 >= 2)
            {
                uint32_t x8_22 = var_cd8;
                uint32_t x9_10 = *var_cd8[2];
                uint32_t x10_3;
                
                if (((x8_22 == 0 || x9_10 == 0) || x8_22 == x9_10))
                    x10_3 = var_cd4;
                
                if ((((x8_22 == 0 || x9_10 == 0) || x8_22 == x9_10) && ((x9_10 == 0 || x10_3 == 0) || x9_10 == x10_3)))
                {
                    bool z_1;
                    
                    if (x10_3 != x8_22)
                        z_1 = x8_22 == 0;
                    else
                        z_1 = true;
                    
                    bool z_2;
                    
                    if (!(z_1))
                        z_2 = x10_3 == 0;
                    else
                        z_2 = true;
                    
                    if (!(z_2))
                        x8_20 = 3;
                    else
                        x8_20 = 2;
                }
                else
                    x8_20 = 3;
            }
            else
                x8_20 = 0;
            
            *(arg3 + 3) = x8_20;
            *(cs2p2p_gNetInfo + 3) = x8_20;
            
            if (strncmp(cs2p2p_gServerString, arg5, 0x100) == 0)
                *cs2p2p_gLastNetDetectTime = time(nullptr);
            
            close(fd);
            result = 0;
        }
    }
    
    if (*(x8 + 0x28) == x8_1)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

