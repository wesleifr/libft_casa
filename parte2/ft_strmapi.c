char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
char *res;
unsigned int i;


res = (char *)malloc(ft_strlen(s) + 1);
if (!res)
return (0);
i = 0;
while (s[i])
{
res[i] = f(i, s[i]);
i++;
}
res[i] = '
␀
';
return (res);
}