/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soriting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:06:30 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/12 17:10:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	int		min;
	t_stack	*temp;

	min = a->value;
	temp = a->next;
	while (temp != NULL)
	{
		if (temp->value < min)
		{
			min = temp->value;
		}
		temp = temp->next;
	}
	return (min);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second > third && first < third)
	{
		s_stack(a, 'a', true);
		r_stack(a, 'a', true);
	}
	else if (first < second && second > third && first > third)
		rr_stack(a, 'a', true);
	else if (first > second && second < third && first < third)
		s_stack(a, 'a', true);
	else if (first > second && second < third && first > third)
		r_stack(a, 'a', true);
	else if (first > second && second > third && first > third)
	{
		r_stack(a, 'a', true);
		s_stack(a, 'a', true);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int		min;
	int		i;
	t_stack	*temp;

	i = 0;
	min = find_min(*a);
	temp = *a;
	while ((temp)->value != min)
	{
		i++;
		temp = temp->next;
	}
	if (i <= 1)
		while (i--)
			r_stack(a, 'a', true);
	else
		while (i++ < 4)
			rr_stack(a, 'a', true);
	p_stack(b, a, 'b');
	sort_three(a);
	p_stack(a, b, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		min;
	int		i;
	t_stack	*temp;

	i = 0;
	min = find_min(*a);
	temp = *a;
	while ((temp)->value != min)
	{
		i++;
		temp = temp->next;
	}
	if (i <= 2)
		while (i--)
			r_stack(a, 'a', true);
	else
		while (i++ < 5)
			rr_stack(a, 'a', true);
	p_stack(b, a, 'b');
	sort_four(a, b);
	p_stack(a, b, 'a');
}
