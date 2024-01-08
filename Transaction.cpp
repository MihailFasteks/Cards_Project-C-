#include "Transaction.hpp"

Transaction::Transaction() : day(0), month(0), week(0), sum(0.0) {}

Transaction::Transaction(int day, int month, int week, float sum, std::string category)
    : day(day), month(month), week(week), sum(sum), category(category) {}

int Transaction::getDay() const {
    return day;
}

int Transaction::getWeek() const {
    return week;
}

int Transaction::getMonth() const {
    return month;
}

float Transaction::getSum() const {
    return sum;
}

std::string Transaction::getCategory() const {
    return category;
}

void Transaction::setSum(float s) {
    sum = s;
}
