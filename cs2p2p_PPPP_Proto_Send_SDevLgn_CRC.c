
int64_t cs2p2p_PPPP_Proto_Send_SDevLgn_CRC(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, uint8_t* arg7)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t var_168 = 0x180092f1;
    int64_t s;
    __builtin_memset(&s, 0, 0x18);
    int64_t var_180;
    __builtin_memset(&var_180, 0, 0x14);
    strncpy(&var_180, arg4, 7);
    int64_t var_178;
    strncpy(&*var_178[4], arg6, 7);
    var_178 = _byteswap(arg5);
    cs2p2p_PPPP_CRCEnc(&var_180, 0x14, &s, 0x18, arg7);
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x1c, arg2, arg3);
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

