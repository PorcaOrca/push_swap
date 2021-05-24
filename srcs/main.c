/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:29:09 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/24 12:22:18 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_val(void *val)
{
	printf("\n%d", *(int *)val);
}

int		*ft_arr_init(char **args, int len)
{
	int		i;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * (len - 1));
	if (!arr)
		return (NULL);
	i = 1;
	if (len > 2)
	{
		while (i < len)
		{
			arr[i - 1] = ft_atoi(args[i]);
			i++;
		}
	}
	return (arr);
}

t_list	*ft_lst_init(int *arr, int len)
{
	int		i;
	t_list	*stack;
	t_list	*temp;

	i = 0;
	len--;
	stack = NULL;
	while (i < (len))
	{
		temp = ft_lstnew(&arr[i]);
		if (!temp)
		{
			while (stack)
			{
				temp = stack->next;
				free(stack);
				stack = temp;
			}
			return (NULL);
		}
		ft_lstadd_back(&stack, temp);
		i++;
	}
	return (stack);
}

int		main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*temp;
	int		*arr;
	int		step_count;

	step_count = 0;
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
		return (-1);
	arr = ft_arr_init(argv, argc);
	*stack_a = ft_lst_init(arr, argc);
	*stack_b = NULL;

	ft_long_seq(stack_a, stack_b, &step_count);

	printf("steps:%d\n", step_count);

	temp = *stack_a;
	printf("stack a:\n");
	while (temp)
	{
		printf("%d\n", *(int *)(temp->content));
		temp = temp->next;
	}

	temp = *stack_b;
	printf("stack b:\n");
	while (temp)
	{
		printf("%d\n", *(int *)(temp->content));
		temp = temp->next;
	}

	free(stack_a);
	free(stack_b);

	return (0);
}
