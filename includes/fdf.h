/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:46:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/01 18:45:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#include "mlx.h"
#include <math.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

# define BITS_PER_PIXEL 32
# define SIZE_LINE 4
# define ENDIAN 1
# define LW 1001
# define WW 1001
# define LI 100
# define WI 100
# define HEXA "0123456789abcdefABCDEF"

typedef struct		s_coord
{
	int				z;
	unsigned int	color;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_datacoord
{
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

int					ft_fdf_init(t_fdf **fdf);
int					ft_put_pxl_img(t_fdf *fdf, unsigned int color, int id);
int					ft_exit_fdf(char *msg, ...);

int					ft_get_map_info(t_fdf *fdf, char *map);
int					ft_prepare_coord(t_fdf *fdf, t_datacoord **dc);
int					ft_fill_coord(t_datacoord *dc);
t_coord				*ft_coord_new(char *abs, int *j);

int					ft_putcoord_img(t_fdf *fdf);
int					ft_putlpoint(t_fdf *fdf, int x_start, int y_start, int x_end, int y_end);

void				ft_putline(t_coord *line);
void				ft_putcoord(t_coord **coord);
int					ft_count_coord(t_coord *line);

#endif
