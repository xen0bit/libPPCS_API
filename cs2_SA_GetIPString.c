
int64_t cs2_SA_GetIPString(void* arg1, char* arg2, socklen_t arg3)

{
    int32_t x0;
    int32_t* x1;
    
    if (*(arg1 + 4) == 0)
    {
        x1 = (arg1 + 8);
        x0 = 0xa;
    }
    else
    {
        x0 = 2;
        x1 = (arg1 + 4);
    }
    
    /* tailcall */
    return inet_ntop(x0, x1, arg2, arg3);
}

