
int64_t cs2p2p_PPPP_Proto_Read_TCPRlyReqDSK(char* arg1, char* arg2, int32_t* arg3, char* arg4, char* arg5, char* arg6, char* arg7, sockaddr_cs2* arg8, char* arg9)

{
    strncpy(arg2, arg1, 7);
    strncpy(arg4, &arg1[0xc], 7);
    *arg3 = _byteswap(*(arg1 + 8));
    *arg5 = arg1[0x2c];
    *arg6 = arg1[0x2d];
    arg6[1] = arg1[0x2e];
    arg6[2] = arg1[0x2f];
    *arg7 = arg1[0x30];
    ntohAddrCS2(&arg1[0x14], arg8);
    /* tailcall */
    return strncpy(arg9, &arg1[0x34], 0x17);
}

