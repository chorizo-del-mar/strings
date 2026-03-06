/*
    Copyright (C) 2026 chorizo-del-mar

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/*
 * This is a single-header-file library that adds meta-data to strings
 *
 * To use this library, do this in one C file:
 * 	#define STRINGS_IMPLEMENTATION
 * 	#include "strings.h"
 */

#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_CAPACITY 128

typedef struct {
	size_t len;
	size_t capacity;
}Header;

char* strings_init(void);
void append(char* s, char value);
size_t length(char* s); 
void strings_free(char* s);

#ifdef STRINGS_IMPLEMENTATION

char* strings_init(void) {
	Header* h = (Header*)malloc(sizeof(char)*DEFAULT_CAPACITY + sizeof(Header));
	if (h == NULL) {
		fprintf(stderr, "append failed to allocate new header");
		exit(EXIT_FAILURE);
	}
	h->len = 0;
	h->capacity = DEFAULT_CAPACITY;

	return (char*)(h + 1);

}

void append(char* s, char value) {
	Header* h;

	if (s == NULL) {
		return;
	}

	h = (Header*)s - 1;

	if (h->len == h->capacity) {
		h = (Header*)realloc(h, sizeof(char)*(h->capacity*h->len) + sizeof(Header));
		if (h == NULL) {
			fprintf(stderr, "append failed to reallocate memory");
			exit(EXIT_FAILURE);
		}
		s = (char*)(h + 1);
	}

	s[h->len++] = value;
}
size_t length(char* s) {
	if (s == NULL) {
		return 0;
	}

	Header* h = (Header*)s - 1;
	return h->len;
}
void strings_free(char* s) {
	if (s == NULL) {
		return;
	}

	Header* h = (Header*)s - 1;

	free(h);
}
#endif
