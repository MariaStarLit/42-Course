/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:31:15 by dimarque          #+#    #+#             */
/*   Updated: 2024/03/04 18:27:14 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "header.h"

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <limits.h> // PATH_MAX
# include <signal.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

# include <stddef.h>
# include <sys/ioctl.h>

# include <termios.h>
# include <term.h>
# include <curses.h>

extern int	g_global;

typedef struct s_content
{
	t_list	content;
	char	**cmd_flags;
}	t_content;

typedef struct s_cmdlist
{
	char				**cmds;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_minishell
{
	char		*prompt;
	char		*input;
	char		**history;
	char		**main_arr;
	int			exit;
	int			cmd_count;
	int			fdin;
	int			fdout;
	int			cmd_fd;
	t_list		**env;
	t_cmdlist	*cmdlist;
}	t_minishell;

//* ---- src DIR ----

//! in main.c
void		minishell(t_minishell *ms);

//! in frees.c
void		free_list(t_list **list);
void		free_list_malloc(t_list **list);
void		free_cmd_list(t_cmdlist *cmdlist);
void		free_arr(char **arr);
void		free_ms(t_minishell *ms);

//! in prompt.c
char		*set_prompt(t_minishell *ms);

//! in signals.c
void		signal_c(int signum);
void		signal_process_interrupt(int signum);
void		signal_init(void);
void		signal_d(t_minishell *ms);
void		post_process_signal(void);

//* ---- BuiltIn DIR ----

//! builtin_utils.c
void		change_oldpwd(t_list **lst, char *oldpwd);
char		*get_cont(const char *str, int c);
char		*get_ident(const char *str, int c);
int			get_flag(t_minishell *ms, char *ident, char *new_con, \
char *content);
t_list		*ft_envnew(void *content);

//! in cd.c
void		cd(t_minishell *ms, char **path);

//! in echo.c
void		ft_echo(char **cmd_line);

//! in env.c
void		print_lst(t_list **lst, int flag);
void		env(t_minishell *ms);

//! in exit.c
void		ft_exit(t_minishell *ms, char **path);

//! in export.c
int			valid_ident(char *s);
int			find_ident(t_list **env, char *content, char *new_cont, int flag);
void		ft_export(t_minishell *ms, char **cmd_line);

//! in pwd.c
void		pwd(void);

//! in unset.c
void		unset(t_minishell *ms, char **cmd_line);

//* ---- ms_pipex DIR ----
//! in exec_utils.c

int			is_exec(t_minishell *ms, char *cmd, char **paths);
int			is_usable(t_minishell *ms, char	*cmd, char *cmd_path, \
char **paths_array);

//! in exec.c

void		exec(t_minishell *ms, char **cmd_arr, char	**new_cmds);

//! in hdoc_utils.c

void		change_terminal(void);
int			create_file(t_minishell *ms, char *filename);
char		*create_filename(int here_num);
void		heredoc_signal(int signum);

//! in heredoc.c

char		*heredoc(t_minishell *ms, char *limiter, int here_num);

//! in ms_pipex

int			find_cmd_pos(char **main_arr, int pos);
void		get_exit_status(t_minishell *ms, pid_t pid, int cmds_run);
void		child(t_minishell *ms, int *pipe_fd, int cmds_run, int pos);
void		parent(t_minishell *ms, int *pipe_fd, int cmds_run, int pos);

//* ---- Parser DIR ----

//! in ms_split.c

int			parser_op(char c);
int			countw(char *str);
char		*split_tmp(t_minishell *ms, char *str, int word_len);
int			get_wordl(char *str);
char		**ms_split(t_minishell *ms, char *str);

//! in parser_utils.c
int			quotes(char *str, char c, int i);
int			space_tab(char *str, int i);
int			envar(char *str, int i);
int			others(char *str, int i);

//* --- Replacer DIR ----
//! in replace.c

char		*replace_str(t_minishell *ms, char *str);
char		**replaced_arr(t_minishell *ms);

//! in replace_utils.c

char		*var_iter(t_minishell *ms, char *var);
char		*var_str(t_list *env, char *var);

//* ---- Syntax DIR ----
//! in syntax_err.c
int			redir_syntax(char *str);
int			double_redir_syntax(char *str);
int			dollar_syntax(char *str);
int			sucession_syntax(char *str);
int			token_syntax(char *str);

//! in syntax.c
int			syntax_error(t_minishell *ms);

//* ---- Utils DIR ----
//! in arr_utils.c

int			arr_size(char **arr);

/**
 * Duplicate a string array
 * 
 * @param ms A pointer to the minishell structure
 * @param old The string array to duplicate
 * @return A pointer to the duplicated string array
 * @note Allocates memory dynamically, caller is responsible for freeing it
 * @warning If memory allocation fails, it invokes error() with error type 2
 */
char		**ft_arrdup(t_minishell *ms, char **old);
char		**list_to_array(t_minishell *ms, t_list **list);
void		print_arr(char *str, char **arr);

//! in check_cmd.c
int			isbuiltin(char *str);
void		built_in(t_minishell *ms, char **cmd_flags);

//! in cmd_utils.c

void		print_arr(char *str, char **arr);
void		print_cmdlist(t_cmdlist *cmdlist);
int			cmd_count(char **arr);
char		**cmd_with_flags(t_minishell *ms, char **arr, int pos);

//! in cmd_utils2.c
t_cmdlist	*cmdlist_last(t_cmdlist *lst);
void		cmdlist_add_back(t_cmdlist **lst, t_cmdlist *new);

//! in error.c

/**
 * Handle all errors
 * 
 * @param ms Pointer to the minishell structure
 * @param op Type of error message
 * @param arg (optional) Additional error message
 * @param plus (optional) cmdName
 * @note Type 2: Malloc failure error, prints the provided message 'arg' and \
 * exits with exit code 12 after freeing memory
 * @note Type 3: Custom error, prints the provided message 'arg' and exits with \
 *  the minishell exit code
 */
void		error(t_minishell *ms, int op, char *arg, char *plus);
void		error_message(t_minishell *ms, char *mess, char *plus);
int			open_error(t_minishell *ms, char *filename, int child);
void		pipe_error(t_minishell *ms, int *pipe_fd);
void		fork_error(t_minishell *ms, int *pipe_fd);

//! in error1.c
int			token_message(char token);
void		heredoc_eof(char *limiter);

//! in free2.c

/**
 * @note Just free 2 diff strings so save 1 line
*/
void		free2(char *str, char *str1);
void		free_hdoc(t_minishell *ms);

//! in inits.c

int			var_init(t_minishell *ms);

//! in quotes_utils.c

int			skip_quotes(char *str, int pos);
char		*add_quotes(char *str, char c);
char		*remove_quotes(char *str);
char		**rm_all_quotes(char **cmds);
//void		rm_all_quotes(char **cmds);

//! in redirect.c

void		reset_fds(t_minishell *ms);
void		close_fd(int *fd);
int			redirect(t_minishell *ms, char **main_arr, int pos, int child);

//! in str_utils.c

int			strlen_chr(char *str, char c);
int			strchr_malloc(char *s, char c);
char		*str_front_trim(char *str, char *trim);
int			strcmp_nochr(char *s1, char *s2, char c);
char		*ft_strndup(char *str, int len);

#endif