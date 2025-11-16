void *ft_calloc(size_t count, size_t size)
{
unsigned char *p;
size_t total;
size_t i;


total = count * size;
p = (unsigned char *)malloc(total);
if (!p)
return (0);
i = 0;
while (i < total)
{
p[i] = 0;
i++;
}
return ((void *)p);
}