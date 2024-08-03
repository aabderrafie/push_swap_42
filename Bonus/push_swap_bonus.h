/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:51:05 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/13 12:29:11 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "getnextlien/get_next_line.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack				*ft_stacknew(int value);
int					ft_isnumber(const char *str);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				s_stack(t_stack **stack);
void				sab_stack(t_stack **a, t_stack **b);
void				p_stack(t_stack **to, t_stack **from);
void				r_stack(t_stack **stack);
void				rab_stack(t_stack **a, t_stack **b);
void				rr_stack(t_stack **stack);
void				rrab_stack(t_stack **a, t_stack **b);
void				reverse_sort(t_stack **a, t_stack **b);
int					is_sorted(t_stack *a);
void				get_instructions(t_stack **a, t_stack **b);
void				error(void);
void				free_stack(t_stack **stack);
void				free_args(char **args);

#endif