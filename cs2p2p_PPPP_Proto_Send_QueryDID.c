
int64_t cs2p2p_PPPP_Proto_Send_QueryDID(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    void s1;
    memset(&s1, 0, 0xfc);
    int32_t var_158 = 0x400008f1;
    strncpy(&s1, arg4, 0x40);
    int64_t result = cs2p2p_SendMessage(arg1, &var_158, 0x44, arg2, arg3);
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

