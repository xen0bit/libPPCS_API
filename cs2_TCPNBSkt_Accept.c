
int64_t cs2_TCPNBSkt_Accept(int32_t arg1, union __SOCKADDR_ARG arg2)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x19 + 0x28);
    int32_t len = 0x18;
    int64_t result = accept(arg1, arg2, &len);
    
    if (*(x19 + 0x28) == x8)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

