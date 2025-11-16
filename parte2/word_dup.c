static char *word_dup(const char *s, size_t start, size_t end)
{
char *word;
size_t i;


word = (char *)malloc(end - start + 1);
if (!word)
return (0);
i = 0;
while (start < end)
{
word[i++] = s[start++];
}
word[i] = '
␀
';
return (word);
}