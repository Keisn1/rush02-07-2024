#include "rush02.h"

void ft_putstr(char *str) {
    while (*str)
        ft_putchar(*str++);
}

void ft_putchar(char c) {
    write(STDOUT_FILENO, &c, 1);
}


int	ft_strcmp(char *s1, char *s2)
{
	int	sum;
	int	idx;

	sum = 0;
	idx = 0;
	while (1)
	{
		sum = s1[idx] - s2[idx];
		if (s1[idx] == '\0' || s2[idx] == '\0' || sum)
			return (sum);
		idx++;
	}
}

int ft_strlen(char *s) {
    int count = 0;
    while (s[count]) {
        count++;
    }
    return count;
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	if (size == 0)
		return (ft_strlen(src));
	count = 0;
	while (src[count] != '\0' && (count < size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}

void	ft_putnbr(int nb)
{
	int		arr[10];
	int		idx;
	char	c;

	if (nb < 0)
		write(STDOUT_FILENO, "-", 1);
	idx = 0;
	arr[idx++] = abs(nb % 10);
	nb = abs(nb / 10);
	while (nb > 0)
	{
		arr[idx++] = nb % 10;
		nb /= 10;
	}
	while (--idx >= 0)
	{
		c = arr[idx] + '0';
		write(STDOUT_FILENO, &c, 1);
	}
}
