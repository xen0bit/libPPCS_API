
int64_t cs2_SA_SetSockAddr(int32_t arg1, char* arg2, int32_t arg3, int16_t* arg4)

{
    __builtin_memset(arg4, 0, 0x18);
    void* x2;
    int16_t x8;
    int32_t x9;
    
    if (arg1 == 0xa)
    {
        x8 = 0xa;
        x9 = _byteswap(arg3);
        x2 = &arg4[4];
    }
    else
    {
        if (arg1 != 2)
            return 0xffffffff;
        
        x8 = 2;
        x9 = _byteswap(arg3);
        x2 = &arg4[2];
    }
    
    *arg4 = x8;
    arg4[1] = (x9 >> 0x10);
    /* tailcall */
    return inet_pton(arg1, arg2, x2);
}

