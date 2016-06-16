#include "stdincld.h"

bool _SYS_chkQuit(void)
{
	bool inputGood = false;
	char inputBuff[STR_MX];
	std::cout << "Are you sure you want to quit?" << std::endl;
	while (!inputGood)
	{
		static int invkCount = 0;
		if (invkCount)
		{
			std::cout << "There's been a problem with your input\n";
		}
		std::cout << "[Y/N]: ";
		std::cin.getline(inputBuff,STR_MX);
		invkCount++;
		if (chkValidInput(inputBuff, 0)) //mode
		{
			inputGood = true;
			invkCount = 0;
			break;
		}
	}
	return inputGood;
}
