
char* trim(char* arg1)

{
    char* result = arg1;
    
    while (true)
    {
        uint32_t x8_1 = *result;
        
        if ((x8_1 != 0x20 && x8_1 != 9))
        {
            size_t x0_1 = strlen(result);
            
            if (x0_1 >= 1)
            {
                x0_1 = x0_1;
                
                do
                {
                    uint64_t x10_2 = result[(x0_1 - 1)];
                    
                    if (x10_2 > 0x20)
                        break;
                    
                    if (((1 << x10_2) & 0x100002600) == 0)
                        break;
                    
                    x0_1 -= 1;
                } while ((x0_1 + 1) > 1);
            }
            
            result[x0_1] = 0;
            return result;
        }
        
        result = &result[1];
    }
}

