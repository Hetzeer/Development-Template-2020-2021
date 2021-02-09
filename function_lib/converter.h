#include <iostream>
struct roman
{
	std::string value;
};
struct arabic
{
	int value;
};

class converter
{
	roman r;
	arabic a;
public:
	roman ConvertArabicToRoman(arabic& ar);
	arabic ConvertRomanToArabic(roman& rom);
	roman getRoman();
	arabic getArabian();
	roman check(roman& rom);
	void print();
	int find_ind(int num,int arr[]);
	int find_ind2(std::string sym, std::string arr[]);
};