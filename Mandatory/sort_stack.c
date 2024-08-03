/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:19:02 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/12 17:11:02 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_item_position(t_stack *stack, int index)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	if (stack == NULL)
		return (0);
	while (tmp)
	{
		if (tmp->index != index)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (i);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	index_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *a;
	while (current)
	{
		current->index = 0;
		tmp = *a;
		while (tmp)
		{
			if (current->value > tmp->value)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		min;
	int		size;
	double	max;

	size = stack_size(*a);
	max = 0.05 * size + 10.0;
	min = 0;
	while (*a)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			p_stack(b, a, 'b');
			max++;
			min++;
		}
		else if ((*a)->index < min)
		{
			p_stack(b, a, 'b');
			r_stack(b, 'b', true);
			max++;
			min++;
		}
		else
			r_stack(a, 'a', true);
	}
}

void	reverse_sort(t_stack **a, t_stack **b)
{
	int	len;
	int	max;

	index_stack(a);
	sort_stack(a, b);
	while (*b)
	{
		len = stack_size(*b);
		max = find_max(*b);
		if ((*b)->index == max)
		{
			p_stack(a, b, 'a');
		}
		else if (get_item_position(*b, max) < len / 2)
			r_stack(b, 'b', true);
		else
			rr_stack(b, 'b', true);
	}
}
