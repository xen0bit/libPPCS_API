
int64_t cs2p2p_PPPP_LoginStatus_Check(char* arg1)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    if (arg1 == 0)
        return 0xfffffffb;
    
    int32_t x0 = time(nullptr);
    uint64_t x8_1 = *cs2p2p_gLastSuccessLoginTime;
    
    if (*cs2p2p_gLastSuccessLoginTimeTCP > x8_1)
    {
        x0 = time(nullptr);
        x8_1 = *cs2p2p_gLastSuccessLoginTimeTCP;
    }
    
    *arg1 = (((x0 - x8_1) < 0x3d) ? 1 : 0);
    return 0;
}

