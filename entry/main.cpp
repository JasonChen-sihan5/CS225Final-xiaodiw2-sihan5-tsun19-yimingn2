#include <iostream>
#include "read_data.h"
#include <list>
#include <map>
#include <iterator>
#include <fstream>
using namespace std;
int main()
{

    V2D routes = file_to_V2D("../routes_with_distance.csv");
    V2D airports = file_to_V2D("../American_Airports.csv");
    V2D distances = file_to_V2D("../Distance_of_All_Airports.csv");
    V2D rank = file_to_V2D("../AirportRanking.csv");
    for (unsigned i = 0; i < airports.size(); i++)
    {
        bool check = false;
        for (unsigned j = 0; j < rank.size(); j++)
        {
            if (airports[i][1] == rank[j][2])
            {
                check = true;
                airports[i].push_back(to_string(j));
                break;
            }
        }
        if (!check)
        {
            airports[i].push_back(to_string(387));
        }
    }
    // for (int i = 0; i < (int)airports.size(); ++i)
    // {
    //     for (int j = 0; j < (int)airports[i].size() - 1; ++j)
    //     {
    //         std::cout << airports[i][j] << ", ";
    //     }
    //     std::cout << airports[i][airports[i].size() - 1];
    //     std::cout << "" << std::endl;
    // }
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

    // std::ofstream out("../lalalala.csv");

    // for (auto &row : lala)
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
    while (true)
    {
        int from, to;
        cout << "Type the airport from: ";
        cin >> from;
        cout << "Type the airport to: ";
        cin >> to;
        string fromString;
        string toString;
        for (unsigned i = 0; i < airports.size(); i++)
        {
            if (from == stoi(airports[i][0]))
            {
                fromString = airports[i][1];
            }
            if (to == stoi(airports[i][0]))
            {
                toString = airports[i][1];
            }
        }
        string answer;
        cout << "Please make sure you want to go from " << fromString << " to " << toString << "(Y/N)";
        cin >> answer;
        if (answer == "Y" || answer == "y")
        {
            g.printAllPaths(from, to, distances, airports, fromString, toString);
            break;
        }
        else
        {
            continue;
        }
    }

    // g.printGraph();
    // map<string, int> IATA_number;
    // for (unsigned i = 0; i < american_airports_IATA.size(); i++)
    // {
    //     IATA_number.insert(pair<string, int>(american_airports_IATA[i], stoi(american_airports_num[i])));
    // }
}
