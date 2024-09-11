
char* cs2_SA_GetIPStringByName(int32_t arg1, char* arg2, char* arg3, socklen_t arg4)

{
    int0_t tpidr_el0;
    uint64_t x23 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x23 + 0x28);
    char* result;
    
    if (arg3 == 0)
        result = nullptr;
    else
    {
        memset(arg3, 0, arg4);
        int64_t s;
        __builtin_memset(&s, 0, 0x30);
        *s[4] = arg1;
        result = nullptr;
        struct addrinfo* ai_1;
        
        if (getaddrinfo(arg2, &data_241a8, &s, &ai_1) == 0)
        {
            struct addrinfo* ai = ai_1;
            
            if (ai == 0)
                result = nullptr;
            else
            {
                int64_t s_1;
                __builtin_memset(&s_1, 0, 0x18);
                uint32_t ai_addrlen = ai->ai_addrlen;
                size_t ai_addrlen_1;
                
                if (ai_addrlen < 0x18)
                    ai_addrlen_1 = ai_addrlen;
                else
                    ai_addrlen_1 = 0x18;
                
                memcpy(&s_1, ai->ai_canonname, ai_addrlen_1);
                freeaddrinfo(ai);
                int32_t af;
                int64_t* x1_1;
                
                if (*s_1[4] == 0)
                {
                    int64_t var_58;
                    x1_1 = &var_58;
                    af = 0xa;
                }
                else
                {
                    x1_1 = (&s_1 | 4);
                    af = 2;
                }
                
                result = inet_ntop(af, x1_1, arg3, arg4);
            }
        }
    }
    
    if (*(x23 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

