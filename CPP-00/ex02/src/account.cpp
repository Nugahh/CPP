/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:12:58 by fwong             #+#    #+#             */
/*   Updated: 2023/06/23 23:01:47 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0) {}

Account::~Account(void) {}

void Account::_displayTimestamp(){
	
	char timestamp[16];
	std::time_t rawtime;
	std::time(&rawtime);

	struct std::tm* timeinfo;
	
	timeinfo = std::localtime(&rawtime);

	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << timestamp << "]";
}

void Account::displayAccountsInfos(){
	
	std::cout << _displayTimestamp() << " " << "accounts:" <<  _nbAccounts;
	std::cout << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
}