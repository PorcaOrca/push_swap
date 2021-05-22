/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:38:15 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/22 10:44:33 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_long_seq(t_list **stack_a, t_list **stack_b)
{
	t_list *temp;

	temp = *stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			ft_push();
	}
}
