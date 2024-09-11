
int64_t cs2_TCPNBSkt_Overtime_Connect(int32_t arg1, int16_t* arg2, int32_t arg3, char* arg4)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t x0 = cs2p2p_CurrentTickCount();
    void var_d8;
    memset(&var_d8, 0, 0x68);
    int64_t var_e0 = *(arg2 + 0x10);
    int128_t addr = *arg2;
    socklen_t len;
    
    if (*arg2 == 2)
        len = 0x10;
    else
        len = 0x1c;
    
    int64_t result;
    
    if (connect(arg1, &addr, len) == 0)
    {
    label_13690:
        result = 0;
    }
    else
    {
        int32_t* x0_4 = __errno();
        
        while (true)
        {
            int32_t x8_3 = *x0_4;
            
            if (x8_3 == 0x6a)
                goto label_13690;
            
            if ((x8_3 | 1) != 0x73)
            {
                result = 0xffffffff;
                break;
            }
            
            if (*arg4 == 1)
            {
                result = 0xfffffffe;
                break;
            }
            
            if ((cs2p2p_CurrentTickCount() - x0) > arg3)
            {
                result = 0xfffffffd;
                break;
            }
            
            cs2p2p_mSecSleep(1);
            memset(&var_d8, 0, 0x68);
            int64_t var_e0_1 = *(arg2 + 0x10);
            addr = *arg2;
            socklen_t len_1;
            
            if (*arg2 == 2)
                len_1 = 0x10;
            else
                len_1 = 0x1c;
            
            if (connect(arg1, &addr, len_1) == 0)
                goto label_13690;
        }
    }
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

