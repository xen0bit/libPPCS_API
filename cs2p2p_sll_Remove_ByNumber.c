
void* cs2p2p_sll_Remove_ByNumber(int64_t* arg1, int32_t arg2)

{
    void* result = *arg1;
    
    if (result != 0)
    {
        if (arg2 >= 1)
        {
            int32_t i = (arg2 + 1);
            
            do
            {
                result = *(result + 0x18);
                
                if (result == 0)
                    return result;
                
                i -= 1;
            } while (i >= 2);
        }
        
        void* x9_1 = *(result + 0x20);
        int64_t* x9_2;
        
        if (x9_1 == 0)
            x9_2 = arg1;
        else
            x9_2 = (x9_1 + 0x18);
        
        *x9_2 = *(result + 0x18);
        void* x9_3 = *(result + 0x18);
        void* x9_4;
        
        if (x9_3 == 0)
            x9_4 = &arg1[1];
        else
            x9_4 = (x9_3 + 0x20);
        
        *x9_4 = *(result + 0x20);
        *(result + 0x18) = 0;
        *(result + 0x20) = 0;
        arg1[2] -= 1;
        *(arg1 + 0x14) -= *(result + 4);
    }
    
    return result;
}

