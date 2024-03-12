//
// Created by schir on 13/02/2024.
//

#include "Activity.h"

//COSTRUTTORE
Activity::Activity(int beginTime_h, int beginTime_m, int endTime_h, int endTime_m, string description, Date date) : begin_time_h(beginTime_h), begin_time_m(beginTime_m), end_time_h(endTime_h), end_time_m(endTime_m), description(description), date(date) {}

//IS_EQUAL
bool Activity::is_equal(Activity b) {
    if(date.is_equal(b.date) && begin_time_h == b.getBeginTimeH() && begin_time_m == b.getBeginTimeM() && end_time_h == b.getEndTimeH() && end_time_m == b.getEndTimeM() && description == b.getDescription()){
        return true;
    }
    else{
        return false;
    }
}

// GETTER E SETTER
string Activity::getDescription() const {
    return description;
}
void Activity::setDescription(const string &description) {
    Activity::description = description;
}

const Date &Activity::getDate() const {
    return date;
}
void Activity::setDate(const Date &date) {
    Activity::date = date;
}

int Activity::getBeginTimeH() const {
    return begin_time_h;
}
void Activity::setBeginTimeH(int beginTimeH) {
    begin_time_h = beginTimeH;
}

int Activity::getBeginTimeM() const {
    return begin_time_m;
}
void Activity::setBeginTimeM(int beginTimeM) {
    begin_time_m = beginTimeM;
}

int Activity::getEndTimeH() const {
    return end_time_h;
}
void Activity::setEndTimeH(int endTimeH) {
    end_time_h = endTimeH;
}

int Activity::getEndTimeM() const {
    return end_time_m;
}
void Activity::setEndTimeM(int endTimeM) {
    end_time_m = endTimeM;
}

