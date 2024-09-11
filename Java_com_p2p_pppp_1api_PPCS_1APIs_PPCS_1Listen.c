
uint64_t Java_com_p2p_pppp_1api_PPCS_1APIs_PPCS_1Listen(int64_t* arg1, int64_t arg2, int64_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, int64_t arg7)

{
    int32_t x22_1;
    int64_t x25;
    
    if (arg3 == 0)
    {
        x25 = 0;
        int64_t x26_1;
        
        if (arg7 != 0)
        {
        label_22b0c:
            x26_1 = *(*arg1 + 0x548)(arg1, arg7, 0);
            
            if (x26_1 != 0)
                goto label_22b40;
            
            x22_1 = -0x1388;
        }
        else
        {
        label_22b24:
            x26_1 = 0;
        label_22b40:
            x22_1 = PPCS_Listen(x25, arg4, arg5, arg6, x26_1);
            
            if (x25 != 0)
                *(*arg1 + 0x550)(arg1, arg3, x25);
            
            if (x26_1 != 0)
                *(*arg1 + 0x550)(arg1, arg7, x26_1);
        }
    }
    else
    {
        x25 = *(*arg1 + 0x548)(arg1, arg3, 0);
        
        if (x25 != 0)
        {
            if (arg7 == 0)
                goto label_22b24;
            
            goto label_22b0c;
        }
        
        x22_1 = -0x1388;
    }
    return x22_1;
}

