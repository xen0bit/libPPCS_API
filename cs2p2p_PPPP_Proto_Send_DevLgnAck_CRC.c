
int64_t cs2p2p_PPPP_Proto_Send_DevLgnAck_CRC(char* arg1, int32_t arg2, sockaddr_in* arg3, char arg4, uint8_t* arg5)

{
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    int32_t var_14c = 0;
    int32_t var_148 = 0x80013f1;
    var_14c = arg4;
    int64_t var_144 = 0;
    cs2p2p_PPPP_CRCEnc(&var_14c, 4, &var_144, 8, arg5);
    int64_t result = cs2p2p_SendMessage(arg1, &var_148, 0xc, arg2, arg3);
    
    if (*(x22 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

