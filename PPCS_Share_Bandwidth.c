
int64_t PPCS_Share_Bandwidth(char arg1)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    int64_t result = 0;
    *(cs2p2p_gSDevInfo + 0x60) = arg1;
    
    if ((arg1 == 0 && *(cs2p2p_gSDevInfo + 0x1b8) >= 1))
    {
        result = *(cs2p2p_gSDevInfo + 0x1b0);
        *(cs2p2p_gSDevInfo + 0x1b8) = 3;
        
        if (result != 0)
        {
            pthread_join(result, 0);
            result = 0;
            *(cs2p2p_gSDevInfo + 0x1b0) = 0;
        }
    }
    
    return result;
}

