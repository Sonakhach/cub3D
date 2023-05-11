/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:49:41 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/27 11:59:49 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	size_t	i;
// 	size_t	j;

// 	i = ft_strlen(s1);
// 	j = ft_strlen(s2);
// 	ptr = (char *)malloc((i + j + 1) * sizeof(char));
// 	if (ptr == NULL)
// 		return (0);
// 	if (s1)
// 	{
// 		while (s1 && *s1 != '\0')
// 			*ptr++ = *s1++;
// 	}
// 	if (s2)
// 	{
// 		while (s2 && *s2 != '\0')
// 			*ptr++ = *s2++;
// 	}
// 	*ptr = '\0';
// 	return (ptr - i - j);
// }

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] && s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] && s2)
		ptr[i++] = s2[j++];
	if (s1 != NULL)
		free(s1);
	ptr[i] = 0;
	return (ptr);
}
