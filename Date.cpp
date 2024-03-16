//
// Created by schir on 13/02/2024.
//

#include "Date.h"
#include "stdexcept"
#include <iostream>
using namespace std;

//COSTRUTTORE
Date::Date(int day, int month, int year) : day(day), month(month), year(year){
    try{
        this->is_date_correct();
    }
    catch(const invalid_argument& e){
        cout<< e.what() << endl;
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
void Date::is_date_correct() {
    //controllo prima che la data stia nel max intervallo di mesi e giorni
    //controllo mese
    if(month>12 || month<1){
        throw invalid_argument("Invalid month");
    }
    //controllo giorno
    if(day<1 || day>31){
        throw invalid_argument("Invalid day");
    }
    //ora controllo i mesi che hanno massimo 30 giorni
    if((month==4 || month==6 || month==9 || month==11) && day>30){
        throw invalid_argument("Invalid month, this month has 30 days.");
    }
    else if(month==2){  //ora controllo febbraio a seconda se l'anno è bisestile o no.
        if(((year % 4 ==0 && year % 100 !=0) || (year % 400 ==0)) && day>29){
            throw invalid_argument("Invalid day. Febuary in a leap year has a max of 29 days.");
        }
        else if(day>28){
            cout<<"Febuary in a normal year has a max of 28 days."<<endl;
            throw invalid_argument("Invalid day. Febuary in a normal year has a max of 28 days.");
        }
    }
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