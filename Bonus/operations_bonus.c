/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:36:25 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/13 11:50:13 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	s_stack(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
}

void	sab_stack(t_stack **a, t_stack **b)
{
	s_stack(a);
	s_stack(b);
}

void	p_stack(t_stack **to, t_stack **from)
{
	t_stack	*tmp;

	if (*from)
	{
		tmp = *from;
		*from = (*from)->next;
		tmp->next = *to;
		*to = tmp;
	}
}

void	r_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
}

void	rab_stack(t_stack **a, t_stack **b)
{
	r_stack(a);
	r_stack(b);
}
