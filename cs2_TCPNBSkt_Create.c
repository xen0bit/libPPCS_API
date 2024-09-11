
uint64_t cs2_TCPNBSkt_Create(int16_t arg1)

{
    int0_t tpidr_el0;
    uint64_t x20 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x20 + 0x28);
    uint32_t x19 = arg1;
    int32_t var_2c = 1;
    int32_t x19_1;
    
    if (x19 == 0xa)
        x19_1 = socket(0xa, 1, 0);
    else
    {
        x19_1 = socket(2, 1, 0);
        
        if ((x19 != 2 && (x19_1 & 0x80000000) != 0))
            x19_1 = socket(0xa, 1, 0);
    }
    
    if ((x19_1 & 0x80000000) == 0)
    {
        setsockopt(x19_1, 1, 2, &var_2c, 4);
        fcntl(x19_1, 4, (fcntl(x19_1, 3, 0) | 0x800));
    }
    
    if (*(x20 + 0x28) == x8)
        return x19_1;
    
    __stack_chk_fail();
    /* no return */
}

