/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:47:27 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/22 10:44:43 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_swap(t_list **stack)
{
	t_list	*temp;

	if (ft_lstsize(*stack) > 1)
	{
		temp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		temp->next = *stack;
		*stack = temp;
		return(0);
	}
	return (-1);
}

int		ft_rotate_down(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *stack;
		*stack = temp->next;
		temp->next = NULL;
		return (0);
	}
	return (-1);
}

int		ft_rotate_up(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		*stack = temp->next;
		last = ft_lstlast(*stack);
		last->next = temp;
		temp->next = NULL;
		return (0);
	}
	return (-1);
}

int		ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) > 0)
	{
		if (ft_lstsize(*stack_b) == 0)
		{
			temp = *stack_a;
			*stack_a = (*stack_a)->next;
			*stack_b = temp;
			(*stack_b)->next = NULL;
			return (1);
		}
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, temp);
		return (0);
	}
	return (-1);
}
