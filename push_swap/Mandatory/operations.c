/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:36:25 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/12 17:12:58 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_stack(t_stack **stack, char stack_name, bool print)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
	if (print)
		ft_printf("s%c\n", stack_name);
}

void	sab_stack(t_stack **a, t_stack **b)
{
	s_stack(a, 'a', false);
	s_stack(b, 'b', false);
	ft_printf("ss\n");
}

void	p_stack(t_stack **to, t_stack **from, char stack_name)
{
	t_stack	*tmp;

	if (*from)
	{
		tmp = *from;
		*from = (*from)->next;
		tmp->next = *to;
		*to = tmp;
	}
	ft_printf("p%c\n", stack_name);
}

void	r_stack(t_stack **stack, char stack_name, bool print)
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
	if (print)
		ft_printf("r%c\n", stack_name);
}

void	rab_stack(t_stack **a, t_stack **b)
{
	r_stack(a, 'a', false);
	r_stack(b, 'b', false);
	ft_printf("rr\n");
}
