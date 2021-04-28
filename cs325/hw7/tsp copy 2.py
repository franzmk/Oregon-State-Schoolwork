#!/usr/bin/python3
from math import sqrt, pow
import sys, re, math, time, os, copy

def main(input_file):
	tsp = TSP(input_file)
	start_time = time.time()
	trip = tsp.build_route()
	trip = tsp.two_opt(trip)
	end_time = time.time()
	total_time = end_time - start_time
	tsp.output_results(input_file, trip)
	print("Run-time: " + str(total_time), 's')


class TSP:

    #Initialized on start of program by arg[1]
    def __init__(self, input_file):
        self.cities = self.parse_input(input_file)

    def two_opt(self, route):
        distance = route[0]
        route = route[1:]
        for i in range(len(self.cities) - 2):
            for j in range(i + 1, len(self.cities) - 1):
                # dist1 is current distance between pair of points, dist2 is the swapped distance
                dist1 = self.distance_between(route[i], route[i + 1]) + self.distance_between(route[j], route[j + 1])
                dist2 = self.distance_between(route[i], route[j]) + self.distance_between(route[i + 1], route[j + 1])
                if dist2 < dist1:
                    new_route = self.two_swap(route, i, j)
                    distance = distance - dist1 + dist2
                    route = new_route
        return [distance] + route

    def two_swap(self, route, x, y):
        return route[:x + 1] + route[y:x:-1] + route[y + 1:]

    #Nearest neighbor algorithm to set up coherent path
    def build_route(self):
        current_city = 0
        route = [current_city]
        unvisited = {x for x in self.cities.keys()} #tracker for unvisited cities
        unvisited.remove(current_city)
        total_d = 0  #total distance

        while (len(unvisited) > 0):
            #choose city with lowest edge weight
            min = 9999999  #minimum distance to nearest city
            for city in unvisited:  #for each city
                distance = self.distance_between(current_city, city)
                if distance < min:
                    min = distance
                    next_city = city

            total_d += min  #update total distance
            current_city = next_city  #move to next city
            route += [current_city]  #add city to tour
            unvisited.remove(current_city)  #mark visited

        #Final leg added
        total_d += self.distance_between(route[0], route[len(route) - 1])
        return [total_d] + route #tour distance is [0], since number of cities varies

    # Get the input data into dict format
    def parse_input(self, in_file):

        file = open(in_file, 'r')
        line = file.readline()
        lines = line
        i = 0

        cities = dict()
        #cities consist of city # as the key and x,y coordinates as the values
        while i < int(lines):
            line = file.readline()
            line_parse = re.findall(r'[^,;\s]+', line)
            #print(line)
            cities[int(line_parse[0])] = [int(line_parse[1]), int(line_parse[2])]
            i += 1

        file.close()

        # return vertices, i.e. cities
        return cities

    # output results with .tour file extension
    def output_results(self, input_file_name, travel_list="No Results Generated"):

        # append .tour to original input file
        filename = input_file_name + ".tour"

        # write each value in travel_list on separate line
        with open(filename, 'w') as f:
            for value in travel_list:
                f.write(str(value) + '\n')
            f.close()

    def distance_between(self, city1, city2):
        cities_x = self.cities.get(city1)[0] - self.cities.get(city2)[0]
        cities_y = self.cities.get(city1)[1] - self.cities.get(city2)[1]
        return int(round(math.sqrt(cities_x * cities_x + cities_y * cities_y)))

if __name__ == '__main__':
    main(sys.argv[1])