
int64_t cs2p2p_PPPP_DRWAck_Send(char* arg1, int32_t arg2, sockaddr_in* arg3, char arg4, void* arg5, int32_t arg6)

{
    int0_t tpidr_el0;
    uint64_t x19 = _ReadStatusReg(tpidr_el0);
    int64_t x10 = *(x19 + 0x28);
    uint32_t x10_1 = ((arg6 & 0xffff) << 1);
    uint16_t var_526 = (_byteswap((x10_1 + 4)) >> 0x10);
    uint16_t x11_5 = (_byteswap(arg6) >> 0x10);
    int16_t var_528 = 0xd1f1;
    char var_524 = 0xd1;
    uint16_t var_522 = x11_5;
    char var_523 = arg4;
    
    if ((arg5 != 0 && (arg6 & 0xffff) != 0))
    {
        uint64_t x11_6 = (arg6 & 0xffff);
        int64_t i_4;
        
        if (x11_6 >= 4)
        {
            i_4 = (x11_6 & 0xfffc);
            void* x13_1 = (arg5 + 4);
            void var_51c;
            void* x14_1 = &var_51c;
            int64_t i_3 = i_4;
            int64_t i;
            
            do
            {
                int128_t v0;
                v0 = *(x13_1 - 4);
                int128_t v1;
                v1 = *x13_1;
                *v0[4] = *(x13_1 - 2);
                *v1[4] = *(x13_1 + 2);
                v0 = (vrev32_s8(v0) >> 0x10);
                *v0[4] u>>= 0x10;
                v1 = (vrev32_s8(v1) >> 0x10);
                *v1[4] u>>= 0x10;
                *(x14_1 - 4) = v0;
                *x14_1 = v1;
                *(x14_1 - 2) = *v0[4];
                x13_1 += 8;
                i = i_3;
                i_3 -= 4;
                *(x14_1 + 2) = *v1[4];
                x14_1 += 8;
            } while (i != 4);
            
            if (i_4 != x11_6)
                goto label_e3d0;
        }
        else
        {
            i_4 = 0;
        label_e3d0:
            int64_t x14_2 = (i_4 << 1);
            int16_t* x13_2 = (arg5 + x14_2);
            void* x14_4 = ((&var_528 + x14_2) + 8);
            int64_t i_2 = (x11_6 - i_4);
            int64_t i_1;
            
            do
            {
                uint32_t x12_1 = *x13_2;
                x13_2 = &x13_2[1];
                i_1 = i_2;
                i_2 -= 1;
                *x14_4 = (_byteswap(x12_1) >> 0x10);
                x14_4 += 2;
            } while (i_1 != 1);
        }
    }
    
    int64_t result = cs2p2p_SendMessage(arg1, &var_528, (x10_1 + 8), arg2, arg3);
    
    if (*(x19 + 0x28) == x10)
        return result;
    
    __stack_chk_fail();
    /* no return */
}

