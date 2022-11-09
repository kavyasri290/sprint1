#include <iostream>
#include<polish.h>
using namespace std;

Polish::Polish(string jobId,string description,string machineNo,int duration,string client,string polishName1,string colour1){
		this->polishName=polishName1;
		this->colour=colour1;
	}
string Polish::getPolishName(){return polishName;}
string Polish::getColour(){return colour;}

void Polish:: displayJob() const{
		Job::displayJob();
		cout<<","<<polishName<<","<<colour<<endl;
	}
	

