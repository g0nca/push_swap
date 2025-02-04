/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:21:41 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/04 16:44:23 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checks(int ac, char **av)
{
    if (ac < 2 || (ac == 2 && !av[1][0]))
        return (1);
    if (ft_check_is_number(ac, av) == 1)
        return (1);
    if (ft_ints(ac, av) == 1)
        return (1);
    if (ft_is_double(ac, av) == 1)
        return (1);
    return (0);
}

int     ft_check_is_number(int ac, char **av)
{
    int i;
    int j;

    j = 1;
    i = 0;
    while (j < ac)
    {
        i = 0;
        while (av[j][i])
        {
            if (av[j][i] >= '0' && av[j][i] <= '9' && av[j][i] != ' ')
                i++;
            else if ((av[j][i] == '-' || av[j][i] == '+') && (av[j][i - 1] >= '0' && av[j][i - 1] <= '9'))
                return (1);
            else if ((av[j][i] == '-' || av[j][i] == '+') && (av[j][i + 1] >= '0' && av[j][i + 1] <= '9'))
                i++;
            else if (av[j][i] == ' ')
                i++;
            else
                return (1);
        }
        j++;
    }
    return (0);
}


int     ft_ints(int ac, char **av)
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
        while (args[j])
        {
            num = ft_atol(args[j]);
            if (num < INT_MIN || num > INT_MAX)
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
int ft_is_double(int ac, char **av)
{
    int     i; 
    int     j; 
    int     k; 
    int     total_count;
    char    **args;
    char    **temp;

    i = 1;
    total_count = 0;

    // Passo 1: Contar quantos números existem no total
    while (i < ac)
    {
        temp = ft_split(av[i], ' ');
        j = 0;
        while (temp[j])
        {
            total_count++;  // Conta o total de números
            j++;
        }
        ft_free(temp);  // Libera memória temporária
        i++;
    }

    // Passo 2: Alocar memória para armazenar todos os números
    args = malloc((total_count + 1) * sizeof(char *));
    if (!args)
        return (1);  // Retorna erro se a alocação falhar

    // Passo 3: Preencher args com os números
    i = 1;
    k = 0;
    while (i < ac)
    {
        temp = ft_split(av[i], ' ');
        j = 0;
        while (temp[j])
        {
            args[k] = temp[j];  // Copia o ponteiro para args
            k++;
            j++;
        }
        free(temp);  // Libera a estrutura de ponteiros, mas mantém as strings
        i++;
    }
    args[k] = NULL;  // Finaliza o array com NULL

    // Passo 4: Verificar duplicatas
    i = 0;
    while (i < total_count - 1)
    {
        j = i + 1;
        while (j < total_count)
        {
            if (ft_atol(args[i]) == ft_atol(args[j]))
            {
                ft_free(args);  // Libera args
                return (1);  // Retorna erro por número duplicado
            }
            j++;
        }
        i++;
    }
    ft_free(args);  // Libera args no final
    return (0);  // Retorna 0 se não houver duplicatas
}
/*int     ft_is_double(int ac, char **av)
{
    int i;
    int j;
    char **args;
    long num;

    i = 0;
    while (av[i])
    {
        args = ft_split(av[i], ' ');
        i++;
    }
    i = 0;
    while (args[i])
    {
        printf("%s\n", args[i]);
        i++;
    }
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        j = 0;
        while (args[j])
        {
            num = ft_atol(args[j]);
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
}*/
int     ft_compare(int n, char **args)
{
    int i;
    
    i = 0;
    while(args[i])
    {
        if (n == ft_atol(args[i]))
            return (1);
        i++;
    }
    return(0);
}
