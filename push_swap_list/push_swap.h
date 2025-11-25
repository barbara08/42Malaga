#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	total;
}	t_data;

// utils.c
long	ft_atol(const char *str, char **endptr);
//long	ft_atol(const char *str);
int		ft_number_duplicate(int *stack, int size);
int		ft_is_sorted(int *stack, int size);
void	ft_free_data(t_data *data);
void	ft_print_error_and_free(t_data *data, int error_only);

// parsing.c (Nuevas funciones auxiliares para parser)
int		count_numbers_in_string(const char *str);
int		parse_args(int argc, char **argv, t_data *data);

// rules_*.c (Mantienen sus prototipos originales para no romper tu rules.c)
void	sa(int *a, int len_a);
void	sb(int *b, int len_b);
void	ss(int *a, int len_a, int *b, int len_b);
void	pa(int *a, int *len_a, int *b, int *len_b);
void	pb(int *a, int *len_a, int *b, int *len_b);
void	ra(int *a, int len_a);
void	rb(int *b, int len_b);
void	rr(int *a, int len_a, int *b, int len_b);
void	rra(int *a, int len_a);
void	rrb(int *b, int len_b);
void	rrr(int *a, int len_a, int *b, int len_b);

// small_sort.c
void	ft_sort_three(int *stack_a, int size_a);
void	ft_sort_five(t_data *data);
void	ft_sort_big_number(t_data *data);


// big_sort.c
int	*get_sorted_copy(t_data *data);
void	move_to_b(t_data *data, int i, int max_val);
void	push_chunks_to_b(t_data *data, int *sorted, int chunk_sz);
int	get_max_idx(int *stack, int size);
void	ft_push_back_to_a(t_data *data);

#endif