/**
 * @file read_data.cpp
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
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
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
 * Given a course roster and a list of students and their courses,
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 *
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 *
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */
V2D clean(const V2D &cv, const V2D &student)
{
    // YOUR CODE HERE
    V2D toreturn;
    V2D another;
    for (unsigned i = 0; i < cv.size(); i++)
    {

        std::vector<std::string> toadd;
        toadd.push_back(cv[i][0]);
        for (unsigned j = 0; j < student.size(); j++)
        {
            if (std::find(student[j].begin(), student[j].end(), cv[i][0]) != student[j].end() && std::find(cv[i].begin(), cv[i].end(), student[j][0]) != cv[i].end())
            {
                toadd.push_back(student[j][0]);
            }
        }
        if (toadd.size() != 1)
        {
            toreturn.push_back(toadd);
        }
    }
    int j = 0;
    for (unsigned i = 0; i < toreturn.size(); i++)
    {
        if (toreturn[i][0] != cv[j][0])
        {
            j++;
        }
        std::vector<std::string> toadd;
        toadd.push_back(toreturn[i][0]);
        for (unsigned k = 1; k < cv[j].size(); k++)
        {
            if (std::find(toreturn[i].begin(), toreturn[i].end(), cv[j][k]) != toreturn[i].end())
            {
                toadd.push_back(cv[j][k]);
            }
        }
        another.push_back(toadd);
        j++;
    }
    return another;
}

/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 *
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 *
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 *
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value.
 *
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */
V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots)
{
    // Your code here!
    V2D toreturn;
    return toreturn;
}

Graph::Graph(int V)
{
    this->V = V;
}

void Graph::addEdge(int u, int v, int wt)
{
    if (find(adj[u].begin(), adj[u].end(), pair<int, int>(v, wt)) == adj[u].end())
    {
        adj[u].push_back(make_pair(v, wt));
    }
}

void Graph::printAllPaths(int s, int d, V2D distances, V2D transfer)
{
    bool *visited = new bool[V];
    int *path = new int[V];
    int path_index = 0;
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    string from, to;
    int distance = 10000;
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
    int dis_max = distance * 3;
    cout << dis_max << endl;
    printAllPathsUtil(s, d, visited, path, path_index, 0, 19999, dis_max);
}

void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index, int distance, int prev, int dis_max)
{
    if (distance > 0.6 * dis_max && path_index <= 3)
    {
        return;
    }
    if (path_index > 3)
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
    if (u == d && path_index <= 3)
    {

        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << "**   distance is " << distance;
        cout << endl;
    }
    else
    {
        vector<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[(*i).first])
                printAllPathsUtil((*i).first, d, visited, path,
                                  path_index, distance, u, dis_max);
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
