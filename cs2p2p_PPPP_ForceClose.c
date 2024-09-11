
int64_t cs2p2p_PPPP_ForceClose(int32_t arg1)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    if ((arg1 > 0x100 || (*(cs2p2p_gSession + (arg1 * 0x4d38)) & 0x80000000) != 0))  {  // {"PKciP11sockaddr_inc"}}
        return 0xfffffff5;
    
    pthread_mutex_lock(&data_50d02c);
    void* x8_3 = (cs2p2p_gSession + (arg1 * "PKciP11sockaddr_inc"));
    *(x8_3 + 0x57) = 1;
    *(x8_3 + 0x53) = 1;
    pthread_mutex_unlock(&data_50d02c);
    cs2p2p_PPPP_Close(arg1);
    return 0;
}

