/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef __MENU_H__
#define __MENU_H__
#pragma warning(disable: 4996)
#include "matchmakingagency.h"
#include <string.h>
#define MAX_STRING_SIZE 120//max size of strings in this program.
//main class - provide the main menu for the user to activate and manage the Employess database.
class Menu {
public:
    typedef enum { ADD_CLIENT = 1, REMOVE_CLIENT, PRINT_ALL_CLIENTS, PRINT_MATCHES, EXIT } MenuOption;
    //enum of menu options.
    void mainMenu();//the methods that run the main menu for this program. Resposible to input / ouput with the user.
 
private:
    MatchMakingAgency db;

//private menthods:
    
    void printOptions() const;//print all the menu options to screen.
    void addClient();//input all the nessesary data to create a new client and add it to the Data-Base
    void removeClient();//input the id and remove the asked client from the database
    void printClients() const;//print the entire database
    void printMatches();////prints the matching clients 
    void cleanBuffer();//letting the user insert a name with a space
};

#endif __MENU_H__

