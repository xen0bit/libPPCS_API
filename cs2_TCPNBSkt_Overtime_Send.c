
int64_t cs2_TCPNBSkt_Overtime_Send(int32_t arg1, int64_t arg2, int32_t arg3, int32_t arg4, char* arg5)

{
    int32_t x0 = cs2p2p_CurrentTickCount();
    int32_t x0_1 = cs2p2p_CurrentTickCount();
    
    if (arg3 != 0)
    {
        int32_t x25_1 = 0;
        
        do
        {
            if (*arg5 == 1)
                return 0xfffffffe;
            
            if ((x0_1 - x0) > arg4)
                return 0xfffffffd;
            
            int32_t x0_3 = send(arg1, (arg2 + x25_1), (arg3 - x25_1), "dyP16st_cs2p2p_P2PRdyPcPjS1_");
            
            if (x0_3 <= 0)
            {
                if (*__errno() != 0xb)
                    return 0xffffffff;
                
                cs2p2p_mSecSleep(1);
            }
            else
                x25_1 += x0_3;
            
            x0_1 = cs2p2p_CurrentTickCount();
        } while (x25_1 != arg3);
    }
    
    return 0;
}

