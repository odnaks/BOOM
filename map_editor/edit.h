/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:16:36 by twitting          #+#    #+#             */
/*   Updated: 2019/04/06 20:08:13 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_H
# define EDIT_H

# include <math.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include "libft.h"
# include <stdlib.h>
#include "kiss_sdl.h"

# include <stdio.h>/////////////////////////////////////////////

# define PSECT1 edit->sectors[sect1]
# define PSECT2 edit->sectors[sect2]
# define PVERT1 edit->portvert1
# define PVERT2 edit->portvert2
# define PSECT edit->sectors[edit->portsects[i]]
# define CMP edit->cmp_port
# define SECT edit->sectors[edit->sectnum]
# define WWIN 1024
# define HWIN 768

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_sector
{
	int				floor;
	int				ceiling;
	int				vertex[64];
	int				neighbors[64];
	unsigned int	npoints;
	unsigned int	light;
	int				finished;
	int				texture;
}					t_sector;

typedef struct		s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				color;
}					t_line;

typedef struct		s_sprite
{
	int				x;
	int				y;
	int				type;
	int				sector;
}					t_sprite;

typedef struct		s_map_ui
{
	SDL_Renderer *renderer;
	SDL_Event e;
	kiss_array objects;
	kiss_window window;
	kiss_button button;
	char *message;
	char *message2;
	char *message3;
	char *message4;
	int draw;
	int quit;
	char *title;
	int textbox_width;
	kiss_label label;
	kiss_label label0;
	kiss_label label1;
	kiss_label label2;
	kiss_label label3;
	kiss_label label4;
	kiss_entry entry0;
	kiss_entry entry1;
	kiss_entry entry2;
	kiss_entry entry3;
	kiss_textbox textbox1;
}					t_map_ui;

typedef struct		s_edit
{
	SDL_Surface		*surface;
	SDL_Window		*window;
	t_xy			verts[16384];
	int				quit;
	t_line			nowln;
	t_sector		sectors[256];
	t_sprite		sprites[256];
	int				sectnum;
	int				vertnum;
	int				sprnum;
	int				glvertnum;
	int				put;
	int				portvert1;
	int				portvert2;
	int				portsects[64];
	char			inputstr[16];
	t_xy			player;
	int				playersect;
	int				playerangle;
	int				playersetflag;
	int				buttonflag;
}					t_edit;

void	makebutton2(t_edit *edit);
void	makebutton1(t_edit *edit);
void	putportalline(t_edit *edit, int color);
int		getfirstvert(t_edit *edit, int x, int y);
int		getsecondvert(t_edit *edit, int x, int y);
void	putdot(t_edit *edit, int color, int x, int y);
void	portalcheck(t_edit *edit);
void	makeportals1(t_edit *edit);
void	makeportals2(t_edit *edit);
void	savemap(t_edit *edit);
void	putsectors(t_edit *edit);
void	portalinit(t_edit *edit);
t_edit	*init();
int		putline(t_edit *edit, t_line *l);

#endif