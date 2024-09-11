
int64_t cs2p2p_setup_Socket()

{
    int64_t x0;
    
    if (*cs2p2p_gbUseIPv6 == 1)
        x0 = 0xa;
    else
        x0 = 2;
    
    /* tailcall */
    return socket(x0, 2, 0);
}

