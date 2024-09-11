
int64_t cs2p2p_PPPP_Check(int32_t arg1, int32_t* arg2)

{
    int0_t tpidr_el0;
    uint64_t x20 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x20 + 0x28);
    int64_t result;
    
    if (*cs2p2p_gFlagInitialized == 0)
        result = 0xffffffff;
    else if (arg2 == 0)
        result = 0xfffffffb;
    else
    {
        void* x23_1;
        
        if (arg1 <= 0x100)
            x23_1 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
        
        if ((arg1 > 0x100 || *x23_1 == 0xffffffff))
            result = 0xfffffff5;
        else
        {
            int64_t x22_1 = arg1;
            
            if (*((cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
                result = 0xfffffff2;
            else if (*((cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
                result = 0xffffffec;
            else if (*((cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
                result = 0xfffffff3;
            else if (*((cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc")) + 0x56) != 1)
            {
                memset(&arg2[1], 0, 0x50);
                *arg2 = *x23_1;
                void* x23_2 = (cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc"));
                arg2[0xd] = (time(nullptr) - *(x23_2 + 0x34));
                arg2[0x14] = *(x23_2 + 0x50);
                *(arg2 + 0x51) = *(x23_2 + 0x51);
                strncpy(&arg2[0xe], (x23_2 + 0x38), 0x18);
                *(arg2 + 4) = *(x23_2 + 4);
                *(arg2 + 0x14) = *(x23_2 + 0x14);
                *(arg2 + 0x24) = *(x23_2 + 0x24);
                int32_t x0_3 = *(x23_2 + "nAckPKciP11sockaddr_inc");
                
                if (x0_3 != 0xffffffff)
                {
                    int128_t var_60;
                    cs2p2p_TCPSkt_GetLocalAddr(x0_3, &var_60);
                    *(arg2 + 0x14) = var_60;
                    int128_t v0_2;
                    
                    if (*(x23_2 + 0x50) == 0)
                        v0_2 = *((cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc")) + "PKciP11sockaddr_inc");
                    else
                        v0_2 = *((cs2p2p_gSession + (x22_1 * "PKciP11sockaddr_inc")) + "cs2p2p_PPPP_Proto_Send_P2PReqAck…");
                    
                    *(arg2 + 0x24) = v0_2;
                }
                
                result = 0;
            }
            else
                result = 0xfffffff4;
        }
    }
    
    if (*(x20 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

