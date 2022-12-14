/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <njerasea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:39:25 by njerasea          #+#    #+#             */
/*   Updated: 2022/10/16 10:13:40 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include               <stdio.h>
# include               <string.h>

typedef struct t_count
{
	int	fd;
	int	sd;
	int	i;
	int	j;
	int	k;
	int	keep;
	int	keep2;
	int	*tmp;
	int	num1;
	int	num2;
	int	size_a;
	int	size_b;
	int	mid_chunk;
}	t_c;

void	error_check(int ac, char **av);
void	check_dup(int *res_num, int len);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_ma_count(char **av);
int		*ft_pushint(char **av, int len);
void	ft_free2d(char **free2);
void	ft_sa(int *stack_a, int len, int sec);
void	ft_sb(int *stack_a, int len, int sec);
void	ft_ss(int *stack_a, int *stack_b, t_c *c, int sec);
void	ft_ra(int *stack_a, int len, int sec);
void	ft_rb(int *stack_b, int len, int sec);
void	ft_rr(int *stack_a, int *stack_b, t_c *c, int sec);
void	ft_rra(int *stack_a, int len, int sec);
void	ft_rrb(int *stack_b, int len, int sec);
void	ft_rrr(int *stack_a, int *stack_b, t_c *c, int sec);
void	ft_pa(int *stack_a, int *stack_b, t_c *c, int sec);
void	ft_pb(int *stack_a, int *stack_b, t_c *c, int sec);
void	ft_sort(int *res_num, int len);
void	ft_3_sort(int *res_num, int len);
int		check_sort(int *res_num, int len);
int		*ft_setindex_minmax(int *res_num, int len);
int		ft_5_sort(int *res_num, int len);
int		ft_100_sort(int *res_num, int len);
void	ft_set_chunk(int *stack_a, int len, int *stack_b, t_c *c);
void	ft_set_chunk_stack_b(int *stack_a, int *stack_b, t_c *c, int len);
void	ft_backtoa(int *stack_a, int *stack_b, t_c *c);
int		ft_500_sort(int *res_num, int len);
int		ft_universe(int *res_num, int len);
void	ft_set_round_100(t_c *c, int *res_num, int len, int *stack_b);
void	ft_set_chunk(int *stack_a, int len, int *stack_b, t_c *c);
void	ft_set_pushtob(t_c *this, t_c *c, int *stacK_a, int *stack_b);
void	ft_set_pushtoa(t_c *this, t_c *c, int *stack_a, int *stack_b);
char	*get_next_line(int fd);
char	*ft_readtojoin(int fd, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen_end(const char *s, char end);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_read(char *buffer, size_t lenline);
void	ft_doinstr_err(void);
void	ft_doinstr(int *stack_a, int *stack_b, t_c *c, char *instruc);
int		ft_sort_check(int *stack_a, t_c *c);
void	ft_check_next_line(int *res_num, int *stack_b, t_c *c);

#endif
