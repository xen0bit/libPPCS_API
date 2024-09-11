
int64_t cs2p2p_PPPP_Proto_TCPSend_Hello(char* arg1, int32_t arg2, uint32_t arg3, char* arg4)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int32_t var_128 = 0xf1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_128, 4, arg3, arg4);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

