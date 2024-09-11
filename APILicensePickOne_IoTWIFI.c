
uint64_t APILicensePickOne_IoTWIFI(char* arg1, int32_t arg2, int32_t arg3)

{
    int32_t i = arg3;
    int32_t x0 = strlen(arg1);
    int32_t x8;
    
    if (x0 < 1)
    {
        x8 = 0;
        
        if (i >= 1)
        {
        label_1aa80:
            int32_t x9_1 = 0;
            int32_t x11_2 = (1 - arg2);
            int32_t x14_6;
            
            do
            {
                int32_t x15_6 = (x9_1 + arg2);
                x9_1 += 1;
                i -= 1;
                x14_6 = (x8 % *(APILicenseMatrix_IoTWIFI + (x8 % 0x19)));
                x8 = (x15_6 + x14_6);
                x11_2 -= 1;
            } while (i != 0);
            
            x8 = (x14_6 - x11_2);
        }
    }
    else
    {
        int64_t i_1 = 0;
        x8 = 0;
        
        do
        {
            uint32_t x15_1 = arg1[i_1];
            i_1 += 1;
            x8 = ((i + arg2) + *(APILicenseMatrix_IoTWIFI + ((x8 + x15_1) % 0x19)));
        } while (i_1 < x0);
        
        if (i >= 1)
            goto label_1aa80;
    }
    
    return (x8 % 0x19);
}

