/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:56:08 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/04/21 03:34:12 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_sdl_loop(t_sdl *sdl, int finish)
{
	while (finish)
	{
		SDL_WaitEvent(&sdl->event);
		if (sdl->event.type == SDL_QUIT)
			finish = 0;
		if (sdl->event.type == SDL_KEYDOWN)
			if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
				finish = 0;
	}
}

int		main(int ac, char **av)
{
	t_sdl	sdl;
	t_scene scene;

	(void)av;
	if (ac != 2)
		return (0);
	ft_get_scene(&scene, av[1]);
	printf("s.pos.x = %.0f\n", ((t_sphere *)(scene.obj->data))->pos.x);

	if (!(sdl.pixels = (Uint32*)malloc(sizeof(sdl.pixels) * 640 * 480)))
		return (0);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (-1);
	}
	if ((sdl.win = SDL_CreateWindow("rtv1", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN)) == 0)
	{
		SDL_Quit();
		return (-1);
	}
	sdl.renderer = SDL_CreateRenderer(sdl.win, -1, 0);
	sdl.texture = SDL_CreateTexture(sdl.renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STATIC, 640, 480);
	ft_bzero(sdl.pixels, 640 * 480 * sizeof(Uint32));
	ft_scene(&sdl, &scene);
	SDL_UpdateTexture(sdl.texture, NULL, sdl.pixels, 640 * sizeof(Uint32));
	SDL_RenderClear(sdl.renderer);
	SDL_RenderCopy(sdl.renderer, sdl.texture, NULL, NULL);
	SDL_RenderPresent(sdl.renderer);
	ft_sdl_loop(&sdl, 1);
	SDL_DestroyWindow(sdl.win);
	SDL_Quit();
	return (0);
}
