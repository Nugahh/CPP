/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:12:58 by fwong             #+#    #+#             */
/*   Updated: 2023/06/26 14:01:26 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0) {

	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount << ";created" << std::endl;
	_totalAmount += initial_deposit;
	}

Account::~Account(void) {
	
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(){ return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account:: getNbWithdrawals() { return _totalNbWithdrawals; }

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
	
	_displayTimestamp();
	std::cout << " accounts:" <<  getNbAccounts();
	std::cout << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit){

	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount + deposit;
	std::cout << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
	
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal){

	if (_amount - withdrawal >= 0)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount - withdrawal;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals += _nbWithdrawals;
		_totalAmount -= withdrawal;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int Account::checkAmount() const{

	return _amount;
}

void Account::displayStatus() const{
	
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}