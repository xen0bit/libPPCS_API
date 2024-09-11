
int64_t cs2p2p_PPPP_GetAPIInformation()

{
    memset(cs2p2p_g_P2P_APIInfo, 0, 0x140);
    int32_t x20 = 0;
    int32_t x21 = 0;
    int32_t x22 = 0;
    int64_t i_1 = 0x100;
    int64_t (* x9)() = (cs2p2p_gSession + 0x54);
    int64_t i;
    
    do
    {
        if ((*(x9 - 0x54) & 0x80000000) == 0)
        {
            uint32_t x11_2 = *x9;
            
            if (x11_2 == 1)
                x22 += 1;
            
            if (x11_2 == 0)
            {
                if (*(x9 - 4) == 0)
                    x21 += 1;
                else
                    x20 += 1;
            }
        }
        
        i = i_1;
        i_1 -= 1;
        x9 += "PKciP11sockaddr_inc";
    } while (i != 1);
    int32_t x0_2 = snprintf(cs2p2p_g_P2P_APIInfo, 0x13f, "{\n"LibType":"c++"");
    int64_t x24 = x0_2;
    int64_t x24_1 = (x24 + snprintf((cs2p2p_g_P2P_APIInfo + x24), (0x13f - x0_2), ",\n"LicenseReq":""));
    int32_t x24_2 = (x24_1 + snprintf((cs2p2p_g_P2P_APIInfo + x24_1), (0x13f - x24_1), "Standard""));
    int32_t x24_3 = (x24_2 + snprintf((cs2p2p_g_P2P_APIInfo + x24_2), (0x13f - x24_2), ",\n"Version":"%d.%d.%d.%d"", 4, 1, 3, 0));
    int32_t x24_4 = (x24_3 + snprintf((cs2p2p_g_P2P_APIInfo + x24_3), (0x13f - x24_3), ",\n"BuiltDate":"%s %s"", "Nov 17 2020", "14:51:15"));
    int32_t x24_5 = (x24_4 + snprintf((cs2p2p_g_P2P_APIInfo + x24_4), (0x13f - x24_4), ",\n"MaxNumSess":%d", 0x100));
    int32_t x24_6 = (x24_5 + snprintf((cs2p2p_g_P2P_APIInfo + x24_5), (0x13f - x24_5), ",\n"MaxNumCh":%d", 8));
    int32_t x24_7 = (x24_6 + snprintf((cs2p2p_g_P2P_APIInfo + x24_6), (0x13f - x24_6), ",\n"P2PPunchRange":%d", 3));
    void* const x3;
    
    if (*cs2p2p_gFlagInitialized == 1)
        x3 = &data_24083;
    else
        x3 = &data_24087;
    
    int32_t x24_8 = (snprintf((cs2p2p_g_P2P_APIInfo + x24_7), (0x13f - x24_7), ",\n"Initialized":"%s"", x3) + x24_7);
    
    if (*cs2p2p_gFlagInitialized != 0)
    {
        int32_t x22_1 = (snprintf((cs2p2p_g_P2P_APIInfo + x24_8), (0x13f - x24_8), ",\n"NumSess":%d", x22) + x24_8);
        int32_t x21_1 = (x22_1 + snprintf((cs2p2p_g_P2P_APIInfo + x22_1), (0x13f - x22_1), ",\n"NumRunningConnect":%d", x21));
        x24_8 = (x21_1 + snprintf((cs2p2p_g_P2P_APIInfo + x21_1), (0x13f - x21_1), ",\n"NumRunningListen":%d", x20));
        
        if (x20 != 0)
        {
            time_t x0_25 = time(nullptr);
            uint64_t x8_12 = *cs2p2p_gLastSuccessLoginTime;
            
            if (*cs2p2p_gLastSuccessLoginTimeTCP > x8_12)
            {
                x0_25 = time(nullptr);
                x8_12 = *cs2p2p_gLastSuccessLoginTimeTCP;
            }
            
            x24_8 += snprintf((cs2p2p_g_P2P_APIInfo + x24_8), (0x13f - x24_8), ",\n"LastLoginAck":%d", (x0_25 - x8_12));
        }
    }
    
    snprintf((cs2p2p_g_P2P_APIInfo + x24_8), (0x13f - x24_8), &data_240de);
    return cs2p2p_g_P2P_APIInfo;
}

