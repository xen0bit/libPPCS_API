
int64_t cs2p2p_PPPP_Proto_Send_RlyPortAck(char* arg1, int32_t arg2, sockaddr_in* arg3, int32_t arg4, int32_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int32_t temp0 = _byteswap(arg5);
    int32_t temp0_1 = _byteswap(arg4);
    int64_t var_124 = 0;
    int32_t var_128 = 0x80073f1;
    var_124 = temp0_1;
    *var_124[4] = (temp0 >> 0x10);
    int64_t result = cs2p2p_SendMessage(arg1, &var_128, 0xc, arg2, arg3);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

