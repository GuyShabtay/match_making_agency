/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std;



//get method
char* String::getString()
{
	return c;
}
//set method
void String::setString(char* c)
{
	this->c = c;
}
//Ctor that creats the new string dinamiclly
 String::String(char* c)
{
	this->c = new char[strlen(c) + 1];//creats a string dinamiclly
	strcpy(this->c, c);//copys the given string(parameter) in to the location of the dinamic string
}
 //def Ctor
 String::String()
 {

	 this->c =nullptr;
 }
 //Dtor, free memory
 String::~String()
 {
	 delete []c; //free the momory of c
	 c = nullptr;// makes it null
 }
 //copy Ctor that creats the new string dinamiclly
 String::String(const String& other)
 {
	 this->c = new char[strlen(other.c) + 1];//creats a string dinamiclly
	 strcpy(this->c, other.c);//copys the given string(parameter) in to the location of the dinamic string
 }
 //operator=
 String& String::operator=(const String& other) 
 {
	 if (this != &other) //cheking self input
	 {
		 delete[] c;
		 this->c = new char[strlen(other.c) + 1];//creats a string dinamiclly
		 strcpy(c, other.c);//copys the given string
	 }
	 return *this;
 }
 //operator==
 bool String::operator==(const String& other) const
{
	 int i;
	 for ( i=0;this->c[i]!='\0';i++)//while thw string isnt over
	 {
		 if (this->c[i] != other.c[i]) //checks if its the same char
		 return false;
	 }
	 if (other.c[i] != '\0') //confirms that the secins string isnt longer than the first one
		 return false;
	 //else
		 return true;
}
 //operator<<
 ostream& operator<<(ostream& os,const String& s)
 {
	 os << s.c;//prints the string
	 return os;
 }
 
 
