/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:17:50 by grdalmas          #+#    #+#             */
/*   Updated: 2019/03/05 01:48:40 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void	move_greg(t_struct *p, int move)
{
	if (move == 66)
	{
		system("killall afplay");
		system("afplay ./doomzik/Doom_1.mp3 &");
		if (p->k == 4)
		{
			inverse_map(p,0,0,0);
			system("killall afplay");
			system("afplay ./doomzik/amblobby.mp3 &");
		}
		p->c->p_x = 13.5;
		p->k = 4;
	}
}

void	move_tim(t_struct *p, int move)
{
	if (move == 68)
	{
		system("killall afplay");
		system("afplay ./doomzik/vivaldi_spring.mp3 &");
		if (p->k == 3)
		{
			system("killall afplay");
			system("afplay ./doomzik/amblobby.mp3 &");
		}
		p->c->p_x = 1.5;
		p->k = 3;
	}
}
