
int32_t cs2_TCPNBSkt_Overtime_Accept(int32_t arg1, union __SOCKADDR_ARG arg2, int32_t arg3, char* arg4)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int32_t x0 = cs2p2p_CurrentTickCount();
    int32_t result;
    
    while (true)
    {
        int32_t len = 0x18;
        result = accept(arg1, arg2, &len);
        
        if ((result & 0x80000000) == 0)
            break;
        
        if (*arg4 == 1)
        {
            result = -2;
            break;
        }
        
        if ((cs2p2p_CurrentTickCount() - x0) > arg3)
        {
            result = -3;
            break;
        }
        
        if (*__errno() != 0xb)
        {
            result = -1;
            break;
        }
        
        cs2p2p_mSecSleep(1);
    }
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

