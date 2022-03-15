/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "string.h"
using namespace std;

class Client
{
protected:
	String id;
	String name;
	char gender;
	int age;
	char** hobby;
	int numOfHobbies;
public:
	// get/set methods
	void setGender(char gender);
	char& getGender();
	void setAge(int age);
	int getAge();
	void setNumOfHobbies(int numOfHobbies);
	int getNumOfHobbies();
	void setHobby(char* hobby,int i);
	char* getHobby(int i);
	void setId(String id);
	String& getId();
	void setName(String name);
	String getName();
	Client(String& id, String& name, char& gender, int& age, char** hobby, int& numOfHobbies);//Ctor 
	Client()=default;//default Ctor
	~Client();//free memory
	Client(const Client& other);//copy Ctor 
	void print()const;//print
	Client& operator=(const String& other);
	bool operator==( Client& other) ;//operator==
	bool isExists(char* h);//checks its the string exists
		bool isEqual(char* c,char* h);//cheks if the strings are the same
		friend ostream& operator<<(ostream& os, const Client& client);//operator<<
};
#endif __CLIENT_H__
