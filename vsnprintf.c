
int32_t vsnprintf(char* string, size_t maxlen, char const* format)

{
    /* tailcall */
    return vsnprintf(string, maxlen, format);
}

