/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:14:32 by ahassan           #+#    #+#             */
/*   Updated: 2023/04/10 20:01:52 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void to_upper(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
		std::cout << (char)toupper(str[i]);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
			to_upper(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}