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
    EXPECT_TRUE(aRegister.search_activity(activity3));
    result.clear(); //svuoto result
    result= aRegister.search_activity_daybased(date2);
    EXPECT_TRUE(aRegister.search_activity(activity2));
    result.clear();
    result= aRegister.search_activity_daybased(date1);
    EXPECT_TRUE(aRegister.search_activity(activity1));
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
    EXPECT_EQ(aRegister.register_size(), 1); //controllo dimensione del registro
    EXPECT_TRUE(aRegister.search_activity(activity));
}

TEST(RegisterTest, Remove_Activity){
    Register aRegister("Zayne's Calendar");
    Date date1(26, 2, 2023);
    Date date2(28, 12, 2002);
    Date date3(20,1,1972);
    Activity activity_1(14, 30, 23, 30, "Critical Role Watch", date1);
    Activity activity_2(14,30,16,48,"My Birthday", date2);
    Activity activity_3(13,25,15,37,"Mom's Birthday", date3);
    aRegister.add_activity(activity_1);
    aRegister.add_activity(activity_2); //non inserisco la terza attività
    EXPECT_EQ(aRegister.register_size(), 2); //controllo la dimensione del registro
    aRegister.delete_activity(activity_2);
    EXPECT_EQ(aRegister.register_size(), 1); //ri-controllo la dimensione del registro
    aRegister.delete_activity(activity_3);

}
