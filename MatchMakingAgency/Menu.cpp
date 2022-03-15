/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#define CLIENT 1
#define VIP_CLIENT 0
#include "Menu.h" //this class header - no need to others since they will be included in the database header
#include <iostream> //for output / input
#include <string.h>
using namespace std;



//Main and only public method of this class - run the entire program.
void Menu::mainMenu() {
    bool run = true;//do we want another iteration?
    int option;//the choosen option for the menu.
    while (run) {//while we still want to run:
        printOptions();//print the menu
        cin >> option;//get the user choise
        switch (option) {//act accordingly:
        case ADD_CLIENT: //if we want to add a new employee
            addClient();//activate the methods that resposible for it
            break;//end of this iteration
        case REMOVE_CLIENT:
            removeClient();//a private method in menu class that remove employees from the database
            break;
        case PRINT_ALL_CLIENTS:
            printClients();//menu private method that print the database
            break;
        case PRINT_MATCHES:
            printMatches();//menu private method that promote a given employee
            break;
        case EXIT: run = false; //we want to stop running.
            cout << "Goodbye!\n";//tell the user goodbye.
            //since DataBase wasn't dynamically allocated, its Dtor will clean everything for us.
            break;
        default: cout << "Wrong option. Please try again!\n"; //not a supported option
        }//end switch

    }//end while(run)
}//end method Menu::mainMenu()


////////////////  Private Methods:      //////////////////
//A method that print the menu to screen.
void Menu::printOptions() const {//use the enum so in case of a change we want have to change it.
    cout << "Please choose one of the following options:\n Press\n"
        << "----------------------------------------------------------------------\n"
        << ADD_CLIENT << " in order to add a client to the database." << endl
        << REMOVE_CLIENT << " in order to remove a client from the database." << endl
        << PRINT_ALL_CLIENTS << " in order to print the database." << endl
        << PRINT_MATCHES << " in order to print the matches." << endl
        << EXIT << " in order to quit the program." << endl
        << "----------------------------------------------------------------------\n";
}//end method Menu::printOptions()

//a method to get all the needed data to create a new Client and add it to the Database.

void Menu::addClient() 
{
    //variables to keep information in order to create client:
    char ID[MAX_STRING_SIZE];
    char fullname[MAX_STRING_SIZE];
    char gender;
    int age;
    char** hobby;
    char str[MAX_STRING_SIZE];
    int numOfHobbies;
    int clientType;
    int sameInterest;
    do {
    cout << "Enter the matching number according to your account\n" << "VIP client- 0" << endl << "client- 1" << endl;
        cin >> clientType; //input of the clirnt type
    } while (clientType!=0 && clientType!=1);
    
  
    //let the user know what we need:
    cout << "Please enter all the needed detailed in order to add a new client to the database\n";
    cout << "Please enter the client full name\n";
    cleanBuffer();
    cin.getline(fullname,120);// input of name
    String name(fullname); //create the name as object

    cout << "Please enter the client ID\n";
    cin >> ID;
    String id(ID);//create the date as object

    cout << "Please insert the your gender M/F:"<< endl;
    cin >> gender;// input of gender
    while (gender != 'M' && gender != 'F')
    {
        cout << "Wrong input!\n";
        cin >> gender;
    }

    cout << "Please enter the client age: \n";
    cin >> age;// input of age

    cout << "Please enter the client number of hobbies: \n";
    cin >> numOfHobbies;// input number of hobbies
    while (numOfHobbies < 0)
    {
        cout << "Wrong input!\n";
        cin >> numOfHobbies;
    }
 
    

    cout << "Please enter the client hobbies\n";
    hobby = new char* [numOfHobbies];//dinamiclly alocation
    for (int i= 0; i < numOfHobbies; i++)
    {
        cin >> str; //input rhe hobbies
        hobby[i] = new char[strlen(str + 1)];
        strcpy(hobby[i], str);
    }
    if (clientType == CLIENT)
    {
        Client* newCl = new Client(id, name, gender, age, hobby, numOfHobbies);
        //create the new Client dynamically 
        db.addClient(*newCl);//add the new client to the database!
    }
    else if(clientType == VIP_CLIENT)
    {
        cout << "Please enter number of hobbies for your future matchings: \n";
        cin >> sameInterest;//input number of hobbies for the future matchings 
        VipClient* newCl = new VipClient(id, name, gender, age, hobby, numOfHobbies, sameInterest);//create the new Client dynamically 
        db.addClient(*newCl);//add the new client to the database!
    }
       
    
}//end method Menu::addClient()

//input the id and remove the asked client from the database
void Menu::removeClient()
{
    char Id[MAX_STRING_SIZE];
    cout << "Please enter the id of the employee you wish to remove\n";
    cin >> Id;//get the id
    String id(Id);//creating it as an object
    bool ifRemoved = db.removeClient(Id);//remove the employee
    if (ifRemoved == false)//if it wasn't a valid id
        cout << "Wrong id. No client was removed\n";//alart the user
    else {
        cout << "You just removed a client!\n";
    }
}//end method Menu::removeClient()

//The method print all the database
void Menu::printClients() const 
{
    db.print();//print all the data
}//end method Menu::printClients()

//prints the matching clients
void Menu::printMatches() {
    char Id[MAX_STRING_SIZE];
    cout << "Please enter the id of the client you wish to find matches to\n";
    cin >> Id;//get the id
    String id(Id);//creating it as an object
    int isExists = db.printMatchingClients(id);//get a pointer to that Employee
    if (isExists == 0)//if the id wasn't valid:
        cout << "No matching client was found\n";//alart the user
    
}//end method Menu::printMatches()
void Menu::cleanBuffer()
{
int c;
  do
  {
    c = getchar(); 
  } while (c!= EOF && c != '\n');//letting the user insert a name with a space
}
