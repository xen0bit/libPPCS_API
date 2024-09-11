
void cs2p2p_PPPP_Proto_Read_RlyPortAck(int32_t* arg1, int32_t* arg2, uint16_t* arg3)

{
    *arg2 = _byteswap(*arg1);
    *arg3 = (_byteswap(arg1[1]) >> 0x10);
}

