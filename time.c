
time_t time(time_t* timer)

{
    /* tailcall */
    return time(timer);
}

