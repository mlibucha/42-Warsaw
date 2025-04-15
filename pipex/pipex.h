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
# include <sys/wait.h>
# include <time.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_pip
{
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	char	*cmd1;
	char	*cmd2;

}	t_pip;

int		forking_your_mom(t_pip pip, char **envp);
char	**ft_split(char const *str, char c);
void	ft_free(char **strs);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *c);
#endif