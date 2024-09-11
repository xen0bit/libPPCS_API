
int64_t cs2_SA_GetRemoteSockAddr()

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x19 + 0x28);
    int32_t var_2c = 0x18;
    int64_t s;
    __builtin_memset(s, 0, 0x18);
    int64_t result = getpeername();
    
    if (*(x19 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

