#ifndef WALLET_HPP
#define WALLET_HPP

#include "Abstract.hpp"

class Wallet : public AbstractCard {
public:
    Wallet(const std::string& name, float balance);
};

#endif // WALLET_HPP
