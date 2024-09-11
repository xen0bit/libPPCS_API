
int64_t cs2p2p_TCPSkt_GetLocalAddr(int64_t arg1, int64_t arg2)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x19 + 0x28);
    int32_t var_2c = 0x18;
    int64_t result = getsockname(arg1, arg2, &var_2c);
    
    if (*(x19 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

