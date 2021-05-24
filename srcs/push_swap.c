/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:38:15 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/24 17:11:43 by lspazzin         ###   ########.fr       */
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
/**
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

	temp = *stack_a;
	seq_start = ft_lstnew(temp->content);
}
*/
t_lis_arr	*ft_lstlis_new(int *arr, int last, int lenght)
{
	t_lis_arr	*lis_lst;



	lis_lst = (t_lis_arr *)malloc(sizeof(t_lis_arr));
	lis_lst->next = NULL;
	lis_lst->seq = arr;
	lis_lst->len = lenght;

	lis_lst->end_val = last;
	return (lis_lst);
}

t_lis_arr	*ft_lis(int *arr, int n)
{
	t_lis_arr	*lis_lst;
	t_lis_arr	*temp;
	t_lis_arr	*prev;
	int			*lis_temp;
	int			i;
	int			j;
	int			max;
	int			min;
	int			max_len;
	int			max_inf;

	max = 0;
	min = 2147483647;
	lis_temp = (int *)malloc(sizeof(int));
	*lis_temp = arr[0];
	lis_lst = ft_lstlis_new(lis_temp, arr[0], 1);
	i = 1;
	while (i <= n)
	{
		temp = lis_lst;
		if (arr[i] < min)
		{
			while (temp->next)
				temp = temp->next;
			lis_temp = (int *)malloc(sizeof(int));
			*lis_temp = arr[i];
			temp->next = ft_lstlis_new(lis_temp, arr[i], 1);
			min = arr[i];
		}
		else if (arr[i] > max)
		{
			max_len = 0;
			temp = lis_lst;
			while (temp)
			{
				if (temp->len > max_len)
					max_len = temp->len;
				temp = temp->next;
			}
			temp = lis_lst;
			while (temp->len != max_len)
				temp = temp->next;
			lis_temp = (int *)malloc(sizeof(int) * (temp->len + 1));
			j = 0;
			while (j < (temp->len))
			{
				lis_temp[j] = temp->seq[j];
				j++;
			}
			while (temp->next)
				temp = temp->next;
			temp->next = ft_lstlis_new(lis_temp, arr[i], max_len + 1);
			max = arr[i];
		}
		else
		{
			max_inf = 0;
			temp = lis_lst;
			while (temp)
			{
				if (temp->end_val < arr[i] && temp->end_val > max_inf)
					max_inf = temp->end_val;
				temp = temp->next;;
			}

			temp = lis_lst;
			while (temp->end_val != max_inf)
				temp = temp->next;

			j = 0;
			lis_temp = (int *)malloc(sizeof(int) * (temp->len + 1));
			while (j < temp->len)
			{
				lis_temp[j] = temp->seq[j];
				j++;
			}

			free(temp->seq);
			lis_temp[j] = arr[i];
			temp->seq = lis_temp;
			temp->end_val = arr[i];
			temp->len++;
			max_inf = temp->len;
			temp = lis_lst;
			prev = NULL;
			while (temp)
			{
				if (!prev && temp->len == max_inf)
				{
					lis_lst = temp->next;
					free(temp->seq);
					free(temp);
					temp = lis_lst;
				}
				else if (temp->len == max_inf)
				{
					prev->next = temp->next;
					free(temp->seq);
					free(temp);
					temp = prev->next;
				}
				else
				{
					prev = temp;
					temp = temp->next;
				}
			}
		}
		i++;
	}
	return (lis_lst);
}
