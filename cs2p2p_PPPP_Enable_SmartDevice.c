
int64_t cs2p2p_PPPP_Enable_SmartDevice(char arg1)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    int64_t result = 0;
    *(cs2p2p_gSDevInfo + 0x61) = arg1;
    
    if ((arg1 == 0 && *(cs2p2p_gSDevInfo + 0x62) != 0))
    {
        result = *(cs2p2p_gSDevInfo + 0x1a8);
        *(cs2p2p_gSDevInfo + 0x62) = 2;
        
        if (result != 0)
        {
            pthread_join(result, 0);
            result = 0;
            *(cs2p2p_gSDevInfo + 0x1a8) = 0;
        }
    }
    
    return result;
}

