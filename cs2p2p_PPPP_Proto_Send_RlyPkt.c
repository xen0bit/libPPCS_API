
int64_t cs2p2p_PPPP_Proto_Send_RlyPkt(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, char arg7, int32_t arg8)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x25 + 0x28);
    int32_t temp0 = _byteswap(arg8);
    int32_t var_168 = 0x1c0083f1;
    int32_t var_164 = temp0;
    int64_t var_160;
    __builtin_memset(&var_160, 0, 0x18);
    strncpy(&var_160, arg4, 7);
    int64_t var_158;
    strncpy(&*var_158[4], arg6, 7);
    var_158 = _byteswap(arg5);
    int64_t var_150;
    *var_150[4] = arg7;
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x20, arg2, arg3);
    
    if (*(x25 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

