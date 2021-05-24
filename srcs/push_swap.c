/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:38:15 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/24 12:32:22 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list		*ft_min(t_list **stack_a)
{
	t_list	*temp;
	t_list	*min_value;
	int		a;
	int		b;

	temp = *stack_a;
	a = *(int *)(temp->content);
	while (temp->next)
	{
		b = *(int *)(temp->next->content);
		if (b < a)
		{
			a = b;
			min_value = temp->next;
		}
		temp = temp->next;
	}
	return (min_value);
}

int		ft_long_seq(t_list **stack_a, t_list **stack_b, int *step_count)
{
	t_list		*temp;
	t_list		*seq_start;
	int			i;

	i = 0;
	temp = *stack_a;
	seq_start = ft_min(stack_a);
	while (*(int *)(temp->content) != *(int *)(seq_start->content))
	{
		i++;
		temp = temp->next;
	}
	temp = *stack_a;
	if (i > (ft_lstsize(*stack_a) / 2.0))
	{
		while (*(int *)((*stack_a)->content) != *(int *)(seq_start->content))
			ft_rotate_down(stack_a, step_count);
	}
	else
	{
		while (*(int *)((*stack_a)->content) != *(int *)(seq_start->content))
			ft_rotate_up(stack_a, step_count);
	}
	temp = *stack_b;

/*	temp = *stack_a;
	while (lst_size)
	{
		longest.seq_start = temp;
		longest.seq_len = 1;
		a = *(int *)(temp->content);
		b = *(int *)(temp->next->content);
		while (temp)
		{
			if (b > a)
			{
				longest.seq_len++;
				a = b
			}
		}
		lst_size--;
	}
*/	return (0);
}
