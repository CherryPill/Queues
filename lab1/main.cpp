#include "stdincld.h"
int main(void)
{
	int queueNum = 0;
	std::cout << "lab1" << std::endl;
	queueNum = getUsrNum(0);
	std::cout<<"Chosen number of queues: "<<queueNum<<std::endl;
	node **queueArr = (node**)calloc(queueNum, sizeof(node*));
	front = rear;
	std::cout << queueNum << " queues have been created\n" << std::endl;
	//showQueues(queueArr,queueNum);
	_SYS_MainMenu(queueArr,queueNum);
	return 0;
}