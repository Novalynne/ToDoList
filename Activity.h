//
// Created by schir on 13/02/2024.
//

#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H

#include <string>
#include "Date.h"
using namespace std;

class Activity {
public:
    //COSTRUTTORE
    Activity(int beginTime_h, int beginTime_m, int endTime_h, int endTime_m, string description, Date date);

//GETTER E SETTER
    int getBeginTimeH() const;
    void setBeginTimeH(int beginTimeH);

    int getBeginTimeM() const;
    void setBeginTimeM(int beginTimeM);

    int getEndTimeH() const;
    void setEndTimeH(int endTimeH);

    int getEndTimeM() const;
    void setEndTimeM(int endTimeM);

    string getDescription() const;
    void setDescription(const string &description);

    const Date &getDate() const;
    void setDate(const Date &date);

private:
    int begin_time_h;
    int begin_time_m;
    int end_time_h;
    int end_time_m;
    string description;
    Date date;
};

#endif //TODOLIST_ACTIVITY_H
