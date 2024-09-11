
int64_t cs2p2p_DoSemPost(int32_t arg1, int32_t arg2)

{
    /* tailcall */
    return sem_post((((cs2p2p_gSession + (arg1 * 0x4d38)) + (arg2 << 4)) + 0x68));  {  // {"PKciP11sockaddr_inc"}}
}

