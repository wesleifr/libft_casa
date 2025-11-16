size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
size_t dlen;
size_t i;


dlen = ft_strlen(dst);
if (dstsize <= dlen)
return (dstsize + ft_strlen(src));
i = 0;
while (src[i] && dlen + i + 1 < dstsize)
{
dst[dlen + i] = src[i];
i++;
}
dst[dlen + i] = '
␀
';
return (dlen + ft_strlen(src));
}