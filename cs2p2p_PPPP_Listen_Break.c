
int64_t cs2p2p_PPPP_Listen_Break()

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    *cs2p2p_gFlagUserBreakListen = 1;
    *cs2p2p_gListenTimeOut = 0;
    return 0;
}

