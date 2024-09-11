
char* cs2p2p_SockAddr_LocalIPString(int16_t* arg1, char* arg2, socklen_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x23 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x23 + 0x28);
    char* result = arg2;
    socklen_t len;
    int32_t fd;
    
    if (*arg1 != 0xa)
    {
        fd = socket(2, 2, 0);
        len = 0x10;
    }
    else
    {
        fd = socket(0xa, 2, 0);
        len = 0x1c;
    }
    
    connect(fd, arg1, len);
    int32_t var_11c = 0x80;
    void var_d8;
    getsockname(fd, &var_d8, &var_11c);
    int128_t s;
    __builtin_memset(&s, 0, 0x40);
    uint32_t x8_2 = *arg1;
    
    if (x8_2 == 0xa)
    {
        void var_d0;
        inet_ntop(0xa, &var_d0, &s, arg3);
        sprintf(result, "[%s]", &s);
    }
    else if (x8_2 != 2)
    {
        strncpy(result, "Unknown AF", arg3);
        result = nullptr;
    }
    else
        inet_ntop(2, (&var_d8 | 4), result, arg3);
    
    if (*(x23 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

