char **ft_split(char const *s, char c)
{
char **arr;
size_t i;
size_t j;
size_t idx;


arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
if (!arr)
return (0);
i = 0;
j = 0;
idx = 0;
while (s[i])
{
if (s[i] != c)
{
j = i;
while (s[j] && s[j] != c)
j++;
arr[idx] = word_dup(s, i, j);
if (!arr[idx])
return (0);
idx++;
i = j;
}
else
i++;
}
arr[idx] = 0;
return (arr);
}