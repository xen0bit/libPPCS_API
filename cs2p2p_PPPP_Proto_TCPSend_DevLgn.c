
int64_t cs2p2p_PPPP_Proto_TCPSend_DevLgn(char* arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5, char arg6, char* arg7, int16_t* arg8, uint8_t* arg9, uint32_t arg10, char* arg11)

{
    int0_t tpidr_el0;
    uint64_t x20 = _ReadStatusReg(tpidr_el0);
    int64_t x9 = *(x20 + 0x28);
    int128_t s;
    __builtin_memset(&s, 0, 0x2c);
    int64_t var_190;
    __builtin_memset(&var_190, 0, 0x28);
    strncpy(&var_190, arg3, 7);
    int64_t var_188;
    strncpy(&*var_188[4], arg5, 7);
    char x8_1 = *arg7;
    int32_t temp0 = _byteswap(arg4);
    int64_t var_180;
    *var_180[5] = x8_1;
    *var_180[6] = arg7[1];
    var_188 = temp0;
    *var_180[4] = arg6;
    int64_t var_170 = 0;
    *var_180[7] = arg7[2];
    int64_t var_178;
    var_178 = (_byteswap(*arg8) >> 0x10);
    *var_178[2] = (_byteswap(arg8[1]) >> 0x10);
    *var_178[4] = _byteswap(*(arg8 + 4));
    cs2p2p_PPPP_CRCEnc(&var_190, 0x28, &s, 0x2c, arg9);
    int32_t var_168 = 0x2c0012f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_168, 0x30, arg10, arg11);
    
    if (*(x20 + 0x28) == x9)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

