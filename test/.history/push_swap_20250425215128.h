#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node          *top;
    int             size;
}   t_stack;

/* Stack operations */
void    swap(t_stack *stack);
void    push(t_stack *src, t_stack *dest);
void    rotate(t_stack *stack);
void    reverse_rotate(t_stack *stack);

/* Command operations */
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

/* Sorting algorithms */
void    sort_2(t_stack *a);
void    sort_3(t_stack *a);
void    sort_4_5(t_stack *a, t_stack *b, int size);
void    sort_large(t_stack *a, t_stack *b);

/* Helper functions */
int     is_sorted(t_stack *stack);
int     find_min(t_stack *a);
int     find_min_position(t_stack *a);
int     find_node_position(t_stack *stack, t_node *target);
int     calculate_insert_score(t_stack *a, int value, int b_pos, int b_size);
int     find_insert_position(t_stack *a, int value);
void    push_min_to_b(t_stack *a, t_stack *b);
void    find_optimal_push(t_stack *a, t_stack *b);
void    rotate_to_push(t_stack *a, t_stack *b, t_node *target);
void    final_rotate(t_stack *a);

/* Parsing and initialization */
int     *parse(int argc, char **argv, int *count);
void    count_arg(int argc, char **argv, int *count);
void    clear(char **argv);
void    index_tab(int *tablica, int count);
void    fill_stack(t_stack *stack, int *tablica, int count);
void    free_stack(t_stack *stack);

/* Utility functions */
int     ft_atoi(const char *str);
char    **ft_split(char const *stack, char c);

#endif