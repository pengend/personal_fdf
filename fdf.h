/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 15:14:08 by pxia              #+#    #+#             */
/*   Updated: 2014/12/27 23:48:50 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ABS(x) ((x) < 0 ? - (x) : (x))

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_img
{
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				n;
	unsigned int	color;
}					t_img;

typedef struct		s_3d
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}					t_3d;

typedef struct		s_2d
{
	int				x;
	int				y;
}					t_2d;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_3d			***c;
	t_3d			***a;
	size_t			max_y;
	size_t			max_x;
	t_2d			*ts;
	double			zoom;
	t_img			*i;
}					t_env;

t_3d				***get_init(t_env *e);
t_2d				*ft_getinfo(char *filename);
void				ppixel1(t_3d *c1, int i, int j, t_img *im);
void				ppixel2(t_3d *c1, int i, int j, t_img *im);
int					en(double n);
void				trans(t_3d ***c);
void				get_trans(t_env *e, void (*f)(t_3d*, double), double n);
void				get_affi(t_3d ***c, t_3d ***a, t_2d *ts, double zoom);
void				center(t_env *e);
void				ft_trace_v(t_env *e);
void				ft_trace_h(t_env *e);
void				ft_trace0(double a, t_3d *c1, t_3d *c2, t_img *im);
void				ft_trace1(double a, t_3d *c1, t_3d *c2, t_img *im);
void				ft_trace_d(t_3d *c1, t_3d *c2, t_img *im, int c);
int					get_a(t_3d c1, t_3d c2);
void				ft_trace_line(t_3d *c1, t_3d *c2, t_img *im);
size_t				ft_getlinenumber(char *filename);
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				ft_win(t_3d ***c, t_2d *info);
char				*ft_getfname(char *s);
void				ft_puttab(char **tab);
void				rotationx(t_3d *c, double rad);
void				rotationy(t_3d *c, double rad);
void				rotationz(t_3d *c, double rad);
int					get_next_line(int const fd, char **line);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_nbzero(void *s, size_t start, size_t end);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char*src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char*s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *s1);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strnjoin(const char *s1, const char *s2, size_t n);
char				*ft_strtrim(const char *s);
t_3d				**ft_strsplit(const char *s, char c, int y, t_2d *info);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_tabcpy(char **dest, char **src, size_t n);
void				ft_reverse_tab(char **tab, size_t tablen);
void				ft_reverse_str(char *str);

#endif
