#include "converter.h"

#include <gtest.h>


TEST(test_lib, test1)
{
	converter c;
	arabic ar;
	ar.value = 26;
	c.ConvertArabicToRoman(ar);
    EXPECT_EQ("XXVI", c.getRoman().value);
}
TEST(test_lib, test2)
{
	converter c;
	arabic ar;
	ar.value = 75;
	c.ConvertArabicToRoman(ar);
	EXPECT_EQ("LXXV", c.getRoman().value);
}
TEST(test_lib, test3)
{
	converter c;
	roman r;
	r.value = "DCCLXIV";
	c.ConvertRomanToArabic(r);
	EXPECT_EQ(764, c.getArabian().value);
}
TEST(test_lib, test4)
{
	converter c;
	roman r;
	r.value = "CDLXXXVIII";
	c.ConvertRomanToArabic(r);
	EXPECT_EQ(488, c.getArabian().value);
}
TEST(test_lib, test5)
{
	converter c;
	roman r;
	r.value = "IIII";
	EXPECT_EQ("IV", c.check(r).value);
}
TEST(test_lib, test6)
{
	converter c;
	roman r;
	r.value = "IV";
	EXPECT_EQ("IV", c.check(r).value);
}