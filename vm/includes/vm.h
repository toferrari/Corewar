/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbischof <dbischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:25:16 by dbischof          #+#    #+#             */
/*   Updated: 2017/09/20 17:00:03 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "op.h"
# include "view.h"

# define SETREGISTRE(x, v)	set_registre(battle->cur_process, x - 1, v)
# define GETREGISTRE(x)		get_registre(battle->cur_process, x - 1)
# define PC					battle->cur_process->pc
# define INST				battle->memory[PC]
# define MEMORY				battle->memory
# define SETPC(n)			(mod((PC + n), MEM_SIZE))
# define MAX(a, b)			((a > b) ? a : b)
# define CARRY				battle->cur_process->carry
# define ISREG(x)			(x > 0 && x <= REG_NUMBER)
# define ISOP(x)			(INST > x && INST <= x)
# define STUN				battle->cur_process->stun
# define FLAG				battle->cur_process->flag
# define OPTS				battle->opts

enum{NOTHING, LIVE, LD, ST, ADD, SUB, AND, OR, XOR, ZJMP, LDI, STI, FORK, LLD,
	LLDI, LFORK, AFF};
enum{Z, R, D, I};
enum{C_BLACK, C_RED, C_GREEN, C_YELLOW, C_BLUE, C_PURPLE, C_CYAN, C_GREY};

struct s_battle;
struct s_command;

typedef struct s_view		t_view;
typedef unsigned char		t_uc;
typedef void	(*t_listfunc[16])(struct s_battle *b, struct s_command *c);

typedef struct	s_bot
{
	int			id;
	int			rid;
	char		*name;
	char		*comment;
	t_uc		*instructions;
	int			nb_instructions;
	int			nbprocess;
}				t_bot;

typedef struct	s_bots
{
	int			nb;
	t_bot		*tab[4];
}				t_bots;

typedef struct	s_process
{
	int			registre[REG_NUMBER];
	int			pc;
	int			stun;
	int			dead;
	int			live;
	char		carry;
	t_bot		*bot;
	int			id;
	int			flag;
	int			last_action[3];
}				t_process;

typedef struct	s_fight
{
	int			cycle;
	int			cycle_to_die;
	int			checks;
	int			totalcycle;
	int			first_cycle;
	t_bot		*last_live;
}				t_fight;

typedef struct	s_options
{
	int			ncurses : 1;
	int			verbose : 5;
	int			dump : 1;
	int			n_dump;
}				t_options;

typedef struct	s_battle
{
	t_uc		memory[MEM_SIZE];
	t_uc		print_mem[MEM_SIZE];
	t_process	*cur_process;
	t_bots		bots;
	t_list		*process;
	t_listfunc	func;
	t_view		*view;
	t_fight		fight;
	t_options	opts;
	char		**env;
}				t_battle;

typedef struct	s_command
{
	t_uc		inst;
	t_uc		ocp;
	int			params[3];
	int			size[3];
	int			type[3];
	int			isocp;
	int			len;
	int			error;
}				t_command;

int				open_bot(char *path, t_uc **bot);
t_bot			*creabot(char *path);
t_bots			loadbots(int ac, char **av);
t_list			*loadmemory(t_battle *b);
t_uc			*getmemory(t_battle *b, int index, t_uc *buff, int len);
int				setmemory(t_battle *b, int index, t_uc *s, int len);
t_process		newprocess(t_bot *bot, int pc);
int				chartoint(unsigned char *t, int len);
char			*inttochar(int *i);
int				mod(int a, int b);
t_battle		*initbattle(int ac, char **av, char **env);
void			battle_launch(t_battle *battle);
t_list			*addprocess(t_list **list, t_process process);
t_process		cpyprocess(t_process *orignal, int pc);
int				load_func(t_battle *battle);
int				check_ocp(char inst, char ocp);
int				stun(t_battle *battle, t_command *c);
void			set_registre(t_process *process, int i, int value);
int				get_registre(t_process *process, int i);
void			initoptions(int ac, char **av, t_battle *battle);

void			debug(t_uc *s, int len);
void			displaybot(t_bot *bot);
void			hexa(t_uc *s, int len, int color);
void			displayprocess(t_list *elem);
void			print_memory(t_battle *b);
char			*ft_strhexa(unsigned char *str, int len);
t_command		getcommand(t_battle *battle, int pc);
int				isocp(char inst);
int				t_ind_size(t_battle *battle, char inst, int i, int pc);
void			size_p(t_battle *battle, t_command *c, int pc);

void			sound(t_battle *battle);
int				help();

void			add(t_battle *battle, t_command *c);
void			aff(t_battle *battle, t_command *c);
void			and_ft(t_battle *battle, t_command *c);
void			fork_ft(t_battle *battle, t_command *c);
void			ld(t_battle *battle, t_command *c);
void			ldi(t_battle *battle, t_command *c);
void			lld(t_battle *battle, t_command *c);
void			lldi(t_battle *battle, t_command *c);
void			lfork(t_battle *battle, t_command *c);
void			live(t_battle *battle, t_command *c);
void			or_ft(t_battle *battle, t_command *c);
void			st(t_battle *battle, t_command *c);
void			sti(t_battle *battle, t_command *c);
void			sub(t_battle *battle, t_command *c);
void			xor_ft(t_battle *battle, t_command *c);
void			zjmp(t_battle *battle, t_command *c);

#endif
