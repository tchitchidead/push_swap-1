/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:58:23 by conoel            #+#    #+#             */
/*   Updated: 2019/02/10 11:55:40 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		solve_a(t_elem *root_a, t_elem *root_b, int max, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_a)->next);
	while (root_a->next != root_a && max--)
	{
		tmp = ft_get_max(root_a);
		index = ft_get_index(tmp);
		if (index > size / 2)
			while ((root_a)->previous != tmp)
				exec_ft("rra", root_a, root_b, delay);
		else
			while ((root_a)->previous != tmp)
				exec_ft("ra", root_a, root_b, delay);
		exec_ft("pa", root_a, root_b, delay);
		size--;
	}
}

static void		solve_b(t_elem *root_a, t_elem *root_b, int max, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_b)->next);
	while (root_b->next != root_b && max--)
	{
		tmp = ft_get_min(root_b);
		index = ft_get_index(tmp);
		if (index > size / 2)
			while ((root_b)->previous != tmp)
				exec_ft("rrb", root_a, root_b, delay);
		else
			while ((root_b)->previous != tmp)
				exec_ft("rb", root_a, root_b, delay);
		exec_ft("pb", root_a, root_b, delay);
		size--;
	}
}

/*mvoid		solve_list(t_elem *root_a, t_elem *root_b, int delay)
{
	int size;

	size = heap_size(root_a);
	while (root_a->next != root_a && !issort(root_a))
	{
		cut_a(root_a, root_b, get_median(root_a), delay);
		size /= 2;
		if (heap_size(root_a) <= MIN)
			while (root_a->next != root_a)
				exec_ft("pa", root_a, root_b, delay);
	}
	solve_b(root_a, root_b, size * 2, delay);
	size = heap_size(root_b);
	while (heap_size(root_b) > MIN * 2)
	{
		cut_b(root_a, root_b, get_median(root_b), delay);
		size /= 2;
	}
	solve_b(root_a, root_b, heap_size(root_b), delay);
	solve_a(root_a, root_b, size * 2, delay);
	while (root_a->next != root_a && !issort(root_a))
		cut_a(root_a, root_b, get_median(root_a), delay);
	solve_b(root_a, root_b, heap_size(root_b), delay);
}*/

void		solve_list(t_elem *root_a, t_elem *root_b, int delay)
{
	while (root_a->next != root_a && !issort(root_a))
	{
		cut_a(root_a, root_b, get_median(root_a), delay);
		if (heap_size(root_a) <= MIN)
			solve_a(root_a, root_b, heap_size(root_a), delay);
	}
	while (heap_size(root_b) >= MIN * 2)
	{
		solve_b(root_a, root_b, MIN * 3, delay);
		while (heap_size(root_b) > 0)
			cut_b(root_a, root_b, get_median(root_b), delay);
		while (!issort(root_a))
			exec_ft("pa", root_a, root_b, delay);
		exec_ft("pa", root_a, root_b, delay);
	}
	solve_b(root_a, root_b, heap_size(root_b), delay);
}

int			main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;
	int		delay;

	root_a = load_a(argc, argv);
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		write(2, "Allocation error :(", 21);
		ft_free(root_a, root_b);
		return (-1);
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (argc > 2 && argv[argc - 1][0] == 'c')
	{
		delay = ft_atoi(&(argv[argc - 1][1]));
	}
	else
		delay = -1;
	if (root_a == NULL)
		write(2, "THERE IS NO LIST NIGGA\n", 24);
	else
		small_sort(root_a, root_b, delay);
	ft_free(root_a, root_b);
}