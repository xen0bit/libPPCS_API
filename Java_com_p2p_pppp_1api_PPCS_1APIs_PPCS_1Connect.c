
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1Connect(int64_t* arg1, int64_t arg2, int64_t arg3, int32_t arg4, int32_t arg5)

{
    if (arg3 == 0)
        /* tailcall */
        return cs2p2p_PPPP_Connect(0, arg4, arg5);
    
    int64_t x0_1 = *(*arg1 + 0x548)(arg1, arg3, 0);
    
    if (x0_1 == 0)
        return 0xffffec78;
    
    int32_t x0_3 = cs2p2p_PPPP_Connect(x0_1, arg4, arg5);
    *(*arg1 + 0x550)(arg1, arg3, x0_1);
    return x0_3;
}

