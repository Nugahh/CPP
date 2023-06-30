/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:40:29 by fwong             #+#    #+#             */
/*   Updated: 2023/06/30 18:00:49 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <fstream>
#include <string>

class Harl {
	
	public:
		Harl();
		~Harl();

		void complain(std::string level);

	private:
		void debug();
		void info();
		void warning();
		void error();
};

#endif