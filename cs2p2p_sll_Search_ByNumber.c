
void* cs2p2p_sll_Search_ByNumber(int64_t* arg1, int32_t arg2)

{
    void* result = *arg1;
    
    if ((result != 0 && arg2 >= 1))
    {
        int32_t i = (arg2 + 1);
        
        do
        {
            result = *(result + 0x18);
            
            if (result == 0)
                break;
            
            i -= 1;
        } while (i >= 2);
    }
    
    return result;
}

