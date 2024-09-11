
int64_t cs2p2p_sll_Dump(int64_t* arg1, int32_t arg2)

{
    int64_t result = printf("Total num = %d, Total Size=%d, M…", arg1[2], *(arg1 + 0x14), arg1[3]);
    
    if (arg2 == 2)
    {
        int32_t* i = *arg1;
        
        if (i != 0)
        {
            int32_t x19_1 = 0;
            
            do
            {
                if (x19_1 <= 0xc7)
                    result = printf("%d: Idx=%06d, DataBuf=0x%08lX, S…", x19_1, *i, *(i + 8), i[1]);
                
                i = *(i + 0x18);
                x19_1 += 1;
            } while (i != 0);
        }
    }
    else if (arg2 == 1)
    {
        int32_t* x8_1 = *arg1;
        printf("Head: Idx=%06d, DataBuf=0x%08lX,…", *x8_1, *(x8_1 + 8), x8_1[1]);
        int32_t* x8_2 = arg1[1];
        /* tailcall */
        return printf("Tail: Idx=%06d, DataBuf=0x%08lX,…", *x8_2, *(x8_2 + 8), x8_2[1]);
    }
    
    return result;
}

