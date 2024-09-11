
int32_t cs2_TCPNBSkt_Connect(int32_t arg1, int16_t* arg2)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    void var_a8;
    memset(&var_a8, 0, 0x68);
    int64_t var_b0 = *(arg2 + 0x10);
    int128_t addr = *arg2;
    socklen_t len;
    
    if (*arg2 == 2)
        len = 0x10;
    else
        len = 0x1c;
    
    int32_t result = connect(arg1, &addr, len);
    
    if (result != 0)
    {
        int32_t x8_3 = *__errno();
        
        if (x8_3 == 0x6a)
            result = 0;
        else if ((x8_3 | 1) == 0x73)
            result = -1;
        else
            result = -2;
    }
    
    if (*(x21 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

