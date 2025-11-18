#include "libft.h"

static void putnbr_rec(long n, int fd)
{
    char c;

    if (n >= 10)
        putnbr_rec(n / 10, fd);
    c = (n % 10) + '0';
    write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
    long nb = n;

    if (nb < 0)
    {
        write(fd, "-", 1);
        nb = -nb;
    }
    putnbr_rec(nb, fd);
}
