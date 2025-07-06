#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts++;
    this->_accountIndex = _nbAccounts;
    this->_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex - 1
    << ";amount:" << this->_amount
    << ";created"
    << std::endl;
};

Account::~Account(void)
{
    // Destructor does not need to do anything for this example
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex - 1
    << ";amount:" << this->_amount
    << ";closed"
    << std::endl;
};

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::makeDeposit(int deposit)
{
    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex - 1
    << ";p_amount:" << (_amount - deposit)
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits
    << std::endl;
}

void Account::_displayTimestamp( void )
{
    std::time_t seed = std::time(0);
    std::tm *now = std::localtime(&seed);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);
    std::cout << "[" << buffer << "] ";
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout
    << "accounts:" << Account::_nbAccounts
    << ";total:" << Account::_totalAmount
    << ";deposits:" << Account::_totalNbDeposits
    << ";withdrawals:" << Account::_totalNbWithdrawals
    << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex - 1
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > this->_amount)
    {
        _displayTimestamp();
        std::cout
        << "index:" << this->_accountIndex - 1
        << ";p_amount:" << this->_amount
        << ";withdrawal:refused"
        << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
    _displayTimestamp();
    std::cout
    << "index:" << this->_accountIndex - 1
    << ";p_amount:" << this->_amount + withdrawal
    << ";withdrawal:" << withdrawal
    << ";amount:" << this->_amount
    << ";nb_withdrawals:" << _nbWithdrawals
    << std::endl;
    return true;
}