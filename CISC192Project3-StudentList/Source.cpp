//this program allows the user to enter a list of student names and the program
//will return the name of a student that should be in the beginning of the list
//and the name of the student that should be at the end of the list, alphabetically
//The program will also print out the full original list

#include <iostream>
#include <limits>
using namespace std;

int main()
{
	char choice = 'y';
	while (choice == 'y' || choice == 'Y')
	{
		while (choice == 'y' || choice == 'Y')
		{
			string studentList;
			
			//ask for the student name
			cout << "What is the student Name? ";
			cin >> studentList;
			cout << "Name given is " << studentList << endl;

			//see if the user wants to continue and continue if desired
			cout << "Would you like to add nother student? (Y/N): ";
			cin >> choice;
			cout << endl;
		}


		//see if the user wants to continue and continue if desired
		cout << "Would you like to create another list? (Y/N): ";
		cin >> choice;
		cout << endl;
	}
	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;
	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}