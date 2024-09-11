
char* cs2_SA_GetLocalIPString(int16_t* arg1, char* arg2, socklen_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x23 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x23 + 0x28);
    int32_t var_64 = 0x18;
    int64_t s;
    __builtin_memset(&s, 0, 0x18);
    int32_t fd = socket(*arg1, 2, 0);
    connect(fd, arg1, 0x18);
    getsockname(fd, &s, &var_64);
    close(fd);
    int32_t af;
    int64_t* x1_2;
    
    if (*s[4] == 0)
    {
        int64_t var_58;
        x1_2 = &var_58;
        af = 0xa;
    }
    else
    {
        x1_2 = (&s | 4);
        af = 2;
    }
    
    char* result = inet_ntop(af, x1_2, arg2, arg3);
    
    if (*(x23 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

