/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:36:29 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/22 10:44:53 by lspazzin         ###   ########.fr       */
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

int		ft_push(t_list **stack);
int		ft_rotate_down(t_list **stack);
int		ft_rotate_up(t_list **stack);
int		ft_move(t_list **stack_a, t_list **stack_b);
