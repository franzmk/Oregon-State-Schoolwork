#!/usr/bin/python
#Max Franz

import sys
import pyqrcode
import base64
import hmac
import math
import array
import time
import hashlib
import io

#This function will generate a QR code with a set secret key
def genQR():
	#The QR code is created
	url = pyqrcode.create('otpauth://totp/Max:alice@google.com?secret=JBSWY3DPEHPK3PXP&issuer=Max')

	#The QR code is saved as an SVG
	url.svg('qrcode.svg', scale=4)

	buffer = io.BytesIO()
	url.svg(buffer)

	#print(list(buffer.getvalue()))

#This function will truncate the hmac
def truncate(mac):
	#The offset is the last value in the mac
	offset = int(mac[-1], 16)
	offsetVal = offset * 2

	#This var will grab the first 4 bytes starting at the offset that was grabbed above
	binary = int(mac[(offsetVal):((offsetVal) + 8)], 16)

	#The 0x7fffffff is a binary operation that will convert the 4 bytes that were grabbed from the offset
	binary = binary & 0x7fffffff

	#Return it as a string in order to grab the last 6 digits in the other function
	return str(binary)

#This function will generate the otp based on the static secret key used above
def otp():
	secret = 'JBSWY3DPEHPK3PXP'
	#Converts the secret so it'll work with hmac.new()
	key = base64.b32decode(secret, True)

	#Get's the Unix Time and divides by 30
	counter = int(math.floor(time.time() / 30))
	
	#Convert the Unix Time variable into a byte array
	timeByteArray = array.array('B')
	for i in range(0, 8):
		timeByteArray.insert(0, counter & 0xff)
		counter >>= 8

	#Create the hmac
	mac = hmac.new(key, timeByteArray, hashlib.sha1).hexdigest()

	#Call truncate and then grab just the last 6 digits
	result = truncate(mac)
	#If the binary wasn't returned as a string, I couldn't do this 
	result = result[-6:]

	#Print the result
	print("OTP: " + result)

#This is the main function that will check commandline arguments
def main():
	#Check if there's enough commandline arguments, if not exit
	if len(sys.argv) < 2:
		sys.exit("Not enough commandline arguments!")
	#If there is enough, it will check which function is being called
	else:
		#Calls the qr code function
		if sys.argv[1] == '--generate-qr':
			genQR()
		#Calls the otp function
		elif sys.argv[1] == '--get-otp':
			otp()
		#Exit if wrong commandline argument
		else:
			sys.exit("Wrong commandline argument used!")

#Call the main function
if __name__ == '__main__':
	main()
