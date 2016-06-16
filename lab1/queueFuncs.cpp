#include "stdincld.h"
//all queues
//initial
void _CERT_setPointers(node **queueArr, int qID)
{
	if (queueArr[qID] != nullptr)
	{
		front = queueArr[qID];
		frontTemp = front;
		while (frontTemp != nullptr)
		{
			rear = frontTemp;
			frontTemp = (*frontTemp).nextNode;
		}
	}
	else
	{
		front = rear = nullptr;
	}
}
void showQueues(node **queueArr, int queueNum)
{
	//TO DO make  SETPOINTERS func to set initial pointers
	for (register int i = 0; i < queueNum; i++)
	{
		if (queueArr[i] == nullptr)
		{
			std::cout << "QUEUE #" << i + 1 << " IS EMPTY" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Queue #" <<i+1<< " contains the following entries\n";
			frontTemp = queueArr[i];
			while (frontTemp != nullptr)
			{
				printf("%d", (*frontTemp).value);
				printf(" -> ");
				frontTemp = (*frontTemp).nextNode;
			}
			puts("");
		}
	}
}
//particular queue
void _CERT_showQueue(node **queueArr, int qID)
{
	frontTemp = queueArr[qID];
	if (frontTemp == nullptr)
	{
		std::cout << "Queue #" << qID + 1 <<" is empty"<< std::endl;
	}
	while (frontTemp != nullptr)
	{
		if (frontTemp == front)
		{
			std::cout << "FRONT -> ";
		}
		std::cout << (*frontTemp).value << " -> ";
		if ((*frontTemp).nextNode == nullptr)
		{
			std::cout << "REAR";
		}
		frontTemp = (*frontTemp).nextNode;
	}
	std::cout << std::endl;
}
void _CERT_enQueue(node **queueArr, int qID, int mode)
{
	//static int invkCount = 0;
	int valueTemp = 0;
	valueTemp = getUsrNum(1);

	if (queueArr[qID] == nullptr)
	{
		queueArr[qID] = (node*)calloc(1, sizeof(node));
		front = queueArr[qID];
		rear = front;
	}
	else
	{
		(*rear).nextNode = (node*)calloc(1, sizeof(node));
		rear = (*rear).nextNode;
	}
	(*rear).value = valueTemp;
	std::cout << "A node with value " << valueTemp << " has been appended to the queue" << std::endl;
	std::cin.get();
}
void _CERT_deQueue(node **queueArr, int qID, int mode)
{
	frontTemp = front;
	if (front == nullptr)
	{
		std::cout << "The queue is empty. Nothing to dequeue\n";
	}
	else
	{
		//mode distinction required here
		if ((*front).nextNode!=nullptr)
		{
			frontTemp = (*frontTemp).nextNode;
			std::cout << "Removed an element with value " << (*front).value << "from the queue"<<qID+1<<std::endl;
			free(front);
			front = frontTemp; //designating the new front element
			queueArr[qID] = front;
		}
		//only 1 element in the queue
		else
		{
			std::cout << "Removed an element with value " << (*front).value << "from the queue #" <<qID+1<< std::endl;
			queueArr[qID] = nullptr;
			front = rear = nullptr;
			std::cout << "The queue is now empty\n";
		}
		std::cin.get();
	}
}
void _CERT_clearQueue(node **queueArr, int qID)
{
	if (front == nullptr)
	{
		std::cout << "The queue is empty. Nothing to delete\n";
	}
	else
	{
		frontTemp = front;
		while ((*front).nextNode != nullptr||(*front).nextNode!=nullptr)
		{
			frontTemp = front;
			front = (*front).nextNode;
			free(frontTemp);
		}
	queueArr[qID] = front = nullptr;
	std::cout << "The queue has been cleared\n";
	}
	std::cin.get();
}
int findNumElem(node **queueArr, int qID)
{
	int res = 0;
	assert(queueArr[qID] != nullptr);
	temp = queueArr[qID];
	while (temp != nullptr)
	{
		res++;
		temp = (*temp).nextNode;
	}
	return res;
}
void _CERT_specFunc(node **queueArr, int qID, int qNum) //delete qNum
{
	if (front == nullptr)
	{
		std::cout << "The queue is empty, unable to perform the operation"<<std::endl;
		std::cin.get();
	}
	else
	{

		int numElem = findNumElem(queueArr, qID);
		int *tempArr = (int*)calloc(numElem, sizeof(int));
		//assgn
		int count = 0;
		int temp = 0;
		assert(front != nullptr);
		frontTemp = front;
		//dequeuing
		while (front != nullptr)
		{
			temp = (*front).value;
			memcpy(&tempArr[count], &temp, sizeof(int));
			frontTemp = (*frontTemp).nextNode;
			free(front);
			front = frontTemp;
			count++;
		}
		//current temp dynamic array 
		for (register int x = 0; x < numElem; x++)
		{
			std::cout << x + 1 + "." << tempArr[x] << std::endl;
		}
		count = 0;
		queueArr[qID] = (node*)calloc(1, sizeof(node));
		dummy = queueArr[qID];
		//enqueuing the elements back except for the even ones
		while (count < numElem)
		{
			if (!(count % 2))
				(*dummy).value = tempArr[count];
			count++;
			if (count != numElem)
			{
				if (!(count % 2))
				{
					(*dummy).nextNode = (node*)calloc(1, sizeof(node));
					dummy = (*dummy).nextNode;
				}
			}
			else
			{
				(*dummy).nextNode = nullptr;
				dummy = queueArr[qID];
				front = queueArr[qID];
			}
		}
		free(tempArr);



	}
}
void _CERT_saveFile(node **queueArr, int qID,int qNum)
{

}
void saveFile(node **queueArr, int qnt)
{
	

}