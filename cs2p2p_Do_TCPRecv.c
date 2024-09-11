
void cs2p2p_Do_TCPRecv(int32_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x11 = *(x24 + 0x28);
    void* x8 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
    
    for (int64_t i = 0; i != 0x18; i += 8)
    {
        st_cs2p2p_TCPSessionInfo* x20_1 = *((x8 + "PPP_Proto_Send_ByteCountPKciP11s…") + i);
        
        if ((x20_1 != 0 && *(x20_1 + 0x45) != 0))
        {
            uint64_t x8_2 = *(x20_1 + 0x3c);
            
            if (x8_2 > 7)
                goto label_15468;
            
            arg1 = cs2_TCPNBSkt_Recv(*(x20_1 + 8), ((x20_1 + 0x24) + (x8_2 << 3)), (8 - x8_2));
            
            if ((arg1 & 0x80000000) != 0)
                cs2p2p_ResetTCPrSessionInfo(x20_1);
            else
            {
                x8_2 = (arg1 + *(x20_1 + 0x3c));
                *(x20_1 + 0x3c) = x8_2;
                
                if ((x8_2 & 0xffff) != 8)
                    goto label_15468;
                
                uint16_t var_174;
                uint8_t var_170;
                uint8_t var_16c;
                
                if (cs2p2p_PPPP_Proto_Read_TCPHeader((x20_1 + 0x24), &var_16c, &var_170, &var_174) == 0xffffffff)
                    cs2p2p_ResetTCPrSessionInfo(x20_1);
                else
                {
                    uint32_t x8_4 = var_174;
                    
                    if ((x8_4 >= 0x501 || x8_4 >= 0x101))
                        cs2p2p_ResetTCPrSessionInfo(x20_1);
                    else
                    {
                        int64_t x0_3 = *(x20_1 + 0x30);
                        uint64_t x2_3 = *(x20_1 + 0x38);
                        *(x20_1 + 0x3e) = x8_4;
                        memset(x0_3, 0, x2_3);
                        *(x20_1 + 0x3a) = 0;
                        *(x20_1 + 0x40) = var_16c;
                        char var_16b;
                        *(x20_1 + 0x41) = var_16b;
                        *(x20_1 + 0x42) = var_170;
                        x8_2 = *(x20_1 + 0x3c);
                        char var_16f;
                        *(x20_1 + 0x43) = var_16f;
                    label_15468:
                        
                        if ((x8_2 & 0xffff) == 8)
                        {
                            uint64_t x8_9 = *(x20_1 + 0x3a);
                            uint32_t x9_3 = *(x20_1 + 0x3e);
                            
                            if (x9_3 > x8_9)
                            {
                                arg1 = cs2_TCPNBSkt_Recv(*(x20_1 + 8), (*(x20_1 + 0x30) + x8_9), (x9_3 - x8_9));
                                
                                if ((arg1 & 0x80000000) != 0)
                                    cs2p2p_ResetTCPrSessionInfo(x20_1);
                                else
                                {
                                    uint16_t x5_1 = (arg1 + *(x20_1 + 0x3a));
                                    bool cond:1_1 = *(x20_1 + 0x3e) != x5_1;
                                    *(x20_1 + 0x3a) = x5_1;
                                    void var_168;
                                    
                                    if (!(cond:1_1))
                                    {
                                        if (cs2p2p_PPPP_Proto_Read_TCPMSG((x8 + 0xe8), (x20_1 + 0x40), (x20_1 + 0x42), *(x20_1 + 0x30), &var_168, x5_1) == 0xffffffff)
                                            cs2p2p_ResetTCPrSessionInfo(x20_1);
                                        else
                                        {
                                            memcpy(*(x20_1 + 0x30), &var_168, *(x20_1 + 0x3e));
                                            *(x20_1 + 0x4e) = 1;
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
    
    if (*(x24 + 0x28) == x11)
        return;
    
    __stack_chk_fail();
    /* no return */
}

