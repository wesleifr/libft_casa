#include "libft.h"
#include <stdlib.h>

static size_t count_words(const char *s, char c)
{
    size_t count = 0;
    size_t i = 0;

    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    return count;
}

static char *word_dup(const char *s, size_t start, size_t end)
{
    char *word;
    size_t i = 0;

    word = (char *)malloc(end - start + 1);
    if (!word)
        return NULL;
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return word;
}

char **ft_split(char const *s, char c)
{
    char **arr;
    size_t i, j, idx;

    if (!s)
        return NULL;
    arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!arr)
        return NULL;
    i = 0;
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
                return NULL;
            idx++;
            i = j;
        }
        else
            i++;
    }
    arr[idx] = NULL;
    return arr;
}