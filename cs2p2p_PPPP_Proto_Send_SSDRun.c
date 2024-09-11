
int64_t cs2p2p_PPPP_Proto_Send_SSDRun(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, int16_t* arg7, int16_t* arg8)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int32_t var_158 = 0x340038f1;
    int64_t var_138 = 0;
    uint16_t var_140 = (_byteswap(*arg7) >> 0x10);
    uint32_t x8_4 = arg7[1];
    int32_t temp0_1 = _byteswap(arg5);
    uint16_t var_13e = (_byteswap(x8_4) >> 0x10);
    int64_t var_128 = 0;
    int32_t var_13c = _byteswap(*(arg7 + 4));
    uint16_t var_130 = (_byteswap(*arg8) >> 0x10);
    uint16_t var_12e = (_byteswap(arg8[1]) >> 0x10);
    int32_t var_14c = temp0_1;
    int32_t var_12c = _byteswap(*(arg8 + 4));
    int128_t s1;
    strncpy(&s1, arg4, 7);
    void s1_1;
    strncpy(&s1_1, arg6, 7);
    int128_t s1_2;
    int128_t v0;
    int128_t v1;
    int128_t v2;
    v0 = cs2p2p__P2P_Proprietary_Encrypt("SSD@cs2-network.", &s1, &s1_2, 0x34);
    int32_t var_228;
    *var_128[4] = var_228;
    int128_t var_238;
    *var_138[4] = var_238;
    int128_t var_248;
    int128_t var_144 = var_248;
    s1 = s1_2;
    int64_t result = cs2p2p_SendMessage(arg1, &var_158, 0x38, arg2, arg3);
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

