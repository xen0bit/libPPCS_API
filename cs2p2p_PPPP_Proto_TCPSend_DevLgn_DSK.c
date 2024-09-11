
int64_t cs2p2p_PPPP_Proto_TCPSend_DevLgn_DSK(char* arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5, char arg6, char* arg7, int16_t* arg8, char* arg9, uint8_t* arg10, uint32_t arg11, char* arg12)

{
    int0_t tpidr_el0;
    uint64_t x23 = _ReadStatusReg(tpidr_el0);
    int64_t x8_1 = *(x23 + 0x28);
    void var_164;
    memset(&var_164, 0, 0x44);
    int64_t var_1a8;
    __builtin_memset(&var_1a8, 0, 0x40);
    strncpy(&var_1a8, arg3, 7);
    int64_t var_1a0;
    strncpy(&*var_1a0[4], arg5, 7);
    char x8_2 = *arg7;
    int32_t temp0 = _byteswap(arg4);
    int64_t var_198;
    *var_198[5] = x8_2;
    *var_198[6] = arg7[1];
    var_1a0 = temp0;
    *var_198[4] = arg6;
    int64_t var_188 = 0;
    *var_198[7] = arg7[2];
    int64_t var_190;
    var_190 = (_byteswap(*arg8) >> 0x10);
    *var_190[2] = (_byteswap(arg8[1]) >> 0x10);
    *var_190[4] = _byteswap(*(arg8 + 4));
    int64_t s1;
    strncpy(&s1, arg9, 0x17);
    cs2p2p_PPPP_CRCEnc(&var_1a8, 0x40, &var_164, 0x44, arg10);
    int32_t var_168 = 0x440016f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_168, 0x48, arg11, arg12);
    
    if (*(x23 + 0x28) == x8_1)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

