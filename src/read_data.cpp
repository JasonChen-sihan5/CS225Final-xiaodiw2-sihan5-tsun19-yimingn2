/**
 * @file read_data.cpp
 * Airport graph representation
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "read_data.h"
#include "utils.h"
#include <algorithm>
using namespace std;

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string.
 *
 * @param filename The filename of a CSV-formatted text file.
 */
V2D file_to_V2D(const std::string &filename)
{
  // Your code here!
  V2D toreturn;
  std::string string = file_to_string(filename);
  std::vector<std::string> split;
  int size = SplitString(string, '\n', split);
  for (int i = 0; i < size; i++)
  {
    std::vector<std::string> line;
    std::string trimString = Trim(split[i]);
    SplitString(trimString, ',', line);
    for (unsigned j = 0; j < line.size(); j++)
    {
      line[j] = Trim(line[j]);
    }
    toreturn.push_back(line);
  }
  return toreturn;
}

/**
 * @brief Construct a new Graph:: Graph object
 *
 * @param V number of Vertices
 */
Graph::Graph(int V)
{
  this->V = V;
}

/**
 * @brief Structure to store edges
 *
 * @param u Start vertice
 * @param v End vertice
 * @param wt Edge weight
 */
void Graph::addEdge(int u, int v, int wt)
{
  if (find(adj[u].begin(), adj[u].end(), pair<int, int>(v, wt)) == adj[u].end())
  {
    adj[u].push_back(make_pair(v, wt));
  }
}

/**
 * @brief Function to print all possible paths for user to select best flight route.
 * We choose using DFS to navigate possible paths since we incorporate edge weight.
 * By tracking flight connections using recursion and using back-tracking to record
 * corresponding fligh route, we filtrate 10 or less(depends on possible routes quantity)
 * shortest route with at most one flight connection since the flight is domestically.
 * The 10 shortest path with corresponding price for economy and first class will shown
 * on the screen.
 *
 * @param s Start vertice
 * @param d End vertice
 * @param distances Distances of all airports
 * @param transfer All United States airports with corresponding OpenFlight number
 * @param fromString Place flight from (IATA)
 * @param toString Place destination (IATA)
 */
vector<vector<int>> Graph::printAllPaths(int s, int d, V2D distances, V2D transfer, string fromString, string toString, bool week)
{
  vector<vector<int>> store; // Vector to store flight connections
  bool *visited = new bool[V];
  int *path = new int[V];
  int path_index = 0;
  for (int i = 0; i < V; i++)
  {
    visited[i] = false;
  }
  string from, to;
  int distance = 10000; // In case we do not have distance between two airports
  for (unsigned i = 0; i < transfer.size(); i++)
  {
    if (stoi(transfer[i][0]) == s)
    {
      from = transfer[i][1];
    }
    if (stoi(transfer[i][0]) == d)
    {
      to = transfer[i][1];
    }
  }
  for (unsigned i = 0; i < distances.size(); i++)
  {
    if (distances[i][0] == from && distances[i][1] == to)
    {
      distance = stoi(distances[i][2]);
      break;
    }
  }
  int dis_max = distance * 3; // Recommend distance for user
  cout << dis_max << endl;
  printAllPathsUtil(s, d, visited, path, path_index, 0, 19999, dis_max, store); // Helper method
  // for (unsigned i = 0; i < store.size(); i++)
  // {
  //     for (unsigned j = 0; j < store[i].size() - 1; j++)
  //     {
  //         cout << store[i][j] << " ";
  //     }
  //     cout << "***   distance is " << store[i].at(store[i].size() - 1);
  //     cout << endl;
  // }
  sort(store.begin(), store.end(), sortcol); // sort the vector by its distance (last index)
  cout << "The recommend routes with price according to airports ranking are list below" << endl;
  if (week)
    cout << "Prices are likely to rise over the weekend!!" << endl;
  for (unsigned i = 0; i < (unsigned)min((int)store.size(), 10); i++)
  {
    string s;
    for (unsigned j = 0; j < store[i].size() - 1; j++)
    {
      if (j == 0) // Print start IATA number
        cout << fromString << " ";
      if (j == 2) // Print end IATA number
        cout << toString << " ";
      if (j == 1) // Print flight connection IATA number
      {
        for (unsigned k = 0; k < transfer.size(); k++)
        {
          if (store[i][1] == stoi(transfer[k][0]))
          {
            s = transfer[k][2];
            cout << transfer[k][1] << " ";
            break;
          }
        }
      }
    }
    cout << "***   distance is " << store[i].at(store[i].size() - 1);
    double price = airportsRank(calculatePrice(store[i].at(store[i].size() - 1)) * 0.8, s);
    if (week)
      price = price * 1.2;
    cout << " and the corresponding price is " << price << " for economy class and " << price * 2.5 << " for the First class :)";
    cout << endl;
    cout << endl;
  }
  printCorresAirports(transfer, store);
  vector<vector<int>> toreturn;
  for (unsigned i = 0; i < (unsigned)min((int)store.size(), 10); i++)
  {

    toreturn.push_back(store[i]);
  }
  return toreturn;
}

