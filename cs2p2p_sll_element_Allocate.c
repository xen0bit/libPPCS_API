
int32_t* cs2p2p_sll_element_Allocate(int32_t arg1, int32_t arg2)

{
    int32_t* s = malloc(0x28);
    
    if (s != 0)
    {
        uint64_t bytes = arg2;
        __builtin_memset(s, 0, 0x28);
        int64_t x0_2 = malloc(bytes);
        *(s + 8) = x0_2;
        
        if (x0_2 == 0)
        {
            free(s);
            return nullptr;
        }
        
        memset(x0_2, 0, bytes);
        *s = arg1;
        s[1] = arg2;
    }
    
    return s;
}

