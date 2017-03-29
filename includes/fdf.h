/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:46:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 12:26:25 by mfranc           ###   ########.fr       */
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
}					t_fdf;

int					ft_put_pxl_img(t_fdf fdf, unsigned int color, int *id);
int					ft_fill_img(t_fdf fdf, unsigned int color);
int					ft_exit_fdf(char *msg, ...);
t_fdf				ft_fdf_init(void);

#endif
