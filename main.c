#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char my_func(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void iter_func(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'A' && *c <= 'Z')
        *c += 32;
}

int main(void)
{
    // 1. Teste de funções is*
    printf("isalpha('a') = %d\n", ft_isalpha('a'));
    printf("isdigit('9') = %d\n", ft_isdigit('9'));
    printf("isalnum('9') = %d\n", ft_isalnum('9'));
    printf("isascii(128) = %d\n", ft_isascii(128));
    printf("isprint(' ') = %d\n", ft_isprint(' '));

    // 2. Teste de strlen
    char *str = "Hello 42!";
    printf("strlen(\"%s\") = %zu\n", str, ft_strlen(str));

    // 3. Teste de memset, bzero, memcpy, memmove
    char buf[20] = "1234567890";
    ft_memset(buf, 'A', 5);
    printf("memset: %s\n", buf);

    ft_bzero(buf + 5, 5);
    printf("bzero: %s\n", buf);

    char src[] = "ABCDEFG";
    char dst[10];
    ft_memcpy(dst, src, 7);
    dst[7] = '\0';
    printf("memcpy: %s\n", dst);

    char mv[] = "1234567";
    ft_memmove(mv + 2, mv, 5);
    mv[7] = '\0';
    printf("memmove: %s\n", mv);

    // 4. Teste strlcpy, strlcat
    char dest[20] = "Hello";
    size_t n = ft_strlcpy(dest, "42", 20);
    printf("strlcpy: %s (len=%zu)\n", dest, n);

    n = ft_strlcat(dest, "Libft", 20);
    printf("strlcat: %s (len=%zu)\n", dest, n);

    // 5. Teste toupper, tolower
    printf("toupper('a') = %c\n", ft_toupper('a'));
    printf("tolower('A') = %c\n", ft_tolower('A'));

    // 6. Teste strchr, strrchr, strncmp, memchr, memcmp, strnstr
    char *s = "Hello 42 World!";
    printf("strchr: %s\n", ft_strchr(s, '4'));
    printf("strrchr: %s\n", ft_strrchr(s, 'l'));
    printf("strncmp(\"Hello\", \"HellO\", 5) = %d\n", ft_strncmp("Hello", "HellO", 5));
    printf("memchr: %s\n", (char *)ft_memchr(s, 'W', ft_strlen(s)));
    printf("memcmp(\"abc\", \"abd\", 3) = %d\n", ft_memcmp("abc", "abd", 3));
    printf("strnstr(\"Hello 42 World\", \"42\", 15) = %s\n", ft_strnstr("Hello 42 World", "42", 15));

    // 7. Teste atoi, calloc, strdup
    printf("atoi(\"-42\") = %d\n", ft_atoi("-42"));
    char *dup = ft_strdup("Duplicate me");
    printf("strdup: %s\n", dup);
    free(dup);

    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("calloc[%d] = %d\n", i, arr[i]);
    free(arr);

    // 8. Teste substr, strjoin, strtrim, split, itoa, strmapi, striteri
    char *sub = ft_substr("Hello 42 World", 6, 2);
    printf("substr: %s\n", sub);
    free(sub);

    char *joined = ft_strjoin("Hello ", "42!");
    printf("strjoin: %s\n", joined);
    free(joined);

    char *trimmed = ft_strtrim("  \tHello 42  \n", " \n\t");
    printf("strtrim: '%s'\n", trimmed);
    free(trimmed);

    char **split = ft_split("42 is the answer", ' ');
    for (int i = 0; split[i]; i++)
    {
        printf("split[%d] = %s\n", i, split[i]);
        free(split[i]);
    }
    free(split);

    char *num = ft_itoa(-12345);
    printf("itoa: %s\n", num);
    free(num);

    char *map = ft_strmapi("abc", my_func);
    printf("strmapi: %s\n", map);
    free(map);

    char str_iter[] = "ABC";
    ft_striteri(str_iter, iter_func);
    printf("striteri: %s\n", str_iter);

    // 9. Teste write functions
    ft_putchar_fd('X', 1);
    ft_putstr_fd("Hello FD\n", 1);
    ft_putendl_fd("End of line", 1);
    ft_putnbr_fd(12345, 1);
    ft_putchar_fd('\n', 1);

    return 0;
}
