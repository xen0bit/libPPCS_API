
int64_t cs2p2p_GetInetAddrByName(char* arg1, in_addr_t* arg2)

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    int32_t x0 = strcmp("255.255.255.255", arg1);
    in_addr_t x0_2;
    
    if (x0 != 0)
        x0_2 = inet_addr(arg1);
    
    int32_t result;
    
    if ((x0 != 0 && x0_2 == 0xffffffff))
    {
        int32_t x0_5;
        
        if (*cs2p2p_gbUseIPv6 == 1)
            x0_5 = 0xa;
        else
            x0_5 = 2;
        
        int32_t var_cc = 0x80;
        sockaddr_storage var_c8;
        result = SockAddr_Query(x0_5, arg1, 0, &var_c8, &var_cc);
        
        if (result == 0)
        {
            in_addr_t x8_1;
            in_addr_t var_c4;
            in_addr_t var_b4;
            
            if (*cs2p2p_gbUseIPv6 != 1)
                x8_1 = var_c4;
            else
                x8_1 = var_b4;
            *arg2 = x8_1;
        }
    }
    else
    {
        result = 0;
        *arg2 = inet_addr(arg1);
    }
    
    if (*(x21 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

