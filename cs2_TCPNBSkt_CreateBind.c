
uint64_t cs2_TCPNBSkt_CreateBind(int32_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    int32_t var_6c = 1;
    int32_t fd = socket(2, 1, 0);
    int32_t x22;
    
    if (fd <= 0)
    {
        x22 = 1;
        fd = socket(0xa, 1, 0);
        
        if ((fd & 0x80000000) == 0)
            goto label_12fd0;
        
        fd = -1;
    }
    else
    {
        x22 = 0;
    label_12fd0:
        setsockopt(fd, 1, 2, &var_6c, 4);
        fcntl(fd, 4, (fcntl(fd, 3, 0) | 0x800));
        int16_t* x1_1;
        int64_t x2_2;
        int16_t var_68;
        
        if (x22 == 0)
        {
            uint16_t x8_3 = (_byteswap(arg1) >> 0x10);
            x1_1 = &var_68;
            x2_2 = 0x10;
            int64_t var_60_1 = 0;
            var_68 = 2;
            int32_t var_64 = 0;
            uint16_t var_66_2 = x8_3;
        }
        else
        {
            int32_t temp0_1 = _byteswap(arg1);
            var_68 = 0xa;
            int32_t s;
            __builtin_memset(&s, 0, 0x18);
            uint16_t var_66_1 = (temp0_1 >> 0x10);
            x1_1 = &var_68;
            x2_2 = 0x1c;
        }
        
        if (bind(fd, x1_1, x2_2) == 0xffffffff)
        {
            shutdown(fd, 2);
            close(fd);
            fd = -1;
        }
    }
    
    if (*(x21 + 0x28) == x8)
        return fd;
    
    __stack_chk_fail();
    /* no return */
}

