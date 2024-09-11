
uint64_t cs2p2p_over_time_receive(char* arg1, int32_t arg2, uint8_t* arg3, int32_t arg4, int16_t* arg5, int32_t arg6)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x25 + 0x28);
    void buf;
    memset(&buf, 0, 0x5a0);
    int64_t len = arg4;
    memset(arg3, 0, len);
    void readfds;
    memset(&readfds, 0, 0x80);
    __FD_SET_chk(arg2, &readfds, 0x80);
    uint64_t timeout_1 = (arg6 / 0x3e8);
    uint64_t timeout = timeout_1;
    uint64_t var_710 = ((arg6 - (timeout_1 * 0x3e8)) * 0x3e8);
    int32_t x23_1 = select((arg2 + 1), &readfds, nullptr, nullptr, &timeout);
    
    if ((x23_1 + 1) >= 2)
    {
        if (__FD_ISSET_chk(arg2, &readfds, 0x80) == 0)
            x23_1 = 0;
        else
        {
            socklen_t addrlen = 0x80;
            void addr;
            x23_1 = recvfrom(arg2, &buf, len, 0, &addr, &addrlen);
            
            if ((x23_1 & 0x80000000) == 0)
            {
                if ((arg1 == 0 || *arg1 == 0))
                    memcpy(arg3, &buf, x23_1);
                else
                    cs2p2p__P2P_Proprietary_Decrypt(arg1, &buf, arg3, x23_1);
                
                *(arg5 + 0xc) = 0;
                *(arg5 + 4) = 0;
                *arg5 = 2;
                int16_t var_706;
                arg5[1] = var_706;
                int32_t x8_8;
                int32_t var_704;
                int32_t var_6f4;
                
                if (*cs2p2p_gbUseIPv6 != 1)
                    x8_8 = var_704;
                else
                    x8_8 = var_6f4;
                *(arg5 + 4) = x8_8;
            }
        }
    }
    
    if (*(x25 + 0x28) == x8)
        return x23_1;
    
    __stack_chk_fail();
    /* no return */
}

