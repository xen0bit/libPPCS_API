
int64_t cs2_TCPNBSkt_Send(int32_t arg1, int64_t arg2, int32_t arg3)

{
    int32_t result = send(arg1, arg2, arg3, "dyP16st_cs2p2p_P2PRdyPcPjS1_");
    
    if (result > 0)
        return result;
    
    if (*__errno() != 0xb)
        return -1;
    
    return 0;
}

