
int64_t cs2p2p_PPPP_DeInitialize()

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    int64_t (* const x21_1)() = cs2p2p_gSession;
    
    for (int64_t i = 0; i != 0x100; )
    {
        if ((*x21_1 & 0x80000000) == 0)
            cs2p2p_PPPP_Close(i);
        
        i += 1;
        x21_1 += "PKciP11sockaddr_inc";
    }
    
    int64_t x0_2 = *(cs2p2p_gSDevInfo + 0x1a8);
    *(cs2p2p_gSDevInfo + 0x62) = 2;
    
    if (x0_2 != 0)
    {
        pthread_join(x0_2, 0);
        *(cs2p2p_gSDevInfo + 0x1a8) = 0;
    }
    
    int64_t x0_3 = *(cs2p2p_gSDevInfo + 0x1b0);
    *(cs2p2p_gSDevInfo + 0x1b8) = 3;
    
    if (x0_3 != 0)
    {
        pthread_join(x0_3, 0);
        *(cs2p2p_gSDevInfo + 0x1b0) = 0;
    }
    
    uint64_t x0_4 = *cs2p2p_gCRCKey;
    
    if (x0_4 != 0)
        free(x0_4);
    
    *cs2p2p_gCRCKey = 0;
    *cs2p2p_gFlagInitialized = 0;
    return 0;
}

