/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallintersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:12:44 by ebednar           #+#    #+#             */
/*   Updated: 2019/04/15 16:31:20 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	wallintersect_1(t_rend *rend)
{
	RO1 = (t_xy){R->t1.x, R->t1.y};
	RO2 = (t_xy){R->t2.x, R->t2.y};
	if (R->t1.y < R->nfz.x)
	{
		if (R->i1.y > 0)
		{
			R->t1.x = R->i1.x;
			R->t1.y = R->i1.y;
		}
		else
		{
			R->t1.x = R->i2.x;
			R->t1.y = R->i2.y;
		}
	}
}

void	wallintersect_2(t_rend *rend, t_env *env)
{
	if (R->t2.y < R->nfz.x)
	{
		if (R->i1.y > 0)
		{
			R->t2.x = R->i1.x;
			R->t2.y = R->i1.y;
		}
		else
		{
			R->t2.x = R->i2.x;
			R->t2.y = R->i2.y;
		}
	}
	if (fabs(R->t2.x - R->t1.x) > fabs(R->t2.y - R->t1.y))
	{
		R->u0 = (R->t1.x - RO1.x) * (ET[0]->w - 1) / (RO2.x - RO1.x);
		R->u1 = (R->t2.x - RO1.x) * (ET[0]->w - 1) / (RO2.x - RO1.x);
	}
	else
	{
		R->u0 = (R->t1.y - RO1.y) * (ET[0]->w - 1) / (RO2.y - RO1.y);
		R->u1 = (R->t2.y - RO1.y) * (ET[0]->w - 1) / (RO2.y - RO1.y);
	}
}

void	wallintersect(t_rend *rend, t_env *env)
{
	if (R->t1.y <= 0 || R->t2.y <= 0)
	{
		R->nfz.x = 1e-4;
		R->nfz.y = 5;
		R->nfside.x = 1e-5;
		R->nfside.y = 20;
		R->wintsect1.x = -R->nfside.x;
		R->wintsect1.y = R->nfz.x;
		R->wintsect2.x = -R->nfside.y;
		R->wintsect2.y = R->nfz.y;
		R->i1 = intersect(R->t1, R->t2, R->wintsect1, R->wintsect2);
		R->wintsect1.x = R->nfside.x;
		R->wintsect2.x = R->nfside.y;
		R->i2 = intersect(R->t1, R->t2, R->wintsect1, R->wintsect2);
		wallintersect_1(R);
		wallintersect_2(R, env);
	}
}

void	rendportals(t_env *env, t_rend *rend)
{
	R->nya = (R->x - R->x1) * (R->ny2a - R->ny1a) / (R->x2 - R->x1) + R->ny1a;
	R->ncya = CLAMP(R->nya, R->ytop[R->x], R->ybottom[R->x]);
	R->nyb = (R->x - R->x1) * (R->ny2b - R->ny1b) / (R->x2 - R->x1) + R->ny1b;
	R->ncyb = CLAMP(R->nyb, R->ytop[R->x], R->ybottom[R->x]);
	vlinetop(env, R);
	if (R->nowsect->sky != 1)
	{
		if (ESEC[R->nowsect->neighbors[R->s]].sky == 1)
			R->ytop[R->x] = CLAMP(R->cya + 1, R->ytop[R->x], HWIN - 1);
		else
			R->ytop[R->x] = CLAMP(MAX(R->cya, R->ncya),
				R->ytop[R->x], HWIN - 1);
	}
	else
	{
		if (ESEC[R->nowsect->neighbors[R->s]].sky == 1)
			R->ytop[R->x] = CLAMP(MIN(R->cya, R->ncya),
				R->ytop[R->x], HWIN - 1);
		else
			R->ytop[R->x] = CLAMP(R->ncya, R->ytop[R->x], HWIN - 1);
	}
	vlinebot(env, R);
	R->ybottom[R->x] = CLAMP(MIN(R->cyb, R->ncyb), 0, R->ybottom[R->x]);
}
