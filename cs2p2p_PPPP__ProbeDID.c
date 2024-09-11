
uint64_t cs2p2p_PPPP__ProbeDID(char* arg1, char* arg2)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    void var_568;
    memset(&var_568, 0, 0x500);
    int32_t x21 = -2;
    
    if ((arg1 != 0 && arg2 != 0))
    {
        int64_t var_578 = 0;
        int64_t var_570_1 = 0;
        in_addr_t x0_2 = inet_addr(arg1);
        *var_578[4] = x0_2;
        
        if (x0_2 == 0xffffffff)
            x21 = -3;
        else
        {
            var_578 = 0x6c7d0002;
            int32_t fd = cs2p2p_setup_Socket();
            int32_t var_584 = 1;
            setsockopt();
            int32_t x24_1 = 0;
            
            while (true)
            {
                cs2p2p_PPPP_Proto_Write_Header(&var_568, 0x30, 0);
                
                if ((cs2p2p_SendMessage(cs2p2p_gP2PKeyString, &var_568, 4, fd, &var_578) & 0x80000000) == 0)
                {
                    uint8_t var_580;
                    uint16_t var_57c;
                    void var_68;
                    int32_t x0_7 = cs2p2p_PPPP_Proto_Recv_ALL(cs2p2p_gP2PKeyString, fd, &var_68, 0x64, &var_580, &var_57c, &var_568, 0x500);
                    
                    if ((x0_7 == 0 && (var_580 == 0x41 && var_57c == 0x14)))
                    {
                        int64_t var_598 = 0;
                        int64_t var_590 = 0;
                        uint32_t var_59c;
                        cs2p2p_PPPP_Proto_Read_PunchPkt(&var_568, &var_590, &var_59c, &var_598);
                        sprintf(arg2, "%s-%06d-%s", &var_590, var_59c, &var_598);
                        x21 = 0;
                        break;
                    }
                    
                    if (x0_7 == 0xffffffff)
                        x24_1 += 1;
                    
                    if (x0_7 == 0xffffffff)
                    {
                        if (x24_1 <= 0xe)
                            continue;
                        
                        x21 = -1;
                        break;
                    }
                }
                
                x21 = -4;
                break;
            }
            
            close(fd);
        }
    }
    
    if (*(x22 + 0x28) == x8)
        return x21;
    
    __stack_chk_fail();
    /* no return */
}

