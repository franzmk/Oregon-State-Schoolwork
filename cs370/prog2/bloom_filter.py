#!/usr/bin/python

import sys
import hashlib
import math
import os.path
from os import path
import time


#This function will hash the input string using SHA224
def hash1(s, blen):
	m = hashlib.sha224()
	m.update(s)
	temp = m.hexdigest()
	return (int(temp, 16) % blen) #The return value is modded by the length of the bloom filter in order to return an index

#This function will hash the input string using SHA224
def hash2(s, blen):
	m = hashlib.sha256()
	m.update(s)
	temp = m.hexdigest()
	return (int(temp, 16) % blen) #The return value is modded by the length of the bloom filter in order to return an index

#This function will hash the input string using SHA224
def hash3(s, blen):
	m = hashlib.sha384()
	m.update(s)
	temp = m.hexdigest()
	return (int(temp, 16) % blen) #The return value is modded by the length of the bloom filter in order to return an index

#This function will hash the input string using SHA224
def hash4(s, blen):
	m = hashlib.sha512()
	m.update(s)
	temp = m.hexdigest()
	return (int(temp, 16) % blen) #The return value is modded by the length of the bloom filter in order to return an index

#This function will hash the input string using SHA224
def hash5(s, blen):
	m = hashlib.md5()
	m.update(s)
	temp = m.hexdigest()
	return (int(temp, 16) % blen) #The return value is modded by the length of the bloom filter in order to return an index

#This function will take the dictionary of words as an input and will fill the bloom filter correctly with 3 hash functions
def insert3(bloom3, dictionary):
	for word in dictionary: #Every word in the dictionary is hashed three times in order to get the appropriate indexes
		index1 = hash1(word, len(bloom3)) 
		index2 = hash2(word, len(bloom3))
		index3 = hash3(word, len(bloom3))

		#If the indexes aren't 1 already, they're flipped to 1
		if bloom3[index1] == 0:
			bloom3[index1] = 1
		if bloom3[index2] == 0:
			bloom3[index2] = 1
		if bloom3[index3] == 0:
			bloom3[index3] = 1

#This function will take the dictionary of words as an input and will fill the bloom filter correctly with 5 hash functions
def insert5(bloom5, dictionary):
	for word in dictionary: #Every word in the dictionary hashed five times in order to get the correct number of indexes
		index1 = hash1(word, len(bloom5))
		index2 = hash2(word, len(bloom5))
		index3 = hash3(word, len(bloom5))
		index4 = hash4(word, len(bloom5))
		index5 = hash5(word, len(bloom5))

		#If the indexes aren't 1 already, they're flipped to 1
		if bloom5[index1] == 0:
			bloom5[index1] = 1
		if bloom5[index2] == 0:
			bloom5[index2] = 1
		if bloom5[index3] == 0:
			bloom5[index3] = 1
		if bloom5[index4] == 0:
			bloom5[index4] = 1
		if bloom5[index5] == 0:
			bloom5[index5] = 1

#This function will take finput that holds the passwords that are being checked against the bloom filter
def check3(bloom3, finput):
	b3_start = time.time() #The whole thing is timed
	for inputs in finput: #Every input is hashed three times 
		index1 = hash1(inputs, len(bloom3))
		index2 = hash2(inputs, len(bloom3))
		index3 = hash3(inputs, len(bloom3))

		#If all of the indexes are 1, then that input might be in the bloom filter
		if bloom3[index1] == 1 and bloom3[index2] == 1 and bloom3[index3] == 1:
			#The output3.txt file is opened and maybe is written
			out3 = open(sys.argv[6], "a")
			out3.write("maybe\n")
			out3.close()
		else: #If any of the indexes are 0, the input is not in the bloom filter
			#The output3.txt file is opened and no is written
			out3 = open(sys.argv[6], "a")
			out3.write("no\n")
			out3.close()
	b3_end = time.time() #The timer is stopped
	b3_time = b3_end - b3_start
	print("Bloom Filter 3 Time: " + str(b3_time)) #The time is printed

#This function will take finput that holds the passwords that are being checked against the bloom filter
def check5(bloom5, finput):
	b5_start = time.time() #This is also timed
	for inputs in finput: #Every input is hashed five times
		index1 = hash1(inputs, len(bloom5))
		index2 = hash2(inputs, len(bloom5))
		index3 = hash3(inputs, len(bloom5))
		index4 = hash4(inputs, len(bloom5))
		index5 = hash5(inputs, len(bloom5))

		#If all of the indexes are 1, then the input might be in the bloom filter
		if bloom5[index1] == 1 and bloom5[index2] == 1 and bloom5[index3] == 1 and bloom5[index4] == 1 and bloom5[index5] == 1:
			out5 = open(sys.argv[7], "a")
			out5.write("maybe\n")
			out5.close()
		else: #If any of the indexes are 0, then the input is not in the bloom filter
			out5 = open(sys.argv[7], "a")
			out5.write("no\n")
			out5.close()
	b5_end = time.time() #The timer is stopped
	b5_time = b5_end - b5_start
	print("Bloom Filter 5 Time: " + str(b5_time))

#This function will run the program
def main():
	if len(sys.argv) < 8: #This will check if the right number of commandline arguments are being used
		sys.exit("Not enough commandline arguments! Exiting...")
	else: #If there is enough, the program will run
		if path.exists('output3.txt') == False: #This checks if the output3.txt file exists, if it doesn't, one is created
			f = open('output3.txt', "w+")
			f.close()
		else: #If it does exist, it's removed and a new one is created
			os.remove('output3.txt')
			f = open('output3.txt', "w+")
			f.close()
		#This will check if the output5.txt file exists, if it doesn't then one is created
		if path.exists('output5.txt') == False:
			f = open('output5.txt', "w+")
			f.close()
		else: #If it does exist, it's removed and a new one is created
			os.remove('output5.txt')
			f = open('output5.txt', "w+")
			f.close()

		#This is the variable that holds the dictionary of words to be inserted into the bloom filter
		dictionary = open(sys.argv[2]).read().splitlines()

		n = len(dictionary)
		p = 0.05
		
		#This is the 3 hash function bloom filter
		bloom3 = [0]*4000000

		#The dictionary of words is inserted into the bloom filter
		insert3(bloom3, dictionary)

		#This is the 5 hash function bloom filter
		bloom5 = [0]*6000000

		#The dictionary of words is inserted into the bloom filter
		insert5(bloom5, dictionary)

		#This variable holds the list of bad passwords to be checked against the bloom filters
		finput = open(sys.argv[4]).read().splitlines()

		#This function checks against the 3 hash function bloom filter
		check3(bloom3, finput)

		#This function checks against the 5 hash function bloom filter
		check5(bloom5, finput)

#The main function is called
main()
