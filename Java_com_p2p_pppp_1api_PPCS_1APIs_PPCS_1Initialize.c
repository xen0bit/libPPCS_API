
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1Initialize(int64_t* arg1, int64_t arg2, int64_t arg3)

{
    int32_t x21;
    
    if (arg3 == 0)
        x21 = -0x1388;
    else
    {
        int64_t x0_1 = *(*arg1 + 0x5c0)(arg1, arg3, 0);
        x21 = cs2p2p_PPPP_Initialize();
        
        if (x0_1 != 0)
            *(*arg1 + 0x600)(arg1, arg3, x0_1, 0);
    }
    
    return x21;
}

