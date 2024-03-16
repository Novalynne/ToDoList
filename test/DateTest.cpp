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

    EXPECT_THROW(Date date(10, 0, 2023), std::invalid_argument); // mese <1
    EXPECT_THROW(Date date(10, 13, 2023), std::invalid_argument); // mese >12
    EXPECT_THROW(Date date(33, 8, 2023), std::invalid_argument); // giorno >31
    EXPECT_THROW(Date date(0, 8, 2023), std::invalid_argument); //giorno <1
    EXPECT_THROW(Date date(31, 9, 2023), std::invalid_argument); // mese 9 ha 30 giorni max
    EXPECT_THROW(Date date(29, 2, 2023), std::invalid_argument); //febbraio 2023 ha 28 giorni max
    EXPECT_THROW(Date date(30, 2, 2024), std::invalid_argument); // febbraio 2024 ha 29 giorni max

}
