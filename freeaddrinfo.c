
void freeaddrinfo(struct addrinfo* ai)

{
    /* tailcall */
    return freeaddrinfo(ai);
}

