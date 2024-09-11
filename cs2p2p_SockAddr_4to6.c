
int64_t cs2p2p_SockAddr_4to6(void* arg1, void* arg2)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int128_t s_1;
    __builtin_memset(&s_1, 0, 0x40);
    char* x0;
    int128_t v0;
    x0 = inet_ntop(2, (arg1 + 4), &s_1, 0x40);
    v0 = data_23b00;
    int64_t s;
    __builtin_memset(&s, 0, 0x20);
    int128_t var_b0 = v0;
    struct addrinfo* ai_1;
    int32_t result = getaddrinfo(x0, "16888", &var_b0, &ai_1);
    
    if (result == 0)
    {
        struct addrinfo* ai = ai_1;
        
        if (ai != 0)
        {
            struct addrinfo* ai_next = ai;
            
            do
            {
                if (ai_next->ai_family == 0xa)
                {
                    char* ai_canonname = ai_next->ai_canonname;
                    
                    if (ai_canonname != 0)
                    {
                        memcpy(arg2, ai_canonname, ai_next->ai_addrlen);
                        *(arg2 + 2) = *(arg1 + 2);
                        break;
                    }
                }
                
                ai_next = ai_next->ai_next;
            } while (ai_next != 0);
        }
        
        result = freeaddrinfo(ai);
    }
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

