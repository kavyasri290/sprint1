#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<istream>
#include<ostream>
#include<vector>
#include<iterator>
#include <sstream>
#include <algorithm>
#include<array>
#include<string>
#include<mutex>
#include<machinescheduler.h>
#include<job.h>
#include<cut.h>
#include<bend.h>
#include<polish.h>
#include<pattern.h>
using namespace std;
//declaring mutex
mutex m1;
mutex m2;
mutex m3;


        int MachineScheduler::readInputFile(const char* inpFile) 
        {
		int i=0;
	        ifstream input;//opening file to be readed
                input.open(inpFile);
		//try block to catch ecxeption
	        try{
              	if (!input.is_open())
              	{
                    cout << "Unable to open input file " << inpFile << endl;
                    return 1;
                }
	        }catch(...){
		    cout << "Unable to open input file ";
		  }
	      
         	
		string line;
               while(getline(input,line))
               {
		//declaring instance variables of all classes
		string line;
		stringstream ss;
		string jobId;
		string description;
		int duration;
		string machineNo;
		string client;
		int length;
		int noOfUnits;
		string shape;
		string noOfBends;
		string polishName;
		string colour;
		string patternName;
		int c=0,c1=0,c2=0,c3=0,c4=0;

		//parsing jobdata from inpFile 
		if(getline(ss,jobId,':'))
			c++;
		if(getline(ss,description,':'))
			c++;
		if(getline(ss,machineNo,':'))
			c++;
		ss>>duration;
		duration=atof(duration);
		if(getline(ss,duration,":"));
			c++;
		if(getline(ss,client,':'))
			c++;
		c1=c;c2=c;c3=c;c4=c;

		ss>>len;
		length=atof(len);
		if(getline(ss,length,":"));
			c1++;
		ss>>units;
		noOfUnits=atof(units);
		if(getline(ss,noOfUnits,":"));
			c1++;

		if(getline(ss,shape,":"));
			c2++;
		if(getline(ss,noOfBends,":"));
			c2++;

		if(getline(ss,polishName,":"));
			c3++;
		if(getline(ss,colour,":"));
			c3++;

		if(getline(ss,patternName,":"));
			c4++;

		
		if(c1==7 && jobId!=" " && machineNo=="M1" && duration!=0){
		
			s1[i]=Schedule1(jobId:description:machineNo:duration:client,length,noOfUnits);
			i++;
		} 
		else if(c2==7 && jobId!=" " && machineNo=="M2" && duration!=0)
		{
			s2[i]=Schedule2(jobId:description:machineNo:duration:client:shape:noOfBends);
			i++;

		}
		else if(c3==7 && jobId!=" " && machineNo=="M2" && duration!=0)
		{
			s2[i]=Schedule2(jobId:description:machineNo:duration:client:poliahName:colour);
			i++;
		}
		else if(c4==6  && jobId!=" " && machineNo=="M3" && duration!=0)
		{
			s3[i]=Schedule3(jobId:description:machineNo:duration:client:patternName);
			i++;
		}
		else
			cout<<"Invalide job type"<<endl;
	       }

	       input.close();
	      
	       return 0;
	}
//Thread class
void Thread::thread1(){
	//opening file to be writed
	ofstream file1;
	file1.open("schedule1.txt");
	try{
        	if (!file1.is_open())
            	cout<<"invalid file";
	}catch(...){
		cout<<"invalid file";
	}
   	      
	ofstream file2;
	file2.open("schedule2.txt");
	try{
        	if (!file2.is_open())
            	cout<<"invalid file";
	}catch(...){
		cout<<"invalid file";
	}

	ofstream file3;
	file3.open("schedule3.txt");
	try{
        	if (!file3.is_open())
            	cout<<"invalid file";
	}catch(...){
		cout<<"invalid file";
	}
	m1.lock();
	for(int i=0;i<=size(s1);i++)
	{
		cout<<s1<<endl;
		file1<<jobId<<" "<<d1<<" "<<d1+duration;
	}
	m1.unlock();
	m2.lock();
	for(int i=0;i<=size(s2);i++)
	{
		cout<<s2<<endl;
		file2<<jobId<<" "<<d2<<" "<<d2+duration;
	}
	m2.unlock();
	m3.lock();
	for(int i=0;i<=size(s3);i++)
	{
		cout<<s3<<endl;
		file3<<jobId<<" "<<d3<<d3+duration;
	}
	m3.unlock();
	file1.close();
	file2.close();
	file3.close();
	return 0;
}

