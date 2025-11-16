char *ft_itoa(int n)
{
char *res;
long nb;
int len;


nb = n;
len = (n <= 0);
while (n)
{
len++;
n /= 10;
}
res = (char *)malloc(len + 1);
if (!res)
return (0);
res[len] = '
␀
';
if (nb == 0)
res[0] = '0';
if (nb < 0)
{
res[0] = '-';
nb = -nb;
}
while (nb)
{
res[--len] = (nb % 10) + '0';
nb /= 10;
}
return (res);
}