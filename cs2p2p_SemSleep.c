
int32_t* cs2p2p_SemSleep(int64_t arg1, uint32_t arg2)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x11 = *(x21 + 0x28);
    uint64_t x8_1 = (arg2 / 0x3e8);
    uint64_t var_48 = x8_1;
    uint64_t var_40 = ((arg2 - (x8_1 * 0x3e8)) * 0xf4240);
    int32_t i;
    
    do
        i = sem_trywait(arg1);
     while (i == 0);
    int32_t* result = sem_timedwait(arg1, &var_48);
    
    if (result != 0)
    {
        result = __errno();
        
        if (*result != 0x6e)
            result = cs2p2p_mSecSleep(arg2);
    }
    
    if (*(x21 + 0x28) == x11)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

