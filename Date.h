//
// Created by schir on 13/02/2024.
//

#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H

class Date {
public:
    //COSTRUTTORE DISTRUTTORE
    Date(int day, int month, int year);


    //DATE UGUALI
    bool is_equal(Date b);

    //CONTROLLO DATE
    bool is_date_correct();

    //GET E SET
    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

private:
    int day;
    int month;
    int year;
};

#endif //TODOLIST_DATE_H
