
int64_t Check_MSG_Ready(void* arg1, int32_t* arg2, int128_t* arg3, uint8_t* arg4, uint16_t* arg5, int64_t arg6)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int64_t result;
    
    if (*(arg1 + 0x4e) == 0)
        result = 0xffffffff;
    else
    {
        uint64_t x22_1 = *(arg1 + 0x3e);
        void var_568;
        memcpy(&var_568, *(arg1 + 0x30), x22_1);
        *(arg1 + 0x3a) = 0;
        *(arg1 + 0x3e) = 0;
        *(arg1 + 0x4e) = 0;
        
        if (arg2 != 0)
            *arg2 = *(arg1 + 8);
        
        if (arg3 != 0)
        {
            arg3[1] = *(arg1 + 0x1c);
            *arg3 = *(arg1 + 0xc);
        }
        
        if (cs2p2p_PPPP_Proto_Read_Header(&var_568, arg4, arg5) == 0)
        {
            uint64_t x2_2 = *arg5;
            
            if ((x22_1 - 4) != x2_2)
                result = 0xfffffffc;
            else
            {
                void var_564;
                memcpy(arg6, &var_564, x2_2);
                result = 0;
            }
        }
        else
            result = 0xfffffffd;
    }
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

