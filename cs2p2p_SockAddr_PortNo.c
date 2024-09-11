
uint64_t cs2p2p_SockAddr_PortNo(int16_t* arg1)

{
    if ((*arg1 | 8) != 0xa)
        return 0xffffffff;
    
    return (_byteswap(arg1[1]) >> 0x10);
}

