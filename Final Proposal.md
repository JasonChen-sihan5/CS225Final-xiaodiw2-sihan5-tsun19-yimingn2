## Leading Question 

Our group aims to use the graph algorithm to implement a recommending system for airports to  guests. The primary purpose of our project is to find recommended airports between guests’ departures and terminals. The recommending system will take several conditions like distance, times of transfer, expenditure, comfort level, etc., to weigh all options of routes. The system will provide three to four conditions to the user and let the user choose their priority of those conditions. Then the system will change the weight of those conditions during processing. The output of our system will be several routes, including the least expenditure route, the least time-consuming route, etc. The datasets of our project come from multiple sources(introduced in the second part). By implementing the graphic algorithm, we expect to gain the ability to collect, manage, and apply data to different functions. Another expectation would be to gain the ability to implement different algorithms to generate proper graphs and images as the final output of our project. 

## Dataset Acquisition

We will try to acquire data from the OpenFlights dataset and gain some data about airline ranking, airline price, and airport rating from other online sources.## Data Format	We will use `.dat` and `.csv` data formats. ## Data Correction	We will check the data format to ensure that each data set has the same number of information points. We will use `ifstream` to process files and track the information we get.## Data StorageWe will use `ifstream` to read files and store them in different vectors or arrays. We will create some enum to store the airplane ranking for future recommendations.

## Algorithm

 We will use Dijkstra’s shortest path algorithm and the Floyd cycle detection algorithm. The runtime of Dijkstra algorithm would be $O(|E|+|V|\log{\frac{|E|}{|V|}}\log{|V|})$. The runtime of Floyd cycle algorithm is $O(n)$

## Timeline

Below are the important components (with expected dates) of our project:

1. Data acquisition: The correct datasets should be collected. Ensure that errors do not occur in datasets.（Nov 4th--Nov 11th)
2. Data processing: The collected data might be in different formats, so we should transform the data into a unified format that C++ programs can properly process. （Nov 12th--Nov 14th)
3. BFS traversal algorithm（Nov 14nd--Nov 18th)
4. Shortest Path algorithm: Dijkstra’s algorithm. The major function of our project.（Nov 18th--Nov 27th)
5. Graphic output: visualization. (Nov 27th- Dec 7th)
6. Before the Mid-Project check-in, We shall finish collecting data and be able to implement the code of BFS traversal.