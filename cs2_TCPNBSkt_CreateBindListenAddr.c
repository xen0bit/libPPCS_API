
uint64_t cs2_TCPNBSkt_CreateBindListenAddr(int16_t* arg1, int32_t arg2)

{
    int32_t fd = cs2_TCPNBSkt_Create(*arg1);
    
    if ((fd & 0x80000000) != 0)
        fd = -1;
    else
    {
        int32_t x0_3 = bind(fd, arg1, 0x18);
        int32_t x0_5;
        
        if (x0_3 != 0xffffffff)
            x0_5 = listen(fd, arg2);
        
        if ((x0_3 == 0xffffffff || x0_5 == 0xffffffff))
        {
            shutdown(fd, 2);
            close(fd);
            fd = -1;
        }
    }
    
    return fd;
}

