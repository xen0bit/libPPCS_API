
int64_t APILicenseCalculate(char* arg1, int32_t arg2, char* arg3, int32_t arg4)

{
    int64_t x22 = arg4;
    int32_t result = memset(arg3, 0, x22);
    
    if (arg4 >= 1)
    {
        int64_t i_1 = 0;
        bool cond:4_1;
        
        do
        {
            result = strlen(arg1);
            int32_t x8_1;
            
            if (result < 1)
                x8_1 = 0;
            else
            {
                x8_1 = 0;
                int64_t x10_1 = result;
                char* x11_1 = arg1;
                int64_t i;
                
                do
                {
                    uint32_t x12_1 = *x11_1;
                    x11_1 = &x11_1[1];
                    i = x10_1;
                    x10_1 -= 1;
                    x8_1 = (((i_1 + 1) + arg2) + *(APILicenseMatrix + ((x8_1 + x12_1) % 0x19)));
                } while (i != 1);
            }
            
            int32_t x9_2 = 0;
            int64_t x10_2 = 1;
            int32_t x11_7;
            
            do
            {
                x10_2 -= 1;
                x11_7 = (x8_1 % *(APILicenseMatrix + (x8_1 % 0x19)));
                x8_1 = ((x9_2 + arg2) + x11_7);
                x9_2 += 1;
            } while (i_1 != -(x10_2));
            
            int32_t x8_7 = (((arg2 + x11_7) - x10_2) % 0x19);
            char x8_8;
            
            if (x8_7 == 0xe)
                x8_8 = 0x5a;
            else
                x8_8 = (x8_7 + 0x41);
            
            arg3[i_1] = x8_8;
            
            if ((i_1 + 1) >= x22)
                break;
            
            cond:4_1 = i_1 < 5;
            i_1 += 1;
        } while (cond:4_1);
    }
    
    return result;
}

