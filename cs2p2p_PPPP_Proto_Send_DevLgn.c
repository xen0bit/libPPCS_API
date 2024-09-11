
int64_t cs2p2p_PPPP_Proto_Send_DevLgn(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, char arg7, char* arg8, int16_t* arg9)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t var_168 = 0x280010f1;
    int64_t var_164;
    __builtin_memset(&var_164, 0, 0x28);
    strncpy(&var_164, arg4, 7);
    int64_t var_15c;
    strncpy(&*var_15c[4], arg6, 7);
    char x8_1 = *arg8;
    int32_t temp0 = _byteswap(arg5);
    int64_t var_154;
    *var_154[5] = x8_1;
    *var_154[6] = arg8[1];
    var_15c = temp0;
    *var_154[4] = arg7;
    int64_t var_144 = 0;
    *var_154[7] = arg8[2];
    int64_t var_14c;
    var_14c = (_byteswap(*arg9) >> 0x10);
    *var_14c[2] = (_byteswap(arg9[1]) >> 0x10);
    *var_14c[4] = _byteswap(*(arg9 + 4));
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x2c, arg2, arg3);
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

