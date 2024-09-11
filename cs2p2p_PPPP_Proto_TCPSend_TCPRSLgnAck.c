
int64_t cs2p2p_PPPP_Proto_TCPSend_TCPRSLgnAck(char* arg1, int32_t arg2, char arg3, uint32_t arg4, char* arg5)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int64_t var_128 = 0x40051f1;
    *var_128[4] = arg3;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_128, 8, arg4, arg5);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

