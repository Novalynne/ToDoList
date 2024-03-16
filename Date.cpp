//
// Created by schir on 13/02/2024.
//

#include "Date.h"
#include "stdexcept"
#include <iostream>
using namespace std;

//COSTRUTTORE
Date::Date(int day, int month, int year) : day(day), month(month), year(year){
    if (!this->is_date_correct()){
        throw std::invalid_argument("Date not valid.");
    }
}

//IS EQUAL
bool Date::is_equal(Date b) {
    if(day==b.day && month==b.month && year==b.year){
        return true;
    }
    else{
        return false;
    }
}

//DATE CORRECT?
bool Date::is_date_correct() {
    //controllo prima che la data stia nel max intervallo di mesi e giorni
    //controllo mese
    bool valid=true;
    if(month>12 || month<1){
        cout<<"Month not valid."<<endl;
        valid=false;
    }
    //controllo giorno
    if(day<1 || day>31){
        cout<<"Day not valid."<<endl;
        valid=false;
    }
    //ora controllo i mesi che hanno massimo 30 giorni
    if((month==4 || month==6 || month==9 || month==11) && day>30){
        cout<< "This month " << month << " has a max of 30 days." <<endl;
        valid=false;
    }
    else if(month==2){  //ora controllo febbraio a seconda se l'anno è bisestile o no.
        if(((year % 4 ==0 && year % 100 !=0) || (year % 400 ==0)) && day>29){
            cout<<"Febuary in a leap year has a max of 29 days."<<endl;
            valid=false;
        }
        else if(day>28){
            cout<<"Febuary in a normal year has a max of 28 days."<<endl;
            valid=false;
        }
    }
    return valid;
}

// GET E SET
int Date::getDay() const {
    return day;
}
void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}
void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}
void Date::setYear(int year) {
    Date::year = year;
}