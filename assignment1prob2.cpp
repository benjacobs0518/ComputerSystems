#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>

struct User{
  string username;
  float gpa;
  int age;
};

void printList​(vector <User> us)
{
  for (int i = 0; i < us.size(); i++)
  {
    cout<<us[i].username << " [" << us[i].gpa << "] age:" << us[i].age << endl;
  }
}

void addUser(vector <User> &us, string username,float gpa, int age)
{
  us.push_back ({username, gpa, age});
}

int main (int argc, char *argv[])
{
    string filename = argv[1];
    vector <User> us;
    int usercounter = 0;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
      string line;
      while(getline(myfile,line))
      {
        int locationInArray =0;
        string temp[3];
        for (int i=0; i < line.length(); i++)
        {
           if (line[i] == ',')
           {
               locationInArray++;
           }
           else if(line[i] == ' ')
           {}
           else
           {
               temp[locationInArray] = temp[locationInArray] + line[i];
           }

        }
        string tempN = temp[0];
        float tempF = stof(temp[1]);
        int age = stoi(temp[2]);
        us.push_back ({tempN, tempF, age});
    }
    printList​(us);
    cout<< endl;
    cout << " Added user " << endl;
    addUser(us, "ADDEDUSER", 6.2, 100);
    printList​(us);
}
}
