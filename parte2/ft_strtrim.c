char *ft_strtrim(char const *s1, char const *set)
{
size_t start;
size_t end;


start = 0;
while (s1[start] && isinset(s1[start], set))
start++;
end = ft_strlen(s1);
while (end > start && isinset(s1[end - 1], set))
end--;
return (ft_substr(s1, start, end - start));
}