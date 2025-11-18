#include "libft.h"

char *ft_strnstr(const char *hay, const char *ned, size_t len)
{
size_t i;
size_t j;


if (!*ned)
return ((char *)hay);
i = 0;
while (hay[i] && i < len)
{
j = 0;
while (hay[i + j] && ned[j] && i + j < len
&& hay[i + j] == ned[j])
j++;
if (!ned[j])
return ((char *)&hay[i]);
i++;
}
return (0);
}