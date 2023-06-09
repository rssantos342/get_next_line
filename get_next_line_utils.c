/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:43:04 by ride-sou          #+#    #+#             */
/*   Updated: 2023/05/09 12:35:32 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *temp, char line_break)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i] != '\0')
	{
		if (temp[i] == line_break)
			return (&temp[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *temp, char *buffer)
{
	int		i;
	int		j;
	char	*strjoin;

	i = -1;
	j = 0;
	if (!temp)
	{
		temp = malloc(sizeof(char) * 1);
		temp[0] = '\0';
	}
	if (!temp || !buffer)
		return (NULL);
	strjoin = malloc(sizeof(char) *((ft_strlen(temp) + ft_strlen(buffer)) + 1));
	if (!strjoin)
		return (NULL);
	while (temp[++i] != '\0')
		strjoin[i] = temp[i];
	while (buffer[j] != '\0')
		strjoin[i++] = buffer[j++];
	strjoin[i] = '\0';
	free(temp);
	return (strjoin);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*line;

	i = 0;
	if (temp[i] == 0)
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == 0)
	{
		free(temp);
		return (NULL);
	}
	new_temp = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!new_temp)
		return (NULL);
	i = i + 1;
	while (temp[i] != '\0')
		new_temp[j++] = temp[i++];
	new_temp[j] = '\0';
	free(temp);
	return (new_temp);
}
