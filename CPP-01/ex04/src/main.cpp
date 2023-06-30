/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:23:14 by fwong             #+#    #+#             */
/*   Updated: 2023/06/30 18:30:25 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
	
	std::string toReplace = argv[2];
	std::string replaceWith = argv[3];
	std::ofstream outfile;
	std::ifstream infile;
	std::string line;
	
	infile.open(argv[1]);
	if (argc != 4)
	{
		std::cout << "Usage: ./sed [filename] [string to replace] [string to replace with]" << std::endl;
		return 1;
	}
	if (infile.is_open() == false)
	{
		std::cout << "Error: File not found." << std::endl;
		return 1;
	}
	outfile.open((argv[1] + std::string(".replace")).c_str());
	if (infile.is_open() == false)
	{
		std::cout << "Error: File not found." << std::endl;
		return 1;
	}
	while (getline(infile, line))
	{
		size_t prev_pos = 0;
		size_t pos = line.find(toReplace);
		while (pos != std::string::npos)
		{
			line.erase(pos, toReplace.length());
			line.insert(pos, replaceWith);
			prev_pos = pos + toReplace.length();
			pos = line.find(toReplace, prev_pos);
		}
		outfile << line << std::endl;
	}
	outfile.close();
	infile.close();
	return 0;
}