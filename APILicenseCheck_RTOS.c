
int64_t APILicenseCheck_RTOS(char* arg1, int32_t arg2, int64_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int64_t var_48 = 0;
    int64_t var_40 = 0;
    int32_t i_2 = strlen(arg1);
    int64_t x8_1 = 0;
    bool cond:1_1;
    
    do
    {
        int32_t x16_1 = 0;
        
        if (i_2 >= 1)
        {
            char* x18_1 = arg1;
            int64_t i_1 = i_2;
            int64_t i;
            
            do
            {
                uint32_t x2 = *x18_1;
                x18_1 = &x18_1[1];
                i = i_1;
                i_1 -= 1;
                x16_1 = (((x8_1 + 1) + arg2) + *(APILicenseMatrix_RTOS + ((x16_1 + x2) % 0x19)));
            } while (i != 1);
        }
        
        int64_t x17_2 = -1;
        int32_t x18_2 = arg2;
        int32_t x1_5;
        
        do
        {
            x17_2 += 1;
            x1_5 = (x16_1 % *(APILicenseMatrix_RTOS + (x16_1 % 0x19)));
            x16_1 = (x18_2 + x1_5);
            x18_2 += 1;
        } while (x8_1 != x17_2);
        
        int32_t x16_7 = (((x1_5 + x18_2) - 1) % 0x19);
        char x16_8;
        
        if (x16_7 == 0xe)
            x16_8 = 0x5a;
        else
            x16_8 = (x16_7 + 0x41);
        
        cond:1_1 = x8_1 != 5;
        *(&var_48 + x8_1) = x16_8;
        x8_1 += 1;
    } while (cond:1_1);
    int64_t result;
    
    if (strcmp(arg3, &var_48) != 0)
        result = 0xffffffff;
    else
        result = 0;
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

