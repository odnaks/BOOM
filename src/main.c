/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:20:03 by twitting          #+#    #+#             */
/*   Updated: 2019/04/15 13:12:35 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "render.h"

void	fps(t_env *env)
{
	double	time;

	env->fps++;
	move_mob(env);
	mob_attack(env);
	time = (clock() - env->frame) / CLOCKS_PER_SEC;
	env->timer += time;
	if (time < (1.0 / 90.0))
		SDL_Delay((1.0 / 90.0 - time) * 1000);
	if (env->timer >= 1.0)
	{
		env->oldfps = env->fps;
		env->fps = 0;
		env->timer -= 1;
	}
}

void	ft_error(int errnum)
{
	if (errnum == 1)
		ft_putendl_fd("FFFFFFFFFreeeee", 2);
	if (errnum == 2)
		ft_putendl_fd("Memory allocation error, aborting...", 2);
	if (errnum == 3)
		ft_putendl_fd("Something wrong with map file, aborting...", 2);
	if (errnum == 4)
		ft_putendl_fd("SDL initialization has failed, aborting...", 2);
	exit(errnum);
}

void	remove_src(void)
{
	system("rm -rf textures");
	system("rm -rf music");
	system("rm -rf img");
	system("rm -rf fonts");
	system("rm epic.map");
}

int		main(int argc, char **argv)
{
	t_env		*env;
	t_rend		*rend;
	SDL_Event	e;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_error(2);
	if (!(R = (t_rend *)malloc(sizeof(t_rend))))
		ft_error(2);
	system("tar -xf resources.doom");
	if (argc > 1 && !ft_strcmp(argv[1], "map"))
		ft_strcpy(env->mapname, "created.map");
	else
		ft_strcpy(env->mapname, "epic.map");
	grandparser(env);
	texnulling(env);
	init(env);
	inittext(env);
	env->state = 0;
	while (!(env->quit))
		start(env, &e, R);
	SDL_DestroyWindow(env->window);
	SDL_Quit();
	remove_src();
	return (0);
}
