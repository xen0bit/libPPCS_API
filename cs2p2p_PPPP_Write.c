
uint64_t cs2p2p_PPPP_Write(int32_t arg1, char arg2, int64_t arg3, int32_t arg4)

{
    if (*cs2p2p_gFlagInitialized == 0)
        return 0xffffffff;
    
    if (arg2 > 7)
        return 0xfffffffb;
    
    if ((arg4 > 0x200000 || (arg3 == 0 || arg4 == 0)))
        return 0xfffffffb;
    
    if ((arg1 > 0x100 || *(cs2p2p_gSession + (arg1 * 0x4d38)) == 0xffffffff))  {  // {"PKciP11sockaddr_inc"}}
        return 0xfffffff5;
    
    int64_t x26_1 = arg1;
    
    if (*((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + 0x57) == 1)
        return 0xfffffff2;
    
    if (*((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + 0x58) == 1)
        return 0xffffffec;
    
    if (*((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + 0x55) == 1)
        return 0xfffffff3;
    
    if (*((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + 0x56) == 1)
        return 0xfffffff4;
    
    pthread_mutex_lock(&data_50d02c);
    uint64_t x28_1 = arg2;
    int64_t x8_8 = (cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc"));
    void* x21_1 = &*"p_PPPP_Proto_Send_RlyPortPKciP11…"[(x8_8 + (x28_1 << 1))];
    uint64_t x22_1 = *x21_1;
    
    if ((0x400 - x22_1) >= arg4)
    {
        memcpy((((x8_8 + (x28_1 << 0xa)) + x22_1) + 0x5b8), arg3, arg4);
        *x21_1 = (*x21_1 + arg4);
    }
    else
    {
        memcpy((((x8_8 + (x28_1 << 0xa)) + x22_1) + 0x5b8), arg3, (0x400 - x22_1));
        int64_t x21_2 = (cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc"));
        void* x8_11 = (x21_2 + (x28_1 << 1));
        uint32_t x8_12 = *(x8_11 + 0x598);
        uint32_t* s = malloc(0x28);
        
        if (s == 0)
            goto label_216ec;
        
        __builtin_memset(s, 0, 0x28);
        int64_t x0_2 = malloc(0x400);
        *(s + 8) = x0_2;
        uint32_t* s_2;
        
        if (x0_2 == 0)
        {
            s_2 = s;
        label_216d4:
            free(s_2);
        label_216ec:
            *((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + 0x53) = 1;
            *((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + 0x58) = 1;
            pthread_mutex_unlock(&data_50d02c);
            return 0xffffffec;
        }
        
        *s = x8_12;
        s[1] = 0x400;
        memcpy(x0_2, ((x21_2 + (x28_1 << 0xa)) + 0x5b8), 0x400);
        uint32_t var_68_1;
        var_68_1 = (((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + (x28_1 << 5)) + 0x198);
        cs2p2p_sll_Put((((cs2p2p_gSession + (x26_1 * "PKciP11sockaddr_inc")) + (x28_1 << 5)) + 0x198), s);
        int32_t x24_2 = (arg4 - (0x400 - x22_1));
        int64_t x20_1 = (arg3 + (0x400 - x22_1));
        int16_t x28_2 = (*(x8_11 + 0x598) + 1);
        *(x8_11 + 0x598) = x28_2;
        
        if (x24_2 >= 0x400)
        {
            int32_t i = (arg4 + x22_1);
            
            do
            {
                uint32_t* s_1 = malloc(0x28);
                
                if (s_1 == 0)
                    goto label_216ec;
                
                __builtin_memset(s_1, 0, 0x28);
                int64_t x0_4 = malloc(0x400);
                *(s_1 + 8) = x0_4;
                
                if (x0_4 == 0)
                {
                    s_2 = s_1;
                    goto label_216d4;
                }
                
                *s_1 = x28_2;
                s_1[1] = 0x400;
                memcpy(x0_4, x20_1, 0x400);
                cs2p2p_sll_Put(var_68_1, s_1);
                i -= 0x400;
                x20_1 += 0x400;
                x28_2 = (*(x8_11 + 0x598) + 1);
                *(x8_11 + 0x598) = x28_2;
            } while (i > 0x7ff);
            
            x24_2 = (i - 0x400);
        }
        
        *x21_1 = 0;
        
        if (x24_2 >= 1)
        {
            memcpy(((x21_2 + (x28_1 << 0xa)) + 0x5b8), x20_1, x24_2);
            *x21_1 = x24_2;
        }
    }
    
    pthread_mutex_unlock(&data_50d02c);
    return arg4;
}

