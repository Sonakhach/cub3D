/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:49:16 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/27 16:37:21 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char	*s1)
{
	char	*new;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	new = (char *)malloc((i + 1) * sizeof(*s1));
	if (new == NULL)
		return (0);
	else
	{
		if (!s1 || !new)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
}
