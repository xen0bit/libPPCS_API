
char const* inet_ntop(int32_t af, void const* src, char* dst, socklen_t size)

{
    /* tailcall */
    return inet_ntop(af, src, dst, size);
}

