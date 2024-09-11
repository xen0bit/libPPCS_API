
int64_t cs2p2p_PPPP_Proto_Send_SmartPunchTo(char* arg1, int32_t arg2, sockaddr_in* arg3, int16_t* arg4, int32_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int32_t var_148 = 0x14003ff1;
    int64_t var_13c = 0;
    uint32_t x8_1 = *arg4;
    int32_t temp0 = _byteswap(arg5);
    uint16_t var_144 = (_byteswap(x8_1) >> 0x10);
    uint16_t var_142 = (_byteswap(arg4[1]) >> 0x10);
    int32_t var_140 = _byteswap(*(arg4 + 4));
    uint16_t var_134 = (temp0 >> 0x10);
    char x5;
    char var_132 = x5;
    char x6;
    char var_131 = x6;
    int128_t var_248;
    cs2p2p__P2P_Proprietary_Encrypt("SSD@cs2-network.", &var_144, &var_248, 0x14);
    int32_t var_238;
    var_134 = var_238;
    var_144 = var_248;
    int64_t result = cs2p2p_SendMessage(arg1, &var_148, 0x18, arg2, arg3);
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

