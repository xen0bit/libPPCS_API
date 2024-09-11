
int64_t cs2p2p_PPPP_DRW_Send(char* arg1, int32_t arg2, sockaddr_in* arg3, char arg4, int32_t arg5, int64_t arg6, int32_t arg7)

{
    int0_t tpidr_el0;
    uint64_t x23 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x23 + 0x28);
    int32_t temp0 = _byteswap(arg5);
    int32_t temp0_1 = _byteswap((arg7 + 4));
    uint64_t x22 = (arg7 & 0xffff);
    int16_t var_548 = 0xd0f1;
    uint16_t var_546 = (temp0_1 >> 0x10);
    char var_544 = 0xd1;
    uint16_t var_542 = (temp0 >> 0x10);
    char var_543 = arg4;
    void var_540;
    
    if ((arg6 != 0 && (arg7 & 0xffff) != 0))
        memcpy(&var_540, arg6, x22);
    int64_t result = cs2p2p_SendMessage(arg1, &var_548, (x22 + 8), arg2, arg3);
    
    if (*(x23 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

