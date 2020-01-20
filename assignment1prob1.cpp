#include <iostream>
using namespace std;
#include<fstream>
#include<string>

void sort(int calculatedArray[], int counter)
{
    bool sorted = false;
    int temp = 0;
    while(sorted == false)
    {
        sorted = true;

        for (int l = 0; l < counter -  1; l++)
        {
            if ((counter > 1) and (calculatedArray[l] > calculatedArray[l+1]))
            {
                temp = calculatedArray[l];
                calculatedArray[l] = calculatedArray[l+1];
                calculatedArray[l+1] = temp;
                sorted = false;
            }
        }

    }
    for (int i = 0; i <counter; i++)
                {
                    cout<<calculatedArray[i];
                    if ((i < counter - 1))
                    {
                        cout <<", ";
                    }
                }
                cout<<endl;
}

void insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    int counter = 0;
    ifstream myfilestream;
    myfilestream.open("attempt.txt");

    if (myfilestream.is_open())
    {
        string line = "";
        while (getline(myfilestream, line))
        {
            myArray[counter] = stoi(line);
            counter++;
            sort(myArray, counter);
        }

    }
    cout<<"test"<<endl;
    myArray[counter] = newValue;
    counter++;
    sort(myArray, counter);

}

int main()
{
    int sortedArray[100];
    insertIntoSortedArray(sortedArray, 100, -3);
}
