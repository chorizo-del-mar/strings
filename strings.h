#include <stdlib.h>

#define DEFAULT_CAPACITY 128

typedef struct {
	size_t len;
	size_t capacity;
}Header;

void strings_init(char** s);
void append(char* s, char value);
size_t length(char* s); 
void free_strings(char* s);

#ifdef STRINGS_IMPLEMENTATION

void strings_init(char** s) {
	Header* h = (Header*)malloc(sizeof(char)*DEFAULT_CAPACITY + sizeof(Header));
	if (h == NULL) {
		fprintf(stderr, "append failed to allocate new header");
		exit(EXIT_FAILURE);
	}
	h->len = 0;
	h->capacity = DEFAULT_CAPACITY;

	*s = (char*)(h + 1);

}

void append(char* s, char value) {
	Header* h;

	if (s == NULL) {
		return;
	}

	h = (Header*)s - 1;

	if (h->len == h->capacity) {
		h = (Header*)realloc(h, sizeof(char)*(h->capacity*2) + sizeof(Header));
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
void free_strings(char* s) {
	if (s == NULL) {
		return;
	}

	Header* h = (Header*)s - 1;

	free(h);
}
#endif
