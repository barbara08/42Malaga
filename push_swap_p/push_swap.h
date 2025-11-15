#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>



int ft_atoi_validate(const char *str, int *error);
int ft_number_duplicate(int *stack, int size);
int ft_is_sorted(int *stack, int size);
void ft_print_error_and_free(int *a, int *b);

void sa_swap(int a[], int len_a);
void sb_swap(int b[], int len_b);
void ss_swap(int a[], int len_a, int b[], int len_b);

void pa_push(int a[], int *len_a, int b[], int *len_b);
void pb_push(int a[], int *len_a, int b[], int *len_b);

void ra_rotate(int a[], int len_a);
void rb_rotate(int b[], int len_b);
void rr_rotate(int a[], int len_a, int b[], int len_b);

void rra_reverse_rotate(int a[], int len_a);
void rrb_reverse_rotate(int b[], int len_b);
void rrr_reverse_rotate(int a[], int len_a, int b[], int len_b);

void ft_sort_three(int *stack_a, int size_a);
void ft_sort_five(int *a, int *size_a, int *b, int *size_b);

//int find_chunk_index(int value, int sorted[], int chunk_size, int total);
void push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total);
int find_max_index(int b[], int len_b);
void push_back_to_a(int a[], int *len_a, int b[], int *len_b);
int get_chunk_size(int total);

void sort_large(int *a, int *len_a, int *b, int *len_b, int total);

#endif