/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:26:15 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/13 11:48:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	rr_stack(t_stack **stack)
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
}

void	rrab_stack(t_stack **a, t_stack **b)
{
	rr_stack(a);
	r_stack(b);
}
