
int64_t cs2p2p_PPPP_Proto_TCPSend_TCPRlyReqDSK(char* arg1, int32_t arg2, char* arg3, int32_t arg4, char* arg5, char arg6, char* arg7, sockaddr_cs2* arg8, char* arg9, uint32_t arg10, char* arg11)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8_2 = *(x22 + 0x28);
    void s1;
    memset(&s1, 0, 0x4c);
    strncpy(&s1, arg3, 7);
    void s1_1;
    strncpy(&s1_1, arg5, 7);
    int32_t var_15c = _byteswap(arg4);
    char var_138 = arg6;
    char var_137 = *arg7;
    char var_136 = arg7[1];
    char x7;
    char var_134 = x7;
    char var_135 = arg7[2];
    void var_150;
    htonAddrCS2(arg8, &var_150);
    void s1_2;
    strncpy(&s1_2, arg9, 0x17);
    int32_t var_168 = 0x4c0054f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_168, 0x50, arg10, arg11);
    
    if (*(x22 + 0x28) == x8_2)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

