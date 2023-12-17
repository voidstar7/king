#include <stdio.h>

#define STRINGIZE(x) #x
#define EXPAND_AND_STRINGIZE(x) STRINGIZE(x)

#define LINE_FILE "Line " EXPAND_AND_STRINGIZE(__LINE__) " of " __FILE__

int main(void)
{
    const char *str = LINE_FILE;
    puts(str);
    return 0;
}

