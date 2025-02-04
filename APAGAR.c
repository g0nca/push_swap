int     ft_is_double(int ac, char **av)
{
    int i;
    int j;
    char **args;
    long num;

    i = 1;
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        j = 0;
        while (args[i][j])
        {
            num = ft_atol(&args[i][j]);
            printf("NUM:%ld\n", num);
            printf("ARGS[j]:%c\n", args[i][j + 1]);
            if(ft_compare(num, &args[j + 1]) == 1 || ft_compare(num, &av[i + 1]) == 1)
            {
                ft_free(args);
                return (1);
            }
            j++;
        }
        ft_free(args);
        i++;     
    }
    return (0);
}