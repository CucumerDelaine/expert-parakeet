#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int				value;
	int				order;
	int				flag;
	struct s_struct	*next;
	int				size;
}					t_struct;

typedef struct s_main
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}					t_main;

int				ft_atoi(const char *str);
void			quicksort(int *numbers, int left, int right);
void			ft_putstr(char *s);
int				ft_isdigit(int num);
int				checker_argv(char *argv);
int				checker_duplic(int *arr, int size);
int				checker_sort(int *arr, int *arr_sort, int size);
int				found_at_buf(int arr, int *arr_sort, int size);
void			ft_lstadd_back(t_struct **lst, t_struct *new);
t_struct		*ft_lstlast_size(t_struct *lst, int size);
t_struct		*ft_lstlast(t_struct *lst);
void			new_list(t_struct **head, int order, int value);
int				ft_lstsize(t_struct *lst);
void			sa(t_struct **head_stek_a);
void			sb(t_struct **head_stek_b);
void			ss(t_struct **head_stek_a, t_struct **head_stek_b);
void			pb(t_struct **head_stek_a, t_struct **head_stek_b);
void			pa(t_struct **head_stek_b, t_struct **head_stek_a, t_main base);
void			ra(t_struct **head_stek_a);
void			rb(t_struct **head_stek_b);
void			rr(t_struct **head_stek_a, t_struct **head_stek_b);
void			rra(t_struct **head_stek_a);
void			rrb(t_struct **head_stek_b);
void			rrr(t_struct **head_stek_a, t_struct **head_stek_b);
int				found_best_way_end_low(t_struct *some_stek, t_main *base);
int				found_best_way_start_low(t_struct *some_stek, t_main *base);
int				found_best_way_start_big(t_struct *some_stek, t_main *base);
int				found_best_way_end_big(t_struct *some_stek, t_main *base);
int				found_mid_and_less(t_struct *head, t_main *base);
int				found_mid_and_more(t_struct *head, t_main *base);
void			first_corr_stek(t_struct **head_a, \
t_struct **head_b, t_main *base);
void			back_to_stek_a(t_struct **head_a, \
t_struct **head_b, t_main *base);
int				found_next_start(t_struct *head_a, t_main *base);
int				found_next_end(t_struct *head_a, t_main *base);
void			sort_at_stek_b(t_struct **head_a, \
t_struct **head_b, t_main *base);
void			second_corr_stek_a(t_struct **head_a, \
t_struct **head_b, t_main *base);
int				five_and_less_a(t_struct **head_a, \
t_struct **head_b, t_main *base);
int				step_one_two(t_struct **head_a, \
t_struct **head_b, t_main *base, int i);
void			three_elem_a(t_struct **head_a);
void			step_three(t_struct **head_a, \
t_struct **head_b, t_main *base);
void			step_five(t_struct **head_a, t_struct **head_b, t_main *base);
void			step_four(t_struct **head_a, \
t_struct **head_b, t_main *base, int i);
void			step_six(t_struct **head_a, \
t_struct **head_b, t_main *base, int i);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
int				ft_argv_len(char **argv);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
void			quesort(int *arr, int left, int right);
void			three_elem_b(t_struct **head_b);
int				five_and_less_b(t_struct **head_b, \
t_struct **head_a, t_main *base);
char			**ft_free_strok(char **res, int i);
int				have_argv(char *argv, int *argc, int **arr_sort, int **arr);
int				have_no_argv(char **argv, int *argc, int **arr_sort, int **arr);
int				func_main(int **arr, int **ar_sort, int argc);
void			zamena(t_struct **head_a);
void			zamena2(t_struct **head_a);
void			zamena3(t_struct **head_b);
void			zamena4(t_struct **head_b);

#endif