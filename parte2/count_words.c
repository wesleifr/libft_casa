static size_t count_words(const char *s, char c)
{
size_t cnt;
int in;


cnt = 0;
in = 0;
while (*s)
{
if (*s != c && !in)
{
in = 1;
cnt++;
}
else if (*s == c)
in = 0;
s++;
}
return (cnt);
}