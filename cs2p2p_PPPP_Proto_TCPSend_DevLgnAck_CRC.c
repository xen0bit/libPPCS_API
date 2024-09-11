
int64_t cs2p2p_PPPP_Proto_TCPSend_DevLgnAck_CRC(char* arg1, int32_t arg2, char arg3, uint8_t* arg4, uint32_t arg5, char* arg6)

{
    int0_t tpidr_el0;
    uint64_t x23 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x23 + 0x28);
    int32_t var_15c = 0;
    var_15c = arg3;
    int64_t var_154 = 0;
    cs2p2p_PPPP_CRCEnc(&var_15c, 4, &var_154, 8, arg4);
    int32_t var_158 = 0x80013f1;
    int64_t result = cs2p2p_PPPP_Proto_TCPSend_MSG(arg1, arg2, &var_158, 0xc, arg5, arg6);
    
    if (*(x23 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

