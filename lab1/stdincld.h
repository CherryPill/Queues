#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "mainStruct.h"
#include "inputValidation.h"
#include "_SYS_chk.h"
#include "_SYS_menu.h"
#include "queueFuncs.h"
#include "displayMenu.h"

const int STR_MX = 257;
const int STR_MN = 4;
const int QUEUE_MX = 10;
const int MENU_BULL_MN = 1;
const int MMENU_BULL_MX = 3;
const int QMENU_BULL_MX = 6;
const unsigned int VAL_MX = UINT_MAX;
const char SPACE = '\033';
//prompt messages
const std::string GL_MSG_CONT = "Press Enter to continue";
const std::string GL_MSG_Q = "Enter the number of queues to create: ";
const std::string GL_MSG_V = "Enter a value for the node: ";
const std::string GL_MSG_POST_QUIT = "Quitting...";
const std::string GL_MSG_QUES_QUIT = "Are you sure you want to quit?";
const std::string GL_MSG_YN = "[Y/N]: ";
const std::string GL_APP_NAME = "\t\t\t\tDynamic queue creation";
//error messages
const std::string GL_ERR_L = "The input string is too large\n";
const std::string GL_ERR_YN_W = "Only 'Y' and 'N' characters and their lowercase equivalents are accepted\n";
const std::string GL_ERR_NO_W_QUE = "Only numbers from 1 thru 7 are accepted\n";
const std::string GL_ERR_NO_W_MAIN = "Only number from 1 thru 4 are accepted\n";
const std::string GL_ERR_EMP_IN = "Incorrect/empty input\n";
const std::string GL_ERR_INPUT_PROB = "There's been a problem with your input\n";
