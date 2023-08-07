/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:25:24 by fwong             #+#    #+#             */
/*   Updated: 2023/07/12 18:25:24 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain {

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		std::string setIdea(std::string idea, int index);
		std::string getIdea(int index) const;
		
	private:
		std::string _ideas[100];
};

#endif