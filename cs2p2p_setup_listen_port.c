
uint64_t cs2p2p_setup_listen_port(uint16_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    int64_t x0;
    
    if (*cs2p2p_gbUseIPv6 == 1)
        x0 = 0xa;
    else
        x0 = 2;
    
    int32_t var_4c = 1;
    int32_t fd = socket(x0, 2, 0);
    
    if (fd != 0xffffffff)
    {
        setsockopt(fd, 1, 2, &var_4c, 4);
        setsockopt(fd, 1, 6, &var_4c, 4);
        void var_48;
        
        if (cs2p2p_TryBind(fd, arg1, &var_48) == 0xffffffff)
        {
            close(fd);
            fd = -3;
        }
    }
    
    if (*(x21 + 0x28) == x8)
        return fd;
    
    __stack_chk_fail();
    /* no return */
}

