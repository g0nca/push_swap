/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:51:53 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/05 13:24:53 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_count_total_numbers(int ac, char **av)
{
	int		i;
	int		j;
	int		total_count;
	char	**temp;

	i = 1;
	total_count = 0;
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
		{
			total_count++;
			j++;
		}
		ft_free(temp);
		i++;
	}
	return (total_count);
}

char	**ft_store_numbers(int ac, char **av, int total_count)
{
	char	**args;
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	args = malloc((total_count + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		j = 0;
		while (temp[j])
			args[k++] = temp[j++];
		free(temp);
		i++;
	}
	args[k] = NULL;
	return (args);
}

int	ft_has_duplicate(char **args, int total_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < total_count - 1)
	{
		j = i + 1;
		while (j < total_count)
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
