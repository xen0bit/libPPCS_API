
int64_t cs2p2p_PPPP_Connect_Break()

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    *cs2p2p_gFlagUserBreakConnect = 1;
    return 0;
}

