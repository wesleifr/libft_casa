char *ft_strrchr(const char *s, int c)
{
const char *last;


last = 0;
while (*s)
{
if (*s == (char)c)
last = s;
s++;
}
if (c == '
␀
')
return ((char *)s);
return ((char *)last);
}