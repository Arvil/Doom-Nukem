/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:35:25 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/02 07:08:08 by bbataini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void		ingame(t_struct *p, int i)
{
	key_press_hook(p);
	raycasting(p, 0, 0);
	alive(p);
	weapon(p);
	sprite_move(p);
	while (i < NUMPORTE)
	{
		if (p->porte[i].poort == 1 && p->porte[i].open > 0)
			p->porte[i].open -= p->porte[i].spd;
		if (p->porte[i].poort == 0 && p->porte[i].open <= 1)
			p->porte[i].open += p->porte[i].spd;
		i++;
	}
	if (p->cure == 0 && p->difficulty == 0)
		p->life -= 0.01;
	else if (p->cure == 0 && p->difficulty == 1)
		p->life -= 0.02;
	if (p->trump == 7)
	{
		p->dead = 5;
		p->menu = 2;
	}
}

void	ingameover(t_struct *p)
{
	char *s;

	if (p->temp > 79)
		p->dead++;
	s = ft_itoa(5 - p->dead);
	mlx_string_put(p->mlx_ptr, p->w_ptr, 900, 500, 0xffffff, "Retour au menu :");
	mlx_string_put(p->mlx_ptr, p->w_ptr, 1080, 500, 0xffffff, s);
	free(s);
	if (p->dead == 5)
	{
		p->menu = 4;
		p->sprite[0].k = 2;
		p->sprite[1].k = 8;
		p->sprite[3].k = 1;
		p->sprite[16].k = 7;
		p->sprite[19].k = 6;
		init(p);
		initplayer(p);
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[124].img_ptr, 0, 0);
	}
	else
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[119].img_ptr, 340, 0);
}


void	draw_game(t_struct *p)
{
	char *s;

	p->time.update(&p->time);
	if (p->temp < 80)
		p->temp++;
	else
		p->temp = 0;
	if (p->menu == 1)
		ingame(p, 0);
	else if (p->menu == 2) // GAME OVER MODE
		ingameover(p);
	else if (p->menu == 3) // MAP EDITOR
	{
		if (p->edit != 0)
			img_to_img(p, p->mousex - 350, p->mousey - 20, p->edit, 0.15625);
		else if (p->edits > 19)
			img_to_img(p, p->mousex - 350, p->mousey - 20, p->sprite[p->edits].id, 0.15625);
		mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->img_ptr2, 340, 0);
		//		hookcreator(p);
		creator_map(p, 0, 0);
	}
	s = ft_itoa((int)p->time.fps); /// FPS
	mlx_string_put(p->mlx_ptr, p->w_ptr, 1595, 5, 0xffffff, s);
	free(s); ///////////////////////////////////////////////


	//	printf("%i ",p->difficulty);
	//	else if (p->menu == 4)
	//		mouse_release_menu(
}
