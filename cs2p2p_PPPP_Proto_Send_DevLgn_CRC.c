
int64_t cs2p2p_PPPP_Proto_Send_DevLgn_CRC(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, char arg7, char* arg8, int16_t* arg9, uint8_t* arg10)

{
    int0_t tpidr_el0;
    uint64_t x28 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x28 + 0x28);
    int32_t var_168 = 0x2c0012f1;
    int64_t s;
    __builtin_memset(&s, 0, 0x2c);
    int64_t var_190;
    __builtin_memset(&var_190, 0, 0x28);
    strncpy(&var_190, arg4, 7);
    int64_t var_188;
    strncpy(&*var_188[4], arg6, 7);
    char x8_1 = *arg8;
    int32_t temp0 = _byteswap(arg5);
    int64_t var_180;
    *var_180[5] = x8_1;
    *var_180[6] = arg8[1];
    var_188 = temp0;
    *var_180[4] = arg7;
    int64_t var_170 = 0;
    *var_180[7] = arg8[2];
    int64_t var_178;
    var_178 = (_byteswap(*arg9) >> 0x10);
    *var_178[2] = (_byteswap(arg9[1]) >> 0x10);
    *var_178[4] = _byteswap(*(arg9 + 4));
    cs2p2p_PPPP_CRCEnc(&var_190, 0x28, &s, 0x2c, arg10);
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x30, arg2, arg3);
    
    if (*(x28 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

