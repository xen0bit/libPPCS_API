
int64_t cs2p2p_PPPP_Proto_Send_ListReq1(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int32_t var_158 = 0x140067f1;
    int64_t var_154;
    __builtin_memset(&var_154, 0, 0x14);
    strncpy(&var_154, arg4, 7);
    int64_t var_14c;
    strncpy(&*var_14c[4], arg6, 7);
    var_14c = _byteswap(arg5);
    int64_t result = cs2p2p_SendMessage(arg1, &var_158, 0x18, arg2, arg3);
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

