
int64_t cs2p2p_PPPP_Proto_Recv_ALL(char* arg1, int32_t arg2, sockaddr_in* arg3, uint32_t arg4, char* arg5, uint16_t* arg6, int64_t arg7, int16_t arg8)

{
    int0_t tpidr_el0;
    uint64_t x27 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x27 + 0x28);
    char var_608;
    memset(&var_608, 0, 0x5a0);
    int32_t x0_2 = cs2p2p_over_time_receive(arg1, arg2, &var_608, 0x5a0, arg3, arg4);
    int64_t result;
    
    if (x0_2 == 0)
        result = 0xffffffff;
    else
    {
        char var_5f8;
        
        if ((x0_2 & 0x80000000) != 0)
            result = 0xfffffffe;
        else if ((x0_2 != 0x11 || var_5f8 != 0))
        {
        label_c330:
            
            if (var_608 != 0xf1)
                result = 0xfffffffd;
            else
            {
                int16_t var_606;
                *arg6 = (_byteswap(var_606) >> 0x10);
                char var_607;
                *arg5 = var_607;
                uint64_t x2_1 = *arg6;
                
                if ((x0_2 - 4) != x2_1)
                    result = 0xfffffffc;
                else
                {
                    void var_604;
                    void* x1_1 = &var_604;
                    
                    if (x2_1 <= arg8)
                    {
                        memcpy(arg7, x1_1, x2_1);
                        result = 0;
                    }
                    else
                    {
                        memcpy(arg7, x1_1, arg8);
                        result = 0xfffffffb;
                    }
                }
            }
        }
        else if (strcmp(&var_608, "338DB900E5592B32") == 0)
            result = 0xffffff9d;
        else
        {
            if (strcmp(&var_608, "338DB900E559KILL") != 0)
                goto label_c330;
            
            result = 0xffffff9e;
        }
    }
    
    if (*(x27 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

