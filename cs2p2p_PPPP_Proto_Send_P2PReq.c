
int64_t cs2p2p_PPPP_Proto_Send_P2PReq(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, int16_t* arg7)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x25 + 0x28);
    int32_t var_168 = 0x240020f1;
    int64_t var_164;
    __builtin_memset(&var_164, 0, 0x24);
    strncpy(&var_164, arg4, 7);
    int64_t var_15c;
    strncpy(&*var_15c[4], arg6, 7);
    var_15c = _byteswap(arg5);
    int64_t var_14c = 0;
    int64_t var_154;
    *var_154[4] = (_byteswap(*arg7) >> 0x10);
    *var_154[6] = (_byteswap(arg7[1]) >> 0x10);
    var_14c = _byteswap(*(arg7 + 4));
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x28, arg2, arg3);
    
    if (*(x25 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

