/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#include "client.h"
#include "vipclient.h"
#include <string.h>
#include <iostream> 
using namespace std;

//Ctor 
VipClient::VipClient(String id, String name, int gender, int age, char** hobby, int numOfHobbies, int sameInterest) ///////
{
	this->id = (id.getString());//getting the string
	this->name=(name.getString()); //getting the string
	int i;
	this->gender = gender;
	Client:: setAge(age);//setting up the age 35 a default if its a wrong input
	this->numOfHobbies = numOfHobbies;
	this->hobby = new char* [numOfHobbies];//Dynamic memory allocation
	for (int i = 0; i < numOfHobbies; i++)
	{
		this->hobby[i] = new char[strlen(hobby[i] + 1)];//Dynamic memory allocation
		strcpy(this->hobby[i], hobby[i]);
	}
	this->sameInterest = sameInterest;//the number of wanted hobbies foe future matchings

}
//Dtor ,free memory
VipClient::~VipClient()
{// deletes all the Dynamic memory allocations
	id.~String();
	id = nullptr;
	name.~String();
	name = nullptr;
	for (int i = 0; i < numOfHobbies; i++)
	{
		delete hobby[i];
	}
	delete[] hobby;
}//operator==
	bool VipClient::operator==(VipClient & other)
	{
		int i,count=0;
		if (gender != other.gender)//checks for opposite gender
		{
			if ((age - other.age <= 5 && age - other.age >= 0) || (other.age - age <= 5 && other.age - age >= 0))// checks for 5 years difference
			{
				for (i = 0; i < numOfHobbies; i++)
				{
					if (isExists(other.hobby[i]))//checks its the string exists
						count++; //counting the number of hobbies found
					if (count==sameInterest) //if its the same number of wanted hobbies foe future matchings
						return true;
				}
			}
		}
		//else other not equal to this
		return false;
	}
	

