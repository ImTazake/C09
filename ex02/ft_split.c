/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisilva <tisilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 08:58:20 by tisilva           #+#    #+#             */
/*   Updated: 2026/08/12 12:01:46 by tisilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_get_word(char *str, char *charset, int *pos)
{
	int		start;
	int		len;
	int		i;
	char	*word;

	while (str[*pos] && ft_is_charset(str[*pos], charset))
		(*pos)++;
	start = *pos;
	while (str[*pos] && !ft_is_charset(str[*pos], charset))
		(*pos)++;
	len = *pos - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		count;
	int		i;
	int		pos;

	count = ft_count_words(str, charset);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < count)
	{
		result[i] = ft_get_word(str, charset, &pos);
		if (!result[i])
			return (NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	**result;
// 	int		i;

// 	result = ft_split("ola,como, estás", ", ");
// 	if (!result)
// 		return (1);

// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("Palavra %d: %s\n", i + 1, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	return (0);
// }