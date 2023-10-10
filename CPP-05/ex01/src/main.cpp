/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:42:15 by fwong             #+#    #+#             */
/*   Updated: 2023/10/09 23:05:17 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int    main(){
    Bureaucrat    John = Bureaucrat("John", 103);
    Form myForm = Form("myForm", 100, 90);

    std::cout << John << std::endl;
    std::cout << myForm << std::endl;
    try {
        Form badForm = Form("badForm", 170, 90);
        std::cout << badForm << std::endl;
    }
    catch (std::exception const & e)
    { std::cout << e.what() << std::endl; }
    
    try { myForm.beSigned(John); }
    catch (std::exception const & e) { std::cout << e.what() << std::endl; }
    
    John.incrementGrade();
    std::cout << John << std::endl;
    
    John.incrementGrade();
    std::cout << John << std::endl;
    
    John.incrementGrade();
    std::cout << John << std::endl;
    
    try{ myForm.beSigned(John); }
    catch (std::exception const & e) { std::cout << e.what() << std::endl; }
    
    try { myForm.beSigned(John); }
    catch (std::exception const & e) { std::cout << e.what() << std::endl; }
    return (0);
}
	
