
char* myrindex(char* arg1, int32_t arg2)

{
    char* result_1 = arg1;
    char* result = nullptr;
    char* result_2 = result_1;
    uint32_t i;
    
    do
    {
        i = *result_2;
        result_2 = &result_2[1];
        
        if (i == arg2)
            result = result_1;
        
        result_1 = result_2;
    } while (i != 0);
    return result;
}

