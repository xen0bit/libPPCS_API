
int64_t cs2p2p_PPPP_DRW_TCPSend(char* arg1, int32_t arg2, char arg3, int32_t arg4, int64_t arg5, int32_t arg6, uint32_t arg7, char* arg8)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int32_t temp0 = _byteswap(arg4);
    int32_t temp0_1 = _byteswap((arg6 + 4));
    uint64_t x23 = (arg6 & 0xffff);
    int16_t var_558 = 0xd0f1;
    uint16_t var_556 = (temp0_1 >> 0x10);
    char var_554 = 0xd1;
    uint16_t var_552 = (temp0 >> 0x10);
    char var_553 = arg3;
    void var_550;
    
    if ((arg5 != 0 && (arg6 & 0xffff) != 0))
        memcpy(&var_550, arg5, x23);
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_558, (x23 + 8), arg7, arg8);
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

