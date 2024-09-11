
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1PktRecv(int64_t* arg1, int64_t arg2, int32_t arg3, int32_t arg4, int64_t arg5, int64_t arg6, int32_t arg7)

{
    int32_t x23 = -0x1388;
    
    if (((arg4 & 0x80000000) == 0 && arg5 != 0))
    {
        int64_t x0_1 = *(*arg1 + 0x5c0)(arg1, arg5, 0);
        
        if (arg6 == 0)
        {
            x23 = cs2p2p_PPPP_PktRecv(arg3, arg4, x0_1, 0, arg7);
            
            if (x0_1 != 0)
                *(*arg1 + 0x600)(arg1, arg5, x0_1, 0);
        }
        else
        {
            int64_t x0_3 = *(*arg1 + 0x5d8)(arg1, arg6, 0);
            x23 = cs2p2p_PPPP_PktRecv(arg3, arg4, x0_1, x0_3, arg7);
            
            if (x0_3 != 0)
                *(*arg1 + 0x618)(arg1, arg6, x0_3, 0);
            
            if (x0_1 != 0)
                *(*arg1 + 0x600)(arg1, arg5, x0_1, 0);
        }
    }
    
    return x23;
}

