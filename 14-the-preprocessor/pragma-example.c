#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

int main(void)
{
	IDENT(foo);
	// expands to PRAGMA(ident "foo")
	// then expands to _Pragma("ident \"foo\"")
}
