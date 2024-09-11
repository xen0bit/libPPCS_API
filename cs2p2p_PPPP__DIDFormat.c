
void cs2p2p_PPPP__DIDFormat(void* arg1, int64_t arg2)

{
    if (arg1 != 0)
    {
        int64_t x9_1 = 0;
        int32_t x8_1 = 0;
        char x11_1 = 1;
        bool cond:0_1;
        
        do
        {
            uint32_t x12_1 = *(arg1 + x9_1);
            
            if ((x12_1 - 0x30) <= 9)
            {
                if (x11_1 == 1)
                {
                    *(arg2 + x8_1) = 0x2d;
                    x12_1 = *(arg1 + x9_1);
                    x11_1 = 0;
                    x8_1 += 1;
                }
                
                *(arg2 + x8_1) = x12_1;
                x8_1 += 1;
            }
            else if ((x12_1 - 0x61) <= 0x19)
            {
                if (x11_1 == 0)
                {
                    *(arg2 + x8_1) = 0x2d;
                    x12_1 = *(arg1 + x9_1);
                    x8_1 += 1;
                    x11_1 = 1;
                }
                
                *(arg2 + x8_1) = (x12_1 + 0xe0);
                x8_1 += 1;
            }
            else if ((x12_1 - 0x41) <= 0x19)
            {
                if (x11_1 == 0)
                {
                    *(arg2 + x8_1) = 0x2d;
                    x12_1 = *(arg1 + x9_1);
                    x8_1 += 1;
                    x11_1 = 1;
                }
                
                *(arg2 + x8_1) = x12_1;
                x8_1 += 1;
            }
            else if (x12_1 != 0x2d)
                break;
            
            cond:0_1 = x9_1 < 0x3f;
            x9_1 += 1;
        } while (cond:0_1);
    }
}

