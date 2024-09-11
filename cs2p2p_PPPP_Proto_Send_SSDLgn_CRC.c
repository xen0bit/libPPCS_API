
int64_t cs2p2p_PPPP_Proto_Send_SSDLgn_CRC(char* arg1, int32_t arg2, sockaddr_in* arg3, char* arg4, int32_t arg5, char* arg6, uint8_t* arg7)

{
    int0_t tpidr_el0;
    uint64_t x26 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x26 + 0x28);
    int32_t var_168 = 0x180036f1;
    int64_t s;
    __builtin_memset(&s, 0, 0x18);
    int64_t var_280;
    __builtin_memset(&var_280, 0, 0x14);
    strncpy(&var_280, arg4, 7);
    int64_t var_278;
    strncpy(&*var_278[4], arg6, 7);
    var_278 = _byteswap(arg5);
    cs2p2p_PPPP_CRCEnc(&var_280, 0x14, &s, 0x18, arg7);
    int128_t var_268;
    cs2p2p__P2P_Proprietary_Encrypt("SSD@cs2-network.", &s, &var_268, 0x18);
    int64_t var_258;
    int64_t var_154 = var_258;
    s = var_268;
    int64_t result = cs2p2p_SendMessage(arg1, &var_168, 0x1c, arg2, arg3);
    
    if (*(x26 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

