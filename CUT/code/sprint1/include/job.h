#ifndef JOB_H
#define JOB_H
#include<vector>
#include<algorithm>

using namespace std;

class Job{
	protected:
		//declaring instance variables
		string jobId;
		string description;
		string machineNo;
		int duration;
		string client;
	public:
		void show(vector<Job> jobs);
		Job();
		Job(string,string,string,int,string);
		~Job();
		string getJobId();
		string getDescription();
		string getMachineNo();
		int getDuration();
		string getClient();
		virtual	void displayJob() const ;
};
#endif
