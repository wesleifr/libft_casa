char *ft_substr(char const *s, unsigned int start, size_t len)
{
char *sub;
size_t i;
size_t slen;


slen = ft_strlen(s);
if (start >= slen)
return (ft_strdup(""));
if (len > slen - start)
len = slen - start;
sub = (char *)malloc(len + 1);
if (!sub)
return (0);
i = 0;
while (i < len)
{
sub[i] = s[start + i];
i++;
}
sub[i] = '
␀
';
return (sub);
}