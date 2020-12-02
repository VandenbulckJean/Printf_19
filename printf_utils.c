/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:50 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/01 13:21:52 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int		isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strjoin_back(char *s1, char *s2)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	if (!(newline = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	temp = newline;
	while (s1[i])
		*temp++ = s1[i++];
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	free(s1);
	return (newline);
}

char	*ft_strjoin_front(char *s1, char *s2)
{
	char	*newline;
	char	*temp;
	int		i;

	i = 0;
	if (!(newline = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	temp = newline;
	while (*s2)
		*temp++ = *s2++;
	while (s1[i])
		*temp++ = s1[i++];
	*temp = '\0';
	free(s1);
	return (newline);
}
