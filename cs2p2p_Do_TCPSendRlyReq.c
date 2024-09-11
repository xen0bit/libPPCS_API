
void cs2p2p_Do_TCPSendRlyReq(int32_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x15 = _ReadStatusReg(tpidr_el0);
    int64_t x15_1 = *(x15 + 0x28);
    void* x8 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
    void* var_90 = (x8 + 0x17b);
    *(x8 + 0x18c);
    *(cs2p2p_gNetInfo + 3);
    int64_t i = 0;
    char var_88 = 0;
    int16_t var_84 = 0x104;
    char var_82 = 3;
    
    do
    {
        st_cs2p2p_TCPSessionInfo* x25_1 = *((x8 + "PPP_Proto_Send_ByteCountPKciP11s…") + i);
        
        if ((x25_1 != 0 && *(x25_1 + 0x45) != 0))
        {
            uint32_t x8_2 = *(x25_1 + 0x4b);
            void* x24_2;
            
            if (x8_2 == 0)
            {
                x24_2 = (x25_1 + 0x49);
                
                if (*x24_2 != 0)
                    goto label_152a0;
            }
            else
            {
                *(x25_1 + 0x4b) = (x8_2 + 1);
                
                if ((x8_2 + 1) >= 0x65)
                {
                    x24_2 = (x25_1 + 0x49);
                    *x24_2 = 1;
                    *(x24_2 + 2) = 0;
                label_152a0:
                    void var_80;
                    cs2p2p_TCPSkt_GetLocalAddr(*(x25_1 + 8), &var_80);
                    pthread_mutex_lock(&data_50d02c);
                    
                    if (*(x8 + "vLgnAckPKciP11sockaddr_inc") == 0)
                        *(x8 + "vLgnAckPKciP11sockaddr_inc") = 2;
                    
                    pthread_mutex_unlock(&data_50d02c);
                    *(x25_1 + 8);
                    char* var_a0_1 = &var_88;
                    int32_t var_a8_1 = 0;
                    void* var_b0_1 = &var_80;
                    
                    if (cs2p2p_PPPP_Proto_TCPSend_TCPRlyReq() == 0)
                        *x24_2 = 0;
                    else
                        cs2p2p_ResetTCPrSessionInfo(x25_1);
                }
            }
        }
        
        i += 8;
    } while (i != 0x18);
    
    if (*(x15 + 0x28) == x15_1)
        return;
    
    __stack_chk_fail();
    /* no return */
}

