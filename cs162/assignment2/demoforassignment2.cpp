#include <iostream>
#include <fstream>

using namespace std;

string get_filename(ifstream& my_ifstream) {
	do {//not needed for assignment
		string filename;
		cin >> filename;
		my_ifstream.clear();
		my_ifstream.open(filename);
	
	} while(my_ifstream.fail());

}


int main() {
	in_file.open("teams.txt"); //later, pass-by reference
	of_stream out_file;

	out_file.open("teams.txt", ios:app);

	out_file << "hello team" << endl;
	//out_file.close(); use when you want to re-open

	ifstream in_file;
	in_file.open("file.txt");

	string line;
	getline(my_ifstream, line);//NOT recommended for assignment2, getline uses different whitespace between lines

	string filename;
	filename = get_filename();

	if (some_string == "4") {
		quit();
	}
	
	//ifstream or ofstream's internal fail boolean
	

}
