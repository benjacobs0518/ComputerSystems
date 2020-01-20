#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

  struct wordItem{
  string word;
  int count;
  };

  void splitSent(string sent, string fill[], int size)
  {
     int locationInArray = 0;

      for (int i=0; i < 53; i++)
      {
         if (sent[i] == ' ')
         {
             locationInArray++;
         }

         else
         {
             fill[locationInArray] = fill[locationInArray] + sent[i];
         }
      }

  }

void getStopWords(char *ignoreWordFileName, string ignoreWords[])
{
    int counter=0;
    string filename = ignoreWordFileName;
    ifstream myfile(filename);

    if (myfile.is_open())
    {
        string line = "";
        while (getline(myfile, line))
            {
            ignoreWords[counter] = line;
            counter++;
            }
    }

}

bool isStopWord(string word, string ignoreWords[])
{
    for(int i =0;i<50;i++)
    {
        if(word == ignoreWords[i])
        {
            return true;
        }
    }
    return false;
}

int getTotalNumberNonStopWords(wordItem list[],int length)
{
    int NumberNonStopWords = 0;

    for(int i =0; i< length; i++)
    {
        NumberNonStopWords = NumberNonStopWords+list[i].count;
    }

    return NumberNonStopWords;
}

void arraySort(wordItem list[], int length)
{
    int tempCount=0;
    string tempWord ="";
    bool sorted=false;
    while(sorted == false)
    {
        sorted  = true;
        for(int i=0; i<length-1; i++)
        {
            if(list[i].count < list[i+1].count)
            {
                sorted = false;
                tempWord = list[i].word;
                tempCount = list[i].count;
                list[i] = list[i+1];

                list[i+1].word = tempWord;
                list[i+1].count = tempCount;
            }
        }
    }
}

void printTopN(wordItem wordItemList[], int topN)
{
    for(int i =0; i<topN; i++)
    {
        cout<< wordItemList[i].count << " - " << wordItemList[i].word << endl;
    }
}

string *getBiggerArray(string *oldArray, int oldCapacity)
{
  string *newArray = new string[oldCapacity*2];

  for(int i=0; i<oldCapacity; i++)
  {
    newArray[i] = oldArray[i];
  }
  delete [] oldArray;
  return newArray;
}


int main (int argc, char *argv[])
{

  string strn = argv[1];
  string filename = argv[2];
  string ignoreWord = argv[3];
  int n = stoi(strn);

  int locationInArray = 0;

  ifstream myfile(filename);
  if (myfile.is_open())
  {
    int capacity = 100;
    string *allWords = new string[capacity];
    int locationInArray=0;
    string line;
    while(getline(myfile,line))
    {

      for (int i=0; i < line.length(); i++)
      {
        if(locationInArray >=capacity)
        {
         allWords = getBiggerArray(allWords, capacity);
         capacity = capacity * 2;
        }
        
         if (line[i] == ' ')
         {

             locationInArray++;
         }
         else
         {
             allWords[locationInArray] = allWords[locationInArray] + line[i];
         }



  }

  //printTopN(wordsInDoc, n);
}
        for (int i = 0; i < 5; i++)
        {
          cout << allWords[i] << endl;
        }

}
}
