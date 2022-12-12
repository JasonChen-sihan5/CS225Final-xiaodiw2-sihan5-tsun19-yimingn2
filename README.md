# CS225Final-xiaodiw2-sihan5-tsun19-yimingn2: US Airline Flight Ticket Recommendations

[Project Summary](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/README.md#project-summary) · [Code](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/README.md#code) · [Data](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/README.md#data) · [Documents](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/README.md#documents)

## [Presentation Video]()

## Project Summary

​	Our project's purpose is giving suggestion to travelers to find proper flight routes from their departures to terminals.

## Code

​	**All code of this project can be found in the folder [src](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/tree/main/src) and [entry](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/tree/main/entry).** 

> **Note**
>
> 1. Make sure you are running the program in [Docker](https://www.docker.com/). If not, follow this [Guide](https://courses.engr.illinois.edu/cs225/sp2022/resources/own-machine/) to get started.
>
> 2. In the first time you try to compile our project, please delete the original `build` folder and using `mkdir build` in your terminal to create your own empty folder.
>
> 3. Then, to using `cmake` for configuring, please using the following command in your terminal:
>
>    - `cd build`
>    - `cmake ..`
>
>    Then you can using `make` command to compile.

### Running Instructions

​	Running `./main` to execute `main.cpp` in the folder `entry/` directory.

​	Then, please walk through the following steps to find the OpenFlight code for each desired airport on [Airport Search](https://openflights.org/html/apsearch):

![Aiport Search1](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/documents/Materials/AirportSearch1.png)

![Airport Search2](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/documents/Materials/AirportSearch2.png)

![Airport Search3](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/documents/Materials/AirportSearch3.png)

![Airport Search4](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/documents/Materials/AirportSearch4.png)



## Data

​	We collect data from multiple sources, and the list of data sources is the following:

|                         Data Sources                         |                             File                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| [U.S. Department of Transportation](https://www.transportation.gov/) | [Function of Price](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/data/Function%20of%20Price.pdf), [January 2022 Air Travel Consumer Report](https://www.transportation.gov/individuals/aviation-consumer-protection/january-2022-air-travel-consumer-report), [August 2022 Air Travel Consumer Report](https://www.transportation.gov/individuals/aviation-consumer-protection/august-2022-air-travel-consumer-report), [Airport Rankings 2019](https://www.bts.gov/airport-rankings-2019) |
|     [OpenFlights.org](https://openflights.org/data.html)     | [airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat), [airlines.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airlines.dat), [routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat) |

​	We have edited all of these raw data to `.csv` file to impleament in our project. You can find all data file in the folder [data](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/tree/main/data) or using `cd data` in terminal.

## Documents

​	Our [final proposal](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/documents/Final%20Proposal.md), [team contract](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/blob/main/documents/Team%20Contract.md), and the written report can be found in the folder [documents](https://github.com/JasonChen-sihan5/CS225Final-xiaodiw2-sihan5-tsun19-yimingn2/tree/main/documents).
