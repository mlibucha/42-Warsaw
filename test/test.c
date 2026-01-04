#include "push_swap.h"

void	sort_3(t_stack *a)// tylko zmiana nazw z x y z bo sie gubilem
{
	int	first = a->top->value;
	int	second = a->top->next->value;
	int	third = a->top->next->next->value;

	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_4_5(t_stack *a, t_stack *b)//leka zmiana co mi chat wyrzucil zamiast 2 funkcji jedna 
{
	int	min;
	int	i;
	int	size = a->size;

	i = 0;
	while (i++ < size - 3)
	{
		min = get_min(a);
		while (a->top->value != min)
		{
			if (find_position(a, min) <= a->size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}
#include <stdio.h>
void	radix_sort(t_stack *a, t_stack *b)// dodatkowa funkcjA do sortowania zamiast sort_big
{
	int	max_num = a->size - 1;
	int	max_bits = 0;
	int	i;
	int	j;
	int	size;

	while ((max_num >> max_bits) != 0)
		max_bits++;
	printf("%dni\n", max_bits);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		size = a->size;
		while (++j < size)
		{
			if (((a->top->index >> i) & 1) == 1)
			{
				printf("%dtest\n",);
				ra(a);;
			}
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
	}
}
