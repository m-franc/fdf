/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:46:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/06 22:59:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include <math.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define BITS_PER_PIXEL 32
# define SIZE_LINE 4
# define ENDIAN 1
# define LW 1200
# define WW 1200
# define LI 1200
# define WI 1200
# define HEXA "0123456789abcdefABCDEF"

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_datacoord
{
	int				x;
	int				y;
	int				i;
	int				*pi;
	t_list			*map_info;
	t_coord			*cl_cpy;
	t_coord			**coord_cpy;
	char			*line_cpy;
	int				nb_line;
}					t_datacoord;

typedef struct		s_fdf
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*addr;
	int				img_in_win;
	int				b_pxl;
	int				size_l;
	int				endian;
	t_list			*map_info;
	t_coord			**coord;
}					t_fdf;

typedef struct		s_drawdatas
{
	int				x;
	int				y;
	int				distance_x;
	int				distance_y;
	int				x_inc;
	int				y_inc;
	unsigned int	color;
}					t_draw_datas;

void				ft_coorddel(t_coord **coord);
int					ft_fdf_init(t_fdf **fdf);
void				ft_put_pxl_img(t_fdf *fdf, unsigned int color, int id);
int					ft_exit_fdf(char *msg, ...);

int					ft_get_map_info(t_fdf *fdf, char *map);
int					ft_prepare_coord(t_fdf *fdf, t_datacoord **dc);
int					ft_fill_coord(t_datacoord *dc);
t_coord				*ft_coord_new(char *abs, int *j, int x, int y);

void				ft_putcoord_img(t_fdf *fdf, t_datacoord *dc);
int					ft_putlpoint(t_fdf *fdf, t_coord *start, t_coord *end);

void				ft_iso_application(t_coord **coord);
void				ft_ratio_application(t_coord **coord, t_datacoord *dc);
void				ft_placement_application(t_coord *tmp,
		t_coord **coord, t_datacoord *dc);

int					ft_get_min_max_y(t_datacoord *dc,
		t_coord **coord, int *y_max);
int					ft_get_min_max_x(t_coord **coord, int *x_max);
int					ft_get_padd_z(t_coord **coord);
int					ft_get_scale(int ratio_x, int ratio_y, int ratio_z);

void				ft_putline(t_coord *line);
void				ft_putcoord(t_coord **coord);
int					ft_count_coord(t_coord *line);

#endif
