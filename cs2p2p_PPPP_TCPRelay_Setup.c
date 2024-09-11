
int32_t cs2p2p_PPPP_TCPRelay_Setup(int32_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x20 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x20 + 0x28);
    int32_t var_ac = 0x30;
    *((cs2p2p_gSession + (arg1 * 0x4d38)) + "DevLgnAckPKciP11sockaddr_inc") = 0;  {  // {"PKciP11sockaddr_inc"}}
    int32_t result = cs2_TCPNBSkt_Create(2);
    
    if ((result & 0x80000000) != 0)
        *((cs2p2p_gSession + (arg1 * 0x4d38)) + "DevLgnAckPKciP11sockaddr_inc") = 2;  {  // {"PKciP11sockaddr_inc"}}
    else
    {
        int64_t x23_1 = arg1;
        char* x3_1;
        
        if (*((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + 0x50) == 0)
            x3_1 = cs2p2p_gFlagUserBreakConnect;
        else
            x3_1 = cs2p2p_gFlagUserBreakListen;
        
        *((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + "nAckPKciP11sockaddr_inc") = result;
        char x8_6;
        
        if ((cs2_TCPNBSkt_Overtime_Connect(result, ((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + "P11sockaddr_inj"), 0x1388, x3_1) & 0x80000000) != 0)
        {
            x8_6 = 3;
        label_1c30c:
            *((cs2p2p_gSession + (arg1 * 0x4d38)) + "DevLgnAckPKciP11sockaddr_inc") = x8_6;  {  // {"PKciP11sockaddr_inc"}}
            result = cs2_TCPNBSkt_Close(*((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + "nAckPKciP11sockaddr_inc"));
            *((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + "nAckPKciP11sockaddr_inc") = 0xffffffff;
        }
        else
        {
            void* x8_2 = (cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc"));
            int32_t x10_1 = *(x8_2 + 0x18c);
            int32_t x9_1 = *(x8_2 + "PKciP11sockaddr_inj");
            int64_t s;
            __builtin_memset(&s, 0, 0x1c);
            int32_t temp0_1 = _byteswap(x10_1);
            int32_t temp0_2 = _byteswap(x9_1);
            int64_t var_70;
            var_70 = temp0_1;
            uint32_t x10_3 = *((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + 0x50);
            int64_t var_68;
            *var_68[4] = temp0_2;
            int64_t x8_4 = *(x8_2 + 0x183);
            int32_t x0_1 = *((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + "nAckPKciP11sockaddr_inc");
            uint8_t* const x4_1;
            
            if (x10_3 == 0)
                x4_1 = cs2p2p_gFlagUserBreakConnect;
            else
                x4_1 = cs2p2p_gFlagUserBreakListen;
            
            s = *(x8_2 + 0x17b);
            var_70 = x8_4;
            int32_t var_60;
            var_60 = x10_3;
            int32_t x0_2 = cs2_TCPNBSkt_Overtime_Send(x0_1, &s, 0x1c, 0x1388, x4_1);
            sockaddr_cs2 var_a8;
            int32_t x0_4;
            
            if ((x0_2 & 0x80000000) == 0)
            {
                char* x4_2;
                
                if (*((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + 0x50) == 0)
                    x4_2 = cs2p2p_gFlagUserBreakConnect;
                else
                    x4_2 = cs2p2p_gFlagUserBreakListen;
                
                x0_4 = cs2_TCPNBSkt_Overtime_Recv(*((cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc")) + "nAckPKciP11sockaddr_inc"), &var_a8, &var_ac, 0x1388, x4_2);
            }
            
            if (((x0_2 & 0x80000000) != 0 || (x0_4 & 0x80000000) != 0))
            {
                x8_6 = 4;
                goto label_1c30c;
            }
            
            void* x19_2 = (cs2p2p_gSession + (x23_1 * "PKciP11sockaddr_inc"));
            ntohAddrCS2(&var_a8, (x19_2 + "PKciP11sockaddr_inc"));
            sockaddr_cs2 var_90;
            ntohAddrCS2(&var_90, (x19_2 + "cs2p2p_PPPP_Proto_Send_P2PReqAck…"));
            *((cs2p2p_gSession + (arg1 * 0x4d38)) + "DevLgnAckPKciP11sockaddr_inc") = 1;  {  // {"PKciP11sockaddr_inc"}}
            result = time(nullptr);
            *(x19_2 + 0x34) = result;
        }
    }
    
    if (*(x20 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

