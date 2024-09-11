
void __stack_chk_fail() __noreturn

{
    /* tailcall */
    return __stack_chk_fail();
}

