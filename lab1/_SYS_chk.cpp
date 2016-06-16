#include "stdincld.h"

bool _SYS_chkQuit(void)
{
	bool inputGood = false;
	char inputBuff[STR_MX];
	std::cout << GL_MSG_QUES_QUIT << std::endl;
	while (!inputGood)
	{
		static int invkCount = 0;
		if (invkCount)
		{
			std::cout << GL_ERR_INPUT_PROB;
		}
		std::cout << GL_MSG_YN;
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
