/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:46 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 13:34:32 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			isinstr(char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void		free_data(t_fnc_data *data)
{
	free(data->string);
	free(data);
}

char		*ft_strdup(char *s1)
{
	char	*s1bis;
	size_t	i;

	if (!(s1))
		return (s1bis = ft_strdup("(null)"));
	i = ft_strlen(s1);
	if (!(s1bis = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1bis[i] = s1[i];
		i++;
	}
	s1bis[i] = '\0';
	return (s1bis);
}

int			free_all_return(t_fnc_data *data, int i)
{
	free_data(data);
	return (i);
}
