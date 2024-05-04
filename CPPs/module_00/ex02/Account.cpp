/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-avel <mde-avel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:27:11 by mde-avel          #+#    #+#             */
/*   Updated: 2024/04/27 13:58:04 by mde-avel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
int		_accountIndex = 0;
int		_amount = 0;
int		_nbDeposits = 0;
int		_nbWithdrawals = 0;

Account::Account( void ) {}

//[19920104_091532] index:0;amount:42;created
Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";created" << std::endl;
	_nbAccounts++;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";closed" << std::endl;
}

// std::cout << "[19920104_091532] ";
// 1992 01 04 _ 09:15:32
//  %Y  %m %d _ %H %M %S
void	Account::_displayTimestamp( void )
{
	char timeString[16];
	std::time_t tt = std::time(0);
	
	std::strftime(timeString, sizeof(timeString), "%Y%m%d_%H%M%S", std::localtime(&tt));
	std::cout << "[" << timeString << "] ";
}

int	Account::getNbAccounts( void )      {return (Account::_nbAccounts);}
int	Account::getTotalAmount( void )     {return (Account::_totalAmount);}
int	Account::getNbDeposits( void )      {return (Account::_totalNbDeposits);}
int	Account::getNbWithdrawals( void )   {return (Account::_totalNbWithdrawals);}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << getTotalAmount() 
			  << ";deposits:" << getNbDeposits() 
			  << ";withdrawals:" << getNbWithdrawals() 
			  << std::endl;             
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit ) 
{
	int	previous_amount = _amount;

	_displayTimestamp();
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits ++;
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << previous_amount 
			  << ";deposit:" << deposit 
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;  
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal ) 
{
	int	previous_amount = _amount;

	_displayTimestamp();
	if(checkAmount() < withdrawal)
	{
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << previous_amount 
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals ++;
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << previous_amount 
		  		  << ";withdrawal:" << withdrawal 
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
		return true;
	}
}

int		Account::checkAmount( void ) const {return (_amount);}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount 
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;  
}