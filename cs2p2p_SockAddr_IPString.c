
char* cs2p2p_SockAddr_IPString(int16_t* arg1, char* arg2, socklen_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x20 = _ReadStatusReg(tpidr_el0);
    int64_t x9 = *(x20 + 0x28);
    char* result = arg2;
    int128_t s;
    __builtin_memset(&s, 0, 0x40);
    uint32_t x9_1 = *arg1;
    
    if (x9_1 == 0xa)
    {
        inet_ntop(0xa, &arg1[4], &s, arg3);
        sprintf(result, "[%s]", &s);
    }
    else if (x9_1 != 2)
    {
        strncpy(result, "Unknown AF", arg3);
        result = nullptr;
    }
    else
        inet_ntop(2, &arg1[2], result, arg3);
    
    if (*(x20 + 0x28) == x9)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

