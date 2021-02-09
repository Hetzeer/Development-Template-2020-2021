#include <stdio.h>
#include "converter.h"

int main() {
	converter conv;
	arabic arab;
	roman rom;
	
	rom.value = "VIII";
	arab.value = 19;
	conv.ConvertRomanToArabic(rom);
	conv.print();
	conv.ConvertArabicToRoman(arab);
	conv.print();
	rom.value = "IIIII";
	std::cout << conv.check(rom).value << std::endl;
	
	

  return 0;
}