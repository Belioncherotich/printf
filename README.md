This is a group task on 0x11.c printf:
function that produces output according to a format.
Handle the following conversion specifiers: d, i
Handle the following custom conversion specifiers:b-the unsigned int argument is converted to binary
Handle the following conversion specifiers:u, o, x, X
Use a local buffer of 1024 chars in order to call write as little as possible.
Handle the following custom conversion specifier: S : prints the string. Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
Handle the following conversion specifier: p.
Handle the following flag characters for non-custom conversion specifiers:+ space #
Handle the following length modifiers for non-custom conversion specifiers:l, h. Conversion specifiers to handle: d, i, u, o, x, X
Handle the field width for non-custom conversion specifiers.
Handle the precision for non-custom conversion specifiers.
Handle the 0 flag character for non-custom conversion specifiers.
Handle the - flag character for non-custom conversion specifiers.
Handle the following custom conversion specifier: r : prints the reversed string
Handle the following custom conversion specifier: R: prints the rot13'ed string
Putting all options to work together.
