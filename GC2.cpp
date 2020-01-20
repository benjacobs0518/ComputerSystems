#include <fstream>]
#include <string>
using namespace std;

struct Edge
{
    vertex *v;
};

struct vertex
{
    int node;
    std::vector<Edge> Edges;
};

void addEdge(std::string v1, std::string v2, int distance)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    Edge ed;
                    ed.v = &vertices[j];
                    ed.distance = distance;
                    vertices[i].Edges.push_back(ed);
                }
            }
        }
    }
}

void addVertex(std::string name)
{
    vertex av;
    av.name = name;
    vertices.push_back(av);
}

int main(int argc, const char *argv[])
{
  ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open())
  {

  }
}
