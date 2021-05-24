/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:36:29 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/24 16:59:31 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef struct		s_lis_arr
{
	int					*seq;
	int					len;
	int					end_val;
	struct s_lis_arr	*next;
}					t_lis_arr;


int			ft_swap(t_list **stack, int *step_count);
int			ft_rotate_down(t_list **stack, int *step_count);
int			ft_rotate_up(t_list **stack, int *step_count);
int			ft_push(t_list **stack_a, t_list **stack_b, int *step_count);
int			ft_long_seq(t_list **stack_a, t_list **stack_b, int *step_count);
t_lis_arr	*ft_lis(int *arr, int n);
