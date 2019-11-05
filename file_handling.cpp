#include<iostream>
#include<fstream>
using namespace std;
void Example(); // function prototype
int main(void)
{
	cout<<"Size of an int : "<<sizeof(int)<<endl;  //just for the size of int 
		cout<<"Size of a float : "<<sizeof(float)<<endl;  //size of float
		Example(); // calling Example
}
void Example()
{
	ofstream fout;
	fout.open("sample.txt");  //using relative path
	fout<<"Hello World";
	fout.close();   //Always close the file after you open it
	
	
	
	ifstream fin;
	fin.open("sample.txt");
	/*
	if(fin)       // if file open succesfully-->True
	{
		getline(fin,line);    //line can be anything
		// getline takes first line and store it in line
	}
	*/
	// if you want multiple lines then you have to use while
	while(fin)
	{
		string line;
		getline(fin,line);
		cout<<line;
		// if fin-->true means that the file opened succesfully then while loop executes again and again and takes line by line
		//how loop stops
		//fin automatically become false when EOF-->reached (End of file)
		
	}
	fin.close();
}
