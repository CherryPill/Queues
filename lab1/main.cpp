#include "stdincld.h"
int main(void)
{
	int queueNum = 0;
	std::cout << GL_APP_NAME << std::endl;
	queueNum = getUsrNum(0);
	std::cout<<"Chosen number of queues: "<<queueNum<<std::endl;
	node **queueArr = (node**)calloc(queueNum, sizeof(node*));
	front = rear;
	std::cout << queueNum << " queues have been created\n" << std::endl;
	std::cout<<GL_MSG_CONT;
	std::cin.get();
	_SYS_MainMenu(queueArr,queueNum);
	std::cout<<GL_MSG_POST_QUIT<<std::endl;
	return 0;
}