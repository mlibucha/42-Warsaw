#include "push_swap.h"

void	sa(t_stack *a) { if (a->size >= 2) { swap(a); write(1, "sa\n", 3); } }
void	sb(t_stack *b) { if (b->size >= 2) { swap(b); write(1, "sb\n", 3); } }
void	ss(t_stack *a, t_stack *b) { if (a->size >= 2 && b->size >= 2) { swap(a); swap(b); write(1, "ss\n", 3); } }
void	pa(t_stack *a, t_stack *b) { if (b->size > 0) { push(b, a); write(1, "pa\n", 3); } }
void	pb(t_stack *a, t_stack *b) { if (a->size > 0) { push(a, b); write(1, "pb\n", 3); } }
void	ra(t_stack *a) { if (a->size >= 2) { rotate(a); write(1, "ra\n", 3); } }
void	rb(t_stack *b) { if (b->size >= 2) { rotate(b); write(1, "rb\n", 3); } }
void	rr(t_stack *a, t_stack *b) { if (a->size >= 2 && b->size >= 2) { rotate(a); rotate(b); write(1, "rr\n", 3); } }
void	rra(t_stack *a) { if (a->size >= 2) { reverse_rotate(a); write(1, "rra\n", 4); } }
void	rrb(t_stack *b) { if (b->size >= 2) { reverse_rotate(b); write(1, "rrb\n", 4); } }
void	rrr(t_stack *a, t_stack *b) { if (a->size >= 2 && b->size >= 2) { reverse_rotate(a); reverse_rotate(b); write(1, "rrr\n", 4); } }