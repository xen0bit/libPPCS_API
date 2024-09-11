
uint64_t cs2p2p_ProbeIPv4()

{
    int0_t tpidr_el0;
    uint64_t x21 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x21 + 0x28);
    int32_t fd;
    int128_t v0;
    fd = socket(2, 2, 0);
    int32_t x20_1;
    
    if ((fd & 0x80000000) != 0)
        x20_1 = 0;
    else
    {
        v0 = data_23b10;
        int64_t s;
        __builtin_memset(&s, 0, 0x20);
        int128_t var_70 = v0;
        struct addrinfo* ai;
        
        if (getaddrinfo("8.8.8.8", "16888", &var_70, &ai) == 0)
        {
            struct addrinfo* ai_next = ai;
            
            if (ai_next == 0)
            {
            label_11e88:
                x20_1 = 0;
            }
            else
            {
                while (true)
                {
                    char buf = 0;
                    x20_1 = 1;
                    
                    if ((sendto(fd, &buf, 1, 0, ai_next->ai_canonname, ai_next->ai_addrlen) & 0x80000000) == 0)
                        break;
                    
                    ai_next = ai_next->ai_next;
                    
                    if (ai_next == 0)
                        goto label_11e88;
                }
            }
            
            close(fd);
            freeaddrinfo(ai);
        }
        else
            x20_1 = -1;
    }
    
    if (*(x21 + 0x28) == x8)
        return x20_1;
    
    __stack_chk_fail();
    /* no return */
}

