# 42-gnl-libft-ft_printf

## Overview

This project is a collection of three essential components often required in 42 School projects: `get_next_line` (gnl), `libft`, and `ft_printf`. Each of these components serves a specific purpose and can be used individually or together in larger projects.

### Components

1. **get_next_line (gnl):**
   - `get_next_line` is a function designed to read a line from a file descriptor. It is particularly useful when dealing with input streams that may not fit into fixed-size buffers.

2. **libft:**
   - `libft` is a custom C library that provides a set of common functions for string manipulation, memory management, linked lists, and more. This library is meant to be a replacement for the standard C library functions, with a focus on efficiency and 42 School guidelines.

3. **ft_printf:**
   - `ft_printf` is a custom implementation of the printf function. It allows formatted output to be displayed on the console, offering a wide range of formatting options similar to the standard printf in C.

## Usage

### get_next_line (gnl)

To use `get_next_line` in your project, follow these steps:

```c
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    while (get_next_line(fd, &line)) {
        // Process each line as needed
        printf("%s\n", line);
        free(line);
    }
    close(fd);

    return 0;
}
```

### libft

To use libft in your project, simply include the header file and link against the library:

```c
#include "libft.h"

int main() {
    // Use libft functions here

    return 0;
}
```

### ft_printf
To use ft_printf, include the header file and use it as you would with the standard printf:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");

    return 0;
}
```

### Installation

To use these components in your project, simply copy the relevant files into your project directory and include the corresponding header files in your source code.
