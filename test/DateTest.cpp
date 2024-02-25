//
// Created by schir on 21/02/2024.
//
#include "gtest/gtest.h"
#include "../Date.h"


TEST(DateTest, ConstructorTest) {
    Date date(28, 12, 2002);
    EXPECT_EQ(date.getDay(), 28);
    EXPECT_EQ(date.getMonth(), 12);
    EXPECT_EQ(date.getYear(), 2002);
}

TEST(DateTest, IsEqualDate) {
    Date d1(10, 7, 2023);
    Date d2(10, 7, 2023);
    ASSERT_TRUE(d1.is_equal(d2));
    d2.setDay(11);
    ASSERT_FALSE(d1.is_equal(d2));
}

TEST(DateTest, IsDateCorrect) {
    Date date(10, 0, 2023);
    EXPECT_FALSE(date.is_date_correct()); // mese <1
    date.setMonth(13); //10 13 2023
    EXPECT_FALSE(date.is_date_correct()); // mese >12
    date.setDay(33);
    date.setMonth(8); //33 8 2023
    EXPECT_FALSE(date.is_date_correct()); // giorno >31
    date.setDay(0); //0 8 2023
    EXPECT_FALSE(date.is_date_correct()); //giorno <1
    date.setMonth(9);
    date.setDay(31); //31 9 2023
    EXPECT_FALSE(date.is_date_correct()); // mese 9 ha 30 giorni max
    date.setMonth(2);
    date.setDay(29); //29 2 2023
    EXPECT_FALSE(date.is_date_correct()); //febbraio 2023 ha 28 giorni max
    date.setYear(2024);
    date.setDay(30); //30 2 2024
    EXPECT_FALSE(date.is_date_correct()); // febbraio 2024 ha 29 giorni max
}


