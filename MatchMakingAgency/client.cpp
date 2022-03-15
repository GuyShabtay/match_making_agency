/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#include "client.h"
#include <string.h>
#include <iostream> 
using namespace std;

//set method
void Client::setNumOfHobbies(int numOfHobbies)
{
	while (numOfHobbies < 0)
	{
		cout << "Wrong input!\n";
		cin >> numOfHobbies;
	}
}
//get method
int Client::getNumOfHobbies()
{
	return numOfHobbies;
}
//set method
void Client::setHobby(char* hobby,int i)
{
	strcpy(this->hobby[i], hobby);
}
//get method
char* Client::getHobby(int i)
{
	return hobby[i];
}
//set method
void Client::setName(String name)
{
	this->name = name;
}
//get method
String Client::getName()
{
	return name;
}
//set method
void Client::setId(String id)
{
	this->id=id;
}
//get method
String& Client::getId()
{
	return id;
}
//set method
void Client::setGender(char gender)
{
		
		while (gender != 'M' && gender != 'F')
		{
			cout << "Wrong input!\n";
			cin >> gender;
	    }
}
//get method
char& Client::getGender()
{
	return gender;
}
//set method
void Client::setAge(int age)
{
		if (age < 18 || age>120)
			this->age = 35;
		else
			this->age = age;
}
//get method
int Client::getAge()
{
	return age;
}


//Ctor 
Client::Client(String& id, String& name, char& gender, int& age, char** hobby, int& numOfHobbies) :id(id.c), name(name.c)
{
	int i;
	this->gender = gender;
	setAge(age); //setting up the age 35 a default if its a wrong input
	this->numOfHobbies = numOfHobbies;
	this->hobby = new char* [numOfHobbies];//Dynamic memory allocation
	for (int i = 0; i < numOfHobbies; i++)
	{
		this->hobby[i] = new char[strlen(hobby[i] + 1)];//Dynamic memory allocation
		strcpy(this->hobby[i], hobby[i]);// copies the given parameter
	}
}
//Dtor ,free memory
Client::~Client()
{// deletes all the Dynamic memory allocations
	id.~String();
	name.~String();
	for (int i = 0; i < numOfHobbies; i++)
	{
	 delete hobby[i];
	}
	delete[] hobby;
 	

}
//copy Ctor 
Client::Client(const Client& other)
{
	id.c = new char[strlen(other.id.c) + 1];//creats a string dinamiclly
	strcpy(id.c, other.id.c);//copys the given string(parameter) in to the location of the dinamic string
	name.c = new char[strlen(other.name.c) + 1];//creats a string dinamiclly
	strcpy(name.c, other.name.c);//copys the given string(parameter) in to the location of the dinamic string
	gender = other.gender;
	age = other.age;
	char** hobby = new char* [numOfHobbies]; 
	this->hobby = other.hobby;
	for (int i = 0; i < numOfHobbies; i++)
	{
		this->hobby[i] = new char[strlen(other.hobby[i] + 1)]; //Dynamic memory allocation
		this->hobby[i] = other.hobby[i];// copies the given parameter
	}
}
//operator==
bool Client::operator==(Client& other)
{
	int i;
	if (gender != other.gender) //checks for opposite gender
	{
		if ((age - other.age <= 5 && age - other.age >= 0) || (other.age - age <= 5 && other.age - age >= 0)) // checks for 5 years difference
		{
			for (i = 0; i < numOfHobbies; i++)
			{
				if (isExists(other.hobby[i])) //checks its the string exists
					return true;
			}
		}
	}
	//else other not equal to this
	return false;
}
//checks its the string exists
bool Client::isExists(char* h)
{
	int i;
	for (i = 0; i < numOfHobbies; i++)
	{
		if (isEqual(this->hobby[i], h))//if its the same string
			return true;
	}
	return false;
}
//cheks if they are the same
bool Client::isEqual(char* c,char* h)
{
	int i;
	for (i = 0; c[i] != '\0'; i++) //cheks if the strings are even
	{
		if (c[i] !=h[i])
			return false;
	}
	if (h[i] != '\0')//confirms that the second atring isnt longer
		return false;
	//else
	return true;
}
//operator<<
ostream& operator<<(ostream& os, const Client& client) //prints the clients information
{
	os << "Name: " << client.name <<endl<< "ID: " << client.id<<endl;//prints the parameters
	if (client.gender=='M' )//prints the full words
		os <<"Gender: Male"<< endl;
	else if (client.gender == 'F')
		os << "Gender: Feamale"<< endl;
	os <<"Age: "<<client.age<< endl;//prints the parameters
	os << "Hobbies: \n";
	for (int i = 0; i < client.numOfHobbies; i++)
	{
		os << client.hobby[i] << endl;//prints the parameters(hobbies)
	}
	os << endl;

	return os;
}