
int32_t cs2p2p_BroadcastMessage(char* arg1, char* arg2, int32_t arg3, int32_t arg4, int32_t arg5)

{
    int0_t tpidr_el0;
    uint64_t x8 = _ReadStatusReg(tpidr_el0);
    int64_t x8_1 = *(x8 + 0x28);
    int64_t x0;
    
    if (*cs2p2p_gbUseIPv6 == 1)
        x0 = 0xa;
    else
        x0 = 2;
    
    int32_t fd = socket(x0, 2, 0);
    int32_t var_308;
    int128_t var_2e8;
    int32_t x0_2;
    
    if ((fd & 0x80000000) == 0)
    {
        var_308 = 0x280;
        int128_t* var_300_1 = &var_2e8;
        x0_2 = ioctl(fd, 0x8912, &var_308);
    }
    
    uint32_t x28;
    
    if (((fd & 0x80000000) == 0 && x0_2 == 0))
        x28 = (var_308 / 0x28);
    else
        x28 = 0;
    
    int32_t result = close(fd);
    __builtin_memset(&var_308, 0, 0x40);
    
    if (x28 >= 1)
    {
        int32_t x24_1 = 0;
        uint16_t x27_1 = (_byteswap(arg5) >> 0x10);
        
        do
        {
            GetIP(x24_1, &var_2e8, &var_308);
            result = strcmp("127.0.0.1", &var_2e8);
            
            if (result != 0)
            {
                result = strncmp("169.254", &var_2e8, 7);
                
                if (result != 0)
                {
                    int16_t var_318 = 2;
                    uint16_t var_316_1 = x27_1;
                    inet_aton(&var_308, (&var_318 | 4));
                    result = cs2p2p_SendMessageLocal(arg1, arg2, arg3, arg4, &var_318);
                }
            }
            
            x24_1 += 1;
        } while (x28 != x24_1);
    }
    
    if (*(x8 + 0x28) == x8_1)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

