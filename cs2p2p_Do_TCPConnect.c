
void cs2p2p_Do_TCPConnect(int32_t arg1, int32_t arg2)

{
    int64_t x23 = arg1;
    st_cs2p2p_TCPSessionInfo* x20 = *((cs2p2p_gSession + (arg1 * 0x4d38)) + "PPP_Proto_Send_ByteCountPKciP11s…");  {  // {"PKciP11sockaddr_inc"}}
    
    if (x20 != 0)
    {
        int32_t x21_1 = *(x20 + 8);
        
        if (x21_1 == 0xffffffff)
        {
            if (((cs2p2p_CurrentTickCount() - *(x20 + 0x2c)) >> 4) >= 0x271)
            {
                x21_1 = cs2_TCPNBSkt_Create(2);
                
                if (x21_1 != 0xffffffff)
                {
                    cs2p2p_ResetTCPrSessionInfo(x20);
                    *(x20 + 8) = x21_1;
                    
                    if (*(x20 + 0x45) == 0)
                        goto label_1451c;
                }
            }
        }
        else if (*(x20 + 0x45) == 0)
        {
        label_1451c:
            arg1 = cs2_TCPNBSkt_Connect(x21_1, (x20 + 0xc));
            
            if (arg1 == 0xffffffff)
                *(x20 + 0x45) = 0;
            else if (arg1 != 0)
            {
                *(x20 + 0x2c) = cs2p2p_CurrentTickCount();
                cs2p2p_ResetTCPrSessionInfo(x20);
            }
            else
            {
                *(x20 + 0x45) = 1;
                uint64_t x8_2 = (arg2 - 1);
                *(x20 + 0x2c) = cs2p2p_CurrentTickCount();
                
                if (x8_2 <= 3)
                    switch (x8_2)
                    {
                        case 0:
                        {
                            *(x20 + 0x47) = 1;
                            break;
                        }
                        case 1:
                        {
                            *(x20 + 0x46) = 1;
                            break;
                        }
                        case 2:
                        {
                            *(x20 + 0x4d) = 1;
                            break;
                        }
                        case 3:
                        {
                            *(x20 + 0x4c) = 1;
                            break;
                        }
                    }
            }
        }
    }
    
    st_cs2p2p_TCPSessionInfo* x20_1 = *((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + "o_Send_ByteCountPKciP11sockaddr_…");
    
    if (x20_1 != 0)
    {
        int32_t x21_2 = *(x20_1 + 8);
        
        if (x21_2 == 0xffffffff)
        {
            if (((cs2p2p_CurrentTickCount() - *(x20_1 + 0x2c)) >> 4) >= 0x271)
            {
                x21_2 = cs2_TCPNBSkt_Create(2);
                
                if (x21_2 != 0xffffffff)
                {
                    cs2p2p_ResetTCPrSessionInfo(x20_1);
                    *(x20_1 + 8) = x21_2;
                    
                    if (*(x20_1 + 0x45) == 0)
                        goto label_145f0;
                }
            }
        }
        else if (*(x20_1 + 0x45) == 0)
        {
        label_145f0:
            arg1 = cs2_TCPNBSkt_Connect(x21_2, (x20_1 + 0xc));
            
            if (arg1 == 0)
            {
                *(x20_1 + 0x45) = 1;
                uint64_t x8_15 = (arg2 - 1);
                *(x20_1 + 0x2c) = cs2p2p_CurrentTickCount();
                
                if (x8_15 <= 3)
                    switch (x8_15)
                    {
                        case 0:
                        {
                            *(x20_1 + 0x47) = 1;
                            break;
                        }
                        case 1:
                        {
                            *(x20_1 + 0x46) = 1;
                            break;
                        }
                        case 2:
                        {
                            *(x20_1 + 0x4d) = 1;
                            break;
                        }
                        case 3:
                        {
                            *(x20_1 + 0x4c) = 1;
                            break;
                        }
                    }
            }
            else if (arg1 != 0xffffffff)
            {
                *(x20_1 + 0x2c) = cs2p2p_CurrentTickCount();
                cs2p2p_ResetTCPrSessionInfo(x20_1);
            }
            else
                *(x20_1 + 0x45) = 0;
        }
    }
    
    st_cs2p2p_TCPSessionInfo* x20_2 = *((cs2p2p_gSession + (x23 * "PKciP11sockaddr_inc")) + "yteCountPKciP11sockaddr_inj");
    
    if (x20_2 != 0)
    {
        int32_t x21_3 = *(x20_2 + 8);
        
        if (x21_3 == 0xffffffff)
        {
            if (((cs2p2p_CurrentTickCount() - *(x20_2 + 0x2c)) >> 4) >= 0x271)
            {
                x21_3 = cs2_TCPNBSkt_Create(2);
                
                if (x21_3 != 0xffffffff)
                {
                    cs2p2p_ResetTCPrSessionInfo(x20_2);
                    *(x20_2 + 8) = x21_3;
                    
                    if (*(x20_2 + 0x45) == 0)
                        goto label_146c4;
                }
            }
        }
        else if (*(x20_2 + 0x45) == 0)
        {
        label_146c4:
            arg1 = cs2_TCPNBSkt_Connect(x21_3, (x20_2 + 0xc));
            
            if (arg1 == 0)
            {
                *(x20_2 + 0x45) = 1;
                uint64_t x8_24 = (arg2 - 1);
                *(x20_2 + 0x2c) = cs2p2p_CurrentTickCount();
                
                if (x8_24 <= 3)
                    switch (x8_24)
                    {
                        case 0:
                        {
                            *(x20_2 + 0x47) = 1;
                            break;
                        }
                        case 1:
                        {
                            *(x20_2 + 0x46) = 1;
                            break;
                        }
                        case 2:
                        {
                            *(x20_2 + 0x4d) = 1;
                            break;
                        }
                        case 3:
                        {
                            *(x20_2 + 0x4c) = 1;
                            break;
                        }
                    }
            }
            else
            {
                if (arg1 != 0xffffffff)
                {
                    *(x20_2 + 0x2c) = cs2p2p_CurrentTickCount();
                    /* tailcall */
                    return cs2p2p_ResetTCPrSessionInfo(x20_2);
                }
                
                *(x20_2 + 0x45) = 0;
            }
        }
    }
}

