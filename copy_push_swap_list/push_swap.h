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
void	ft_free_data(t_data *data);
void	ft_print_error_and_free(t_data *data, int error_only);

//libft.c
long	ft_converted_digit(const char *str, const char **endptr);
long	ft_atoi(const char *str, char **endptr);
int		ft_number_duplicate(int *stack, int size);
int		ft_is_sorted(int *stack, int size);

// parsing.c
int		ft_count_numbers_in_string(const char *str);
int		ft_fill_stack_from_str(const char *str, t_data *data);
int		ft_parse_args(int argc, char **argv, t_data *data);

// rules_*.c
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

// aux_big_sort.c
void	ft_bubble_sort(int *array, int size);
int		*ft_get_sorted_copy(t_data *data);
void	ft_move_to_b(t_data *data, int i, int max_value);
void	ft_push_chunks_to_b(t_data *data, int *sorted, int chunk_size);


// aux_sort.c
int		ft_get_min_index(int *a, int size);
int		ft_get_max_index(int *stack, int size);
void	ft_push_back_to_a(t_data *data);


// sorted.c
void	ft_sort_three(int *stack_a, int size_a);
void	ft_sort_five(t_data *data);
void	ft_sort_big_number(t_data *data);

#endif