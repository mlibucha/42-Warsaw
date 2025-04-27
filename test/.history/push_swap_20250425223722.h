#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node          *top;
    int             size;
} t_stack;

/* Stack Operations */
void swap(t_stack *stack);
void push(t_stack *src, t_stack *dest);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

/* Command operations */
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

/* Sorting functions */
int is_sorted(t_stack *stack);
int find_min(t_stack *a);
int find_min_position(t_stack *a);
void sort_2(t_stack *a);
void sort_3(t_stack *a);
void push_min_to_b(t_stack *a, t_stack *b);
void sort_4_5(t_stack *a, t_stack *b, int size);
void index_tab(int *tablica, int count);
void sort_large(t_stack *a, t_stack *b);
void final_rotate(t_stack *a);

/* Parsing and initialization */
void fill_stack(t_stack *stack, int *tablica, int count);
void free_stack(t_stack *stack);
int *parse(int argc, char **argv, int *count);

/* Helper functions */
int ft_isdigit(int c);
int ft_isspace(char c);
int ft_atoi(const char *str);
int count_numbers(char **argv);

#endif