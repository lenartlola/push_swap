# libft.h
## A collections of standard C library functions with some additional ones.

The aim of this project is to re-create some standard C library functions including some additional ones the functions created in Libft will become the basic building blocks of later projects that we are going to create in the later of the program.
Using C standard library at 42 is strictly forbidden, the only functions we're allowed to use are "write(), malloc(), free()", we as well have access to "size_t, and NULL" to create our own functions.
Every type of errors "Segmentation fault, buss error, memory overflow, memory overlapping, etc" should be handled carefully.

## Build

Clone this repository.
```sh
git clone https://github.com/0x1nf3ct3d/libft
```

cd into the libft directory.

```sh
cd libft
```

Make

```sh
make
```

delete all the *.o files.
```sh
make clean
```

Delete all the *.0 files plus libft.a
```sh
make fclean
```

Remake everything.
```sh
make re
```

## Manual
| functions | description |
| ------ | ------ |
| ft_atoi | converts ASCII string to integer. |
| ft_bzero | Writes zeroes to byte string. |
| ft_calloc | Contiguously allocates size bytes of memory and returns a pointer to the allocated memory. |
| ft_isalpha | Checks if a character is whether alphabetic or not. |
| ft_isdigit | checks if a character is a digit or not. |
| ft_isalnum | Checks if a character isalpha or isdigit or non-alnum. |
| ft_isascii | Cheks whether a character is ascii or not. |
| ft_isprint | Checks if a character is printable or not. |
| ft_itoa | Recives an integer and converts it to a string with allocating enough space for it. |
| ft_memchr | Scans memory for string. |
| ft_memcmp | Compares two memory areas of string. |
| ft_memcpy | Copies an area of memory to another. |
| ft_memmove | Moves an area of memory to another. |
| ft_memset | Writes n area of memory with a byte value. |
| ft_putchar_fd | Writes a character to a file descriptor. |
| ft_putendl_fd | Writes a string to a file descriptor, followed by a new line. |
| ft_putnbr_fd | Writes a number to a file descriptor. |
| ft_putstr_fd | Writes a string to a file descriptor. |
| ft_split | Split a string using a given character as a second parameter. |
| ft_strchr | Locates character in string. |
| ft_strdup | Duplicates a string. |
| ft_striteri | Applies a function to eacg character of a string. |
| ft_strjoin | Concatinates two string. |
| ft_strlcat | Concatinates two string to a bounded size. |
| ft_strlcpy | Copies a string to anothere to a bounded size. |
| ft_strlen | Returns length of a given string. |
| ft_strmapi | Applies a function to each character of a given string. |
| ft_strncmp | Compares two string to n character. |
| ft_strnstr | Locates a substring in a string. |
| ft_strrchr | Locates character in string. |
| ft_strtrim | Trims the beginning and the end of a string if they match the given chars. |
| ft_substr | Returns a substring in a given string from a given index to a given length. |
| ft_tolower | Convert char to lowercase. |
| ft_toupper | Convert char to uppercase. |

## Functions without standard manual

- ft_substr : 

        char *ft_substr(char const *s, unsigned int start,size_t len);

        1.  The string from which to create the substring.
        2.  The start index of the substring in the string’s’.
        3.  The maximum length of the substring.

- ft_strjoin : 

        char *ft_strjoin(char const *s1, char const *s2);

        1.  The prefix string.
        2.  The suffix string.

- ft_strtrim : 

        char *ft_strtrim(char const *s1, char const *set);

        1.  The string to be trimmed.
        2.  The reference set of characters to trim.

- ft_split : 

        char **ft_split(char const *s, char c);

        1.  The string to be split.
        2.  The delimiter character.
       
- ft_itoa : 

        char *ft_itoa(int n);

- ft_strmapi : 

        char *ft_strmapi(char const *s, char (*f)(unsignedint, char));
        
        1.  The string on which to iterate.
        2.  The function to apply to each character.

- ft_striteri : 

        void ft_striteri(char *s, void (*f)(unsigned int,char*));
        
        1.  The string on which to iterate.
        2.  The function to apply to each character.

- ft_putchar_fd : 

        void ft_putchar_fd(char c, int fd);
        
        1.  The character to output.
        2.  The file descriptor on which to write.
        

- ft_putstr_fd : 

        void ft_putstr_fd(char *s, int fd);
        
        1.  The string to output.
        2.  The file descriptor on which to write.

- ft_putendl_fd : 

        void ft_putendl_fd(char *s, int fd);
        
        1.  The string to output.
        2.  The file descriptor on which to write.
        
- ft_putnbr_fd : 

        void ft_putnbr_fd(int n, int fd);
        
        1.  The integer to output.
        2.  The file descriptor on which to write.
        
### What is a file descriptor?
[RTFWikipedia](https://en.wikipedia.org/wiki/File_descriptor)

### Useful resources

Here are some good resources I used in order to achieve my project:

- [Makefile](https://makefiletutorial.com/) - An awsome introduction into Makefile.
- [Build your own library](https://www.cs.dartmouth.edu/~campbell/cs50/buildlib.html)
- [How to code](https://stackoverflow.com/)

### Testing functions
In the time of writing this first version of the manual I have not built my own tester even though it should be a part of the project, but anyway I came out with some good developed tester for the purpose and I personally used two of them, feel free to on internet to find other testers.
- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [libftTester](https://github.com/Tripouille/libftTester)

## License

42Lausanne

**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

