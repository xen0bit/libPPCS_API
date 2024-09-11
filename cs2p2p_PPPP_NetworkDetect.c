
int64_t cs2p2p_PPPP_NetworkDetect(char* arg1, uint16_t arg2)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    if (arg1 == 0)
        return 0xfffffffb;
    
    /* tailcall */
    return cs2p2p_PPPP__DoNetWorkDetect(arg1, 0, arg1, arg2, cs2p2p_gServerString, cs2p2p_gP2PServerAddr, (cs2p2p_gP2PServerAddr + 0x10), (cs2p2p_gP2PServerAddr + 0x20));
}

