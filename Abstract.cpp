#include "Abstract.hpp"
#include <iostream>
#include <fstream>
using namespace std;
// Конструкторы и деструктор
AbstractCard::AbstractCard() : name(""), balance(0.0), transCount(0), transactions(nullptr) {}

AbstractCard::AbstractCard(const std::string& name, float balance)
    : name(name), balance(balance), transCount(0), transactions(nullptr) {}

AbstractCard::~AbstractCard() {
    delete[] transactions;
}


std::string AbstractCard::getName() const {
    return name;
}

void AbstractCard::setName(const std::string& name) {
    this->name = name;
}

float AbstractCard::getBalance() const {
    return balance;
}

void AbstractCard::setBalance(float balance) {
    this->balance = balance;
}


void AbstractCard::addTransaction(int day, int month, int week, float sum, const std::string& category) {
    if ((sum > 0) && (category == "clothes" || category == "food" || category == "travels")) {
        Transaction* newTransactions = new Transaction[transCount + 1];
        for (int i = 0; i < transCount; ++i) {
            newTransactions[i] = transactions[i];
        }
        newTransactions[transCount] = Transaction(day, month, week, sum, category);
        delete[] transactions;
        transactions = newTransactions;
        ++transCount;

        balance -= sum;
        std::cout << "Operation was successful!" << std::endl;
        if (balance == 0) {
            std::cout << "Your account is empty!" << std::endl;
        }
        else if (balance < 0) {
            std::cout << "You're in a debt!" << std::endl;
        }
    }
    else {
        std::cout << "Wrong input!" << std::endl;
    }
}

void AbstractCard::addSum(float s) {
    if (s < 0) {
        balance += s;
    }
    else {
        std::cout << "Wrong input!" << std::endl;
    }
}

void AbstractCard::show() const {
    std::cout << "Name: " << name << ", Balance: " << balance << ", Q-ty trans-s: " << transCount << std::endl;
}


void AbstractCard::makeOrder(const std::string& per, int num) {
    if ((per=="day"||per=="week"||per=="month")&&(num>0)){
        string categories[] = {"clothes", "food", "travels"};
        ofstream fout;
        string path="/Users/michalis04/Desktop/XCODE NEW/ProjectFile.pages";
        fout.open(path, ofstream::app);
        if(!fout.is_open()){
            cout<<"Error opening of file! Data won`t be noticed!"<<endl;
        }
        else
        {
            for (const string& category : categories) {
                for (int i = 0; i < transCount; ++i) {
                    if ((per == "day" && transactions[i].getDay()==num)||(per=="week"&&transactions[i].getWeek()==num)||
                        (per == "month" && transactions[i].getMonth()==num)) {
                        if (transactions[i].getCategory()==category) {
                            cout << "Категория: " << category << ", Сумма: " << transactions[i].getSum() << endl;
                            fout << "Категория: " << category << ", Сумма: " << transactions[i].getSum() << endl;
                        }
                    }
                }
            }
           
        }
        fout.close();
           
    }
    else{
        cout<<"Wrong input!"<<endl;
    }}


void AbstractCard::makeRating(const std::string& per, int num) {
    if ((per=="week"||per=="month")&&(num>0)){
        int size=3;
        Transaction* top = new Transaction[size];
        Transaction* tempTransactions = new Transaction[transCount];
                for (int i = 0; i < transCount; ++i) {
                    tempTransactions[i] = transactions[i];
                }
        string categories[] = {"clothes", "food", "travels"};
        Transaction temp;
        for (int i=0;i<transCount;i++){
            for (int j=0;j<transCount-1-i;j++){
                if (tempTransactions[j].getSum()<tempTransactions[j+1].getSum()){
                    temp=tempTransactions[j];
                    tempTransactions[j]=tempTransactions[j+1];
                    tempTransactions[j+1]=temp;
                }
            }
        }
        
        int count=0;
        for (int i=0;((i<transCount)&&(count<3));i++){
            if ((per=="week")&&(tempTransactions[i].getWeek()==num)){
                top[i]=tempTransactions[i];
                count++;
            }
           else if((per=="month")&&(tempTransactions[i].getMonth()==num)){
               top[i]=tempTransactions[i];
               count++;
           }
        }
        
                         
        ofstream fout;
        string path="/Users/michalis04/Desktop/XCODE NEW/ProjectFile.pages";
        fout.open(path, ofstream::app);
        if(!fout.is_open()){
            cout<<"Error opening of file! Data won`t be noticed!"<<endl;
        }
        else
        {
            cout<<"Sort by sum for "<<per<<": "<<endl;
            fout<<"Sort by sum for "<<per<<": "<<endl;
            for (int i=0;i<size;i++){
                cout<<"Top "<<i+1<<": "<<tempTransactions[i].getSum()<<" - "<<tempTransactions[i].getCategory()<<endl;
                fout<<"Top "<<i+1<<": "<<tempTransactions[i].getSum()<<" - "<<tempTransactions[i].getCategory()<<endl;
            }
         
            cout<<"Sort by category for "<<per<<": "<<endl;
            fout<<"Sort by category for "<<per<<": "<<endl;
            cout<<"Input your category: ";
            string category;
            cin>>category;
                 int count1=0;
            for (int j=0;((j<transCount)&&(count1<3));j++){
                if ((per=="week")&&(tempTransactions[j].getWeek()==num)&&(tempTransactions[j].getCategory()==category)){
                    top[j]=tempTransactions[j];
                    cout<<"Top "<<count1+1<<": "<<top[j].getSum()<<" - "<<top[j].getCategory()<<endl;
                    fout<<"Top "<<count1+1<<": "<<top[j].getSum()<<" - "<<top[j].getCategory()<<endl;
                    count1++;
                }
                else if((per=="month")&&(tempTransactions[j].getMonth()==num)&&(tempTransactions[j].getCategory()==category)){
                    top[j]=tempTransactions[j];
                    cout<<"Top "<<count1+1<<": "<<top[j].getSum()<<" - "<<top[j].getCategory()<<endl;
                    fout<<"Top "<<count1+1<<": "<<top[j].getSum()<<" - "<<top[j].getCategory()<<endl;
                    count1++;
                }
                    
                }
            cout<<endl;
            cout<<endl;
        }
        fout.close();
           
        if(top!=nullptr){
            delete[]top;
        }
        if(tempTransactions!=nullptr){
            delete[]tempTransactions;
        }
      

                }
    else{
        cout<<"Wrong input!"<<endl;
        return;
    }
}

