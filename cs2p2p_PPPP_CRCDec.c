
uint64_t cs2p2p_PPPP_CRCDec(char* arg1, int32_t arg2, int64_t arg3, int32_t arg4, char* arg5)

{
    char* x23 = arg1;
    char* x0_1 = malloc(arg2);
    int32_t x19 = (arg2 - 4);
    
    if (x19 > arg4)
        x19 = -1;
    else
    {
        uint32_t i_1;
        
        if (arg5 != 0)
            i_1 = *arg5;
        
        int32_t x9_2;
        char x8_1;
        char x10_1;
        char x11_1;
        char x14_1;
        
        if ((arg5 == 0 || i_1 == 0))
        {
            x8_1 = 7;
            x10_1 = 5;
            x14_1 = 3;
            x11_1 = 1;
            x9_2 = (arg2 - 1);
            
            if (arg2 >= 1)
            {
            label_bb6c:
                uint64_t i_2 = arg2;
                char* x15_7 = x0_1;
                uint64_t i;
                
                do
                {
                    uint32_t x17_7 = *x23;
                    x23 = &x23[1];
                    uint32_t x11_5 = x11_1;
                    uint32_t x14_6 = x14_1;
                    uint32_t x18_5 = x10_1;
                    uint32_t x0_5 = x8_1;
                    char x4 = (((x14_1 ^ x11_1) ^ x10_1) ^ x8_1);
                    x11_1 = *((&data_23919 + ((((x17_7 % x11_5) + x14_6) & 7) << 3)) + (((x18_5 % x0_5) + x17_7) & 7));
                    x14_1 = *((&data_23919 + ((((x17_7 % x14_6) + x18_5) & 7) << 3)) + (((x0_5 % x11_5) + x17_7) & 7));
                    x10_1 = *((&data_23919 + ((((x17_7 % x18_5) + x0_5) & 7) << 3)) + (((x11_5 % x14_6) + x17_7) & 7));
                    x8_1 = *((&data_23919 + ((((x17_7 % x0_5) + x11_5) & 7) << 3)) + (((x14_6 % x18_5) + x17_7) & 7));
                    i = i_2;
                    i_2 -= 1;
                    *x15_7 = (x4 ^ x17_7);
                    x15_7 = &x15_7[1];
                } while (i != 1);
            }
        }
        else
        {
            void* x9_1 = &arg5[1];
            x11_1 = 1;
            x14_1 = 3;
            x10_1 = 5;
            x8_1 = 7;
            
            do
            {
                int32_t x13_1 = (i_1 & 0xff);
                uint32_t x11_2 = x11_1;
                uint32_t x14_2 = x14_1;
                uint32_t x10_2 = x10_1;
                uint32_t x8_2 = x8_1;
                i_1 = *x9_1;
                x9_1 += 1;
                x11_1 = *((&data_23919 + ((((x13_1 % x11_2) + x14_2) & 7) << 3)) + (((x10_2 % x8_2) + x13_1) & 7));
                x14_1 = *((&data_23919 + ((((x13_1 % x14_2) + x10_2) & 7) << 3)) + (((x8_2 % x11_2) + x13_1) & 7));
                x10_1 = *((&data_23919 + ((((x13_1 % x10_2) + x8_2) & 7) << 3)) + (((x11_2 % x14_2) + x13_1) & 7));
                x8_1 = *((&data_23919 + ((((x13_1 % x8_2) + x11_2) & 7) << 3)) + (((x14_2 % x10_2) + x13_1) & 7));
            } while (i_1 != 0);
            
            x9_2 = (arg2 - 1);
            
            if (arg2 >= 1)
                goto label_bb6c;
        }
        int64_t x8_11 = x9_2;
        
        if (x0_1[x8_11] != 0x43)
            x19 = -1;
        else
        {
            x0_1[x8_11] = 0;
            int64_t x8_13 = (arg2 - 2);
            
            if (x0_1[x8_13] != 0x43)
                x19 = -1;
            else
            {
                x0_1[x8_13] = 0;
                int64_t x8_15 = (arg2 - 3);
                
                if (x0_1[x8_15] != 0x43)
                    x19 = -1;
                else
                {
                    x0_1[x8_15] = 0;
                    int64_t x8_16 = x19;
                    
                    if (x0_1[x8_16] != 0x43)
                        x19 = -1;
                    else
                    {
                        x0_1[x8_16] = 0;
                        memcpy(arg3, x0_1, x19);
                        free(x0_1);
                    }
                }
            }
        }
    }
    
    return x19;
}

