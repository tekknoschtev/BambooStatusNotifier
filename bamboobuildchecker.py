import urllib2
import re
import httplib
import getpass
import base64
import re
import time
import serial
from BeautifulSoup import BeautifulSoup

status = 'N'

page = urllib2.urlopen("https://www.google.com/")
soup = BeautifulSoup(page)

result = soup.find(text = re.compile('Gogle'))

if result == 'Google':
	status = 'Y'
else:
	status = 'N'

ser = serial.Serial('COM3')
if status == 'Y':
	ser.write("n")
else:
	ser.write("m")

print status
print result
	
ser.close()

