#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#include "push_swap.h"

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
void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (!stack->top || !stack->top->next)
        return;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void push(t_stack *src, t_stack *dest)
{
    t_node *temp;

    if (!src->top)
        return;
    temp = src->top;
    src->top = src->top->next;
    temp->next = dest->top;
    dest->top = temp;
    dest->size++;
    src->size--;
}

void rotate(t_stack *stack)
{
    t_node *temp;
    t_node *current;

    if (!stack->top || !stack->top->next)
        return;
    temp = stack->top;
    stack->top = stack->top->next;
    temp->next = NULL;
    current = stack->top;
    while (current->next)
        current = current->next;
    current->next = temp;
}

void reverse_rotate(t_stack *stack)
{
    t_node *temp;
    t_node *current;

    if (!stack->top || !stack->top->next)
        return;
    current = stack->top;
    while (current->next->next)
        current = current->next;
    temp = current->next;
    current->next = NULL;
    temp->next = stack->top;
    stack->top = temp;
}

/* Command operations */
void sa(t_stack *a) {
    if (a->size < 2) return;
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack *b) {
    if (b->size < 2) return;
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b) {
    if (a->size < 2 || b->size < 2) return;
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void pa(t_stack *a, t_stack *b) {
    if (b->size == 0) return;
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b) {
    if (a->size == 0) return;
    push(a, b);
    write(1, "pb\n", 3);
}

void ra(t_stack *a) {
    if (a->size < 2) return;
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b) {
    if (b->size < 2) return;
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b) {
    if (a->size < 2 || b->size < 2) return;
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void rra(t_stack *a) {
    if (a->size < 2) return;
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *b) {
    if (b->size < 2) return;
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b) {
    if (a->size < 2 || b->size < 2) return;
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}

/* Sorting functions */
int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

int find_min(t_stack *a)
{
    int min = a->top->value;
    t_node *current = a->top->next;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

int find_min_position(t_stack *a)
{
    int min = find_min(a);
    int pos = 0;
    t_node *current = a->top;
    
    while (current)
    {
        if (current->value == min)
            return pos;
        pos++;
        current = current->next;
    }
    return -1;
}

void sort_2(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a);
}

void sort_3(t_stack *a)
{
    int x = a->top->value;
    int y = a->top->next->value;
    int z = a->top->next->next->value;

    if (x > y && y < z && x < z) sa(a);
    else if (x > y && y > z) { sa(a); rra(a); }
    else if (x > y && y < z && x > z) ra(a);
    else if (x < y && y > z && x < z) { sa(a); ra(a); }
    else if (x < y && y > z && x > z) rra(a);
}

void push_min_to_b(t_stack *a, t_stack *b)
{
    int min_pos = find_min_position(a);
    int min = find_min(a);
    
    while (a->top->value != min)
    {
        if (min_pos <= a->size / 2)
            ra(a);
        else
            rra(a);
    }
    pb(a, b);
}

void sort_4_5(t_stack *a, t_stack *b, int size)
{
    push_min_to_b(a, b);
    if (size == 5)
        push_min_to_b(a, b);
    sort_3(a);
    pa(a, b);
    if (size == 5)
        pa(a, b);
}

void index_tab(int *tablica, int count)
{
    int *sorted = malloc(count * sizeof(int));
    if (!sorted)
    {
        write(2, "Error\n", 6);
        exit(1);
    }

    for (int i = 0; i < count; i++)
        sorted[i] = tablica[i];

    // Sort the copy using bubble sort
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    // Replace each element with its index
    for (int i = 0; i < count; i++)
    {
        int value = tablica[i];
        for (int j = 0; j < count; j++)
        {
            if (sorted[j] == value)
            {
                tablica[i] = j;
                break;
            }
        }
    }

    free(sorted);
}

void sort_large(t_stack *a, t_stack *b)
{
    int max_bit = 0;
    int max_number = a->size - 1;

    while ((max_number >> max_bit) != 0)
        max_bit++;

    for (int bit = 0; bit < max_bit; bit++)
    {
        int j = a->size;
        for (int i = 0; i < j; i++)
        {
            if (((a->top->value >> bit) & 1) == 0)
                pb(a, b);
            else
                ra(a);
        }

        while (b->size > 0)
            pa(a, b);
    }

    final_rotate(a);
}

void final_rotate(t_stack *a)
{
    int min_pos = find_min_position(a);
    int size = a->size;

    while (min_pos != 0)
    {
        if (min_pos <= size / 2)
        {
            ra(a);
            min_pos--;
        }
        else
        {
            rra(a);
            min_pos = (min_pos + 1) % size;
        }
    }
}

/* Parsing and initialization */
void fill_stack(t_stack *stack, int *tablica, int count)
{
    t_node *temp;
    int i = count - 1;
    
    while (i >= 0)
    {
        temp = malloc(sizeof(t_node));
        if (!temp)
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        temp->value = tablica[i];
        temp->next = stack->top;
        stack->top = temp;
        stack->size++;
        i--;
    }
}

void free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *next;
    
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
    stack->size = 0;
}

static int ft_isdigit(int c) {
    return (c >= '0' && c <= '9');
}

static int ft_isspace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || 
            c == '\v' || c == '\f' || c == '\r');
}

static int ft_atoi(const char *str) {
    long result = 0;
    int sign = 1;

    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str)) {
        result = result * 10 + (*str - '0');
        if ((sign == 1 && result > INT_MAX) || 
            (sign == -1 && -result < INT_MIN))
            return (sign == 1) ? INT_MAX : INT_MIN;
        str++;
    }
    return (int)(result * sign);
}

static int count_numbers(char **argv) {
    int count = 0;
    char **ptr = argv + 1;
    
    while (*ptr) {
        char *stack = *ptr;
        while (*stack) {
            while (*stack && ft_isspace(*stack)) stack++;
            if (*stack && (*stack == '+' || *stack == '-')) stack++;
            if (*stack && !ft_isdigit(*stack)) return -1;
            if (*stack && ft_isdigit(*stack)) {
                count++;
                while (*stack && ft_isdigit(*stack)) stack++;
            }
        }
        ptr++;
    }
    return count;
}

int *parse(int argc, char **argv, int *count) {
    *count = count_numbers(argv);
    if (*count <= 0) return NULL;
    
    int *numbers = malloc(sizeof(int) * (*count));
    if (!numbers) return NULL;
    
    int i = 0;
    for (int arg = 1; arg < argc; arg++) {
        char *stack = argv[arg];
        while (*stack) {
            while (*stack && ft_isspace(*stack)) stack++;
            if (!*stack) break;
            
            int num = ft_atoi(stack);
            numbers[i++] = num;
            
            while (*stack && !ft_isspace(*stack)) stack++;
        }
    }
    
    // Check for duplicates
    for (int j = 0; j < *count; j++) {
        for (int k = j + 1; k < *count; k++) {
            if (numbers[j] == numbers[k]) {
                free(numbers);
                return NULL;
            }
        }
    }
    
    return numbers;
}

/* Main function */
int main(int argc, char **argv)
{
    t_stack a, b;
    int count, *tablica;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;
    
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 0;

    tablica = parse(argc, argv, &count);
    if (!tablica)
    {
        write(2, "Error\n", 6);
        return 1;
    }

    index_tab(tablica, count);
    fill_stack(&a, tablica, count);

    if (!is_sorted(&a))
    {
        if (count == 2) sort_2(&a);
        else if (count == 3) sort_3(&a);
        else if (count <= 5) sort_4_5(&a, &b, count);
        else sort_large(&a, &b);
    }

    free(tablica);
    free_stack(&a);
    free_stack(&b);
    return 0;
}
