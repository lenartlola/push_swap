/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabir <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:29:27 by hsabir            #+#    #+#             */
/*   Updated: 2021/10/20 11:35:51 by hsabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntword(const char *str, char c)
{
	size_t	cnt;
	size_t	flag;

	cnt = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (cnt);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strndup(const char *s, size_t num)
{
	char	*word;
	char	*temp;

	word = (char *)malloc(sizeof(char) * (num + 1));
	if (!word)
		return (0);
	temp = word;
	while (num-- > 0)
		*temp++ = *s++;
	*temp = '\0';
	return (word);
}

static void	ft_free_str(char **s, int i)
{
	while (i--)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	nb;
	size_t	cnt;
	char	**result;

	if (s == NULL)
		return (0);
	cnt = ft_cntword(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!result)
		return (0);
	nb = -1;
	while (++nb < cnt)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[nb] = ft_strndup(s, ft_wordlen(s, c));
		if (!result[nb])
		{
			ft_free_str(result, nb - 1);
			return (0);
		}
		s += ft_wordlen(s, c);
	}
	result[cnt] = NULL;
	return (result);
}
