#!/usr/bin/python3
import sys, re, math, time

#The main function, runs the program, takes inputFile as a parameter
def main(inputFile):
    #Cities is a dictionary that contains all the information from the inputFile
	cities = inputFunction(inputFile)
    #Start time will begin the timer in order to track how long the process takes
	startTime = time.time()
    #This line will build the initial route using the nearest neighbor algorithm
	trip = buildRoute(cities)
    #This line will optimize the solution using 2-OPT
	trip = twoOpt(cities, trip)
    #End time will mark the end of the timer
	endTime = time.time()
    #Total time will be how ever long the inputFile took to process and optimize
	totalTime = endTime - startTime
    #The outputFunction will output a .tour file
	outputFunction(inputFile, trip)
    #The run time is printed for ease of use
	print("Run-time: " + str(totalTime), 's')

#The inputFunction takes the inputFile and reads all the data, placing it into a dictionary called cities
def inputFunction(inputFile):
    #The file is opened
    file = open(inputFile, 'r')
    #The first line is read which contains the number of cities
    line = file.readline()
    #Another temp var named lines is used for the while loop bound
    lines = line
    #A temp var i is used to track how many lines have been read
    i = 0
    #The cities dictionary is declared
    cities = dict()
    #In the while loop, information about the cities is read
    while i < int(lines):
        #A new line is read from the inputFile
        line = file.readline()
        #The entire line is parsed
        line_parse = re.findall(r'[^,;\s]+', line)
        #The key is set to the city number and the x, y coords are set as the values
        cities[int(line_parse[0])] = [int(line_parse[1]), int(line_parse[2])]
        #i is increased to keep track of how many lines have been read
        i += 1
    #The file is closed
    file.close()

    #Return the cities dictionary
    return cities

#The buildRoute function utilizes the nearest neighbor algorithm to setup a route that will be optimized
def buildRoute(cities):
    currentCity = 0
    route = [currentCity]
    #This unvisited var will keep track of the currently unvisited cities
    unvisited = {x for x in cities.keys()}
    #The first city is removed because it is the currentCity
    unvisited.remove(currentCity)
    #Total distance is initalized to 0
    totalDist = 0

    #While there is still unvisited cities, this for loop will run
    while (len(unvisited) > 0):
        #We want to choose the city with the lowest edge weight
        #the minDist var is set to an arbitrarily high number because we're using it to compare later on
        minDist = 99999
        #For loop that checks all unvisited cities
        for city in unvisited:
            #The distance between the currentCity and the next city is calculated
            distance = distanceBetween(cities, currentCity, city)
            #If the calculated distance is less than the minDist var, enter this if
            if distance < minDist:
                #The minDist is set to distance because that is the new minDist
                minDist = distance
                #nextCity is set to continue the for loop and comparisons
                nextCity = city

        #The totalDist val is updated to include the most recent treck
        totalDist += minDist
        #Set currentCity to move to the next unvisited city
        currentCity = nextCity
        #Add the currentCity to the tour
        route += [currentCity]
        #Remove the currentCity from the unvisited var
        unvisited.remove(currentCity)

    #Add the last leg of the tour to the totalDist
    totalDist += distanceBetween(cities, route[0], route[len(route) - 1])
    #Return the total distance
    return [totalDist] + route

#The twoOpt function will optimize the route built by the nearest neighbor algorithm
def twoOpt(cities, route):
    #The first distance is declared
    distance = route[0]
    #The route is set to the rest of the values in cities
    route = route[1:]
    #The outer for loop runs 2 values less than cities is long
    for i in range(len(cities) - 2):
        #The inner for loop runs 1 less time than cities is long
        for j in range(i + 1, len(cities) - 1):
            #dist1 is the current distance between a pair of points 
            dist1 = distanceBetween(cities, route[i], route[i + 1]) + distanceBetween(cities, route[j], route[j + 1])
            #dist2 is the distance when those points are swapped
            dist2 = distanceBetween(cities, route[i], route[j]) + distanceBetween(cities, route[i + 1], route[j + 1])
            #If the swapped point is better, we want to use it
            if dist2 < dist1:
                #This line performs the point swap operation, assigning the new route to those swapped points
                newRoute = route[:i + 1] + route[j:i:-1] + route[j + 1:]
                #The distance is calculated
                distance = distance - dist1 + dist2
                route = newRoute
    #The distance is returned
    return [distance] + route

#the distanceBetween function will find the distance between two cities
def distanceBetween(cities, city1, city2):
    #This is the y coord
    citiesY = cities.get(city1)[1] - cities.get(city2)[1]
    #This is the x coord
    citiesX = cities.get(city1)[0] - cities.get(city2)[0]
    #the distance between them is returned
    return int(round(math.sqrt(citiesX * citiesX + citiesY * citiesY)))

#the outputFunction will output a new file with the name inputFile + ".tour"
def outputFunction(inputFileName, trip):
    #Add .tour to the fileName
    fileName = inputFileName + ".tour"

    #Write each visited city into the new .tour file
    with open(fileName, 'w') as f:
        #For loop cycles through all of the cities that were visited
        for value in trip:
            f.write(str(value) + '\n')
        #Close the file
        f.close()

#Calls the main function
if __name__ == '__main__':
    main(sys.argv[1])