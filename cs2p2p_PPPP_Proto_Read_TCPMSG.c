
int64_t cs2p2p_PPPP_Proto_Read_TCPMSG(char* arg1, uint8_t* arg2, uint8_t* arg3, uint8_t* arg4, uint8_t* arg5, uint16_t arg6)

{
    int0_t tpidr_el0;
    uint64_t x24 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x24 + 0x28);
    int64_t result;
    
    if (_TCPRelay_CheckCRC_Verify(arg4, arg6, arg3) == 0)
    {
        void var_558;
        _TCPRelay_Proprietary_Decrypt(arg2, arg4, &var_558, arg6);
        cs2p2p__P2P_Proprietary_Decrypt(arg1, &var_558, arg5, arg6);
        result = 0;
    }
    else
        result = 0xffffffff;
    
    if (*(x24 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

