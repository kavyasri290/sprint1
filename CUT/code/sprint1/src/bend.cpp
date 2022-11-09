#include <iostream>
#include <bend.h>
using namespace std;


Bend::Bend(string jobId,string description,string machineNo,int duration,string client,string shape,string noOfBends){
		this->shape=shape;
		this->noOfBends=noOfBends;
	}
string Bend::getShape(){return shape;}
string Bend::getNoOfBends(){return noOfBends;}

void Bend::displayJob() const{
		Job::displayJob();
		cout<<","<<shape<<","<<noOfBends<<endl;
	}
	

