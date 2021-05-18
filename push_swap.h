/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:31:39 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/18 14:28:06 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef struct 		s_seq
{
	int	*seq_start;
	int	seq_len;
	int	seq_pos;
}					t_seq;

int		ft_swap(t_list **stack);
int		ft_rotate_down(t_list **stack);
int		ft_rotate_up(t_list **stack);
int		ft_move(t_list **stack_a, t_list **stack_b);