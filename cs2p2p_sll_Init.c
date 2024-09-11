
void cs2p2p_sll_Init(void* arg1, int32_t arg2)

{
    if (arg1 != 0)
    {
        __builtin_memset(arg1, 0, 0x20);
        *(arg1 + 0x18) = arg2;
    }
}

