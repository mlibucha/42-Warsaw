#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

/* Basic stack operations */
void swap(t_stack *stack) {
    if (!stack->top || !stack->top->next) return;
    t_node *first = stack->top;
    t_node *second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void push(t_stack *src, t_stack *dest) {
    if (!src->top) return;
    t_node *tmp = src->top;
    src->top = src->top->next;
    tmp->next = dest->top;
    dest->top = tmp;
    dest->size++;
    src->size--;
}

void rotate(t_stack *stack) {
    if (!stack->top || !stack->top->next) return;
    t_node *tmp = stack->top;
    stack->top = stack->top->next;
    tmp->next = NULL;
    t_node *last = stack->top;
    while (last->next) last = last->next;
    last->next = tmp;
}

void reverse_rotate(t_stack *stack) {
    if (!stack->top || !stack->top->next) return;
    t_node *prev = NULL;
    t_node *curr = stack->top;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = stack->top;
    stack->top = curr;
}

/* Command operations */
void sa(t_stack *a) { if (a->size > 1) { swap(a); write(1, "sa\n", 3); } }
void sb(t_stack *b) { if (b->size > 1) { swap(b); write(1, "sb\n", 3); } }
void ss(t_stack *a, t_stack *b) { if (a->size > 1 && b->size > 1) { swap(a); swap(b); write(1, "ss\n", 3); } }
void pa(t_stack *a, t_stack *b) { if (b->size > 0) { push(b, a); write(1, "pa\n", 3); } }
void pb(t_stack *a, t_stack *b) { if (a->size > 0) { push(a, b); write(1, "pb\n", 3); } }
void ra(t_stack *a) { if (a->size > 1) { rotate(a); write(1, "ra\n", 3); } }
void rb(t_stack *b) { if (b->size > 1) { rotate(b); write(1, "rb\n", 3); } }
void rr(t_stack *a, t_stack *b) { if (a->size > 1 && b->size > 1) { rotate(a); rotate(b); write(1, "rr\n", 3); } }
void rra(t_stack *a) { if (a->size > 1) { reverse_rotate(a); write(1, "rra\n", 4); } }
void rrb(t_stack *b) { if (b->size > 1) { reverse_rotate(b); write(1, "rrb\n", 4); } }
void rrr(t_stack *a, t_stack *b) { if (a->size > 1 && b->size > 1) { reverse_rotate(a); reverse_rotate(b); write(1, "rrr\n", 4); } }

/* Sorting helpers */
int is_sorted(t_stack *stack) {
    t_node *n = stack->top;
    while (n && n->next) {
        if (n->value > n->next->value) return 0;
        n = n->next;
    }
    return 1;
}

int get_min(t_stack *stack) {
    int min = stack->top->value;
    t_node *n = stack->top->next;
    while (n) {
        if (n->value < min) min = n->value;
        n = n->next;
    }
    return min;
}

int get_max(t_stack *stack) {
    int max = stack->top->value;
    t_node *n = stack->top->next;
    while (n) {
        if (n->value > max) max = n->value;
        n = n->next;
    }
    return max;
}

/* Small sorts */
void sort_2(t_stack *a) {
    if (a->top->value > a->top->next->value) sa(a);
}

void sort_3(t_stack *a) {
    int x = a->top->value;
    int y = a->top->next->value;
    int z = a->top->next->next->value;

    if (x > y && y < z && x < z) sa(a);
    else if (x > y && y > z) { sa(a); rra(a); }
    else if (x > y && y < z && x > z) ra(a);
    else if (x < y && y > z && x < z) { sa(a); ra(a); }
    else if (x < y && y > z && x > z) rra(a);
}

void sort_4_5(t_stack *a, t_stack *b, int size) {
    int min;
    for (int i = 0; i < size - 3; i++) {
        min = get_min(a);
        while (a->top->value != min) {
            if (find_position(a, min) <= a->size / 2) ra(a);
            else rra(a);
        }
        pb(a, b);
    }
    sort_3(a);
    while (b->size > 0) pa(a, b);
}

/* Large sort implementation */
int find_position(t_stack *stack, int val) {
    int pos = 0;
    t_node *n = stack->top;
    while (n) {
        if (n->value == val) return pos;
        pos++;
        n = n->next;
    }
    return -1;
}

int get_target_pos(t_stack *a, int b_val) {
    int target_pos = 0;
    int min = INT_MAX;
    t_node *n = a->top;
    
    while (n) {
        if (n->value > b_val && n->value < min) {
            min = n->value;
            target_pos = find_position(a, min);
        }
        n = n->next;
    }
    return (min != INT_MAX) ? target_pos : find_position(a, get_min(a));
}

void move_to_top(t_stack *stack, int pos, char stack_name) {
    int size = stack->size;
    while (pos > 0 && pos <= size / 2) {
        if (stack_name == 'a') ra(stack);
        else rb(stack);
        pos--;
    }
    while (pos > size / 2 && pos < size) {
        if (stack_name == 'a') rra(stack);
        else rrb(stack);
        pos++;
    }
}

void push_chunk(t_stack *a, t_stack *b, int start, int end) {
    int pushed = 0;
    while (pushed < end - start && a->size > 0) {
        int closest = find_closest_in_range(a, start, end);
        int pos = find_position(a, closest);
        move_to_top(a, pos, 'a');
        pb(a, b);
        pushed++;
        if (b->size > 1 && b->top->value < b->top->next->value)
            rb(b);
    }
}

int find_closest_in_range(t_stack *stack, int start, int end) {
    t_node *n = stack->top;
    int closest = INT_MAX;
    int closest_val = stack->top->value;
    
    while (n) {
        if (n->value >= start && n->value < end && n->value < closest) {
            closest = n->value;
            closest_val = n->value;
        }
        n = n->next;
    }
    return closest_val;
}

void sort_100(t_stack *a, t_stack *b) {
    int chunk_size = 20;
    for (int i = 0; i < 5; i++) {
        push_chunk(a, b, i * chunk_size, (i + 1) * chunk_size);
    }
    
    while (b->size > 0) {
        int min_moves = INT_MAX;
        t_node *best = NULL;
        t_node *curr = b->top;
        int b_pos = 0;
        
        while (curr) {
            int target_pos = get_target_pos(a, curr->value);
            int moves = (b_pos <= b->size / 2) ? b_pos : b->size - b_pos;
            moves += (target_pos <= a->size / 2) ? target_pos : a->size - target_pos;
            
            if (moves < min_moves) {
                min_moves = moves;
                best = curr;
            }
            
            curr = curr->next;
            b_pos++;
        }
        
        int target_pos = get_target_pos(a, best->value);
        int best_pos = find_position(b, best->value);
        
        while (a->top->value != target_pos && b->top != best) {
            if (target_pos <= a->size / 2 && best_pos <= b->size / 2) rr(a, b);
            else if (target_pos > a->size / 2 && best_pos > b->size / 2) rrr(a, b);
            else break;
        }
        
        move_to_top(a, target_pos, 'a');
        move_to_top(b, best_pos, 'b');
        pa(a, b);
    }
    
    int min_pos = find_position(a, get_min(a));
    move_to_top(a, min_pos, 'a');
}

void sort_500(t_stack *a, t_stack *b) {
    int chunk_size = 35;
    for (int i = 0; i < 15; i++) {
        push_chunk(a, b, i * chunk_size, (i + 1) * chunk_size);
    }
    
    while (b->size > 0) {
        t_node *best = find_best_push(a, b);
        execute_best_push(a, b, best);
    }
    
    final_position(a);
}

/* Parsing and initialization */
void fill_stack(t_stack *stack, int *nums, int count) {
    for (int i = count - 1; i >= 0; i--) {
        t_node *new = malloc(sizeof(t_node));
        new->value = nums[i];
        new->next = stack->top;
        stack->top = new;
        stack->size++;
    }
}

void free_stack(t_stack *stack) {
    t_node *n = stack->top;
    while (n) {
        t_node *tmp = n->next;
        free(n);
        n = tmp;
    }
    stack->top = NULL;
    stack->size = 0;
}

/* Main execution */
int main(int argc, char **argv) {
    if (argc < 2) return 0;
    
    t_stack a = {NULL, 0};
    t_stack b = {NULL, 0};
    
    // Parse input
    int count = 0;
    int *nums = parse_input(argv, &count);
    if (!nums) {
        write(2, "Error\n", 6);
        return 1;
    }
    
    // Normalize numbers
    normalize_numbers(nums, count);
    
    // Fill stack
    fill_stack(&a, nums, count);
    free(nums);
    
    // Sort based on size
    if (!is_sorted(&a)) {
        if (count == 2) sort_2(&a);
        else if (count == 3) sort_3(&a);
        else if (count <= 5) sort_4_5(&a, &b, count);
        else if (count <= 100) sort_100(&a, &b);
        else sort_500(&a, &b);
    }
    
    free_stack(&a);
    free_stack(&b);
    return 0;
}
