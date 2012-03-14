import urllib2
import re
import httplib
import getpass
import base64
import re
import time
import serial
from BeautifulSoup import BeautifulSoup

status = 'PN'

page = urllib2.urlopen("https://www.google.com/")
soup = BeautifulSoup(page)

status = soup.find(text = re.compile('Gogle'))
print status

ser = serial.Serial('COM3')
if status == 'PN':
	ser.write("m")
else:
	ser.write("n")
ser.close()

