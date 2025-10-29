#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h> //para mi funcion ft_printf

//Validations utils.c
int		ft_atoi_validate(const char *str, int *error);
int		ft_number_duplicate(int *stack, int size);
int		ft_is_sorted(int *stack, int size);
void	ft_putstr_fd(char *s, int fd); //en vez de utilizar write, pero no lo uso

//Sorted sorted.c
/*
void	ft_sort_three(int *stack_a, int size_a);
void	ft_sort_five(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	ft_index_stack(int *stack, int size);
void	ft_sort_big(int *a, int *len_a, int *b, int *len_b);
*/

void	ft_sort_three(int *stack_a, int size_a);
void	ft_sort_five(int *stack_a, int *size_a, int *stack_b, int *size_b);
void sort_five(int *a, int size_a);
void    ft_sort_big_num(int *a, int len_a, int *b, int len_b);
void    print_stack(char *name, int stack[], int len);

//Operations
void	sa_swap(int a[], int len_a);
void	sb_swap(int b[], int len_b);
void	ss_swap(int a[], int len_a, int b[], int len_b);
void	pa_push(int a[], int *len_a, int b[], int *len_b);
void	pb_push(int a[], int *len_a, int b[], int *len_b);
void	ra_rotate(int a[], int len_a);
void	rb_rotate(int b[], int len_b);
void	rr_rotate(int a[], int len_a, int b[], int len_b);
void	rra_reverse_rotate(int a[], int len_a);
void	rrb_reverse_rotate(int b[], int len_b);
void	rrr_reverse_rotate(int a[], int len_a, int b[], int len_b);

#endif
