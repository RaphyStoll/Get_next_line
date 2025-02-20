<a name="english-version"></a>

# GetNextLine Project

<a href="[#french-version](https://github.com/RaphyStoll/Get_next_line/README.md)" style="text-decoration:none;">
  <button style="border:none; cursor:pointer;">
    🇫🇷 Français
  </button>
</a>
&nbsp;&nbsp;
<a href="[#english-version](https://github.com/RaphyStoll/Get_next_line/README.eng.md)" style="text-decoration:none;">
  <button style="background-color:#e0f7fa; border:none; cursor:pointer;">
    🇬🇧 English
  </button>
</a>

## Overview

The `GetNextLine` project aims to develop a function that reads a line from a file descriptor. This
project introduces the concept of static variables in C programming and provides a practical
function for reading lines from files or standard input.

## Table of Contents

- [GetNextLine Project](#getnextline-project)
	- [Overview](#overview)
	- [Table of Contents](#table-of-contents)
	- [Objectives](#objectives)
	- [Rules](#rules)
	- [Mandatory Part](#mandatory-part)
		- [Function: `get_next_line`](#function-get_next_line)
		- [Requirements:](#requirements)
		- [Restrictions:](#restrictions)
	- [Bonus Part](#bonus-part)
		- [Bonus Files:](#bonus-files)
	- [Directory Structure](#directory-structure)
	- [Compilation](#compilation)
	- [Testing](#testing)

## Objectives

- Develop a function to read lines from a file descriptor.
- Explore the use of static variables in C.
- Ensure compliance with coding standards and proper memory management.

## Rules

- The project must be written in C.
- Code must adhere to the Norme standards.
- Functions should not terminate unexpectedly (e.g., segmentation fault).
- All dynamically allocated memory must be properly freed.

## Mandatory Part

### Function: `get_next_line`

- **Prototype:** `char *get_next_line(int fd);`
- **Files:** `get_next_line.h`, `get_next_line.c`, `get_next_line_utils.c`
- **Parameters:** `fd` - file descriptor to read from.
- **Return Value:** The content of the read line or `NULL` if there's nothing more to read or an
  error occurs.
- **Allowed External Functions:** `read`, `malloc`, `free`

### Requirements:

- Successive calls to `get_next_line()` should read the entire text file line by line.
- The function should return the line just read, including the newline character (`\n`), unless the
  end of the file is reached without a newline.
- The function should work correctly for both files and standard input.
- The project must compile with the `-D BUFFER_SIZE=n` option, allowing the buffer size to be
  specified.

### Restrictions:

- The `libft` library is not allowed.
- The `lseek()` function is prohibited.
- Global variables are not permitted.

## Bonus Part

- Implement `get_next_line()` using a single static variable.
- Extend `get_next_line()` to handle multiple file descriptors simultaneously.

### Bonus Files:

- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

## Directory Structure

```plaintext
header/
  get_next_line.h
  get_next_line_bonus.h
objects/
  bonus/
	get_next_line_bonus.o
	get_next_line_utils_bonus.o
	main_bonus.o
  main/
	get_next_line.o
	get_next_line_utils.o
	main.o
source/
  bonus/
	get_next_line_bonus.c
	get_next_line_utils_bonus.c
	main_bonus.c
  main/
	get_next_line.c
	get_next_line_utils.c
	main.c
test/
  txt/
	empty.txt
	file_with_null_bytes.txt
	infinite_line.txt
	lines_with_only_spaces.txt
	long_line.txt
	long_line_with_newline.txt
	mixed_line_lengths.txt
	multiple_consecutive_newlines.txt
	multiple_lines.txt
	no_newline_at_end.txt
	non_printable_characters.txt
	one_line_no_newline.txt
	one_line_with_newline.txt
	only_newlines.txt
	text.txt
	unicode_characters.txt
output/
  gnl
  gnl_bonus
```

## Compilation

To compile the project, use the provided Makefile:

```sh
make
```

To clean the build files, use:

```sh
make clean
```

## Testing

- The `test/txt` directory contains various test files to validate the functionality of
  `get_next_line()`.
