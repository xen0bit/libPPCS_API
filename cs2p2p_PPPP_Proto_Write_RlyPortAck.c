
void cs2p2p_PPPP_Proto_Write_RlyPortAck(int64_t* arg1, int32_t arg2, int32_t arg3)

{
    int32_t temp0_1 = _byteswap(arg2);
    int32_t temp0 = _byteswap(arg3);
    *arg1 = 0;
    *arg1 = temp0_1;
    *(arg1 + 4) = (temp0 >> 0x10);
}

