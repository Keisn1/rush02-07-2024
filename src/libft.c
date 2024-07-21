/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:04:20 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:04:23 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putstr_err(char *str)
{
	while (*str)
		ft_putchar_err(*str++);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putchar_err(char c)
{
	write(STDERR_FILENO, &c, 1);
}

char* ft_strchr(char* str, int c)
{
   while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return 0;

}

char	*ft_strdup(char *src)
{
	char	*res_o;
	char	*res;
	int		len;

	src = skip_space(src);

	len = ft_strlen(src);
	res = malloc((len + 1) * sizeof(char));
	if (res == (void *)0)
		return (res);
	res_o = res;
	while (*src)
		*res++ = *src++;
	*res = '\0';
	return (res_o);
}
