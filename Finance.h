#ifndef FINANCE_H
#define FINANCE_H
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "IncomesXml.h"
#include "Expense.h"
#include "ExpensesXml.h"


using namespace std;
class Finance
{
private:
    vector<Income> incomes;
    int idOfLastIncome;
    IncomesXml incomesXml;
    vector<Expense> expenses;
    int idOfLastExpense;
    ExpensesXml expensesXml;
public:
    Finance(int loggedUserId);
    virtual ~Finance();
    void addIncome(int userLoggedId);
    void addExpense(int userLoggedId);
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displayAnyPeriodBalance();
private:
    Income giveNewIncomeData(int userLoggedId);
    Expense giveNewExpenseData(int userLoggedId);
    int getDaysCount(int month, int year);
    string getTodaysDate();
    string getDateOfLastDayCurrentMonth();
    string getDateOfFirstDayCurrentMonth();
    string getDateOfFirstDayPreviousMonth();
    string getDateOfLastDayPreviousMonth();
    string intToStringWithZero(int intCount);
    void displayIncomeData(Income income);
    void displayExpenseData(Expense expense);
    double checkIncomeData(Income income, string minDate, string maxDate);
    double checkExpenseData(Expense expense, string minDate, string maxDate);
    double displayAllIncomes(string minDate, string maxDate);
    double displayAllExpenses(string minDate, string maxDate);
    void sortIncomesByDate(vector<Income> &incomes);
    void sortExpensesByDate(vector<Expense> &expenses);
};

#endif // FINANCE_H
