#ifndef ABSTRACTCARD_HPP
#define ABSTRACTCARD_HPP

#include <string>
#include "Transaction.hpp"

class AbstractCard {
private:
    std::string name;
    float balance;
    int transCount;
    Transaction* transactions;

public:
    AbstractCard();
    AbstractCard(const std::string& name, float balance);
    ~AbstractCard();

    std::string getName() const;
    void setName(const std::string& name);
    float getBalance() const;
    void setBalance(float balance);
    void addTransaction(int day, int month, int week, float sum, const std::string& category);
    void addSum(float s);
    void show() const;
    void makeOrder(const std::string& per, int num);
    void makeRating(const std::string& per, int num);
};

#endif // ABSTRACTCARD_HPP
