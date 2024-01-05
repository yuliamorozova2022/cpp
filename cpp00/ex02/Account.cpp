// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //
#include "Account.hpp"
/*
public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

}

*/
#include <ctime>
#include <iostream>
//#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	std::cout << "["
			<< (1900 + now->tm_year)
			<< (1+ now->tm_mon)
			<< (now->tm_mday) << "_"
			<< (now->tm_hour)
			<< (now->tm_min)
			<< (now->tm_sec)<< "]";
}

Account::Account(int initial_deposit) {
	//counter = 0;
    //std::cout << Account._displayTimestamp() << " index:"<< std::endl;
    //std::cout << "  [ADD]   [SEARCH]    [EXIT]" << std::endl;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount 
			<< ";created" << std::endl;
}

Account::~Account() {
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
    std::cout << " index:" << _accountIndex 
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
	return(_nbAccounts);
}

int Account::getTotalAmount( void ) {
	return(_totalAmount);
}

int Account::getNbDeposits( void ) {
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";p_amount:" << _amount;
	if (withdrawal > checkAmount()) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const {
	return (_amount);
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
    std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}