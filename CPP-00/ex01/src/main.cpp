/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:56:02 by fwong             #+#    #+#             */
/*   Updated: 2023/06/26 14:05:13 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string input;
	std::string id;

	while (1)
	{
		const std::string cases[3] = { "ADD", "SEARCH", "EXIT" };
		int i = 0;
		
		getline(std::cin, input);
		if (std::cin.fail()) {
            std::cin.clear();
            return (1);
        }
		while (i < 3 && input.compare(cases[i]))
		{
			std::cout << cases[i] << std::endl;
			i++;
		}
		switch (i)
		{
			case 0:
				phonebook.add();
				break;
			case 1:
				phonebook.search();
				break;
			case 2:
				exit(0);
				break ;
		}
	}
}