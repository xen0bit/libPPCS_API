
int64_t cs2p2p_PPPP_Proto_TCPSend_TCPRSLgn(char* arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5, int32_t arg6, int32_t arg7, int32_t arg8, int16_t arg9, int32_t arg10, sockaddr_cs2* arg11, uint32_t arg12, char* arg13)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x9_2 = *(x25 + 0x28);
    int128_t var_164;
    __builtin_memset(&var_164, 0, 0x38);
    strncpy(&var_164, arg3, 7);
    strncpy(&*var_164[0xc], arg5, 7);
    int32_t temp0 = _byteswap(arg4);
    int32_t temp0_1 = _byteswap(arg10);
    int32_t temp0_2 = _byteswap(arg6);
    int32_t temp0_3 = _byteswap(arg7);
    int32_t temp0_4 = _byteswap(arg8);
    int32_t temp0_5 = _byteswap(arg9);
    *var_164[8] = temp0;
    int128_t var_154;
    *var_154[4] = temp0_1;
    *var_154[8] = (temp0_2 >> 0x10);
    *var_154[0xa] = (temp0_3 >> 0x10);
    *var_154[0xc] = (temp0_4 >> 0x10);
    *var_154[0xe] = (temp0_5 >> 0x10);
    int128_t var_144;
    htonAddrCS2(arg11, &var_144);
    int32_t var_168 = 0x380050f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_168, 0x3c, arg12, arg13);
    
    if (*(x25 + 0x28) == x9_2)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

