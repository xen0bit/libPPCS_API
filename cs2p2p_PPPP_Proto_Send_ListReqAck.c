
uint64_t cs2p2p_PPPP_Proto_Send_ListReqAck(char* arg1, int32_t arg2, sockaddr_in* arg3, char arg4, void* arg5)

{
    uint64_t bytes = (8 | ((arg4 & 0xff) << 4));
    
    if (bytes > 0x500)
        return 0xfffffffe;
    
    int16_t* x0_2 = malloc(bytes);
    
    if (x0_2 == 0)
        return 0xfffffffd;
    
    uint16_t x8_3 = (_byteswap((bytes + 0xfffc)) >> 0x10);
    *(x0_2 + 4) = 0;
    *x0_2 = 0x69f1;  {  // {"icensePickOne_RTOSPcii"}}
    x0_2[1] = x8_3;
    x0_2[2] = arg4;
    
    if (arg4 != 0)
    {
        void* x8_4 = &x0_2[4];
        uint64_t i_1 = arg4;
        void* x10_1 = (arg5 + 4);
        uint64_t i;
        
        do
        {
            *x8_4 = 0;
            *(x8_4 + 8) = 0;
            i = i_1;
            i_1 -= 1;
            *x8_4 = (_byteswap(*(x10_1 - 4)) >> 0x10);
            *(x8_4 + 2) = (_byteswap(*(x10_1 - 2)) >> 0x10);
            int32_t x11_7 = *x10_1;
            x10_1 += 0x10;
            *(x8_4 + 4) = _byteswap(x11_7);
            x8_4 += 0x10;
        } while (i != 1);
    }
    
    int32_t x0_4 = cs2p2p_SendMessage(arg1, x0_2, bytes, arg2, arg3);
    free(x0_2);
    return x0_4;
}

