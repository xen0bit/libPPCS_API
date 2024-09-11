
int64_t cs2p2p_PPPP_Proto_Send_SDevLgnAck_CRC(char* arg1, int32_t arg2, sockaddr_in* arg3, int16_t* arg4, uint8_t* arg5)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int32_t var_148 = 0x140092f1;
    int64_t s;
    __builtin_memset(&s, 0, 0x14);
    int64_t var_150 = 0;
    uint16_t var_158 = (_byteswap(*arg4) >> 0x10);
    uint16_t var_156 = (_byteswap(arg4[1]) >> 0x10);
    int32_t var_154 = _byteswap(*(arg4 + 4));
    cs2p2p_PPPP_CRCEnc(&var_158, 0x10, &s, 0x14, arg5);
    int64_t result = cs2p2p_SendMessage(arg1, &var_148, 0x18, arg2, arg3);
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

