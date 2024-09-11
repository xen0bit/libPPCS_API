
uint64_t cs2_SA_GetLocalPort(int64_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x19 + 0x28);
    int32_t var_44 = 0x18;
    void var_40;
    getsockname(arg1, &var_40, &var_44);
    
    if (*(x19 + 0x28) == x8)
    {
        int16_t var_3e;
        return (_byteswap(var_3e) >> 0x10);
    }
    
    __stack_chk_fail();
    /* no return */
}

