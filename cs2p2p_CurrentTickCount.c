
uint64_t cs2p2p_CurrentTickCount()

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x19 + 0x28);
    int32_t var_38;
    gettimeofday(&var_38, nullptr);
    
    if (*(x19 + 0x28) == x8)
    {
        int64_t var_30;
        uint64_t x9_1 = ((var_30 * 0x20c49ba5e353f7cf) >> 0x40);
        return (((x9_1 >> 7) + (x9_1 >> 0x3f)) + (var_38 * 0x3e8));
    }
    
    __stack_chk_fail();
    /* no return */
}

