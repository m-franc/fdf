/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:46:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/04/01 17:49:45 by mfranc           ###   ########.fr       */
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

typedef struct		s_coord
{
	int				z;
	unsigned int	color;
	struct s_coord	*next;
}					t_coord;

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

int					ft_get_map_info(t_fdf fdf, char *map);
t_fdf				ft_fdf_init(void);
int					ft_put_pxl_img(t_fdf fdf, unsigned int color, int *id);
int					ft_exit_fdf(char *msg, ...);
int					ft_fill_coord(t_fdf fdf);
void				ft_put_coordline(t_coord *line);

#endif
