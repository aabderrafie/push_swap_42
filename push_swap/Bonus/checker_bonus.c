/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:35:36 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/13 11:48:54 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	handle_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	error();
}

void	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		s_stack(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		s_stack(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		sab_stack(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		p_stack(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		p_stack(b, a);
	else if (!ft_strncmp(line, "rra\n", 4))
		rr_stack(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rr_stack(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrab_stack(a, b);
	else if (!ft_strncmp(line, "ra\n", 3))
		r_stack(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		r_stack(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rab_stack(a, b);
	else
		handle_error(a, b);
}

void	get_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_instruction(line, a, b);
		free(line);
	}
}
