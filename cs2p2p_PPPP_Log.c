
void cs2p2p_PPPP_Log(FILE* arg1, char* arg2, int64_t arg3, int128_t arg4 @ v0, int128_t arg5 @ v1, int128_t arg6 @ v2, int128_t arg7 @ v3, int128_t arg8 @ v4, int128_t arg9 @ v5, int128_t arg10 @ v6, int128_t arg11 @ v7)

{
    int128_t var_2d0 = arg10;
    int128_t var_2c0 = arg11;
    int128_t var_2f0 = arg8;
    int128_t var_2e0 = arg9;
    int128_t var_310 = arg6;
    int128_t var_300 = arg7;
    int128_t var_330 = arg4;
    int128_t var_320 = arg5;
    int64_t x6;
    int64_t var_290 = x6;
    int64_t x7;
    int64_t var_288 = x7;
    int64_t x4;
    int64_t var_2a0 = x4;
    int64_t x5;
    int64_t var_298 = x5;
    int64_t var_2b0 = arg3;
    int64_t x3;
    int64_t var_2a8 = x3;
    int0_t tpidr_el0;
    uint64_t x22 = _ReadStatusReg(tpidr_el0);
    int64_t x8 = *(x22 + 0x28);
    
    if (*cs2p2p_PPPP_LOG_OFF == 0)
    {
        void var_12c;
        memcpy(&var_12c, "Loging - ", 0xd3);
        void var_22c;
        memset(&var_22c, 0, 0x100);
        void var_238;
        time(&var_238);
        struct tm* x0_4 = localtime(&var_238);
        sprintf(&var_22c, "%s/%02d%02d.log", arg1, x0_4->tm_mday, x0_4->tm_hour);
        arg1 = fopen(&var_22c, &data_23a69);
        
        if (arg1 != 0)
        {
            fprintf(arg1, "[%04d-%02d-%02d ", (x0_4->tm_year + 0x76c), (x0_4->tm_mon + 1), x0_4->tm_mday);
            int128_t v0;
            int128_t v1;
            v0 = fprintf(arg1, "%02d:%02d:%02d]", x0_4->tm_hour, x0_4->tm_min, x0_4->tm_sec);
            int32_t var_23c_1 = 0xffffff80;
            int32_t var_240_1 = 0xffffffd0;
            int128_t var_280;
            int128_t* var_250_1 = &var_280;
            var_280 = &arg_0;
            int128_t var_270_1 = &var_2b0;
            void string;
            vsprintf(&string, arg2);
            fprintf(arg1, "%s\n", &var_12c);
            fclose(arg1);
        }
    }
    
    if (*(x22 + 0x28) == x8)
        return;
    
    __stack_chk_fail();
    /* no return */
}

