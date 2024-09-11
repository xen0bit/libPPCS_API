
char* cs2p2p_PPPP_Proto_Read_RlyRdy(char* arg1, char* arg2, int32_t* arg3, char* arg4)

{
    strncpy(arg2, arg1, 7);
    char* result = strncpy(arg4, &arg1[0xc], 7);
    *arg3 = _byteswap(*(arg1 + 8));
    return result;
}

