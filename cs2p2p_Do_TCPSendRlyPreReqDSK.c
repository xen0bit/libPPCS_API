
void cs2p2p_Do_TCPSendRlyPreReqDSK(int32_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x11 = *(x25 + 0x28);
    void* x8 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
    int64_t x27 = arg1;
    *(x8 + 0x18c);
    *(cs2p2p_gNetInfo + 3);
    st_cs2p2p_TCPSessionInfo* x24 = *(x8 + "PPP_Proto_Send_ByteCountPKciP11s…");
    char var_88 = 0;
    int16_t var_84 = 0x104;
    char var_82 = 3;
    void var_80;
    
    if ((x24 != 0 && (*(x24 + 0x4c) != 0 && *(x24 + 0x45) != 0)))
    {
        cs2p2p_TCPSkt_GetLocalAddr(*(x24 + 8), &var_80);
        *(x24 + 8);
        char* var_98_1 = &var_88;
        int32_t var_a0_1 = 0;
        void* var_b0_1 = &var_80;
        void* var_a8_1 = (x8 + 0x100);
        
        if (cs2p2p_PPPP_Proto_TCPSend_TCPRlyReqDSK() == 0)
            *(x24 + 0x4c) = 0;
        else
            cs2p2p_ResetTCPrSessionInfo(x24);
    }
    
    st_cs2p2p_TCPSessionInfo* x24_1 = *((cs2p2p_gSession + (x27 * "PKciP11sockaddr_inc")) + "o_Send_ByteCountPKciP11sockaddr_…");
    
    if ((x24_1 != 0 && (*(x24_1 + 0x4c) != 0 && *(x24_1 + 0x45) != 0)))
    {
        cs2p2p_TCPSkt_GetLocalAddr(*(x24_1 + 8), &var_80);
        *(x24_1 + 8);
        char* var_98_2 = &var_88;
        int32_t var_a0_2 = 0;
        void* var_b0_2 = &var_80;
        void* var_a8_2 = (x8 + 0x100);
        
        if (cs2p2p_PPPP_Proto_TCPSend_TCPRlyReqDSK() == 0)
            *(x24_1 + 0x4c) = 0;
        else
            cs2p2p_ResetTCPrSessionInfo(x24_1);
    }
    
    st_cs2p2p_TCPSessionInfo* x24_2 = *((cs2p2p_gSession + (x27 * "PKciP11sockaddr_inc")) + "yteCountPKciP11sockaddr_inj");
    
    if ((x24_2 != 0 && (*(x24_2 + 0x4c) != 0 && *(x24_2 + 0x45) != 0)))
    {
        cs2p2p_TCPSkt_GetLocalAddr(*(x24_2 + 8), &var_80);
        *(x24_2 + 8);
        int32_t var_a0_3 = 0;
        char* var_98_3 = &var_88;
        void* var_b0_3 = &var_80;
        void* var_a8_3 = (x8 + 0x100);
        
        if (cs2p2p_PPPP_Proto_TCPSend_TCPRlyReqDSK() == 0)
            *(x24_2 + 0x4c) = 0;
        else
            cs2p2p_ResetTCPrSessionInfo(x24_2);
    }
    
    if (*(x25 + 0x28) == x11)
        return;
    
    __stack_chk_fail();
    /* no return */
}

