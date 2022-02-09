#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
void Lower(string name , int &i)
{
	if(name[i] >= 'A' && name[i] <= 'Z')
	{
		name[i] += 32;
	}
}

void Fname(string name , int &i , int &j)
{
		for(int i=name.length() ; i>=0 ; i--)
	{
			if(name[i] == ' ')
			{
				for(int j=i+1 ; j<name.length() ; j++)
				{
					if(name[j] >= 'A' && name[j] <= 'Z')
					{
						name[j] += 32;
					}
					cout<<name[j];
				}
				break;
			}
			
	}
}

void Lname(string name , int &i , int &j)
{
		for (i = 0; i<name.length(); i++)
	{

		if(name[i] >= 'A' && name[i] <= 'Z')
			{
				name[i] += 32;
			}
		else if (name[i] == ' ')		
			continue;
		for (j = name.length(); j>=0; j--)
		{
			if (name[j]==' ')
				{
					j++;
					break;
				}
		}
		if (name[i] == name[j])
			break;
		else cout<<name[i];			
		}		
}
int main()
{
	int i,j;
	string name;
	cout<<"Nhap ten: ";
	getline(cin,name);
	
	cout<<name.length()<<endl;

	Fname(name, i , j);
	cout<<endl;
	Lname(name, i , j);
}

