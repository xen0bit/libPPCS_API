
void cs2p2p_PPPP_thread_send_DRW(int32_t arg1) __noreturn

{
    int128_t v0;
    v0 = 0x6e;
    *v0[2] = 0x6e;
    *v0[4] = 0x6e;
    *v0[6] = 0x6e;
    *v0[8] = 0x6e;
    *v0[0xa] = 0x6e;
    *v0[0xc] = 0x6e;
    *v0[0xe] = 0x6e;
    uint32_t x8 = *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53);  {  // {"PKciP11sockaddr_inc"}}
    *((cs2p2p_gSession + (arg1 * 0x4d38)) + "cs2p2p_PPPP_Proto_Send_RlyHelloP…") = v0;  {  // {"PKciP11sockaddr_inc"}}
    int32_t x9_1;
    
    if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + "nAckPKciP11sockaddr_inc") == 0xffffffff)  {  // {"PKciP11sockaddr_inc"}}
        x9_1 = 0x28;
    else
        x9_1 = 0xa;
    
    *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x5c) = x9_1;  {  // {"PKciP11sockaddr_inc"}}
    
    if (x8 == 0)
    {
        do
        {
            pthread_mutex_lock(&data_50d02c);
            cs2p2p_DoDRWSend(arg1);
            pthread_mutex_unlock(&data_50d02c);
            
            if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) != 0)  {  // {"PKciP11sockaddr_inc"}}
                break;
            
            cs2p2p_mSecSleep(*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x5c));  {  // {"PKciP11sockaddr_inc"}}
        } while (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x53) == 0);  {  // {"PKciP11sockaddr_inc"}}
    }
    
    pthread_exit(nullptr);
    /* no return */
}

