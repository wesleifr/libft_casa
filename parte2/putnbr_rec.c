static void putnbr_rec(long n, int fd)
{
char c;


if (n >= 10)
putnbr_rec(n / 10, fd);
c = (n % 10) + '0';
write(fd, &c, 1);
}