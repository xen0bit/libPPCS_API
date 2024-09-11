
int64_t cs2p2p_PPPP_Check_Buffer(int32_t arg1, char arg2, int32_t* arg3, int32_t* arg4)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int64_t result;
    
    if (*cs2p2p_gFlagInitialized == 0)
        result = 0xffffffff;
    else if (arg2 > 7)
        result = 0xfffffffb;
    else if ((arg1 > 0x100 || *(cs2p2p_gSession + (arg1 * 0x4d38)) == 0xffffffff))  {  // {"PKciP11sockaddr_inc"}}
        result = 0xfffffff5;
    else
    {
        int64_t x24_1 = arg1;
        
        if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
            result = 0xfffffff2;
        else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
            result = 0xffffffec;
        else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
            result = 0xfffffff3;
        else if (*((cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc")) + 0x56) != 1)
        {
            pthread_mutex_lock(&data_50d02c);
            
            if (arg3 != 0)
            {
                int64_t x9_2 = (cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc"));
                void* x8_15 = (x9_2 + (arg2 << 5));
                *arg3 = ((*(x8_15 + 0x2ac) + *(x8_15 + 0x1ac)) + *(x8_15 + 0x3ac));
                int32_t x0 = *(x9_2 + "nAckPKciP11sockaddr_inc");
                
                if (x0 != 0xffffffff)
                {
                    int32_t var_4c = 0;
                    ioctl(x0, "P_Proto_Send_QueryDIDAckPKciP11s…", &var_4c);
                    *arg3 += var_4c;
                }
            }
            
            if (arg4 != 0)
            {
                uint64_t x8_20 = arg2;
                int64_t x9_4 = (cs2p2p_gSession + (x24_1 * "PKciP11sockaddr_inc"));
                int64_t x8_21 = (x9_4 + (x8_20 << 1));
                *arg4 = ((*((x9_4 + (x8_20 << 5)) + 0x4ac) + *(x8_21 + "sockaddr_in")) - *(x8_21 + "d_RlyPortPKciP11sockaddr_in"));
            }
            
            pthread_mutex_unlock(&data_50d02c);
            result = 0;
        }
        else
            result = 0xfffffff4;
    }
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

