#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

//aux functions =>	utils.c
int		ft_atoi_validate(const char *str, int *error);
int		ft_number_duplicate(int *stack, int size);
int		ft_is_sorted(int *stack, int size);
void	ft_print_error_and_free(int *a, int *b);
void	ft_print_stack(char *name, int stack[], int len); //No lo piden

//operations =>		rules_*.c
void	sa(int a[], int len_a);
void	sb(int b[], int len_b);
void	ss(int a[], int len_a, int b[], int len_b);

void	pa(int a[], int *len_a, int b[], int *len_b);
void	pb(int a[], int *len_a, int b[], int *len_b);

void	ra(int a[], int len_a);
void	rb(int b[], int len_b);
void	rr(int a[], int len_a, int b[], int len_b);

void	rra(int a[], int len_a);
void	rrb(int b[], int len_b);
void	rrr(int a[], int len_a, int b[], int len_b);

//sorted	=>		sorted.c
void	ft_sort_three(int *stack_a, int size_a);
void	ft_sort_five(int *a, int *size_a, int *b, int *size_b);

int		ft_get_chunk_size(int total);
int		ft_find_max_index(int b[], int len_b);
void	ft_push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total);
void	ft_push_back_to_a(int a[], int *len_a, int b[], int *len_b);
void	ft_sort_big_number(int *a, int *len_a, int *b, int *len_b, int total);

#endif