
void cs2p2p_sll_element_Free(void* arg1)

{
    if (arg1 == 0)
        return;
    
    int64_t x0 = *(arg1 + 8);
    
    if (x0 != 0)
        free(x0);
    
    /* tailcall */
    return free(arg1);
}

