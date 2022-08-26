/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chashin <chashin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:58:55 by chashin           #+#    #+#             */
/*   Updated: 2022/06/08 19:30:00 by chashin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"ops.h"
#include"ft_funcs.h"

int	do_op(int a, int b, char op)
{
	int	num;
	int	(*func[5])(int, int);

	num = 0;
	func[0] = &add;
	func[1] = &sub;
	func[2] = &mul;
	func[3] = &div;
	func[4] = &mod;
	if (op == '+')
		num = func[0](a, b);
	else if (op == '-')
		num = func[1](a, b);
	else if (op == '*')
		num = func[2](a, b);
	else if (op == '/')
		num = func[3](a, b);
	else if (op == '%')
		num = func[4](a, b);
	else
		write(1, "0\n", 2);
	return (num);
}

int	main(int argc, char **argv)
{
	char	op;
	int		num;

	if (argc != 4)
		return (0);
	op = *argv[2];
	if (ft_strlen(argv[2]) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if ((op == '/' || op == '%') && ft_atoi(argv[3]) == 0)
	{
		if (op == '/')
			write(1, "Stop : division by zero\n", 24);
		if (op == '%')
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	num = do_op(ft_atoi(argv[1]), ft_atoi(argv[3]), op);
	if (op != '+' && op != '-' && op != '*' && op != '%' && op != '/')
		return (0);
	ft_putnbr(num);
	write(1, "\n", 1);
}
