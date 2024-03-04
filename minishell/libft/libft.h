/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimarque <dimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:51 by dimarque          #+#    #+#             */
/*   Updated: 2024/02/24 19:16:30 by dimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

// for ft_printf
# include <stdarg.h>

// for get_next_line
# include <fcntl.h> // O_RDONLY
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list
{
	int				n;
	int				equal;
	char			*ident;
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(const char *str);

/**
 * Set a block of memory to zero
 * 
 * @param s Pointer to the memory block to set
 * @param n Number of bytes to set to zero
 */
void			ft_bzero(void *s, size_t n);

/**
 * Allocate and zero-initialize memory
 * 
 * @param nitems Number of elements to allocate
 * @param size Size of each element in bytes
 * @return A pointer to the allocated memory block, or NULL if allocation fails
 * @note The allocated memory is set to zero using ft_memset
 * @warning If memory allocation fails, it returns NULL
 */
void			*ft_calloc(size_t nitems, size_t size);
int				ft_isalnum(int arg);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int arg);
int				ft_isspace(char c);

/**
 * Locate character in block of memory
 * 
 * @param str Pointer to the memory block to search
 * @param c The character to search for (as an integer)
 * @param n Number of bytes to search
 * @return A pointer to the first occurrence of the character c in the memory
 * block str, or NULL the character is not found within the first n bytes
 */
void			*ft_memchr(const void *str, int c, size_t n);

/**
 * Compare two memory blocks
 * 
 * @param s1 Pointer to the first memory block
 * @param s2 Pointer to the second memory block
 * @param n Number of bytes to compare
 * @return An integer less than, equal to, or greater than zero if the first n
 * bytes of s1 are found to be less than, equal to, or greater than the first n
 * bytes of s2, respectively
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Copy memory area
 * 
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy
 * @return A pointer to the destination memory area (dest)
 * @note If both dest and src are NULL, returns NULL
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copy memory area, allowing overlapping memory blocks
 * 
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy
 * @return A pointer to the destination memory area (dest)
 * @note If both dest and src are NULL, returns NULL
 * @warning This function ensures that the copying takes place safely even if
 * the memory blocks overlap
 */
void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Fill a block of memory with a specified value
 * 
 * @param b Pointer to the memory block to fill
 * @param c The value to be set (as an unsigned char)
 * @param len Number of bytes to be set to the value
 * @return A pointer to the memory block
 */
void			*ft_memset(void *b, int c, size_t len);

/**
 * Locate the first occurrence of a character in a string
 * 
 * @param str The string to search within
 * @param c The character to search for (as an integer)
 * @return A pointer to the first occurrence of the character 'c' in the string
 * 'str', or NULL if the character is not found
 */
char			*ft_strchr(const char *s, int c);

/**
 * Duplicate a string
 * 
 * @param str The string to duplicate
 * @return A pointer to the duplicated string
 * @note Allocates memory dynamically, caller is responsible for freeing it
 * @warning If memory allocation fails, it returns NULL
 */
char			*ft_strdup(const char *str);

/**
 * Concatenate two strings safely, ensuring the destination buffer is not
 * overflowed
 * 
 * @param dst The destination string where the result will be stored
 * @param src The source string to concatenate to the destination
 * @param size The size of the destination buffer
 * @return The total length of the concatenated string, truncated to fit within
 * the buffer size
 * @note The function ensures that the resulting string is null-terminated and
 * does not overflow the destination buffer
 */
size_t			ft_strlcat(char *dst, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * Copy a string into a destination buffer with size limit
 * 
 * @param dest The destination buffer where the string will be copied
 * @param src The source string to copy
 * @param size The size of the destination buffer
 * @return The length of the source string (excluding the null terminator)
 * @note The function copies at most 'size - 1' characters from 'src' into 'dest'
 * and ensures null-termination
 */
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Locate the last occurrence of a character in a string
 * 
 * @param s The string to search within
 * @param c The character to search for (as an integer)
 * @return A pointer to the last occurrence of the character 'c' in the string
 * 's', or NULL if the character is not found
 */
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int ch);
int				ft_toupper(int ch);

// parte 2

/**
 * Extract a substring from a string
 * 
 * @param s The string from which to extract the substring
 * @param start The index of the starting character of the substring in s
 * @param len The maximum length of the substring to extract
 * @return A newly allocated substring, or NULL if allocation fails or start is
 * greater than or equal to the length of s
 * @note The substring is extracted starting from the character at index 'start'
 * up to 'len' characters or until the end of the string, whichever comes first
 * @warning The returned substring must be freed by the caller to avoid memory
 * leaks
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * Trim leading and trailing characters from a string that match the characters
 * in a specified set
 * 
 * @param s1 The string to trim
 * @param set The set of characters to trim from the string
 * @return A newly allocated string with leading and trailing characters removed,
 * or NULL if allocation fails
 * @note The characters to be trimmed are specified in the string 'set'
 * @warning The returned string must be freed by the caller to avoid memory leaks
 */
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);

/**
 * Split a string into an array of substrings based on a delimiter character
 * 
 * @param str The string to split
 * @param c The delimiter character used to split the string
 * @return A newly allocated array of strings, each representing a substring, or
 * NULL if allocation fails
 * @note The substrings are obtained by splitting the input string 'str' wherever
 * the delimiter character 'c' occurs
 * @warning The returned array of strings, as well as the strings themselves,
 * must be freed by the caller to avoid memory leaks
 */
char			**ft_split(char const *str, char c);
char			*ft_itoa(int n);

/**
 * Apply a function to each character of a string to create a new string
 * 
 * @param str The input string
 * @param f The function to apply to each character of the string
 * @return A newly allocated string resulting from applying the function 'f' to
 * each character of 'str', or NULL if allocation fails
 * @note The function 'f' is applied to each character of 'str' along with its
 * index in the string
 * @warning The returned string must be freed by the caller to avoid memory leaks
 */
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));

/**
 * Apply a function to each character of a string along with its index
 * 
 * @param str The string to iterate over
 * @param f The function to apply to each character along with its index
 * @note The function 'f' is applied to each character of 'str' along with its
 * index in the string
 */
void			ft_striteri(char *str, void (*f)(unsigned int, char *));

// bonus
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
	void (*del)(void *));

// ft_printf
int				ft_base(long long nbr, char *type);
int				ft_options(va_list ap, const char type);
int				ft_print_ptr(unsigned long long nbr, char *type);
int				ft_printchar(int c);
int				ft_printf(const char *s, ...);
int				ft_printnbr(int nbr);
int				ft_printstr(char *str);

// get next line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char			*get_next_line(int fd);
size_t			ft_strlen_gnl(const char *str);
char			*ctrl_l(char *buffer);

// Other
int				ft_strcmp(char *s1, char *s2);
//char			*rm_quots(char *str);
//char			*if_quot_marks(char *cmd_line);

#endif