/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:15:45 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/13 14:46:51 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parseformat(va_list args, const char *format)
{
	int	printed_chars;

	printed_chars = 0;
	if (*format == 'c')
		printed_chars += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		printed_chars += ft_printstr(va_arg(args, char *));
	else if (*format == 'p')
		printed_chars += ft_printptr(va_arg(args, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		printed_chars += ft_printnbr(va_arg(args, int));
	else if (*format == 'u')
		printed_chars += ft_printnbrui(va_arg(args, unsigned int));
	else if (*format == 'x')
		printed_chars += ft_print_lowerhex(va_arg(args, unsigned int));
	else if (*format == 'X')
		printed_chars += ft_print_upperhex(va_arg(args, unsigned int));
	else if (*format == '%')
		printed_chars += ft_putchar('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_chars += ft_parseformat(args, format);
			format++;
		}
		else
			printed_chars += ft_putchar(*format++);
	}
	va_end(args);
	return (printed_chars);
}

/* int	main(void)
{
	void	*test;

	test = NULL;
	printf("ft_printf : %d\nprintf : %d", ft_printf(" %p %p \n", &test, &test),
		printf(" %p %p \n", &test, &test));
} */
