#include<iostream>
#include<fstream> //where ifstream and ofstream defined
using namespace std;
void Bin_Example();
void output_matrix(int a[][3],int rows,int cols);
int main()
{
	/*
	when we execute this and open our file there 
	should be garbage because we have .bin file having 0 and 1 
	 and out text editor is trying to convert it to ASCII A,B,C..........and so on..
	*/
	Bin_Example();
	/*
	When you want to open the file you should know its size and to know the file size you should open the image (problem)...
	solution just say we have image file jpg and then if we will read its 1st and second integar then 1st int has height
	and second has its width(this is standrad and you should know the standard)
	Note extensions does not matter you can try this by just saving the python file as .cpp extension 
	and then open it with python interpreter 
	then it shall be perfectly fine.........
	if you want to go to a specific line use seek there..
	*/
	return 0;
}
/*
Now we want to keep binary numbers in our file and output them.
one way is to casting mean first convert decimal number to its corresponding ASCII
e.g 49 'A' and then again convert it back to 49 to 
get its orignal value so it is a kind of very slow process
so we will do this using 2D arrays method
*/
void output_matrix(int a[][3],int rows,int cols)
{
	for(int i = 0 ; i < rows; i++)
	{
	
		for(int j = 0;j < cols; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Bin_Example()
{
	int pixels[3][3];
	for(int i = 0 ; i < 3; i++)
	
		for(int j = 0;j < 3; j++)
		
			pixels[i][j] = 1 + i*j;
		
	output_matrix(pixels,3,3);
	ofstream fout("data.bin",ios::binary); // ofstream is defined in <fstream>
	// you can give any extension
	for(int i = 0 ; i < 3; i++)
		for(int j = 0;j < 3; j++)
		/*
			fout.write((char*) &pixels[i][j] ,sizeof(int)); 
			Note: fout.write takes two things the place where 
			you want to write that thing (Address) and number of bytes
			fout.write( &pixels[i][j] ,sizeof(int)) Error-->it says give me character(f.write says give me address of character)
			so we will add (char*) in our code
			 and also it does not make any differnce
		*/
	fout.close(); // Always close the file after you worked on it
	cout<<"Resetting Pixels"<<endl;
	for(int i = 0 ; i < 3; i++)
		for(int j = 0;j < 3; j++)
			pixels[i][j]=0;
		output_matrix(pixels,3,3);
	fout.close();
	cout<<"Reading again..."<<endl;
	ifstream fin("data.bin",ios::binary);
	// you can give any extension
	if(!fin)  
	// if(fin.fail()) alternative
	{
		cout<<"Failed to read file..."<<endl;
	}
	else
	{
		/*
		 when we write we should knew that i have written integar? and what was their size?
		 because the number of integars that need to be read <= number of integars write
		 */
	for(int i = 0 ; i < 3; i++)
		for(int j = 0;j < 3; j++)
			fin.read((char*) &pixels[i][j] ,sizeof(int));
			//You should knew about the file you are reading(data type)
	}
	fin.close();
	output_matrix(pixels,3,3);
	/*                           
	ofstream fout is just like we do fout.open 
	and then (ios::binary) to tell fout that it shall 
	be binary value this must be provided
	*/
}
