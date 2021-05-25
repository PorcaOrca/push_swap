/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:38:15 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/25 13:36:31 by lodovico         ###   ########.fr       */
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

void		ft_lis_case3_del(t_lis_arr **lis_lst, int del_val, int n)
{
	t_lis_arr	*temp;
	t_lis_arr	*prev;

	temp = *lis_lst;
	prev = NULL;
	while (temp)
	{
		if (temp->len == del_val && temp->end_val != n)
		{
			if (prev)
				prev->next = temp->next;
			else
				*lis_lst = (*lis_lst)->next;
			free(temp->seq);
			free(temp);
			if (prev)
				temp = prev->next;
			else
				temp = *lis_lst;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
}

void		ft_lis_case3(t_lis_arr **lis_lst, int n)
{
	t_lis_arr	*temp;
	int			*temp_arr;
	int			max_inf;
	int			del_len;
	int			j;
	
	write(1, "case3: ", 7);
	write(1, "\n", 1);
	
	max_inf = 0;
	temp = *lis_lst;
/*
	while (temp)
	{
		j = 0;
		printf("Array:\n");
		while (j < temp->len)
		{
			printf("%d|", temp->seq[j]);
			j++;
		}
		printf("\n");
		temp = temp->next;
	}
*/

	
//  find array with the larger end value that is inferior to the number

	temp = *lis_lst;

	while (temp)
	{
		if (temp->end_val < n && temp->end_val > max_inf)
			max_inf = temp->end_val;
		temp = temp->next;
	}

	temp = *lis_lst;

	while (temp->end_val != max_inf)
		temp = temp->next;
	
	j = 0;
	temp_arr = (int *)malloc(sizeof(int) * (temp->len + 1));

	while (j < temp->len)
	{
		temp_arr[j] = temp->seq[j];
		j++;
	}

	del_len = temp->len + 1;
	temp_arr[j] = n;
	j = 0;
	while (temp->next)
		temp = temp->next;
			
	temp->next = ft_lstlis_new(temp_arr, n, del_len);
	ft_lis_case3_del(lis_lst, del_len, n);
/*		temp = *lis_lst;

	while (temp)
	{
		j = 0;
		printf("Array:\n");
		while (j < temp->len)
		{
			printf("%d|", temp->seq[j]);
			j++;
		}
		printf("\n");
		temp = temp->next;
	}
*/	
	write(1, "--done\n", 7);
}

void		ft_lis_case2(t_lis_arr **lis_lst, int *max, int n)
{
	t_lis_arr	*temp;
	int			*temp_arr;
	int			max_len;
	int			j;
	
	write(1, "case2: ", 7);
	write(1, "\n", 1);
	max_len = 0;
	temp = *lis_lst;
	while (temp)
	{
		if (temp->len > max_len)
			max_len = temp->len;
		temp = temp->next;
	}
	temp = *lis_lst;
	while (temp->len != max_len)
		temp = temp->next;
	temp_arr = (int *)malloc(sizeof(int) * (max_len + 1));
	j = 0;
	while (j < max_len)
	{
		temp_arr[j] = temp->seq[j];
		j++;
	}
	temp_arr[j] = n;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstlis_new(temp_arr, n, max_len + 1);
	*max = n;
	write(1, "--done\n", 7);
}

void		ft_lis_case1(t_lis_arr **lis_lst, int *min, int n)
{
	t_lis_arr	*temp;
	int			*lis_temp;

	write(1, "case1: ", 7);
	write(1, "\n", 1);
	temp = *lis_lst;
	while (temp->next)
		temp = temp->next;
	lis_temp = (int *)malloc(sizeof(int));
	*lis_temp = n;
	temp->next = ft_lstlis_new(lis_temp, n, 1);
	*min = n;
	write(1, "--done\n", 7);
}


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
	int			*lis_temp;
	int			i;
	int			max;
	int			min;

	max = arr[0];
	min = arr[0];
	lis_temp = (int *)malloc(sizeof(int));
	*lis_temp = arr[0];
	lis_lst = ft_lstlis_new(lis_temp, arr[0], 1);
	i = 1;
	while (i < n)
	{
		if (arr[i] < min)
			ft_lis_case1(&lis_lst, &min, arr[i]);

		else if (arr[i] > max)
			ft_lis_case2(&lis_lst, &max, arr[i]);

		else
			ft_lis_case3(&lis_lst, arr[i]);

		i++;
	}
	write(1, "end lis\n", 8);
	return (lis_lst);
}
