/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
//#include "client.h"
//#include "vipclient.h"
//#include <string.h>
#include "matchmakingagency.h"
#include <iostream> 
using namespace std;
// def Ctor
MatchMakingAgency::MatchMakingAgency()
{
	int i;
	numOfClients = 0;
	this->cl = new Client * [numOfClients];//Dynamic memory allocation
	for (i = 0; i < numOfClients - 1; i++)
	{
		this->cl[i] = new Client;//Dynamic memory allocation
	}
	cl = nullptr;
}
//set method
void MatchMakingAgency::setNumOfClients(int numOfClients)
{
	this->numOfClients = numOfClients;
}
//get method
int MatchMakingAgency::getNumOfClients()
{
	return numOfClients;
}
//Ctor 
MatchMakingAgency::MatchMakingAgency(Client** cl, int numOfClients)
{
	this->numOfClients = numOfClients;
	this->cl = new Client*[numOfClients];//Dynamic memory allocation
	this->cl = cl;
	for (int i = 0; i < numOfClients; i++)
	{
		this->cl[i] = new Client;//Dynamic memory allocation
		this->cl[i] = cl[i];
	}
	//this->cl = nullptr;
}
//Dtor ,free memory
MatchMakingAgency::~MatchMakingAgency()
{
	for (int i = 0; i < numOfClients; i++)
	{
		cl[i]->~Client();
	}
	delete[]cl;
}

//operator+=
void MatchMakingAgency::operator+=( Client& client)
{
	int i;
	Client** TempArr = NULL;//Temporary array
	if (numOfClients == 0)//The array is empty
	{
		numOfClients = 1;
		this->cl = new Client * [numOfClients];//Dynamic memory allocation
		cl[0] = &client;//Inserting the adress into the array
	}
	else//The array is not empty
	{
		TempArr = new Client * [numOfClients];//Dynamic memory allocation
		for (int i = 0; i < numOfClients; i++)
		{
			
			TempArr[i] = cl[i];  //Copy to temporary array
		
		}
		delete[] cl;//Deleting the previous array
		numOfClients++;//Increasing the array by one
		this->cl = new Client * [numOfClients]; //Dynamic memory allocation
		for (i = 0; i < numOfClients-1; i++)
		{
			this->cl[i] = new Client;//Dynamic memory allocation
			this->cl[i] = TempArr[i];
		}
		this->cl[numOfClients - 1] = new Client;//Dynamic memory allocation
		this->cl[numOfClients - 1] = &client;///Inserting the address into the array
	}
	numOfClients--;
	delete[] TempArr;//Deleting Temporary array
	numOfClients++;
}
//operator -=
void MatchMakingAgency::operator-=(Client& client)
{
	int index,i;
	int count = 0;
	
	Client** TempArr = NULL;//Temporary array
	if (numOfClients == 0)//The array is empty
	{
		exit(1);
	}
	else//The array is not empty
	{
		TempArr = new Client * [numOfClients];//Dynamic memory allocation
		for (i = 0; i < numOfClients; i++)
		{
			if (cl[i]->getId() == client.getId())
				index = i;;
			TempArr[i] = cl[i];//Copy to temporary array
			
		}

		delete[] cl;//Deleting the previous array
		numOfClients--;//Decreasing the array by one
		cl = new Client * [numOfClients]; //Dynamic memory allocation
		for (i = 0; i < index; i++)
		{
			cl[i] = new Client;//Dynamic memory allocation
			cl[i] = TempArr[i];
		}
		for (i = index; i < numOfClients; i++)
		{
			cl[i] = new Client;//Dynamic memory allocation
			cl[i] = TempArr[i + 1];
		}	
	}
	delete[] TempArr;//Deleting Temporary array
}
//operator<<
ostream& operator<<(ostream& os,const MatchMakingAgency& printer)
{
	int i;

	for (i = 0, i <= printer.numOfClients  ; i++;)
	{
		os << "the client:" << printer.cl[i]->getId() << endl << printer.cl[i]->getName() << endl;//prints the parameters
		if (printer.cl[i]->getGender())// checks gow the print the gender
			os << "Male" << endl;
		else
			os << "Female" << endl;
		os << printer.cl[i]->getAge() << endl;//prints the parameters
		for (int i = 0; i < printer.cl[i]->getNumOfHobbies(); i++)
		{
			os << printer.cl[i]->getHobby(i) << endl;//prints the parameters(hobbies)
		}
	}
	return os;
}
//adding a client to the data base
void MatchMakingAgency::addClient(Client& newCl)
{
	int i = 0;
	*this += newCl;
	
}
//finds the client to remove and removes him
  bool MatchMakingAgency::find(Client& client)
{
	for (int i = 0; i < numOfClients; i++)
	{
		if (cl[i]->getId() == client.getId())// checks if it is indeed the client
		{
			*this -= *cl[i];//removes him from data base
			return true;
		}
	}
	//else
	return false;
}
  //print
void MatchMakingAgency::print()const
{
	cout << "the clients are:\n";
	for (int i = 0; i < numOfClients; i++)
	{
		cout << *cl[i];//print client
	}
}
//prints the matching clients
int MatchMakingAgency::printMatchingClients(const String& id)const
{
	int i,j, flag = 0;
	for (i = 0; i < numOfClients; i++)
	{
		if (cl[i]->getId()== id) //checks who is the client
		{
			
				for (j = 0; j < numOfClients; j++)
				{
					if (cl[i] != cl[j] && *cl[i] == *cl[j]) //checks if there is matching client
					{
						cout << *cl[j];// prints the matching client
						flag = 1;
					}
				}
			

		}
	}
	return flag;
}
////checks who is the client to remove
bool MatchMakingAgency::removeClient(const String& id)
{
	int i, j, flag = 0;
	for (i = 0; i < numOfClients; i++)
	{
		if (cl[i]->getId() == id)//checks who is the client
		{
			if (find(*cl[i]))// calls find
				return true;
		}
	}
	//else
	return false;
}
