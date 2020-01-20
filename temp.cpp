#include "Graph.hpp"

 using namespace std;

 void readFileIntoGraph(Graph & g, char* fileName);

 int main(int argc, char*argv[])
 {
      fileName=argv[1];
     Graph graph;
     vector cities;
     ifstream in_stream;
     //cout << fileName << endl;
     in_stream.open(fileName);
     if (!in_stream)
     {
         cout << "Could not open file\n";
         return;
     }

     string city;
     string line;
     getline(in_stream,line);
     std::stringstream ss(line);
     int y = 0;

     // Read a list of cities from the first line
     while (getline(ss,city,','))
     {
         if (city != "cities")
         {
             g.addVertex(city);
             cities.push_back(city);
         }
     }
     int i = 0;
     string input;
     while (!in_stream.eof())
     {
         i = -1;
         getline(in_stream,line);
         stringstream ss(line);

         while (getline(ss,input,','))
         {
             if (i == -1)
                  {
                 city = input;
             }
             else
             {
                 if (input != "-1" && input != "0")
                 {
                    int dist = atoi(in.c_str());
                    cout << " ... Reading in " << city << " -- " << cities[i] << " -- " << dist << endl;
                    graph.addEdge(city, cities[i], dist);
                 }
             }
             i++;
         }
     }
     graph.setAllVerticesUnvisited();
    graph.assignDistricts();
    graph.displayEdges();
 }
