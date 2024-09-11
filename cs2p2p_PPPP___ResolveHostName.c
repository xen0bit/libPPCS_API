
int64_t cs2p2p_PPPP___ResolveHostName(char* arg1, void* arg2)

{
    if (cs2p2p_GetInetAddrByName(arg1, (arg2 + 4)) == 0)
        return 0;
    
    return 0xfffffff9;
}

