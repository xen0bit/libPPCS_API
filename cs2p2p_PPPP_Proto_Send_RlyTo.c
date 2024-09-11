
int64_t cs2p2p_PPPP_Proto_Send_RlyTo(char* arg1, int32_t arg2, sockaddr_in* arg3, int16_t* arg4, int32_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int32_t temp0 = _byteswap(arg5);
    int32_t var_128 = 0x140082f1;
    int32_t var_114 = temp0;
    int64_t var_11c = 0;
    uint16_t var_124 = (_byteswap(*arg4) >> 0x10);
    uint16_t var_122 = (_byteswap(arg4[1]) >> 0x10);
    int32_t var_120 = _byteswap(*(arg4 + 4));
    int64_t result = cs2p2p_SendMessage(arg1, &var_128, 0x18, arg2, arg3);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