/**
 * @brief Show user airports with IATA number
 *
 * @param airports Entering airports
 * @param store OpenFlight number
 */
void Graph::printCorresAirports(V2D airports, vector<vector<int>> store)
{
  cout << "The corresponding airports name is: " << endl;
  int i = 0;
  for (unsigned i = 0; i < (unsigned)min((int)store.size(), 10); i++)
  {
    for (unsigned j = 0; j < airports.size(); j++)
    {
      if (store[i][1] == stoi(airports[j][0]))
      {
        cout << airports[j][1] << ": " << store[i][1] << ".   ";
        // i++;
        // if (i % 4 == 0)
        // {
        //     cout << endl;
        // }
        break;
      }
    }
  }
  cout << endl;
}

/**
 * @brief Discount according to airports rank, higher rank with higher price
 *
 * @param price Transfer flight price
 * @param rank Airport rank
 * @return double Price after discount
 */
double Graph::airportsRank(double price, string rank)
{
  int rankInt = stoi(rank);
  return price * (1 - ((rankInt - 1) * (double)(1 / 967.5)));
}

/**
 * @brief Helper function for printAllPaths
 *
 * @param u Start vertice
 * @param d End vertice
 * @param visited Visited vertices array
 * @param path Path for flight
 * @param path_index Number of flight connections
 * @param distance Distance
 * @param prev Previous vertice
 * @param dis_max Maximum distance for good choice
 * @param store 2D vector to print
 */
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index, int distance, int prev, int dis_max, vector<vector<int>> &store)
{
  if (distance > 0.6 * dis_max && path_index <= 3) // Return if distance exceed limit
  {
    return;
  }
  if (path_index > 3) // Return if more than one flight connection is determined
  {
    return;
  }
  visited[u] = true;
  path[path_index] = u;
  path_index++;
  for (auto it = adj[prev].begin(); it != adj[prev].end(); it++)
  {
    if (it->first == u)
    {
      distance += it->second;
      break;
    }
  }
  // cout << path_index << endl;
  if (u == d && path_index <= 3) // Found the destination
  {

    // for (int i = 0; i < path_index; i++)
    //     cout << path[i] << " ";
    // cout << "**   distance is " << distance;
    // cout << endl;
    if (path_index != 2)
    {
      vector<int> toadd;
      for (int i = 0; i < path_index; i++)
      {
        toadd.push_back(path[i]);
      }
      toadd.push_back(distance);
      store.push_back(toadd);
    }
    else
    {
      cout << "the direct flight is: " << endl;
      for (int i = 0; i < path_index; i++)
        cout << path[i] << " ";
      cout << "**   distance is " << distance;
      cout << " with price " << calculatePrice(distance);
      cout << endl;
    }
  }
  else
  {
    vector<pair<int, int>>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (!visited[(*i).first])
        printAllPathsUtil((*i).first, d, visited, path,
                          path_index, distance, u, dis_max, store);
  }
  path_index--;
  for (auto it = adj[prev].begin(); it != adj[prev].end(); it++)
  {
    if (it->first == u)
    {
      distance -= it->second;
      break;
    }
  }
  visited[u] = false;
}

/**
 * @brief Print the graph
 *
 */
void Graph::printGraph()
{
  int v, w;
  for (int u = 0; u < V; u++)
  {
    if (adj[u].empty())
    {
      continue;
    }
    cout << "Node " << u << " makes an edge with \n";
    for (auto it = adj[u].begin(); it != adj[u].end(); it++)
    {
      v = it->first;
      w = it->second;
      cout << "\tNode " << v << " with edge weight ="
           << w << "\n";
    }
    cout << "\n";
  }
}

/**
 * @brief Calculate the ticket price according to it's distance
 *
 * @param distance Distance for the flight
 * @return int Price for the flight
 */
// in dollar
int Graph::calculatePrice(int distance)
{
  double terminalCharge = 44.18;
  double shortDisPerMile = 0.2417;
  double middleDisPerMile = 0.1843;
  double longDisPerMile = 0.1771;
  if (distance < 500)
  {
    return (int)(distance * shortDisPerMile + 0.5);
  }
  else if (distance < 1500)
  {
    return (int)(distance * middleDisPerMile + 0.5);
  }
  else
  {
    return (int)(distance * longDisPerMile + 0.5);
  }
}