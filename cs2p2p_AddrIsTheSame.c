
int64_t cs2p2p_AddrIsTheSame(void* arg1, void* arg2)

{
    if ((*(arg1 + 4) == *(arg2 + 4) && *(arg1 + 2) == *(arg2 + 2)))
        return 0;
    
    return 1;
}

