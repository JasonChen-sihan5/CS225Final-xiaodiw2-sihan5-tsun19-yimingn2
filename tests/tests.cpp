#include <catch2/catch_test_macros.hpp>

#include "../src/read_data.h"
#include "../src/utils.h"
#include <iostream>

using namespace std;

TEST_CASE("Correct implementation of graph")
{
    Graph g(20000);
    V2D routes = file_to_V2D("../data/routes_with_distance.csv");
    V2D airports = file_to_V2D("../data/American_Airports.csv");
    V2D distances = file_to_V2D("../data/Distance_of_All_Airports.csv");
    V2D rank = file_to_V2D("../data/AirportRanking.csv");
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
    SECTION("Construct a correct graph")
    {
        REQUIRE(g.size() == 20000);
        vector<vector<int>> ints = {
            {3484, 3819, 3830, 1744},
            {3484, 3877, 3830, 1750},
            {3484, 3751, 3830, 1750},
            {3484, 3839, 3830, 1762},
            {3484, 3458, 3830, 1766},
            {3484, 3457, 3830, 1791},
            {3484, 4019, 3830, 1795},
            {3484, 3462, 3830, 1810},
            {3484, 3717, 3830, 1823},
            {3484, 3731, 3830, 1832}};
        vector<vector<int>> lala = g.printAllPaths(3484, 3830, distances, airports, "LAX", "ORD");
        // cout << lala.size() << endl;
        // for (int i = 0; i < (int)lala.size(); ++i)
        // {
        //     for (int j = 0; j < (int)lala[i].size() - 1; ++j)
        //     {
        //         std::cout << lala[i][j] << ", ";
        //     }
        //     std::cout << lala[i][lala[i].size() - 1];
        //     std::cout << "" << std::endl;
        // }
        REQUIRE(lala == ints);
    }
    SECTION("Flight with no routes")
    {
        vector<vector<int>> ints = {};
        vector<vector<int>> lala = g.printAllPaths(3490, 3484, distances, airports, "", "LAX");
        REQUIRE(lala == ints);
    }
    SECTION("Flight with less than 10 routes")
    {
        vector<vector<int>> ints = {
            {3484, 3877, 3498, 1334},
            {3484, 3751, 3498, 1466},
            {3484, 3858, 3498, 1984}};
        vector<vector<int>> lala = g.printAllPaths(3484, 3498, distances, airports, "LAX", "MOT");
        // for (int i = 0; i < (int)lala.size(); ++i)
        // {
        //     for (int j = 0; j < (int)lala[i].size() - 1; ++j)
        //     {
        //         std::cout << lala[i][j] << ", ";
        //     }
        //     std::cout << lala[i][lala[i].size() - 1];
        //     std::cout << "" << std::endl;
        // }
        REQUIRE(lala == ints);
    }
}

TEST_CASE("Correct price algorithm")
{
    Graph g(20000);
    REQUIRE(g.calculatePrice(1000) == 184);
}