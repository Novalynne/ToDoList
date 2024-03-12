//
// Created by schir on 21/02/2024.
//
#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityTest, ConstructorTest){
    Date date(28, 12, 2002);
    Activity activity(14,30,16,48,"My Birthday", date);
    EXPECT_EQ(activity.getBeginTimeH(), 14);
    EXPECT_EQ(activity.getBeginTimeM(), 30);
    EXPECT_EQ(activity.getEndTimeH(), 16);
    EXPECT_EQ(activity.getEndTimeM(), 48);
    EXPECT_EQ(activity.getDescription(), "My Birthday");
}

TEST(ActivityTest, SetterTest){
    Date date(28, 12, 2002);
    Activity activity(14,30,16,48,"My Birthday", date);
    activity.setBeginTimeH(3); //ho deciso di controllare solo un set dato che i restanti sono uguali solo con come diverso
    EXPECT_EQ(activity.getBeginTimeH(), 3);
    activity.setDescription("Bla bla bla"); //controllo descrizione
    EXPECT_EQ(activity.getDescription(), "Bla bla bla");
    Date d(31,12,2024); //controllo data
    activity.setDate(d);
    EXPECT_EQ(activity.getDate().getDay(), 31); //controllo data
    EXPECT_EQ(activity.getDate().getMonth(), 12);
    EXPECT_EQ(activity.getDate().getYear(), 2024);
}

TEST(ActivityTest, IsEqualTest){
    Date date(28, 12, 2002);
    Activity activity_1(14,30,16,48,"My Birthday", date);
    Activity activity_2(14,30,16,48,"My Birthday", date);
    Date date2(31, 7, 1970);
    Activity activity_3(19,45,22,0,"Dad's Birthday", date2);
    ASSERT_TRUE(activity_1.is_equal(activity_2));
    ASSERT_FALSE(activity_1.is_equal(activity_3));
}