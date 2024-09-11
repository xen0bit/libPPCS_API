
int64_t cs2p2p_PPPP_Proto_TCPSend_TCPRSStart(char* arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5, int32_t arg6, sockaddr_cs2* arg7, uint32_t arg8, char* arg9)

{
    int0_t tpidr_el0;
    uint64_t x27 = _ReadStatusReg(tpidr_el0);
    int64_t x9 = *(x27 + 0x28);
    int128_t var_164;
    __builtin_memset(&var_164, 0, 0x30);
    strncpy(&var_164, arg3, 7);
    strncpy(&*var_164[0xc], arg5, 7);
    int32_t temp0 = _byteswap(arg4);
    int32_t temp0_1 = _byteswap(arg6);
    *var_164[8] = temp0;
    int128_t var_154;
    *var_154[4] = temp0_1;
    htonAddrCS2(arg7, &*var_154[8]);
    int32_t var_168 = 0x300052f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_168, 0x34, arg8, arg9);
    
    if (*(x27 + 0x28) == x9)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

