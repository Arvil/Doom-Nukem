/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbataini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:42:01 by bbataini          #+#    #+#             */
/*   Updated: 2019/02/26 02:46:41 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		trump(t_struct *p)
{
//	printf("trump1 :%d\n", p->trump);
//	printf("tool :%d\n", p->tool);
	if (p->trumplive == 1)
	{
	if (p->trump  == 1)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[19].img_ptr, 475, 490);
	else if (p->trump == 2)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[20].img_ptr, 475, 490);
	else if (p->trump == 3)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[118].img_ptr, 475, 490);
	else if (p->trump == 4)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[44].img_ptr, 475, 490);
	else if (p->trump == 5)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[48].img_ptr, 475, 490);
	else if (p->trump == 6)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[49].img_ptr, 475, 490);
//	else if (p->trump == 4)
//		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[117].img_ptr, 475, 490);
//	else if (p->trump == 5)
//		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[118].img_ptr, 475, 490);
	if (p->tool == 1)
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr,p->tex[0].img_ptr, 1400, -100);
	}
}
