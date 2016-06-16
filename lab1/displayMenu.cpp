#include "stdincld.h"
void displayMainMenu(void)
{
	std::cout << std::endl<< "Main menu" << std::endl;
	std::cout << "1 - Show all queues\n";
	std::cout << "2 - Choose a queue to process\n";
	std::cout << "3 - Exit\n"<<std::endl;
}
void displayQueueMenu(void)
{
	std::cout << std::endl<<"Queue Menu" << std::endl;
	std::cout << "1 - Show the queue\n";
	std::cout << "2 - Enqueue an element\n";
	std::cout << "3 - Dequeue an element\n";
	std::cout << "4 - Clear the queue\n";
	std::cout << "5 - Delete every 2nd element from the queue\n";
	std::cout << "6 - Go back to main menu\n" << std::endl;
}
void clearScreen(void)
{
	system("cls");
}