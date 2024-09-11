
uint64_t cs2_SA_GetPort(void* arg1)

{
    return (_byteswap(*(arg1 + 2)) >> 0x10);
}

