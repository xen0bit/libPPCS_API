
int64_t cs2p2p_PPPP_Proto_Send_ReportSessionRdy(char* arg1, int32_t arg2, sockaddr_in* arg3, int32_t arg4, char* arg5, int32_t arg6, char* arg7, char arg8, int16_t arg9, int16_t arg10, int16_t* arg11, int16_t* arg12, int16_t* arg13, int16_t arg14, char arg15, char arg16)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x14 = *(x24 + 0x28);
    int32_t temp0 = _byteswap(arg9);
    int32_t temp0_1 = _byteswap(arg10);
    int32_t temp0_2 = _byteswap(arg14);
    int32_t temp0_3 = _byteswap(arg6);
    int32_t temp0_4 = _byteswap(arg4);
    int32_t var_168 = 0x5400f9f1;
    int32_t var_15c = temp0_3;
    uint16_t var_14c = (temp0 >> 0x10);
    uint16_t var_14a = (temp0_1 >> 0x10);
    uint16_t var_148 = (temp0_2 >> 0x10);
    int32_t var_150 = temp0_4;
    char var_144 = arg15;
    char var_143 = arg16;
    char var_146 = arg8;
    char x7;
    char var_145 = x7;
    void s1;
    strncpy(&s1, arg5, 7);
    void s1_1;
    strncpy(&s1_1, arg7, 7);
    int64_t var_118 = 0;
    uint16_t var_120 = (_byteswap(*arg13) >> 0x10);
    uint16_t var_11e = (_byteswap(arg13[1]) >> 0x10);
    int64_t var_138 = 0;
    int32_t var_11c = _byteswap(*(arg13 + 4));
    uint16_t var_140 = (_byteswap(*arg11) >> 0x10);
    uint16_t var_13e = (_byteswap(arg11[1]) >> 0x10);
    int64_t var_128 = 0;
    int32_t var_13c = _byteswap(*(arg11 + 4));
    uint16_t var_130 = (_byteswap(*arg12) >> 0x10);
    uint16_t var_12e = (_byteswap(arg12[1]) >> 0x10);
    int32_t var_12c = _byteswap(*(arg12 + 4));
    void var_268;
    cs2p2p__P2P_Proprietary_Encrypt("SSD@cs2-network.", &s1, &var_268, 0x54);
    memcpy(&s1, &var_268, 0x54);
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x58, arg2, arg3);
    
    if (*(x24 + 0x28) == x14)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

