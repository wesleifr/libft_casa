void ft_putnbr_fd(int n, int fd)
{
long nb;


nb = n;
if (nb < 0)
{
write(fd, "-", 1);
nb = -nb;
}
putnbr_rec(nb, fd);
}