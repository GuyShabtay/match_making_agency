/* Assignment: 2
Author: Guy Shabtay, ID: 209298272*/
#pragma warning(disable: 4996)
#ifndef __VIPCLIENT_H__
#define __VIPCLIENT_H__
#define M 1
#define F 0
#include "client.h"

class VipClient:public Client
{
private:
	int sameInterest;
	
public:
	VipClient(String id, String name, int gender, int age, char** hobby, int numOfHobbies, int sameInstresrts);//Ctor 
	~VipClient();//free memory
	bool operator==(VipClient& other);//operator==
};
#endif __VIPCLIENT_H__

