/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:29:09 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/14 14:13:49 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_val(void *val)
{
	printf("\n%d", (int)val);
}

int		main(int argc, char *argv[])
{
	int		i;
	t_list	**stack_a;
	t_list	*temp;
	int		*arr;

	stack_a = (t_list **)malloc(sizeof(t_list *));
	i = 1;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (argc > 2)
	{
		while (i < argc)
		{
			arr[i - 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	i = 0;
	*stack_a = ft_lstnew(&arr[i]);
	i++;
	while (i < (argc - 1))
	{
		ft_lstadd_back(stack_a, ft_lstnew((&arr[i])));
		i++;
	}
	temp = *stack_a;
	ft_swap_a(stack_a);
	while (temp)
	{
		printf("\n%d", *(int *)(temp->content));
		temp = temp->next;
	}
	return (0);
}
