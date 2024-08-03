/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:10:12 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/12 17:11:59 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *a)
{
	int		max;
	t_stack	*temp;

	index_stack(&a);
	max = a->index;
	temp = a;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

void	rr_stack(t_stack **stack, char stack_name, bool print)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (*stack && (*stack)->next)
	{
		prev = NULL;
		tmp = *stack;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *stack;
		*stack = tmp;
	}
	if (print)
		ft_printf("rr%c\n", stack_name);
}

void	rrab_stack(t_stack **a, t_stack **b)
{
	rr_stack(a, 'a', false);
	r_stack(b, 'b', false);
	ft_printf("rrr\n");
}
