
int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i = i + 1;
    return (i);
}

char *ft_strnncpy(char *dest, char *src, int n)
{
    int i;

    i = n;
    while(src[i])
    {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *remove_star(char *s1)
{
    int i;

    i = 0;
    while(s1[i])
    {
        if (s1[i] == '*' && s1[i + 1] == '*')
        {
            ft_strnncpy(s1, s1 + 1, i);
        }
        else
            i = i + 1;
    }
    return (s1);
}

void     ft_match2(char *s1, char *s2, int *i, int *j)
{
    if (s2[*j] == '*' && s1[*i] != s2[*j + 1])
            *i = *i + 1;
    if (s2[*j + 1] == s1[*i])
        {
            *i = *i + 1;
            *j = *j + 2;
        }
    if (s1[*i] == s2[*j])
        {
            *i = *i + 1;
            *j = *j + 1;
        }
}

int     ft_match(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    remove_star(s2);
    while(s1[i] || s2[j])
    {
        ft_match2(s1, s2, &i, &j);
        if (i >= ft_strlen(s1) && j >= ft_strlen(s2))
            return (1);
        if  ((s1[i] != s2[j] && s2[j] != '*'))
            return (0);
        if (s1[ft_strlen(s1) - 1] != s2[ft_strlen(s2) - 1] && s2[ft_strlen(s2) - 1] != '*')
            return (0);
    }
    return (1);
}
