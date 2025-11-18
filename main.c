#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/* Funções auxiliares para ft_striteri e ft_strmapi */
void add_index(unsigned int i, char *c)
{
    *c += i;
}

char map_plus_one(unsigned int i, char c)
{
    (void)i; // ignora o índice
    return c + 1;
}

int main(void)
{
    /* --- PARTE 1 --- */
    printf("=== PARTE 1 ===\n");

    printf("ft_isalpha('a') = %d\n", ft_isalpha('a'));
    printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
    printf("ft_isalnum('1') = %d\n", ft_isalnum('1'));
    printf("ft_isascii(127) = %d\n", ft_isascii(127));
    printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
    printf("ft_strlen(\"Hello\") = %zu\n", ft_strlen("Hello"));

    char buffer[50];
    ft_bzero(buffer, 50);
    printf("ft_bzero -> buffer[0] = %d\n", buffer[0]);

    char src[] = "ABCDE";
    char dst[10];
    ft_memcpy(dst, src, 5);
    dst[5] = '\0';
    printf("ft_memcpy -> dst = %s\n", dst);

    ft_memset(dst, 'X', 5);
    dst[5] = '\0';
    printf("ft_memset -> dst = %s\n", dst);

    char s1[] = "Hello";
    char s2[] = "World";
    ft_strlcpy(dst, s1, 10);
    printf("ft_strlcpy -> dst = %s\n", dst);
    ft_strlcat(dst, s2, 10);
    printf("ft_strlcat -> dst = %s\n", dst);

    printf("ft_toupper('a') = %c\n", ft_toupper('a'));
    printf("ft_tolower('A') = %c\n", ft_tolower('A'));

    printf("ft_strchr(\"Hello\", 'e') = %s\n", ft_strchr("Hello", 'e'));
    printf("ft_strrchr(\"Hello\", 'l') = %s\n", ft_strrchr("Hello", 'l'));

    printf("ft_strncmp(\"abc\", \"abd\", 2) = %d\n", ft_strncmp("abc", "abd", 2));

    int arr1[3] = {1, 2, 3};
    int arr2[3] = {1, 2, 4};
    printf("ft_memcmp(arr1, arr2, sizeof(arr1)) = %d\n", ft_memcmp(arr1, arr2, sizeof(arr1)));

    char haystack[] = "Hello world";
    char needle[] = "world";
    printf("ft_strnstr -> %s\n", ft_strnstr(haystack, needle, ft_strlen(haystack)));

    printf("ft_atoi(\"42\") = %d\n", ft_atoi("42"));

    int *p = (int *)ft_calloc(3, sizeof(int));
    printf("ft_calloc -> p[0] = %d\n", p[0]);
    free(p);

    char *dup = ft_strdup("Hello");
    printf("ft_strdup = %s\n", dup);
    free(dup);

    /* --- PARTE 2 --- */
    printf("\n=== PARTE 2 ===\n");

    char *substr = ft_substr("Hello World", 6, 5);
    printf("ft_substr = %s\n", substr);
    free(substr);

    char *joined = ft_strjoin("Hello", "World");
    printf("ft_strjoin = %s\n", joined);
    free(joined);

    char *trimmed = ft_strtrim("   Hello   ", " ");
    printf("ft_strtrim = '%s'\n", trimmed);
    free(trimmed);

    char **split = ft_split("split this string", ' ');
    for (int i = 0; split[i]; i++)
    {
        printf("ft_split[%d] = %s\n", i, split[i]);
        free(split[i]);
    }
    free(split);

    char *itoa_res = ft_itoa(12345);
    printf("ft_itoa = %s\n", itoa_res);
    free(itoa_res);

    char str_iter[] = "ABCDE";
    ft_striteri(str_iter, add_index);
    printf("ft_striteri = %s\n", str_iter);

    char *str_map = ft_strmapi("abc", map_plus_one);
    printf("ft_strmapi = %s\n", str_map);
    free(str_map);

    ft_putchar_fd('X', 1);
    write(1, "\n", 1);
    ft_putstr_fd("Hello FD\n", 1);
    ft_putendl_fd("Hello FD endline", 1);
    ft_putnbr_fd(-12345, 1);
    write(1, "\n", 1);

    return 0;
}
