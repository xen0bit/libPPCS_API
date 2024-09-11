
void cs2p2p_ResetTCPrSessionInfo(char* arg1)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    
    if (arg1 != 0)
    {
        int32_t x24_1 = *(arg1 + 0x2c);
        int64_t x23_1 = *(arg1 + 0x30);
        uint64_t x21_1 = *(arg1 + 0x38);
        char* s2;
        int128_t v0_1;
        s2 = malloc(0xc);
        int64_t x8_1 = *(arg1 + 0x1c);
        v0_1 = *(arg1 + 0xc);
        strcpy(v0_1);
        int32_t x0 = *(arg1 + 8);
        
        if ((x0 & 0x80000000) == 0)
            cs2_TCPNBSkt_Close(x0);
        
        memset(*(arg1 + 0x30), 0, x21_1);
        memset(arg1, 0, 0x50);
        *(arg1 + 0x2c) = x24_1;
        *(arg1 + 0x38) = x21_1;
        *(arg1 + 0x30) = x23_1;
        *(arg1 + 0x1c) = x8_1;
        *(arg1 + 0xc) = v0_1;
        strncpy(arg1, s2, 7);
        *(arg1 + 8) = 0xffffffff;
        free(s2);
    }
    
    if (*(x22 + 0x28) == x8)
        return;
    
    __stack_chk_fail();
    /* no return */
}

