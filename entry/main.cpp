#include <iostream>
#include "../src/read_data.h"
#include <list>
#include <map>
#include <iterator>
#include <fstream>
using namespace std;
int main()
{

    V2D routes = file_to_V2D("../data/routes_with_distance.csv");
    V2D airports = file_to_V2D("../data/American_Airports.csv");
    V2D distances = file_to_V2D("../data/Distance_of_All_Airports.csv");
    // V2D airports = file_to_V2D("../airports.csv");
    // V2D distances = file_to_V2D("../Distance_of_All_Airports.csv");
    Graph g(20000);

    for (unsigned i = 0; i < routes.size(); i++)
    {
        if (routes[i].size() < 6)
        {
            continue;
        }
        int from = stoi(routes[i][3]);
        int to = stoi(routes[i][5]);
        if (routes[i].size() > 9)
        {
            int distance = stoi(routes[i][9]);
            g.addEdge(from, to, distance);
        }
        else
        {
            g.addEdge(from, to, 10000);
        }
    }
    // g.printGraph();

    // for (int i = 0; i < (int)routes.size(); ++i)
    // {
    //     for (int j = 0; j < (int)routes[i].size() - 1; ++j)
    //     {
    //         std::cout << routes[i][j] << ", ";
    //     }
    //     std::cout << routes[i][routes[i].size() - 1];
    //     std::cout << "" << std::endl;
    // }

    // Graph g(20000);
    // for (unsigned i = 0; i < routes.size(); i++)
    // {
    //     // cout << routes[i][3] << endl;
    //     int start = stoi(routes[i].at(3));
    //     int end = stoi(routes[i].at(5));

    //     g.addEdge(start, end);
    // }
    // g.printGraph();
    // V2D american_airports;
    // for (unsigned i = 0; i < airports.size(); i++)
    // {
    //     if (airports[i].size() > 3 && airports[i][3] == "\"United States\"")
    //     {
    //         vector<string> line;
    //         if (airports[i][4] != "\\N")
    //         {
    //             line.push_back(airports[i][0]);
    //             line.push_back(airports[i][4]);
    //             american_airports.push_back(line);
    //         }
    //     }
    // }
    // cout << american_airports[1].size() << endl;
    // for (int i = 0; i < (int)american_airports.size(); ++i)
    // {
    //     for (int j = 0; j < (int)american_airports[i].size() - 1; ++j)
    //     {
    //         std::cout << american_airports[i][j] << ", ";
    //     }
    //     std::cout << american_airports[i][american_airports[i].size() - 1];
    //     std::cout << "" << std::endl;
    // }

    // std::ofstream out("../American_Airports.csv");

    // for (auto &row : american_airports)
    // {
    //     unsigned i = 0;
    //     for (auto col : row)
    //     {

    //         out << col;
    //         if (i < row.size() - 1)
    //         {
    //             out << ",";
    //         }
    //         i++;
    //     }
    //     out << '\n';
    // }
    // out.close();
    // for (int i = 0; i < (int)american_airports_IATA.size(); ++i)
    // {
    //     for (int j = 0; j < (int)american_airports_IATA[i].size() - 1; ++j)
    //     {
    //         std::cout << american_airports_IATA[i][j] << ", ";
    //     }
    //     std::cout << american_airports_IATA[i][american_airports_IATA[i].size() - 1];
    //     std::cout << "" << std::endl;
    // }
    int from, to;
    cout << "Type the airport from: ";
    cin >> from;
    cout << "Type the airport to: ";
    cin >> to;
    g.printAllPaths(from, to, distances, airports);

    // g.printGraph();
    // map<string, int> IATA_number;
    // for (unsigned i = 0; i < american_airports_IATA.size(); i++)
    // {
    //     IATA_number.insert(pair<string, int>(american_airports_IATA[i], stoi(american_airports_num[i])));
    // }
}
