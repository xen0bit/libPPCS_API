
int64_t cs2p2p_PPPP_Proto_TCPSend_HelloAck(char* arg1, int32_t arg2, int16_t* arg3, uint32_t arg4, char* arg5)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int64_t var_11c = 0;
    uint16_t var_124 = (_byteswap(*arg3) >> 0x10);
    uint16_t var_122 = (_byteswap(arg3[1]) >> 0x10);
    int32_t x10_7 = *(arg3 + 4);
    int32_t var_128 = 0x100001f1;
    int32_t var_120 = _byteswap(x10_7);
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_128, 0x14, arg4, arg5);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

