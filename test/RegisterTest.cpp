//
// Created by schir on 21/02/2024.
//

#include "gtest/gtest.h"
#include "../Register.h"

TEST(RegisterTest, ConstructorTest){
    Register aRegister("Zayne's Calendar");
    EXPECT_EQ(aRegister.getName(), "Zayne's Calendar");
    EXPECT_TRUE(aRegister.getReg().empty());
}

TEST(RegisterTest, Search_Activity_Daybased){
    Register aRegister("Zayne's Calendar");
    Date date1(31,7,1970);
    Date date2(28, 12, 2002);
    Date date3(20,1,1972);
    Date date4(12, 2, 2023);
    Activity activity1(19,45,22,0,"Dad's Birthday", date1);
    Activity activity2(14,30,16,48,"My Birthday", date2);
    Activity activity3(13,25,15,37,"Mom's Birthday", date3);
    aRegister.add_activity(activity1); //inserisco 3 attività con date diverse nel registro
    aRegister.add_activity(activity2);
    aRegister.add_activity(activity3);
    list<Activity> result= aRegister.search_activity_daybased(date3); //cerco le attività segnate nella data 3/1/2
    EXPECT_EQ(result.front().getDescription().c_str(), "Mom's Birthday");
    result.clear(); //svuoto result
    result= aRegister.search_activity_daybased(date2);
    EXPECT_EQ(result.front().getDescription().c_str(), "My Birthday");
    result.clear();
    result= aRegister.search_activity_daybased(date1);
    EXPECT_EQ(result.front().getDescription().c_str(), "Dad's Birthday");
    // la data 4 non presenta attività inserite nel registro quindi non può essere cercata dalla funzione e inserita in result (size result 0)
    result.clear();
    result= aRegister.search_activity_daybased(date4);
    EXPECT_EQ(result.size(), 0);
}

TEST(RegisterTest, Add_Activity){
    Register aRegister("Zayne's Calendar");
    Date date(26, 2, 2023);
    Activity activity(14, 30, 23, 30, "Critical Role Watch", date);
    aRegister.add_activity(activity);
    EXPECT_EQ(aRegister.getReg().size(), 1); //controllo dimensione del registro
    EXPECT_EQ(aRegister.getReg().front().getDescription().c_str(), "Critical Role Watch"); //controllo descrizione
    EXPECT_EQ(aRegister.getReg().front().getBeginTimeH(), 14); //controllo ora inizio fine
    EXPECT_EQ(aRegister.getReg().front().getBeginTimeM(), 30);
    EXPECT_EQ(aRegister.getReg().front().getEndTimeH(), 23);
    EXPECT_EQ(aRegister.getReg().front().getEndTimeM(), 30);
    EXPECT_EQ(aRegister.getReg().front().getDate().getDay(), 26); //controllo data
    EXPECT_EQ(aRegister.getReg().front().getDate().getMonth(), 2);
    EXPECT_EQ(aRegister.getReg().front().getDate().getYear(), 2023);
}
