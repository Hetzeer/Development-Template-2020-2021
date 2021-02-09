#include "converter.h"
roman converter::ConvertArabicToRoman(arabic& ar)
{
	int arr_arab[] = { 1,2,3, 4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000};
	std::string arr_rom[] = {"I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"};
	std::string res = "";
	int num = ar.value / 1000;
	for (int i = 0; i < num; i++)
	{
		res += "M";
	}
	num = ar.value % 1000 / 100 * 100;
	if (num != 0)
	{
		res += arr_rom[find_ind(num, arr_arab)];
	}
	num = ar.value % 100 / 10 * 10;
	if (num != 0)
	{
		res += arr_rom[find_ind(num, arr_arab)];
	}
	num = ar.value % 10;
	if (num != 0)
	{
		res += arr_rom[find_ind(num, arr_arab)];
	}
	r.value = res;
	a = ar;
	return r;
}

arabic converter::ConvertRomanToArabic(roman& rom)
{
	int arr_arab[] = { 1,2,3, 4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000 };
	std::string arr_rom[] = { "I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M" };
	int res = 0;
	int i = 0;
	for (i; i < rom.value.size() - 1; i++)
	{
		std::string curr = "";
		std::string next = "";
		curr += rom.value[i];
		next += rom.value[i+1];
		if (arr_arab[find_ind2(curr, arr_rom)] >= arr_arab[find_ind2(next, arr_rom)])
		{
			res += arr_arab[find_ind2(curr, arr_rom)];
		}
		else
		{
			res -= arr_arab[find_ind2(curr, arr_rom)];
		}
	}
	std::string curr2 = "";
	curr2 += rom.value[i];
	res += arr_arab[find_ind2(curr2, arr_rom)];
	a.value = res;
	r = rom;
	return a;
}

roman converter::getRoman()
{
	return r;
}

arabic converter::getArabian()
{
	return a;
}

roman converter::check(roman& rom)
{
	return ConvertArabicToRoman(ConvertRomanToArabic(rom));
}


void converter::print()
{
	std::cout << "arabian - " << a.value << " | roman - " << r.value<<"\n";
}

int converter::find_ind(int num, int arr[])
{
	for (int i = 0; i < 28; i++)
	{
		if (arr[i] == num)
		{
			return i;
		}
	}
	return -1;
}

int converter::find_ind2(std::string sym, std::string arr[])
{
	for (int i = 0; i < 28; i++)
	{
		if (arr[i] == sym)
		{
			return i;
		}
	}
	return -1;
}
