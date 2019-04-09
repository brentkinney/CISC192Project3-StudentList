//this program allows the user to enter a list of student names and the program
//will return the name of a student that should be in the beginning of the list
//and the name of the student that should be at the end of the list, alphabetically
//The program will also print out the full original list

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int main()
{
	char choice = 'y';
	while (choice == 'y' || choice == 'Y')
	{
		string firstAlphabeticalName, lastAlphabeticalName, originalList;
		int numNames = 0;

		while (choice == 'y' || choice == 'Y')
		{
			string tempName;
			char start;
			//choose if importing file or if entering names with keyboard
			cout << "Would you like to import a file (F) or enter by keyboard (K)? " << endl;
			cin >> start;
			//if file (user provides path), read each line, give to String vars
			//if not, go through below
			if (start == 'F' || start == 'f')
			{
				//ask for file path to use and beging reading lines
				string path;
				cout << "Please proide path to file you would like to import. " << endl;
				cin >> path;
				ifstream myfile;
				myfile.open(path, std::ifstream::in);
				bool isOpen = myfile.is_open();
				while (std::getline(myfile, tempName))
				{

					//implement alphabetical checker
					if (numNames == 0)
					{
						firstAlphabeticalName = tempName;
						lastAlphabeticalName = tempName;
					}
					else
					{
						if (tempName < firstAlphabeticalName)
						{
							firstAlphabeticalName = tempName;
						}
						if (tempName > lastAlphabeticalName)
						{
							lastAlphabeticalName = tempName;
						}
					}


					//append name to original list
					originalList = originalList + tempName + '\n';
					numNames++;
				}


				//make sure there are at least 5 names in the file
				if (numNames == 45) {
					break;
				}
				if (numNames < 5) {
					cout << "There are not enough names in the file.  Minimum is 5" << endl;
					break;

				}

				choice = 'n';
			}
			else
			{
				while (choice == 'y' || choice == 'Y')
				{
					//ask for the student name
					
					cout << "What is the student Name? " << endl;
					//cin.ignore();
					cin.ignore(1000, '\n');
					getline(cin, tempName);
					cout << "Name given is " << tempName << endl;

					//implement alphabetical checker
					if (numNames == 0)
					{
						firstAlphabeticalName = tempName;
						lastAlphabeticalName = tempName;
					}
					else
					{
						if (tempName < firstAlphabeticalName)
						{
							firstAlphabeticalName = tempName;
						}
						if (tempName > lastAlphabeticalName)
						{
							lastAlphabeticalName = tempName;
						}
					}


					//append name to original list
					originalList = originalList + tempName + '\n';
					numNames++;


					//see if the user wants to continue and continue if desired
					if (numNames == 45) {
						break;
					}
					if (numNames > 4) {
					cout << "Would you like to add nother student? (Y/N): ";
					cin >> choice;
					cout << endl;
					}
					

				}
			}
		}


		//print the finalized list and alphabetical names
		cout << "First name: " << firstAlphabeticalName << endl;
		cout << "Last name: " << lastAlphabeticalName << endl;
		cout << "Original List: " << endl;
		cout << originalList;

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