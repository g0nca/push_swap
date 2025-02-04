#include "libft.h"

long    ft_atol(const char *str)
{
    long    result;
    int     sign;
    int     i;
    int     j;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] == '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    j = i;
    while (str[j] >= '0' && str[j] <= '9')
    {
        result = result * 10 + str[j] - '0';
        j++;
    }

    return (result * sign);
}