#include<iostream>
#include<cut.h>
using namespace std;

//parameterized constructor

Cut::Cut(string jobId,string description,string machineNo,int duration,string client,int len,int units){
		this->length=len;
		this->noOfUnits=units;
	}
int Cut::getLength(){return length;}
int Cut::getNoOfUnits(){return noOfUnits;}
//displays extended data including base data
void Cut:: displayJob() const{
	Job::displayJob();
	cout<<","<<length<<","<<noOfUnits<<endl;
	}

