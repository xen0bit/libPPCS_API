
int64_t cs2p2p_PPPP_Proto_TCPSend_TCPRlyReqAck(char* arg1, int32_t arg2, char arg3, char arg4, uint32_t arg5, char* arg6)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x19 + 0x28);
    int64_t var_128 = 0x40055f1;
    *var_128[4] = arg3;
    *var_128[5] = arg4;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_128, 8, arg5, arg6);
    
    if (*(x19 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

