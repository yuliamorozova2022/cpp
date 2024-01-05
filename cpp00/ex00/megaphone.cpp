/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliamorozova <yuliamorozova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:38:50 by ymorozov          #+#    #+#             */
/*   Updated: 2023/09/22 15:46:37 by yuliamorozo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_mega(std::string str)
{
	int	i = -1;
	while(str[++i])
	{
		str[i] = toupper(str[i]);
		std::cout << str[i];
	}
}

int	main(int argc, char **argv)
{
	int i = 0;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(argv[++i])
			ft_mega(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}