*This project has been created as part of the 42 curriculum by fstadler.*

Description
- `get_next_line` reads and returns the next line read from a file descriptor. This repository contains a mandatory implementation and a bonus variant that supports multiple file descriptors.

Project structure
- [get_next_line.c](get_next_line.c) / [get_next_line_bonus.c](get_next_line_bonus.c): core implementation(s)
- [get_next_line.h](get_next_line.h) / [get_next_line_bonus.h](get_next_line_bonus.h): public headers
- [get_next_line_utils.c](get_next_line_utils.c) / [get_next_line_utils_bonus.c](get_next_line_utils_bonus.c): helper functions


Instructions
Build
- Compile with `gcc -Wall -Wextra -Werror`.

Example builds
- Compile mandatory implementation:
```
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
```
- Compile bonus implementation (multiple fds):
```
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

Usage
- Run the produced binary with a filepath argument or via stdin:
```
./gnl test.txt
./gnl < test.txt
```

API / Behavior
- Prototype: `char *get_next_line(int fd);`
- Returns a `malloc`-allocated string containing the next line including the terminating `\n` when present.
- Returns `NULL` on EOF or error.
- The caller is responsible for freeing the returned buffer to avoid leaks.
- The implementation handles arbitrarily long lines. The bonus variant supports reading simultaneously from multiple file descriptors.

Testing & Validation
- Use `valgrind` to check for leaks and invalid memory access:
```
valgrind --leak-check=full --show-leak-kinds=all ./gnl test.txt
```

Notes
- Ensure any returned strings are freed by the caller.
- If your implementation uses a `BUFFER_SIZE` macro, test with several sizes.


Resources
- Reference video: https://www.youtube.com/watch?v=8E9siq7apUU

AI usage:
- AI was used for creating README.md and for testing purposes
