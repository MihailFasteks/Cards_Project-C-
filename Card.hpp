#ifndef CARD_HPP
#define CARD_HPP

#include "Abstract.hpp"

class Card : public AbstractCard {
public:
    Card(const std::string& name, float balance);
};

#endif // CARD_HPP
