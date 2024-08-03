/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:47:24 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/16 16:18:20 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_stacks(t_stack **a, t_stack **b, int total_nums)
{
	if (is_sorted(*a))
	{
		free_stack(a);
		exit(0);
	}
	if (total_nums == 2)
		s_stack(a, 'a', true);
	else if (total_nums == 3)
		sort_three(a);
	else if (total_nums == 4)
		sort_four(a, b);
	else if (total_nums == 5)
		sort_five(a, b);
	else if (total_nums > 5)
		reverse_sort(a, b);
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
	check_stacks(&a, &b, total_nums);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
