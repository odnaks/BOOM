/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:42:12 by ebednar           #+#    #+#             */
/*   Updated: 2019/04/15 16:39:58 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# define MAXQUEUE 256
# define BUTTONHEIGHT 4
# define BUTTONWIDTH 2

# include "engine.h"

typedef struct	s_now
{
	int			sectorno;
	int			sx1;
	int			sx2;
}				t_now;

typedef	struct	s_sprque
{
	int			sector;
	int			sx1;
	int			sx2;
	int			ytop[WWIN];
	int			ybottom[WWIN];
	int			visible;
}				t_sprque;

typedef struct	s_scaler
{
	int			result;
	int			bop;
	int			fd;
	int			ca;
	int			cache;
}				t_scaler;

typedef struct	s_rend
{
	int			s;
	int			ytop[WWIN];
	int			ybottom[WWIN];
	t_now		queue[MAXQUEUE];
	t_sprque	sprq[MAXQUEUE];
	t_sector	*nowsect;
	double		vx1;
	double		vy1;
	double		vx2;
	double		vy2;
	t_xy		t1;
	t_xy		t2;
	double		xscale1;
	double		xscale2;
	double		yscale1;
	double		yscale2;
	int			x1;
	int			x2;
	double		yceil;
	double		yfloor;
	int			y1a;
	int			y1b;
	int			y2a;
	int			y2b;
	t_xy		nfz;
	t_xy		nfside;
	t_xy		i1;
	t_xy		i2;
	int			beginx;
	int			endx;
	int			x;
	int			y;
	int			ya;
	int			cya;
	int			yb;
	int			cyb;
	float		nyceil;
	float		nyfloor;
	int			ny1a;
	int			ny1b;
	int			ny2a;
	int			ny2b;
	int			nya;
	int			ncya;
	int			nyb;
	int			ncyb;
	t_now		*head;
	t_now		*tail;
	int			u0;
	int			u1;
	t_xy		org1;
	t_xy		org2;
	int			txtx;
	int			txtz;
	double		hei;
	double		mapx;
	double		mapz;
	int			pel;
	t_xy		wintsect1;
	t_xy		wintsect2;
	t_scaler	ya_int;
	t_scaler	yb_int;
	t_xy		vspr;
	t_xy		tspr;
	int			sprx;
	double		sprxscale;
	double		spryscale;
	int			sprx1;
	int			sprx2;
	double		sprceil;
	double		sprfloor;
	int			sprya;
	int			spryb;
	int			csprya;
	int			cspryb;
	int			sprbegx;
	int			sprendx;
	double		tspr1;
	double		tspr2;
	t_xy		vbut1;
	t_xy		vbut2;
	t_xy		tbut1;
	t_xy		tbut2;
	double		butxscale1;
	double		butyscale1;
	double		butxscale2;
	double		butyscale2;
	int			butx1;
	int			butx2;
	int			butx;
	double		butceil;
	double		butfloor;
	int			buty1a;
	int			buty1b;
	int			buty2a;
	int			buty2b;
	int			cbutya;
	int			cbutyb;
	int			butbegx;
	int			butendx;
	t_scaler	butya_int;
	t_scaler	butyb_int;
	int			butya;
	int			butyb;
	t_xy		vtr1;
	t_xy		vtr2;
	t_xy		ttr1;
	t_xy		ttr2;
	double		trxscale1;
	double		tryscale1;
	double		trxscale2;
	double		tryscale2;
	int			trx1;
	int			trx2;
	int			trx;
	double		trceil;
	double		trfloor;
	int			try1a;
	int			try1b;
	int			try2a;
	int			try2b;
	int			ctrya;
	int			ctryb;
	int			trbegx;
	int			trendx;
	t_scaler	trya_int;
	t_scaler	tryb_int;
	int			trya;
	int			tryb;
	int			bugf;
}				t_rend;

int				start_engine(t_env *env, SDL_Event *e, t_rend *rend);
void			drawsky(t_env *env, t_rend *rend, int sect);
int				scaler_next(t_scaler *sc);
void			rendersprite(t_env *env, t_rend *rend);
void			renderbutton(t_env *env, t_rend *rend);
void			trplane(t_env *env, t_rend *rend, int j);
void			render_wall(t_env *env, t_rend *rend);
void			wallintersect(t_rend *rend, t_env *env);
void			wallxloop(t_env *env, t_rend *rend);
void			start(t_env *env, SDL_Event *e, t_rend *rend);
void			wallscale(t_env *env, t_rend *rend);
void			drawtransp(t_env *env, t_rend *rend, int j);
int				portaledge(t_env *env, t_rend *rend);
void			drawbutton(t_env *env, t_rend *rend);
t_scaler		scaler_init_support1(t_rend *rend);
t_scaler		scaler_init_support2(t_rend *rend);
void			butplane_support3(t_rend *rend, t_env *env);
void			butplane_support(t_rend *rend, int j, t_env *env);
void			drawsprite(t_env *env, t_rend *rend, int j);
void			trintersect2(t_rend *rend, t_env *env, int j);
void			trintersect(t_rend *rend, t_env *env, int j);
void			vlinebot(t_env *env, t_rend *rend);
void			vlinetop(t_env *env, t_rend *rend);
void			vlinewall(t_env *env, t_rend *rend);
void			rendportals(t_env *env, t_rend *rend);
t_scaler		scaler_init_support6(t_rend *rend);
t_scaler		scaler_init_support5(t_rend *rend);
void			checknextrend(t_env *env, t_rend *rend);
void			wallstart(t_env *env, t_rend *rend, t_now *now);

#endif
