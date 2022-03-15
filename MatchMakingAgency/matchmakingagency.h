/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __MATCHMAKINGAGENCY_H__
#define __MATCHMAKINGAGENCY_H__
#include "string.h"
#include "client.h"
#include "vipclient.h"
#define MAX_STRING_SIZE 120//max size of strings in this program.

class MatchMakingAgency
{
private:
	Client** cl;
	int numOfClients;

public:
	void setNumOfClients(int numOfClients);//set method
	int getNumOfClients();//get method
	int printMatchingClients(const String& id)const;//prints the matching clients
	MatchMakingAgency(Client** cl, int numOfClients);//Ctor 
	~MatchMakingAgency();//free memory
	MatchMakingAgency();//def Ctor 
	bool operator==(const Client& other) const;//operator ==
	friend ostream& operator<<(ostream& os,const MatchMakingAgency& printer);// האם הוא משתמש באופרטור של סטרינג
    void operator+=(Client& client);//operator +=
	void operator-=(Client& client);//operator ==
	void addClient(Client& newCl);//adding a client to data base
	bool removeClient(const String& id);//removes client 
	void print()const;//print the data base
	friend ostream& operator<<(ostream& os, const Client& client);//operator ==
	bool find(Client& client);//finds the client to remove
	
};
#endif __MATCHMAKINGAGENCY_H__

