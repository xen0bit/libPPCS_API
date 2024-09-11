
void* cs2p2p_sll_Remove_ByIndex(cs2p2p___the_SLL* arg1, uint32_t arg2)

{
    int64_t* x19 = arg1;
    void* result = cs2p2p_sll_Search_ByIndex(arg1, arg2, nullptr);
    
    if (result != 0)
    {
        void* x8_1 = *(result + 0x20);
        int64_t* x8_2;
        
        if (x8_1 == 0)
            x8_2 = x19;
        else
            x8_2 = (x8_1 + 0x18);
        
        *x8_2 = *(result + 0x18);
        void* x8_3 = *(result + 0x18);
        int64_t* x8_4;
        
        if (x8_3 == 0)
            x8_4 = &x19[1];
        else
            x8_4 = (x8_3 + 0x20);
        
        *x8_4 = *(result + 0x20);
        *(result + 0x18) = 0;
        *(result + 0x20) = 0;
        x19[2] -= 1;
        *(x19 + 0x14) -= *(result + 4);
    }
    
    return result;
}

