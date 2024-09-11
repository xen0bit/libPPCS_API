
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1Check_1Buffer(int64_t* arg1, int64_t arg2, int32_t arg3, int32_t arg4, int64_t arg5, int64_t arg6)

{
    int32_t x23_1;
    
    if ((arg4 & 0x80000000) != 0)
        x23_1 = -0x1388;
    else
    {
        int64_t x21_1;
        
        if (arg5 != 0)
        {
            x21_1 = *(*arg1 + 0x5d8)(arg1, arg5, 0);
            
            if (arg6 == 0)
                goto label_235f8;
            
            goto label_2358c;
        }
        
        x21_1 = 0;
        
        if (arg6 != 0)
        {
        label_2358c:
            int64_t x0_3 = *(*arg1 + 0x5d8)(arg1, arg6, 0);
            x23_1 = cs2p2p_PPPP_Check_Buffer(arg3, arg4, x21_1, x0_3);
            
            if (x0_3 != 0)
                *(*arg1 + 0x618)(arg1, arg6, x0_3, 0);
            
            if (x21_1 != 0)
                *(*arg1 + 0x618)(arg1, arg5, x21_1, 0);
        }
        else
        {
        label_235f8:
            x23_1 = cs2p2p_PPPP_Check_Buffer(arg3, arg4, x21_1, 0);
            
            if (x21_1 != 0)
                *(*arg1 + 0x618)(arg1, arg5, x21_1, 0);
        }
    }
    
    return x23_1;
}

