#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<vector>

class Movie
{
      private:
      string title = "Unknown";
      int year = 2018;
      float rating = 0.0;

      public:
      Movie()
      {
      string title = "Unknown";
      int year = 2018;
      float rating = 0.0;
      }

      Movie(string newTitle, int newYear, float newRating)
      {
      title = newTitle;
      year = newYear;
      rating = newRating;
      }

      string getTitle()
      {
      return title;
      }

      void setTitle(string newTitle)
      {
      title = newTitle;
      }

      int getYear()
      {
      return year;
      }

      void setYear(int newYear)
      {
      year = newYear;
      }

      float getRating()
      {
      return rating;
      }

      void setRating(float newRating)
      {
      rating = newRating;
      }
};

int main()
{
  Movie test_1;
  Movie test_2("Horror", 2018, 5.2);
  Movie test_3("Flowers", 1999, 4.5);

  cout << "Title: " << test_1.getTitle() << " Year: " << test_1.getYear() << " Rating: " << test_1.getRating()<< endl;
  cout << "Title: " << test_2.getTitle() << " Year: " << test_2.getYear() << " Rating: " << test_2.getRating()<< endl;
  cout << "Title: " << test_3.getTitle() << " Year: " << test_3.getYear() << " Rating: " << test_3.getRating()<< endl;


}
