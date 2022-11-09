#include<iostream>
#include<machinescheduler.h>

using namespace std;

int main(int argc ,char *argv[])
{
	if(argc!=1){
		cout<<"invalid usage \n";
		return 1;
	}
	MachineScheduler ms;
	ms.readInputFile(argv[1]);
}
