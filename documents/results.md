## Output and Correctness for Algorithms

### Core Algorithm

​	<u>Dijkstra’s Algorithm</u> and <u>Depth First Search algorithm</u>. 

### Run Time

   Function `printAllPaths` and `printAllPathsUtil` have runtime $O(nlog(n))$. `PrintGraphs` has a runtime of $O(n)$.

### Correctness    

​	We have nearly 100% correctness to display top 10 (if there’s more than 10 routes, otherwise will display all) most recommended paths between any two airports.

### Highlight

​	Here is the pesudocode of one of our core function `printAllPathsUtil`:

```pseudocode
//This program finds the top 10 routes between two airports.
Function printAllPathsUtil(parameter that is used to find paths) {
	Check if distance is out of range: end program if out of range.
	Check if more than one flight connection is detected: reduce flight connection to 2.
	
	Calculate the distance;
	Find the distance of destination.
	Find the direct flight between two airports and print out.
}

```



### Test case

​	In the first test case, we've checked whether a graph could be correctly implemented to ensure no segmentation fault. 

​	In the second test case, we examine the implementation of a directed, weighted graph for aircraft routes to ensure that each airport is successfully linked. 

​	The third test case tests that when the user enters a correct starting point and a correct ending point, it can output the correct route and flight distance. 

​	After checking this, we designed the fourth test case to ensure that when users type something wrong, they can retype it without any special errors, so the program will not crash. 

​	The fifth test case tests the correct route output when the number of routes is small. 

​	The sixth test case ensures that the program can correctly calculate a price, giving multiple constraints, such as terminals and distances or airlines, and the difference between prices on and off weekends. The final test case examines the formula used to calculate prices.



## Answer to Our Leading Question

We used Dijkstra’s algorithm and DFS to find the best flights for our users. During the implementation of our algorithm, we found that the demands for our users differed due to the purpose of traveling. We successfully fulfilled some of the factors users may demand, such as the flying distance, ticket price, and Airport Ranking. Our system will base on users’ requirements to change the weight of different factors. If our users don’t specify a leading factor, the system will automatically generate flights basing on Distance > Price > Airport Ranking.

However, during the searching of the data, we found that we could hardly find data about time of flying. Moreover, the price of the tickets always can’t be paired with time of flying (time of flying and price of tickets don’t shape a linear function). Implementing such factor to our algorithm would enhance the run time of our algorithm, and sometimes it would result in a segmentation fault. Hence, we did not include time of flying as a factor for our users to choose.

In conclusion, our team successfully fulfilled most of our expectations for our project. The next step for each of our teammates is to figure out how to build up the connection between time of flying and other factors we included in our algorithm.