
int64_t PPCS_Connect_Break()

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    *cs2p2p_gFlagUserBreakConnect = 1;
    return 0;
}

