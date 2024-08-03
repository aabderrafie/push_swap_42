/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:47:24 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/16 16:18:30 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_duplicate(int num, t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	process_nums(char **nums, t_stack **a, int *total_nums)
{
	int	j;

	j = 0;
	while (nums[j])
	{
		if (!ft_isnumber(nums[j]) || is_duplicate(ft_atoi(nums[j], NULL), *a))
		{
			free_args(nums);
			free_stack(a);
			error();
		}
		ft_stackadd_back(a, ft_stacknew(ft_atoi(nums[j], NULL)));
		j++;
	}
	*total_nums += j;
}

void	process_arguments(int argc, char **argv, t_stack **a, int *total_nums)
{
	int		i;
	char	**nums;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums || !*nums)
		{
			free_args(nums);
			free_stack(a);
			error();
		}
		process_nums(nums, a, total_nums);
		free_args(nums);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total_nums;

	a = NULL;
	b = NULL;
	total_nums = 0;
	if (argc < 2)
		exit(0);
	process_arguments(argc, argv, &a, &total_nums);
	get_instructions(&a, &b);
	if (is_sorted(a) && b == NULL)
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
