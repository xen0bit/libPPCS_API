
void cs2p2p_PPPP_thread_recv_LanSearch(int32_t arg1) __noreturn

{
    int32_t fd = cs2p2p_setup_listen_port(0x7d6c);
    
    if ((fd & 0x80000000) == 0)
    {
        if (*((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52) == 0)  {  // {"PKciP11sockaddr_inc"}}
        {
            int32_t* x25_1 = (cs2p2p_gSession + (arg1 * "PKciP11sockaddr_inc"));
            void var_570;
            void var_70;
            void var_58;
            uint8_t var_54;
            uint32_t i;
            
            do
            {
                if (cs2p2p_PPPP_Proto_Recv_ALL(cs2p2p_gP2PKeyString, fd, &var_70, 0x32, &var_54, &var_58, &var_570, 0x500) != 0)
                    i = *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52);  {  // {"PKciP11sockaddr_inc"}}
                else
                {
                    i = *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52);  {  // {"PKciP11sockaddr_inc"}}
                    
                    if ((i == 0 && var_54 == 0x30))
                    {
                        cs2p2p_PPPP_Proto_Send_PunchPkt(&x25_1[0x3a], *x25_1, &var_70, (x25_1 + 0x17b), x25_1[0x63], (x25_1 + 0x183));
                        i = *((cs2p2p_gSession + (arg1 * 0x4d38)) + 0x52);  {  // {"PKciP11sockaddr_inc"}}
                    }
                }
            } while (i == 0);
        }
        
        close(fd);
    }
    
    pthread_exit(nullptr);
    /* no return */
}

