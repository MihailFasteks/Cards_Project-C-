//
//  main.cpp
//  Cards
//
//  Created by Michalis on 17.12.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Abstract.hpp"
#include "Transaction.hpp"
#include "Card.hpp"
#include "Wallet.hpp"
using namespace std;


int main() {

    Card card1("Gold", 25.0);
    card1.show();
    
    card1.addSum(77.25);
    card1.show();
    
    card1.addTransaction(1, 1, 4, 220.0, "clothes");
    card1.addTransaction(1, 2, 4, 100.0, "clothes");
    card1.addTransaction(1, 2, 4, 200.0, "clothes");
    card1.addTransaction(1, 2, 4, 400.0, "clothes");
    card1.addTransaction(1, 3, 4, 35000.0, "clothes");

    card1.makeOrder("day", 1);
    card1.makeRating("week", 4);
    return 0;
}
