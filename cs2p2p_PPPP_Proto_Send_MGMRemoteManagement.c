
int64_t cs2p2p_PPPP_Proto_Send_MGMRemoteManagement(char* arg1, int32_t arg2, sockaddr_in* arg3, char arg4, char arg5, int64_t arg6, int16_t arg7)

{
    uint64_t x27 = arg7;
    uint64_t x8_1 = (x27 / 0x4f4);
    int0_t tpidr_el0;
    uint64_t x10 = _ReadStatusReg(tpidr_el0);
    int64_t x9_1 = *(x10 + 0x28);
    uint64_t x8_2;
    
    if ((x27 % 0x4f4) != 0)
        x8_2 = (x8_1 + 1);
    else
        x8_2 = x8_1;
    
    char x26;
    
    if (x8_2 != 0)
        x26 = x8_2;
    else
        x26 = 1;
    
    int64_t result;
    
    if (x26 == 0)
        result = 0;
    else
    {
        int32_t x20_1 = 0;
        int16_t x25_1 = 0;
        
        do
        {
            uint32_t x22_1 = x25_1;
            int16_t var_568 = 0xf8f1;
            int32_t x8_4;
            
            if (((0 - x26) + x20_1) == 0xffffffff)
                x8_4 = (x27 - x22_1);
            else
                x8_4 = 0x4f4;
            
            int32_t x21_1 = (x8_4 & 0xffff);
            uint16_t var_566_1 = (_byteswap((x21_1 + 8)) >> 0x10);
            char var_564_1 = 0xf1;
            char var_560_1 = x20_1;
            char var_562_1 = arg4;
            x20_1 += 1;
            char var_55f_1 = x26;
            uint16_t var_55e_1 = (_byteswap(x8_4) >> 0x10);
            char var_563_1 = arg5;
            
            if ((arg6 != 0 && (x8_4 & 0xffff) != 0))
            {
                void var_55c;
                memcpy(&var_55c, (arg6 + x25_1), x8_4);
                x25_1 = (x21_1 + x22_1);
            }
            
            result = cs2p2p_SendMessage(arg1, &var_568, (x21_1 + 0xc), arg2, arg3);
        } while ((0 - x26) != -(x20_1));
    }
    
    if (*(x10 + 0x28) == x9_1)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

