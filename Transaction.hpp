//
//  Transaction.hpp
//  Cards
//
//  Created by Michalis on 19.12.2023.
//

#ifndef Transaction_hpp
#define Transaction_hpp

#include <string>

class Transaction {
public:
    Transaction();
    Transaction(int day, int month, int week, float sum, std::string category);
    
    int getDay() const;
    int getWeek() const;
    int getMonth() const;
    float getSum() const;
    std::string getCategory() const;
    
    void setSum(float s);

private:
    int day;
    int month;
    int week;
    float sum;
    std::string category;
};

#endif /* Transaction_hpp */




