#include <iostream>
#include<vector>
#include<algorithm>
#include<job.h>

//vector declaration
void Job::show(vector<Job> jobs){
	        
	vector<Job>::iterator it;
	for(it=jobs.begin();it!=jobs.end();++it)
	{
		cout<<"JobId"<<"Machine No"<<"Duration"<<endl;
		cout<<it->jobId<<" "<<it->machineNo<<" "<<it->duration<<endl;
	}
		
}
//parameterized constructor
Job::Job(string jobId,string description,string machineNo,int duration1,string client){
	this->jobId=jobId;
	this->description=description;
	this->machineNo=machineNo;
	this->duration=duration1;
	this->client=client;
	}
	
string Job::getJobId(){return jobId;}
string Job::getDescription(){return description;}
string Job::getMachineNo(){return machineNo;}
int Job::getDuration(){return duration;}
string Job::getClient(){return client;}

//to display job details
void Job::displayJob () const{
	cout<<jobId<<","<<description<<","<<machineNo<<","<<duration<<","<<client<<endl;
	     };
		
	 	

