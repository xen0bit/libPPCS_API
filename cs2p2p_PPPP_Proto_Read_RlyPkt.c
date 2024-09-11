
char* cs2p2p_PPPP_Proto_Read_RlyPkt(int32_t* arg1, char* arg2, int32_t* arg3, char* arg4, char* arg5, int32_t* arg6)

{
    *arg6 = _byteswap(*arg1);
    strncpy(arg2, &arg1[1], 7);
    char* result = strncpy(arg4, &arg1[4], 7);
    *arg3 = _byteswap(arg1[3]);
    *arg5 = arg1[6];
    return result;
}

