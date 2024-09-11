
int64_t cs2p2p_CRCDec(uint8_t* arg1, int32_t arg2, uint8_t* arg3, int32_t arg4)

{
    /* tailcall */
    return cs2p2p_PPPP_CRCDec(arg1, arg2, arg3, arg4, *cs2p2p_gCRCKey);
}

