
int64_t cs2p2p_PPPP_Proto_Send_SSDP2PReqTo(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, int32_t arg7, void* arg8)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    uint64_t x8 = (arg7 & 0xffff);
    int64_t x9 = *(x25 + 0x28);
    uint64_t x26 = (x8 << 4);
    uint16_t x8_2 = (_byteswap((x26 + 0x18)) >> 0x10);
    int16_t var_268 = 0x39f1;  {  // {"xPci"}}
    uint16_t var_266 = x8_2;
    
    if (x8 != 0)
    {
        uint64_t i_1 = (arg7 & 0xffff);
        void var_24c;
        void* x9_1 = &var_24c;
        void* x10_1 = (arg8 + 4);
        uint64_t i;
        
        do
        {
            *x9_1 = 0;
            *(x9_1 + 8) = 0;
            i = i_1;
            i_1 -= 1;
            *x9_1 = (_byteswap(*(x10_1 - 4)) >> 0x10);
            *(x9_1 + 2) = (_byteswap(*(x10_1 - 2)) >> 0x10);
            int32_t x11_7 = *x10_1;
            x10_1 += 0x10;
            *(x9_1 + 4) = _byteswap(x11_7);
            x9_1 += 0x10;
        } while (i != 1);
    }
    
    int32_t var_25c = _byteswap(arg5);
    uint16_t var_250 = (_byteswap(arg7) >> 0x10);
    void s1;
    strncpy(&s1, arg4, 7);
    void s1_1;
    strncpy(&s1_1, arg6, 7);
    void var_468;
    cs2p2p__P2P_Proprietary_Encrypt("SSD@cs2-network.", &s1, &var_468, (x26 + 0x18));
    memcpy(&s1, &var_468, (x26 + 0x18));
    int64_t result = cs2p2p_SendMessage(arg1, &var_268, (x26 + 0x1c), arg2, arg3);
    
    if (*(x25 + 0x28) == x9)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

