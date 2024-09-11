
int64_t DO_APILicenseCheck_IoTWIFI(char* arg1, int32_t arg2, char* arg3)

{
    int0_t tpidr_el0;
    uint64_t x25 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x25 + 0x28);
    int64_t s1 = 0;
    int64_t var_70 = 0;
    uint64_t x0 = *cs2p2p_gCRCKey;
    
    if (x0 != 0)
        free(x0);
    
    if (strchr(arg3, 0x3a) == 0)
    {
        strncpy(&s1, arg3, 0xf);
        uint64_t x0_14 = malloc(4);
        *cs2p2p_gCRCKey = x0_14;
        *x0_14 = 0;
    }
    else
    {
        int64_t bytes = strlen(arg3);
        uint64_t x0_6 = malloc(bytes);
        *cs2p2p_gCRCKey = x0_6;
        memset(x0_6, 0, bytes);
        int64_t x0_8 = strchr(arg3, 0x3a);
        memcpy(&s1, arg3, (x0_8 - arg3));
        memcpy(x0_6, (x0_8 + 1), ((bytes - 1) - strlen(&s1)));
    }
    
    int64_t var_68 = 0;
    int64_t var_60 = 0;
    int32_t i_4 = strlen(arg1);
    int64_t x9 = 0;
    int64_t i_5 = 1;
    bool cond:1_1;
    
    do
    {
        int32_t x17_1 = 0;
        
        if (i_4 >= 1)
        {
            char* x1_3 = arg1;
            int64_t i_3 = i_4;
            int64_t i;
            
            do
            {
                uint32_t x3_1 = *x1_3;
                x1_3 = &x1_3[1];
                i = i_3;
                i_3 -= 1;
                x17_1 = (((x9 + 1) + arg2) + *(APILicenseMatrix_IoTWIFI + ((x17_1 + x3_1) % 0x19)));
            } while (i != 1);
        }
        
        int32_t x18_2 = arg2;
        int64_t i_2 = i_5;
        int32_t x2_8;
        int64_t i_1;
        
        do
        {
            i_1 = i_2;
            i_2 -= 1;
            x2_8 = (x17_1 % *(APILicenseMatrix_IoTWIFI + (x17_1 % 0x19)));
            x17_1 = (x18_2 + x2_8);
            x18_2 += 1;
        } while (i_1 != 1);
        int32_t x17_7 = (((x2_8 + x18_2) - 1) % 0x19);
        char x17_8;
        
        if (x17_7 == 0xe)
            x17_8 = 0x5a;
        else
            x17_8 = (x17_7 + 0x41);
        
        cond:1_1 = x9 != 5;
        *(&var_68 + x9) = x17_8;
        i_5 += 1;
        x9 += 1;
    } while (cond:1_1);
    int64_t result;
    
    if (strcmp(&s1, &var_68) != 0)
        result = 0xffffffff;
    else
        result = 0;
    
    if (*(x25 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

