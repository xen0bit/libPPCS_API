
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1ConnectByServer(int64_t* arg1, int64_t arg2, int64_t arg3, int32_t arg4, int32_t arg5, int64_t arg6)

{
    int32_t x23_1;
    int64_t x21;
    
    if (arg3 == 0)
    {
        x21 = 0;
        
        if (arg6 != 0)
        {
        label_22d34:
            int64_t x0_3 = *(*arg1 + 0x548)(arg1, arg6, 0);
            
            if (x0_3 == 0)
                x23_1 = -0x1388;
            else
            {
                x23_1 = cs2p2p_PPPP_ConnectByServer(x21, arg4, arg5, x0_3);
                *(*arg1 + 0x550)(arg1, arg6, x0_3);
                
                if (x21 != 0)
                    *(*arg1 + 0x550)(arg1, arg3, x21);
            }
        }
        else
        {
        label_22d9c:
            x23_1 = cs2p2p_PPPP_ConnectByServer(x21, arg4, arg5, 0);
            
            if (x21 != 0)
                *(*arg1 + 0x550)(arg1, arg3, x21);
        }
    }
    else
    {
        x21 = *(*arg1 + 0x548)(arg1, arg3, 0);
        
        if (x21 != 0)
        {
            if (arg6 == 0)
                goto label_22d9c;
            
            goto label_22d34;
        }
        
        x23_1 = -0x1388;
    }
    return x23_1;
}

