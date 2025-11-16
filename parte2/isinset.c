static int isinset(char c, const char *set)
{
size_t k;


k = 0;
while (set[k])
{
if (c == set[k])
return (1);
k++;
}
return (0);
}