// driver code

#include <stdio.h>

#define STRINGS_IMPLEMENTATION
#include "strings.h"

int main(int argc, char* argv[]) {
	char* s = NULL;

	strings_init(&s);

	append(s, 'n');
	append(s, 'i');
	append(s, 'c');
	append(s, 'e');

	for (int i = 0; i < (int)length(s); i++)
		putc(s[i], stdout);

	putchar('\n');

	free_strings(s);

	return 0;
}
