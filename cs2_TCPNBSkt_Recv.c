
int64_t cs2_TCPNBSkt_Recv(int32_t arg1, int64_t arg2, int32_t arg3)

{
    int32_t result = recv(arg1, arg2, arg3, 0);
    
    if (result > 0)
        return result;
    
    if (result == 0)
        return -1;
    
    if (*__errno() == 0xb)
        return 0;
    
    return -2;
}

