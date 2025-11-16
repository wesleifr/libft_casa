;
size_t j;


res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
if (!res)
return (0);
i = 0;
while (s1[i])
{
res[i] = s1[i];
i++;
}
j = 0;
while (s2[j])
{
res[i + j] = s2[j];
j++;
}
res[i + j] = '
␀
';
return (res);
}