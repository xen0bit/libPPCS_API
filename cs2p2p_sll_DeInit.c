
void cs2p2p_sll_DeInit(int64_t* arg1)

{
    void* i_1 = *arg1;
    
    if (i_1 != 0)
    {
        void* i;
        
        do
        {
            i = *(i_1 + 0x18);
            arg1[2] -= 1;
            *(arg1 + 0x14) -= *(i_1 + 4);
            int64_t x0 = *(i_1 + 8);
            
            if (x0 != 0)
                free(x0);
            
            free(i_1);
            i_1 = i;
            *arg1 = i;
        } while (i != 0);
    }
}

