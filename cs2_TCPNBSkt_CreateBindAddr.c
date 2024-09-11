
uint64_t cs2_TCPNBSkt_CreateBindAddr(int16_t* arg1)

{
    int32_t fd = cs2_TCPNBSkt_Create(*arg1);
    
    if ((fd & 0x80000000) != 0)
        fd = -1;
    else if (bind(fd, arg1, 0x18) == 0xffffffff)
    {
        shutdown(fd, 2);
        close(fd);
        fd = -1;
    }
    
    return fd;
}

