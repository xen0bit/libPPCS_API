
ssize_t cs2p2p_SendMessage(char* arg1, uint8_t* arg2, int32_t arg3, int32_t arg4, sockaddr_in* arg5)

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
        void var_618;
        cs2p2p_SockAddr_4to6(arg5, &var_618);
        len = arg3;
        buf = &var_5f8;
        addr = &var_618;
        addrlen = 0x1c;
        fd = arg4;
    }
    
    ssize_t result = sendto(fd, buf, len, 0, addr, addrlen);
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

