
void cs2p2p_FreeTCPrSessionInfo(void* arg1)

{
    if (arg1 == 0)
        return;
    
    int32_t x0 = *(arg1 + 8);
    
    if ((x0 & 0x80000000) == 0)
        cs2_TCPNBSkt_Close(x0);
    
    int64_t x0_1 = *(arg1 + 0x30);
    
    if (x0_1 != 0)
        free(x0_1);
    
    /* tailcall */
    return free(arg1);
}

