/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:47:27 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/14 14:13:15 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_swap_a(t_list **stack_a)
{
	t_list	*temp;
	int		size;

	size = ft_lstsize(*stack_a);
	temp = (*stack_a)->next;
	if (size > 1)
	{
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		return(0);
	}
	return (-1);
}
