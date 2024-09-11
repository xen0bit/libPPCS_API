
char* cs2p2p_AllocTCPSessionInfo(char* arg1, char* arg2, uint16_t arg3, int16_t arg4)

{
    char* s1 = malloc(0x50);
    
    if (s1 != 0)
    {
        memset(s1, 0, 0x50);
        int16_t* x0_3 = malloc(arg4);
        *(s1 + 0x30) = x0_3;
        
        if (x0_3 == 0)
        {
            free(s1);
            return nullptr;
        }
        
        *x0_3 = 0;
        cs2_SA_SetSockAddr(2, arg2, arg3, &s1[0xc]);
        *(s1 + 8) = 0xffffffff;
        *(s1 + 0x38) = arg4;
        strncpy(s1, arg1, 7);
    }
    
    return s1;
}

