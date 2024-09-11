
int64_t cs2_TCPNBSkt_Overtime_Recv(int32_t arg1, int64_t arg2, int32_t* arg3, int32_t arg4, char* arg5)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x25 + 0x28);
    int32_t var_6c = arg1;
    int64_t x26 = *arg3;
    *arg3 = 0;
    int32_t x0 = cs2p2p_CurrentTickCount();
    int64_t result;
    
    if (*arg5 == 0)
    {
        while (true)
        {
            if (*arg3 == x26)
            {
                result = 0;
                break;
            }
            
            int32_t x8_4 = (cs2p2p_CurrentTickCount() - x0);
            
            if (x8_4 > arg4)
            {
                result = 0xfffffffd;
                break;
            }
            
            uint32_t x8_5 = (arg4 - x8_4);
            uint32_t x2;
            
            if (x8_5 < 0xa)
                x2 = x8_5;
            else
                x2 = 0xa;
            
            int32_t x0_3 = cs2_TCPNBSkt_Select(&var_6c, 1, x2);
            
            if (x0_3 != 0)
            {
                if ((x0_3 & 0x80000000) != 0)
                {
                    result = 0xffffffff;
                    break;
                }
                
                int64_t x8_6 = *arg3;
                int32_t x0_5 = recv(arg1, (arg2 + x8_6), (x26 - x8_6), 0);
                
                if (x0_5 > 0)
                    *arg3 += x0_5;
                else
                {
                    if (x0_5 == 0)
                    {
                        result = 0xffffffff;
                        break;
                    }
                    
                    if (*__errno() != 0xb)
                    {
                        result = 0xffffffff;
                        break;
                    }
                    
                    *arg3 = *arg3;
                }
            }
            
            if (*arg5 != 0)
                goto label_134a0;
        }
    }
    else
    {
    label_134a0:
        result = 0xfffffffe;
    }
    
    if (*(x25 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

