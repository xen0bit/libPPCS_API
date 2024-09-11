
int64_t cs2p2p_PPPP_Proto_Send_DevLgn_DSK(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, char arg7, char* arg8, int16_t* arg9, char* arg10, uint8_t* arg11)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8_1 = *(x21 + 0x28);
    int32_t var_168 = 0x440016f1;
    void var_164;
    memset(&var_164, 0, 0x44);
    int64_t var_1a8;
    __builtin_memset(&var_1a8, 0, 0x40);
    strncpy(&var_1a8, arg4, 7);
    int64_t var_1a0;
    strncpy(&*var_1a0[4], arg6, 7);
    char x8_2 = *arg8;
    int32_t temp0 = _byteswap(arg5);
    int64_t var_198;
    *var_198[5] = x8_2;
    *var_198[6] = arg8[1];
    var_1a0 = temp0;
    *var_198[4] = arg7;
    int64_t var_188 = 0;
    *var_198[7] = arg8[2];
    int64_t var_190;
    var_190 = (_byteswap(*arg9) >> 0x10);
    *var_190[2] = (_byteswap(arg9[1]) >> 0x10);
    *var_190[4] = _byteswap(*(arg9 + 4));
    int64_t s1;
    strncpy(&s1, arg10, 0x17);
    cs2p2p_PPPP_CRCEnc(&var_1a8, 0x40, &var_164, 0x44, arg11);
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x48, arg2, arg3);
    
    if (*(x21 + 0x28) == x8_1)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

