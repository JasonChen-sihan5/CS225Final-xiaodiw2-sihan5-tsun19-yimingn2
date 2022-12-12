/**
 * @file schedule.h
 * Exam scheduling using graph coloring
 *
 * @author Yiming Niu
 * @author Tianyang Sun
 * @author Sihan Chen
 * @author Xiaodi Wu
 * @date December 2022
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <set>
#include <list>
using namespace std;
typedef std::vector<std::vector<std::string>> V2D;

enum Airlines
{
  Delta = 98,
  Southwest = 100,
  American = 89,
  United = 96,
  JetBlue = 86,
  Alaska = 72,
  Frontier = 48,
  Spirit = 44
};
/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string.
 *
 * @param filename The filename of a CSV-formatted text file.
 * @return The vector of vectors of strings imported from filename
 */
V2D file_to_V2D(const std::string &filename);

/**
 * @brief The graph implementation using adjacency list
 *
 */
class Graph
{
    int V = 20000;
    vector<pair<int, int>> adj[20000];
    void printAllPathsUtil(int, int, bool[], int[], int &, int, int, int, vector<vector<int>> &);

public:
    Graph(int V);
    void addEdge(int u, int v, int wt);
    vector<vector<int>> printAllPaths(int s, int d, V2D distances, V2D transfer, string from, string to, bool week);
    void printGraph();
    int calculatePrice(int distance);
    double airportsRank(double price, string rank);
    void printCorresAirports(V2D airports, vector<vector<int>> store);
    static bool sortcol(vector<int> &v1, vector<int> &v2)
    {
        return v1[3] < v2[3];
    }
    int size()
    {
        return V;
    }
};