#include "stdincld.h"
//rename this
void _SYS_MainMenu(node **queueArr, int qNum)
{
	int choice = 0;
	bool inputGood = false;
	bool exitIntent = false;
	char inputBuff[STR_MX];
	while (!exitIntent)
	{
		displayMainMenu();
		inputGood = false;
		//TO DO: Separate module with modes
		//std::cin.getline(inputBuff, STR_MN);
		while (!inputGood)
		{
			static int invkCount = 0;
			if (invkCount)
			{
				std::cout << "There's been a problem with your input\n";
				//clearScreen();
			}
			std::cout << "Your choice: ";
			std::cin.getline(inputBuff, STR_MN);
			if (chkValidInput(inputBuff,1))
			{
				inputGood = true;
				invkCount = 0;
				break;
			}
			invkCount++;
		}
		choice = atoi(inputBuff);
		switch (choice)
		{
		case 1:
			showQueues(queueArr, qNum);
			break;
		case 2:
		{
			clearScreen();
			_SYS_QueueMenu(queueArr, qNum, _SYS_chooseQueue(qNum));
			break;
		}
		case 3:
		{
				  if (_SYS_chkQuit())
				  {
					  exitIntent = true;
				  }
			break;
		}
		default:
			break;
		}
		std::cin.get();
		clearScreen();
	}
}
void _SYS_QueueMenu(node **queueArr, int qNum, int qID)
{
	_CERT_setPointers(queueArr,qID);
	//invkCountQue = 0;
	//std::cout << "Chosen queue: " <<qID+1<<std::endl;
	char inputBuff[STR_MX];
	bool inputGood = false;
	bool goBack = false;
	int processChoice = 0;
	int mode = 0;
	//TO DO: [OPERATION NOT PERMITTED] next to the menu entry in the queue menu
	//modes for dequeing and queueing required because of the spec function
	//0 - normal
	//1 - spec func
	//fix the menu !!!
	while (!goBack)
	{
		std::cout << "Now modifying queue #" << qID + 1 << std::endl;
		displayQueueMenu();
		inputGood = false;
		while (!inputGood)
		{
			static int invkCount = 0;
			if (invkCount)
			{
				std::cout << "There's been a problem with your input\n";
				//clearScreen();
			}
			std::cout << "Your choice: ";
			std::cin.getline(inputBuff, STR_MN);
			if (chkValidInput(inputBuff, 2))
			{
				inputGood = true;
				invkCount = 0;
				break;
			}
			invkCount++;
		}
		processChoice = atoi(inputBuff);
		std::cout << processChoice << std::endl;
		switch (processChoice)
		{
			case 1:
				_CERT_showQueue(queueArr, qID);
				std::cin.get();
				break;
			case 2:
				_CERT_enQueue(queueArr, qID, mode);
				break;
			case 3:
				_CERT_deQueue(queueArr, qID, mode);
				break;
			case 4:
				_CERT_clearQueue(queueArr, qID);
				break;
			case 5:
				_CERT_specFunc(queueArr, qID,qNum);
				break;
			case 6:
				_SYS_MainMenu(queueArr, qNum);
				break;
			default:
				break;
		}
		clearScreen();
	}
}
int _SYS_chooseQueue(int qNum)
{
	int choice = 0;
	std::cout << "Choose a queue to process:";
	std::cin >> choice;
	std::cin.get();
	assert(choice <= qNum&&choice > 0);
	choice--;
	clearScreen();
	return choice;
}