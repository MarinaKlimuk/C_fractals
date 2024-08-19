/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimuk <mklimuk@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-29 14:19:30 by mklimuk           #+#    #+#             */
/*   Updated: 2024-07-29 14:19:30 by mklimuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Error: Invalid arguments\n"

# define WIDTH 800
# define HEIGHT 800
/*
 * COLORS
 */
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// Psychedelic colors
# define ELECTRIC_BLUE 0x7DF9FF
# define NEON_PINK 0xFF6EC7
# define VIVID_PURPLE 0x9B30FF
# define BRIGHT_YELLOW 0xFFFF33
# define GLOWING_GREEN 0x39FF14
# define HOT_MAGENTA 0xFF00FF
# define VIBRANT_ORANGE 0xFF5F1F
# define LIME_GREEN 0x32CD32
# define CYAN 0x00FFFF
# define BRIGHT_RED 0xFF0033

// x is real, y is imaginary
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

// string utils
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
void		putstr_fd(char *s, int fd);
int			ft_isdigit(int symbol);
double		alphtodbl(char *s);
int			has_digit(char *s);
void		error_message(void);

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

// math
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// static void	handle_pixel(int x, int y, t_fractal *fractal);

// hooks events
int			key_handler(int keysym, t_fractal *fractal);
// clean
int			close_handler(t_fractal *fractal);
int			mouse_handler(int buton, int x, int y, t_fractal *fractal);

int			julia_track(int x, int y, t_fractal *fractal);

#endif
