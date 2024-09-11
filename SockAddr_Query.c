
int64_t SockAddr_Query(int32_t arg1, char* arg2, int16_t arg3, int64_t arg4, int32_t* arg5)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int128_t v0;
    v0 = 0;
    *v0[8] = 0;
    char* x23 = arg2;
    int128_t s_1;
    __builtin_memset(&s_1, 0, 0x50);
    int32_t x0 = strcmp("255.255.255.255", v0);
    in_addr_t x0_2;
    
    if (x0 != 0)
        x0_2 = inet_addr(x23);
    
    int64_t result;
    struct in_addr in;
    
    if ((x0 != 0 && x0_2 == 0xffffffff))
    {
        struct hostent* x0_5 = gethostbyname(x23);
        
        if (x0_5 != 0)
        {
            memcpy(&in, *x0_5->h_addr_list, x0_5->h_length);
            x23 = inet_ntoa(in);
            
            if (arg1 == 0xa)
                goto label_12050;
            
            goto label_120a0;
        }
        
        result = 0xffffffff;
    }
    else
    {
        if (arg1 != 0xa)
        {
        label_120a0:
            memcpy(&s_1, x23, (strlen(x23) + 1));
        }
        else
        {
        label_12050:
            sprintf(&s_1, "64:ff9b::%s", x23);
        }
        
        int128_t v0_1;
        v0_1 = 0;
        *v0_1[8] = 0;
        int128_t s;
        __builtin_memset(&s, 0, 0x20);
        v0_1 = 2;
        int32_t x8_2;
        
        if (arg1 == 0xa)
            x8_2 = arg1;
        else
            x8_2 = 2;
        
        in = 0;
        int32_t var_c4_1 = x8_2;
        int64_t var_c0_1 = 2;
        int128_t s_2;
        sprintf(&s_2, "%d", arg3, v0_1);
        struct addrinfo* ai_1;
        
        if (getaddrinfo(&s_1, &s_2, &in, &ai_1) == 0)
        {
            struct addrinfo* ai = ai_1;
            
            if (ai == 0)
            {
                freeaddrinfo(nullptr);
                result = 0xfffffffe;
            }
            else
            {
                memcpy(arg4, ai->ai_canonname, ai->ai_addrlen);
                *arg5 = ai->ai_addrlen;
                freeaddrinfo(ai);
                result = 0;
            }
        }
        else
            result = 0xffffffff;
    }
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

