/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:47:35 by mdeglain          #+#    #+#             */
/*   Updated: 2017/06/08 15:19:47 by dbischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** INCLUDES
*/

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdarg.h>
# include <locale.h>
# include <inttypes.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

/*
** DEFINE
*/

# define BUF_SZ 10192
# define FLAG_SHARP 1
# define FLAG_ZERO 2
# define FLAG_MINUS 4
# define FLAG_PLUS 8
# define FLAG_SPACE 16
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE    "\x1b[37m"
# define RESET   "\x1b[0m"
# define ULL unsigned long long
# define MY_STDIN (&g_stdin)
# define MY_STDOUT (&g_stdout)
# define MY_STDERR (&g_stderr)

/*
** Structures
*/

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_fd
{
	int			fd;
	int			start;
	t_list		*lst;
	struct s_fd	*next;
}				t_fd;

typedef struct	s_data
{
	void		*tab;
	char		*fmt;
	int			min_w;
	int			accu;
	int			flags;
	int			n;
	int			sign;
	enum
	{
		h,
		hh,
		l,
		ll,
		j,
		z,
		no_mod
	}			mod;
}				t_data;

typedef void	(*t_conv)(t_data*, va_list);

typedef struct	s_file
{
	int				fd;
	char			buf[BUF_SZ];
	int				index;
	unsigned char	*p;
	int				len;
}				t_file;

/*
** Extern for global
*/

extern t_file g_stdin;
extern t_file g_stdout;
extern t_file g_stderr;

/*
** Fonctions _put
*/

void			ft_putchar(char c);
void			ft_putendl(char *s);
void			ft_putnbr(int n);
void			ft_putllnbr(long long int n);
void			ft_putstr(const char *s);
void			ft_putnstr(char *str, int nb);
void			ft_putwchar(wint_t c);
void			ft_putwstr(wint_t *str);
void			ft_putnwstr(wint_t *str, int nb);

/*
**Fonctions _str
*/

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, char const *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
int				ft_strsplit_len(char **str);
void			ft_strsplit_free(char **str);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strrev(char *str);
int				ft_wstrlen(const wint_t *str);
int				ft_wcharlen(const wint_t c);
int				ft_strchrindex(char *s, char c);

/*
** Fonctions _fd
*/

void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_putwchar_fd(wint_t c, int fd);

/*
** Fonctions _mem
*/

void			*ft_memalloc(size_t size);
void			*ft_memchr(char *s, char c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memcpy_bwd(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

/*
** Fonctions _lst
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *node_new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstaddafter(t_list **alst, t_list *node_new);
void			ft_lstshift(t_list **alst);
t_list			*ft_lstln(void *content, size_t content_size);
int				ft_lstlen(t_list *list);

/*
** Fonctions _is
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_strisdigit(char *str);

/*
** Fonction autres
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_bzero(void *s, size_t n);
int				ft_nblen(long long int nb);
char			*ft_base(unsigned long long nb, int base, char *mbr);
int				ft_baselen(int	nb, int base, char *mbr);
void			ft_printn_char(int n, char c);
int				ft_wnstrlen(const wint_t *str, int nb);
long long		ft_abs(long long nb);
int				ft_is_space(char c);
int				ft_nbchr(char *str, char c);

/*
** Fonctions bonus
*/

int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_putnbrendl(int n);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_sqrt(int nb);
double			ft_dsqrt(double nb);
double			ft_piapprox(int n);
int				ft_power(int nb, int power);
int				ft_r_factorial(int nb);

/*
**	get_next_line
*/

int				get_next_line(const int fd, char **line);

/*
**	my_functions
*/

t_file			*my_fopen(char *filename);
int				my_fclose(t_file *file);
char			*my_fgets(char *str, int size, t_file *file);
int				my_fgetc(t_file *file);
int				str_to_int(char *s);
long			str_to_l(char *s);
long long		str_to_ll(char *s);
unsigned int	str_to_uint(char *s);
unsigned long	str_to_ul(char *s);
ULL				str_to_ull(char *s);

/*
** Fonctions ft_printf
*/

int				ft_printf(const char *format, ...);
void			launch(t_data *data, va_list arg);
void			conv_init(t_data *data);
void			parsing(t_data *data, va_list arg);
void			s_conv(t_data *data, va_list arg);
void			conversion(t_data *data, va_list arg);
void			upper_s_conv(t_data *data, va_list arg);
void			upper_d_conv(t_data *data, va_list arg);
void			upper_u_conv(t_data *data, va_list arg);
void			upper_o_conv(t_data *data, va_list arg);
void			upper_c_conv(t_data *data, va_list arg);
void			pct_conv(t_data *data, va_list arg);
void			accu(t_data *data, int len, long long nb);
void			min_width(t_data *data, int len, int id);
void			p_conv(t_data *data, va_list arg);
void			di_conv(t_data *data, va_list arg);
ULL				oux_type(t_data *data, va_list arg);
void			o_process(t_data *data, va_list arg);
void			u_process(t_data *data, va_list arg);
void			x_process(t_data *data, va_list arg);
void			accu_oux(t_data *data, int len);
void			c_conv(t_data *data, va_list arg);
void			write_null(t_data *data);
int				check_null_number(t_data *data, ULL nb);
void			b_process(t_data *data, va_list arg);

#endif
