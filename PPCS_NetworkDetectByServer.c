
int64_t PPCS_NetworkDetectByServer(st_cs2p2p_NetInfo* arg1, uint16_t arg2, char* arg3)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    int64_t result;
    
    if (*cs2p2p_gFlagInitialized == 0)
        result = 0xffffffff;
    else
    {
        result = 0xfffffffb;
        sockaddr_in var_58;
        void var_48;
        sockaddr_in var_38;
        
        if ((arg1 != 0 && arg3 != 0))
            result = cs2p2p_PPPP__DoNetWorkDetect(0xfffffffb, 0, arg1, arg2, arg3, &var_58, &var_48, &var_38);
    }
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

