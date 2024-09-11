
uint64_t cs2_TCPNBSkt_Select(int32_t* arg1, int16_t arg2, int32_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    uint64_t i_1 = arg2;
    void readfds;
    memset(&readfds, 0, 0x80);
    int32_t nfds;
    
    if (i_1 == 0)
        nfds = 1;
    else
    {
        int32_t x24_1 = 0;
        int32_t* x25_1 = arg1;
        uint64_t i;
        
        do
        {
            __FD_SET_chk(*x25_1, &readfds, 0x80);
            int32_t x8_1 = *x25_1;
            x25_1 = &x25_1[1];
            
            if (x24_1 < x8_1)
                x24_1 = x8_1;
            
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
        nfds = (x24_1 + 1);
    }
    
    uint64_t timeout_1 = (arg3 / 0x3e8);
    uint64_t timeout = timeout_1;
    uint64_t var_e0 = ((arg3 - (timeout_1 * 0x3e8)) * 0x3e8);
    int32_t x0_2 = select(nfds, &readfds, nullptr, nullptr, &timeout);
    uint64_t result = (x0_2 & (x0_2 >> 0x1f));
    
    if ((x0_2 >= 1 && arg2 != 0))
    {
        int64_t x21_1 = 0;
        
        while (true)
        {
            if (__FD_ISSET_chk(arg1[x21_1], &readfds, 0x80) != 0)
            {
                result = (x21_1 + 1);
                break;
            }
            
            x21_1 += 1;
            
            if (x21_1 >= arg2)
            {
                result = 0;
                break;
            }
        }
    }
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

