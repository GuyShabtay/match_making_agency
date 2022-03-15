/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef __STRING_H__
#define __STRING_H__ 
#include <iostream>
using namespace std;

class String
{
private:
	char *c;//quality of String object-pointer
public:
	char* getString();//get method
	void setString(char* c);//set method
	String(char* c);//Ctor that creats the new string dinamiclly
	String();//def Ctor
	~String();//free memory
	String(const String& other);//copy Ctor that creats the new string dinamiclly
	String& operator=(const String& other);//operator=
	bool operator==(const String& other) const;//operator==
	friend ostream &operator<<(ostream& os, const String& s); //operator<<
	friend class Client;
};
#endif __STRING_H__


