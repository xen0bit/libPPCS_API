
int64_t cs2p2p_PPPP_Proto_TCPSend_TCPRlyReq(char* arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5, char arg6, char* arg7, char arg8, sockaddr_cs2* arg9, uint32_t arg10, char* arg11)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x9 = *(x24 + 0x28);
    int128_t var_164;
    __builtin_memset(&var_164, 0, 0x34);
    strncpy(&var_164, arg3, 7);
    strncpy(&*var_164[0xc], arg5, 7);
    *var_164[8] = _byteswap(arg4);
    int128_t var_144;
    *var_144[0xc] = arg6;
    *var_144[0xd] = *arg7;
    *var_144[0xe] = arg7[1];
    int32_t var_134;
    var_134 = arg8;
    *var_144[0xf] = arg7[2];
    int128_t var_154;
    htonAddrCS2(arg9, &*var_154[4]);
    int32_t var_168 = 0x340053f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_168, 0x38, arg10, arg11);
    
    if (*(x24 + 0x28) == x9)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

