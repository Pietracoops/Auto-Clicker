//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main() {
//	string line;
//	ifstream myfile("example.txt");
//	if (myfile.is_open())
//	{
//		while (getline(myfile, line))
//		{
//			cout << line << '\n';
//		}
//		myfile.close();
//	}
//
//	else cout << "Unable to open file";
//
//	return 0;
//}

//getline(file, temp);


//std::string str("There are two needles in this haystack with needles.");
//std::string str2("needle");

//// different member versions of find in the same order as above:
//std::size_t found = str.find(str2);
//if (found != std::string::npos)
//	std::cout << "first 'needle' found at: " << found << '\n';

//found = str.find("needles are small", found + 1, 6);
//if (found != std::string::npos)
//	std::cout << "second 'needle' found at: " << found << '\n';

//found = str.find("haystack");
//if (found != std::string::npos)
//	std::cout << "'haystack' also found at: " << found << '\n';

//found = str.find('.');
//if (found != std::string::npos)
//	std::cout << "Period found at: " << found << '\n';

//// let's replace the first needle:
//str.replace(str.find(str2), str2.length(), "preposition");
//std::cout << str << '\n';