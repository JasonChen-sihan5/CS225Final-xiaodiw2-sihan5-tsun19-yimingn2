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
    // std::ofstream out("../routes_with_distance.csv");

    // for (auto &row : routes)
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
    // Graph g(20000);
    // for (unsigned i = 0; i < routes.size(); i++)
    // {
    //     // cout << routes[i][3] << endl;
    //     int start = stoi(routes[i].at(3));
    //     int end = stoi(routes[i].at(5));

    //     g.addEdge(start, end);
    // }
    // g.printGraph();
    // vector<string> american_airports_num;
    // vector<string> american_airports_IATA;
    // for (unsigned i = 0; i < airports.size(); i++)
    // {
    //     if (airports[i].size() > 3 && airports[i][3] == "\"United States\"")
    //     {
    //         if (airports[i][4] != "\\N")
    //         {
    //             american_airports_num.push_back(airports[i][0]);
    //             american_airports_IATA.push_back(airports[i][4]);
    //         }
    //     }
    // }
    // for (int i = 0; i < (int)american_airports_IATA.size(); ++i)
    // {
    //     for (int j = 0; j < (int)american_airports_IATA[i].size() - 1; ++j)
    //     {
    //         std::cout << american_airports_IATA[i][j] << ", ";
    //     }
    //     std::cout << american_airports_IATA[i][american_airports_IATA[i].size() - 1];
    //     std::cout << "" << std::endl;
    // }
    g.printAllPaths(3484, 3830);
    // g.printGraph();
    // map<string, int> IATA_number;
    // for (unsigned i = 0; i < american_airports_IATA.size(); i++)
    // {
    //     IATA_number.insert(pair<string, int>(american_airports_IATA[i], stoi(american_airports_num[i])));
    // }
}
