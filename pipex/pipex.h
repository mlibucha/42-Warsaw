/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:06:41 by e                 #+#    #+#             */
/*   Updated: 2025/04/15 00:07:40 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		here_doc;
	int		cmd_start;
	int		cmd_end;
	int		infile_fd;
	int		outfile_fd;
}	t_pipex;

int		execute_pipeline(t_pipex *pipex, char **argv, char **envp);
void	execute_command(char *cmd, char **envp);
char	*file_path(char *cmd, char **envp);
char	**ft_split(char const *str, char c);
void	ft_free(char **strs);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *c);
#endif