
uint64_t LanIfNum()

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    int64_t x0;
    
    if (*cs2p2p_gbUseIPv6 == 1)
        x0 = 0xa;
    else
        x0 = 2;
    
    int32_t fd = socket(x0, 2, 0);
    int32_t var_2c8;
    int32_t x0_2;
    
    if ((fd & 0x80000000) == 0)
    {
        var_2c8 = 0x280;
        void var_2b8;
        void* var_2c0_1 = &var_2b8;
        x0_2 = ioctl(fd, 0x8912, &var_2c8);
    }
    
    uint32_t x20;
    
    if (((fd & 0x80000000) == 0 && x0_2 == 0))
        x20 = (var_2c8 / 0x28);
    else
        x20 = 0;
    
    close(fd);
    
    if (*(x21 + 0x28) == x8)
        return x20;
    
    __stack_chk_fail();
    /* no return */
}

