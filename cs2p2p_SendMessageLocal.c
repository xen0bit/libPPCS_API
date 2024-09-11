
ssize_t cs2p2p_SendMessageLocal(char* arg1, uint8_t* arg2, int32_t arg3, int32_t arg4, union __CONST_SOCKADDR_ARG arg5)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    void var_5f8;
    memset(&var_5f8, 0, 0x5a0);
    
    if ((arg1 == 0 || *arg1 == 0))
        memcpy(&var_5f8, arg2, arg3);
    else
        cs2p2p__P2P_Proprietary_Encrypt(arg1, arg2, &var_5f8, arg3);
    
    int32_t fd;
    void* buf;
    int64_t len;
    union __CONST_SOCKADDR_ARG addr;
    socklen_t addrlen;
    
    if (*cs2p2p_gbUseIPv6 != 1)
    {
        len = arg3;
        buf = &var_5f8;
        addrlen = 0x10;
        fd = arg4;
        addr = arg5;
        *arg5 = 2;
    }
    else
    {
        int64_t s;
        __builtin_memset(&s, 0, 0x18);
        int16_t var_618 = 0xa;
        int64_t var_60c;
        *var_60c[6] = 0xffff;
        len = arg3;
        int16_t var_616_1 = *(arg5 + 2);
        buf = &var_5f8;
        addr = &var_618;
        addrlen = 0x1c;
        int64_t var_604;
        var_604 = *(arg5 + 4);
        fd = arg4;
    }
    
    ssize_t result = sendto(fd, buf, len, 0, addr, addrlen);
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

