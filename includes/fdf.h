/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:46:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/28 20:02:01 by mfranc           ###   ########.fr       */
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

typedef struct		s_pxl
{
	int				b_ppxl;
	int				size_l;
	int				endian;
}					t_pxl;

typedef struct		s_mlxdatas
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*addr;
	int				img_in_win;
	struct s_pxl	pxl;
}					t_mlxdatas;

t_pxl				pxl_init(void);
int					ft_put_pxl_img(char **addr, unsigned int color);
int					ft_fill_img(t_mlxdatas mlx_datas, unsigned int color);
int					ft_exit_fdf(char *msg, ...);

#endif
