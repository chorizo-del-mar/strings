**Strings Library Documentation**
=====================================

**Overview**
------------

This library provides a simple way to add meta-data to strings. It uses a fixed-size array to store the string data and an additional header structure to keep track of 
the length and capacity.

**Header File (`strings.h`)**
-----------------------------

### Macros

* `STRINGS_IMPLEMENTATION`: Defines a macro that includes the implementation of the library.
* `DEFAULT_CAPACITY`: The default capacity of the string array, set to 128.

### Functions

#### `strings_init(void)`

Initializes a new string with an empty header. Returns a pointer to the string data.

#### `append(char* s, char value)`

Appends a single character to the end of the string. If the string is full, it reallocates memory to double the capacity.

#### `length(char* s)`

Returns the number of characters in the string.

#### `strings_free(char* s)`

Frees the memory allocated for the string and its header.

**Implementation Details**
------------------------

The library uses a fixed-size array to store the string data, with an additional header structure that includes:

* `len`: The current length of the string.
* `capacity`: The remaining capacity of the string array.

When the string is appended, the library checks if it has reached its capacity. If so, it reallocates memory to double the capacity and updates the `capacity` field in 
the header.

**Example Usage**
----------------

To use this library, define the `STRINGS_IMPLEMENTATION` macro and include the `strings.h` file in your C code:
```c
#define STRINGS_IMPLEMENTATION
#include "strings.h"
```
Create a string using `strings_init()` and append characters to it using `append()`. Then, print the length of the string using `length()` and free the memory using 
`strings_free()`.
```c
int main(int argc, char* argv[]) {
    char* s = strings_init();
    append(s, 'n');
    append(s, 'i');
    append(s, 'c');
    append(s, 'e');

    for (int i = 0; i < (int)length(s); i++)
        putchar(s[i]);

    putchar('\n');

    strings_free(s);

    return 0;
}
```
**License**
------------

This library is released under the GNU General Public License version 2 or later. See the `LICENSE.txt` file for more information.

**Copyright Information**
-------------------------

* Copyright (C) 2026 chorizo-del-mar
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* See the `LICENSE.txt` file for more details.

