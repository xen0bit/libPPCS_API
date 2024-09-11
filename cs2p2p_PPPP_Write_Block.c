
uint64_t cs2p2p_PPPP_Write_Block(int32_t arg1, char arg2, int64_t arg3, int32_t arg4)

{
    uint64_t x25 = arg2;
    void* x28 = ((cs2p2p_gSession + (arg1 * 0x4d38)) + (x25 << 1));  {  // {"PKciP11sockaddr_inc"}}
    uint32_t x27 = *(x28 + 0x598);
    int32_t bytes_1 = arg4;
    uint32_t* s = malloc(0x28);
    
    if (s == 0)
        bytes_1 = -1;
    else
    {
        uint64_t bytes = bytes_1;
        __builtin_memset(s, 0, 0x28);
        int64_t x0_1 = malloc(bytes);
        *(s + 8) = x0_1;
        
        if (x0_1 == 0)
        {
            free(s);
            bytes_1 = -1;
        }
        else
        {
            int64_t bytes_2 = bytes_1;
            int64_t x2;
            
            if (bytes > bytes_2)
                x2 = (bytes - bytes_2);
            else
                x2 = 0;
            
            *s = x27;
            s[1] = bytes_1;
            memset((x0_1 + bytes_2), 0, x2);
            memcpy(x0_1, arg3, bytes_2);
            cs2p2p_sll_Put((((cs2p2p_gSession + (arg1 * "PKciP11sockaddr_inc")) + (x25 << 5)) + 0x198), s);
            *(x28 + 0x598) += 1;
        }
    }
    
    return bytes_1;
}

