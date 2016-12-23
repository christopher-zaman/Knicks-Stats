#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Step 1
class PlayerProfile {
public:
	string Name;
	int Points;
	int Rebounds;
	int Assists;
};

void LoadFile(PlayerProfile data[], int&count)
{
	ifstream f("C:\\Users\\christopherzaman\\Desktop\\knicks.txt");
	if (f.good())
	{
		while (!f.eof())
		{
			f >> data[count].Name;
			f >> data[count].Points;
			f >> data[count].Rebounds;
			f >> data[count].Assists;
			count++;
		}
	}
	f.close();
}

// 1 Most Scorer Player
void ScorerPlayer(PlayerProfile data[], int count)
{
	int maxPoints = 0;
	for (int i = 0; i < count; i++)
	{
		if (data[i].Points > maxPoints)
		{
			maxPoints = data[i].Points;
			cout << "Most Scorer Player is: " << data[i].Name << "!" << endl;
		}
	}

}

// 2 Double Double
void Double(PlayerProfile data[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if ((data[i].Points > 9 && data[i].Rebounds > 9) || (data[i].Assists > 9 && data[i].Rebounds > 9) || (data[i].Points > 9 && data[i].Assists > 9))
		{
			cout << data[i].Name << " Achieved double double." << endl;
		}
	}
}

// 3 Triple Double
void Triple(PlayerProfile data[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i].Points && data[i].Rebounds && data[i].Assists > 9)
		{
			cout << data[i].Name << " Recieved a Triple Triple." << endl;
		}
	}
}


// 4 Report 
void Report(PlayerProfile data[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i].Name << ": "
			<< "\tPTS: " << data[i].Points
			<< "\tAST: " << data[i].Assists
			<< "\tREB: " << data[i].Rebounds << endl;
	}
}

int main()
{
	// Step 2 Create an array of type class
	PlayerProfile data[100];
	int count = 0;

	// Step 5: Read the file from disk
	LoadFile(data, count);

	// Step 4
	while (true)
	{
		// Step 3 Create a menu for your program
		cout << "Knicks Stats App Main Menu" << endl;
		cout << "==========================" << endl;
		cout << "1- Most Scoring Player" << endl;
		cout << "2- Double-Double" << endl;
		cout << "3- Triple-Double" << endl;
		cout << "4- Report" << endl;
		cout << "0- Exit" << endl;
		cout << "Make a choice:" << endl;
		int choice;
		cin >> choice;

		//Most Scorer
		if (choice == 1)
		{
			ScorerPlayer(data, count);
		}

		//Double
		else if (choice == 2)
		{
			Double(data, count);
		}

		// Triple
		else if (choice == 3)
		{
			Triple(data, count);
		}

		//Report
		else if (choice == 4)
		{
			Report(data, count);
		}

		else if (choice == 0)
		{
			break;
		}
	}


	system("pause");
	return 0;
}