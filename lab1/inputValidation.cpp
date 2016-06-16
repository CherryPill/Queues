#include "stdincld.h"
//0 for queueNum
//1 for value
int getUsrNum(int mode)
	{
	std::string promptMsg;
	mode ? promptMsg = GL_MSG_V : promptMsg = GL_MSG_Q;
	bool inputGood = false;
	char inputBuff[STR_MX];
	int usrNum = 0;
	while (!inputGood)
	{
		static int invkCnt = 0;
		if (invkCnt)
		{
			std::cout << "There's been an error with your input" << std::endl;
		}
		std::cout << promptMsg;
		std::cin.getline(inputBuff, STR_MX);
		if (chkNum(inputBuff,mode))
		{
			sscanf(inputBuff, "%d", &usrNum);
			inputGood = true;
			invkCnt = 0;
			break;
		}
		else
		{
			invkCnt++;
		}
	}
	return usrNum;
}
bool chkNum(char *inputBuff, int mode)
{
	bool inputGood = true;
	for (register int x = 0; x < strlen(inputBuff); x++)
	{
		if (!isdigit(inputBuff[x]))
		{
			inputGood = false;
			break;
		}
		else
		{
			continue;
		}
	}
	if (inputGood)
	{
		if (atoi(inputBuff) <= (mode ? VAL_MX : QUEUE_MX))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//mode 0 - y/n
//mode 1 - main menu - 1-3
//mode 2 - queue menu - 1-6
//TO DO mode 3 - choose queue depends on the number of created queues 
bool chkValidInput(char *string, int mode)
{
	if (string[0] == SPACE)
	{
		std::cout << "ERROR: " << GL_ERR_EMP_IN;
		return false;
	}
	else
	{
		if (!mode) //y|n
		{
			//TO DO: change to numeric values
			if (!(isalpha(string[0])&&(tolower(string[0])=='y'||tolower(string[0]=='n'))))
			{
				std::cout << GL_ERR_YN_W;
				return false;
			}
		}
		else
		{
				if (mode == 1) //main
				{
					for (register int i = 0; i < strlen(string); i++)
					{
						if (!isdigit(string[i]))
						{
							return false;
						}
					}
					if (atoi(string) > MMENU_BULL_MX)
					{
						return false;
					}
					return true;
				}
				else if (mode == 2) //cert
				{
					for (register int i = 0; i < strlen(string); i++)
					{
						if (!isdigit(string[i]))
						{
							return false;
						}
					}
					if (atoi(string) > QMENU_BULL_MX)
					{
						std::cout << atoi(string);
						return false;
					}
					return true;
				}
		}
	}
}