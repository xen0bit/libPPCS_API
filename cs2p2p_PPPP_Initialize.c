
int64_t cs2p2p_PPPP_Initialize(char* arg1)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int64_t result;
    
    if (*cs2p2p_gFlagInitialized != 0)
        result = 0xfffffffe;
    else if (arg1 == 0)
        result = 0xfffffffb;
    else
    {
        uint8_t x8_2;
        
        if (cs2p2p_ProbeIPv4() != 1)
            x8_2 = ((cs2p2p_ProbeIPv6() == 1) ? 1 : 0);
        else
            x8_2 = 0;
        
        *cs2p2p_gbUseIPv6 = x8_2;
        *cs2p2p_gFlagInitialized = 1;
        *cs2p2p_gLastListenStartTime = 0;
        *cs2p2p_gLastNetDetectTime = 0;
        *cs2p2p_gLastSuccessLoginTime = 0;
        *cs2p2p_gLastSuccessLoginTimeTCP = 0;
        memset(cs2p2p_gSDevInfo, 0, 0x1c0);
        strncpy(cs2p2p_gServerString, arg1, 0x100);
        void var_468;
        memset(&var_468, 0, 0x400);
        cs2p2p_PPPP_DecodeString(arg1, &var_468, 0x400);
        int32_t x0_7 = strlen(&var_468);
        
        if (x0_7 >= 1)
        {
            int64_t x21_1 = 0;
            int32_t x8_3 = 0;
            int32_t x25_1 = 0;
            uint64_t x26_1 = x0_7;
            
            while (true)
            {
                if (*(&var_468 + x21_1) != 0x2c)
                {
                    x21_1 += 1;
                    
                    if (x21_1 == x26_1)
                        break;
                }
                else
                {
                    *(&var_468 + x21_1) = 0;
                    strncpy((cs2p2p_gP2PServerName + (x25_1 << 8)), (&var_468 + x8_3), 0xff);
                    x21_1 += 1;
                    x25_1 += 1;
                    x8_3 = x21_1;
                    
                    if (x21_1 == x26_1)
                        break;
                }
            }
        }
        
        int64_t (* const x21_2)() = cs2p2p_gSession;
        int64_t i_1 = 0x100;
        *(cs2p2p_gP2PServerAddr + 0xc) = 0x647d000200000000;
        *(cs2p2p_gP2PServerAddr + 4) = 0;
        *cs2p2p_gP2PServerAddr = 0x647d0002;
        *(cs2p2p_gP2PServerAddr + 0x14) = 0;
        *(cs2p2p_gP2PServerAddr + 0x1c) = 0x647d000200000000;
        *(cs2p2p_gP2PServerAddr + 0x2c) = 0;
        *(cs2p2p_gP2PServerAddr + 0x24) = 0;
        int64_t i;
        
        do
        {
            memset(x21_2, 0, "PKciP11sockaddr_inc");
            *x21_2 = 0xffffffff;
            *(x21_2 + 0x178) = 0x101;
            i = i_1;
            i_1 -= 1;
            x21_2 += "PKciP11sockaddr_inc";
        } while (i != 1);
        strncpy((cs2p2p_gNetInfo + 0x14), "0.0.0.0", 0x10);
        strncpy((cs2p2p_gNetInfo + 4), "0.0.0.0", 0x10);
        char* x0_13 = strchr(arg1, 0x3a);
        
        if (x0_13 != 0)
        {
            *cs2p2p_gP2PKeyString = 0;
            *(cs2p2p_gP2PKeyString + 8) = 0;
            *(cs2p2p_gP2PKeyString + 0x10) = 0;
            uint32_t x9_3 = x0_13[1];
            
            if ((x9_3 - 0x21) <= 0x5d)
            {
                *cs2p2p_gP2PKeyString = x9_3;
                uint32_t x9_4 = x0_13[2];
                
                if ((x9_4 - 0x21) < 0x5e)
                {
                    *(cs2p2p_gP2PKeyString + 1) = x9_4;
                    uint32_t x9_5 = x0_13[3];
                    
                    if ((x9_5 - 0x21) <= 0x5d)
                    {
                        *(cs2p2p_gP2PKeyString + 2) = x9_5;
                        uint32_t x9_6 = x0_13[4];
                        
                        if ((x9_6 - 0x21) <= 0x5d)
                        {
                            *(cs2p2p_gP2PKeyString + 3) = x9_6;
                            uint32_t x9_7 = x0_13[5];
                            
                            if ((x9_7 - 0x21) <= 0x5d)
                            {
                                *(cs2p2p_gP2PKeyString + 4) = x9_7;
                                uint32_t x9_8 = x0_13[6];
                                
                                if ((x9_8 - 0x21) <= 0x5d)
                                {
                                    *(cs2p2p_gP2PKeyString + 5) = x9_8;
                                    uint32_t x9_9 = x0_13[7];
                                    
                                    if ((x9_9 - 0x21) <= 0x5d)
                                    {
                                        *(cs2p2p_gP2PKeyString + 6) = x9_9;
                                        uint32_t x9_10 = x0_13[8];
                                        
                                        if ((x9_10 - 0x21) <= 0x5d)
                                        {
                                            *(cs2p2p_gP2PKeyString + 7) = x9_10;
                                            uint32_t x9_11 = x0_13[9];
                                            
                                            if ((x9_11 - 0x21) <= 0x5d)
                                            {
                                                *(cs2p2p_gP2PKeyString + 8) = x9_11;
                                                uint32_t x9_12 = x0_13[0xa];
                                                
                                                if ((x9_12 - 0x21) <= 0x5d)
                                                {
                                                    *(cs2p2p_gP2PKeyString + 9) = x9_12;
                                                    uint32_t x9_13 = x0_13[0xb];
                                                    
                                                    if ((x9_13 - 0x21) <= 0x5d)
                                                    {
                                                        *(cs2p2p_gP2PKeyString + 0xa) = x9_13;
                                                        uint32_t x9_14 = x0_13[0xc];
                                                        
                                                        if ((x9_14 - 0x21) <= 0x5d)
                                                        {
                                                            *(cs2p2p_gP2PKeyString + 0xb) = x9_14;
                                                            uint32_t x9_15 = x0_13[0xd];
                                                            
                                                            if ((x9_15 - 0x21) <= 0x5d)
                                                            {
                                                                *(cs2p2p_gP2PKeyString + 0xc) = x9_15;
                                                                uint32_t x9_16 = x0_13[0xe];
                                                                
                                                                if ((x9_16 - 0x21) <= 0x5d)
                                                                {
                                                                    *(cs2p2p_gP2PKeyString + 0xd) = x9_16;
                                                                    uint32_t x9_17 = x0_13[0xf];
                                                                    
                                                                    if ((x9_17 - 0x21) <= 0x5d)
                                                                    {
                                                                        *(cs2p2p_gP2PKeyString + 0xe) = x9_17;
                                                                        uint32_t x9_18 = x0_13[0x10];
                                                                        
                                                                        if ((x9_18 - 0x21) <= 0x5d)
                                                                        {
                                                                            *(cs2p2p_gP2PKeyString + 0xf) = x9_18;
                                                                            uint32_t x9_19 = x0_13[0x11];
                                                                            
                                                                            if ((x9_19 - 0x21) <= 0x5d)
                                                                            {
                                                                                *(cs2p2p_gP2PKeyString + 0x10) = x9_19;
                                                                                uint32_t x9_20 = x0_13[0x12];
                                                                                
                                                                                if ((x9_20 - 0x21) <= 0x5d)
                                                                                {
                                                                                    *(cs2p2p_gP2PKeyString + 0x11) = x9_20;
                                                                                    uint32_t x9_21 = x0_13[0x13];
                                                                                    
                                                                                    if ((x9_21 - 0x21) <= 0x5d)
                                                                                    {
                                                                                        *(cs2p2p_gP2PKeyString + 0x12) = x9_21;
                                                                                        uint32_t x9_22 = x0_13[0x14];
                                                                                        
                                                                                        if ((x9_22 - 0x21) <= 0x5d)
                                                                                            *(cs2p2p_gP2PKeyString + 0x13) = x9_22;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if (*cs2p2p_gbUseIPv6 == 1)
        {
            st_cs2p2p_NetInfo var_490;
            
            if (*cs2p2p_gFlagInitialized != 0)
                cs2p2p_PPPP__DoNetWorkDetect(x0_13, 0, &var_490, 0, cs2p2p_gServerString, cs2p2p_gP2PServerAddr, (cs2p2p_gP2PServerAddr + 0x10), (cs2p2p_gP2PServerAddr + 0x20));
            char var_48e;
            
            if (var_48e == 0)
                *cs2p2p_gbUseIPv6 = 0;
        }
        
        result = 0;
    }
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

