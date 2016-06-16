#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H
struct node
{
	int value;
	struct node *nextNode;
};
extern node *front, *frontTemp, *rear, *temp, *dummy,*dummyFront;
#endif