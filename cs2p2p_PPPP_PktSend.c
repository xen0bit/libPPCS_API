
uint64_t cs2p2p_PPPP_PktSend(int32_t arg1, uint8_t arg2, char* arg3, int32_t arg4)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    if ((arg2 > 7 || (arg3 == 0 || arg4 > 0x4d8)))
        return 0xfffffffb;
    
    if (arg1 <= 0x100)
    {
        void* x24_1 = (cs2p2p_gSession + (arg1 * 0x4d38));  {  // {"PKciP11sockaddr_inc"}}
        
        if (*x24_1 != 0xffffffff)
        {
            int64_t x25_1 = arg1;
            
            if (*((cs2p2p_gSession + (x25_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
                return 0xfffffff2;
            
            if (*((cs2p2p_gSession + (x25_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
                return 0xffffffec;
            
            if (*((cs2p2p_gSession + (x25_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
                return 0xfffffff3;
            
            if (*((cs2p2p_gSession + (x25_1 * "PKciP11sockaddr_inc")) + 0x56) == 1)
                return 0xfffffff4;
            
            if (arg4 == 0)
                return 0;
            
            pthread_mutex_lock(&data_50d02c);
            void* x8_9 = (cs2p2p_gSession + (x25_1 * "PKciP11sockaddr_inc"));
            void* x23_1 = (x8_9 + (x25_1 << 1));
            cs2p2p_PPPP_PSR_Send((x8_9 + 0xe8), *x24_1, (x8_9 + 4), arg2, *(x23_1 + "P_Proto_Read_TCPRlyReqPK19st_cs2…"), arg3, arg4);
            *(x23_1 + "P_Proto_Read_TCPRlyReqPK19st_cs2…") += 1;
            pthread_mutex_unlock(&data_50d02c);
            return arg4;
        }
    }
    
    return 0xfffffff5;
}

