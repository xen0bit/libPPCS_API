
int64_t cs2p2p_PPPP_Proto_Send_DevLgnAck(char* arg1, int32_t arg2, sockaddr_in* arg3, char arg4)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int64_t var_128 = 0x40011f1;
    *var_128[4] = arg4;
    int64_t result = cs2p2p_SendMessage(arg1, &var_128, 8, arg2, arg3);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

