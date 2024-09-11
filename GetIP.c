
int64_t GetIP(int32_t arg1, int64_t arg2, int64_t arg3)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int64_t x0;
    
    if (*cs2p2p_gbUseIPv6 == 1)
        x0 = 0xa;
    else
        x0 = 2;
    
    int32_t fd = socket(x0, 2, 0);
    
    if ((fd & 0x80000000) == 0)
    {
        int32_t var_2e8 = 0x280;
        void var_2d8;
        void* var_2e0_1 = &var_2d8;
        
        if (ioctl(fd, 0x8912, &var_2e8) == 0)
        {
            void* x22_1 = (&var_2d8 + (arg1 * 0x28));
            ioctl(fd, 0x8913, x22_1);
            
            if ((*(x22_1 + 0x10) & 1) != 0)
            {
                ioctl(fd, 0x8915, x22_1);
                char* x0_6 = inet_ntoa(*(x22_1 + 0x14));
                memcpy(arg2, x0_6, (strlen(x0_6) + 1));
                ioctl(fd, 0x8919, x22_1);
                char* x0_11 = inet_ntoa(*(x22_1 + 0x14));
                memcpy(arg3, x0_11, (strlen(x0_11) + 1));
            }
        }
    }
    
    close(fd);
    
    if (*(x24 + 0x28) == x8)
        return 0;
    
    __stack_chk_fail();
    /* no return */
}

