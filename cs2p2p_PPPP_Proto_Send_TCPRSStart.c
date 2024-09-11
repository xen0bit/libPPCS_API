
int64_t cs2p2p_PPPP_Proto_Send_TCPRSStart(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, int32_t arg7, sockaddr_cs2* arg8)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t var_168 = 0x300052f1;
    int64_t var_164;
    __builtin_memset(&var_164, 0, 0x30);
    strncpy(&var_164, arg4, 7);
    int64_t var_15c;
    strncpy(&*var_15c[4], arg6, 7);
    int32_t temp0 = _byteswap(arg5);
    int32_t temp0_1 = _byteswap(arg7);
    var_15c = temp0;
    int64_t var_154;
    *var_154[4] = temp0_1;
    int64_t var_14c;
    htonAddrCS2(arg8, &var_14c);
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x34, arg2, arg3);
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

