#include "doom-nukem.h"


int		mouse_motion_menu(int x, int y, t_struct *p)
{
    if (p->choice == 0)
    {
		if (x >= 635 && x <= 990 && y >= 565 && y <= 635)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[123].img_ptr, 0, 35);
		else if (x >= 630 && x <= 990 && y >= 768 && y <= 815)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[124].img_ptr, 0, 35);
		else if (x >= 720 && x <= 900 && y >= 860 && y <= 910)
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[125].img_ptr, 0, 35);
		else
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[122].img_ptr, 0, 35);
    }
	return (1);
}
/*
int		mouse_clic_menu(int b, int x, int y, t_struct *p)
{
	int		i;

	if (p->choice == 0)
	{
		if ((b == 1) && x >= 635 && x <= 990 && y >= 565 && y <= 635)
			//music
		else if ((b == 1) && x >= 630 && x <= 990 && y >= 768 && y <= 815)
			//music
		else if ((b == 1) && x >= 720 && x <= 900 && y >= 860 && y <= 910)
			//music (Je ne pense pas qu'il faille mettre une musique d'exit)
		else
			//music or nothing
	}
	return (1);
}*/

int		mouse_release_menu(int b, int x, int y, t_struct *p)
{
    if (p->choice == 0)
    {
		if ((b == 1) && x >= 635 && x <= 990 && y >= 565 && y <= 635)
        {
            p->choice = 1;
            p->gm.draw[RUN] = draw_game;
            p->gm.current_state = RUN;
        }
		else if ((b == 1) && x >= 630 && x <= 990 && y >= 768 && y <= 815)
            p->choice = 2;
		else if ((b == 1) && x >= 720 && x <= 900 && y >= 860 && y <= 910)
			close_window(p);
		else
			mlx_put_image_to_window(p->mlx_ptr, p->w_ptr, p->tex[122].img_ptr, 0, 35);
    }
	return (1);
}

void	draw_main_menu(void *gm)
{
	t_struct	*p;

	if (!(p = (t_struct*)gm))
		return ;
	if (p->choice == 0)
	{
        //mlx_hook(p->w_ptr, 4, (1L << 2), mouse_clic_menu, p);
		mlx_hook(p->w_ptr, 5, (1L << 2), mouse_release_menu, p);
		mlx_hook(p->w_ptr, 6, (1L << 6), mouse_motion_menu, p);
	}
    if (p->choice == 2)
	{
        //mlx_hook(p->w_ptr, 4, (1L << 2), mouse_clic_settings, p);
		mlx_hook(p->w_ptr, 5, (1L << 2), mouse_release_settings, p);
		mlx_hook(p->w_ptr, 6, (1L << 6), mouse_motion_settings, p);
	}
    if (p->choice == 3)
	{
        //mlx_hook(p->w_ptr, 4, (1L << 2), mouse_clic_diff, p);
		mlx_hook(p->w_ptr, 5, (1L << 2), mouse_release_diff, p);
		mlx_hook(p->w_ptr, 6, (1L << 6), mouse_motion_diff, p);
	}
}