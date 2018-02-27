#!/usr/bin/python
# Walter Rasmussen - Spring 2018
# Fetches web page and prints to file.

import sys
import requests

# Check args. 
if (len(sys.argv) != 2):
	print "fix your args"
	sys.exit()

# Fetchs contents of url given in arg. 
url = sys.argv[1]
page = requests.get(url)

# Checks if url is valid.
if (page.status_code != 200):
	print "Website does not exist. "
	sys.exit()

# Writes website html line by line into file.
webfile = open("site","w")
for line in page:
	webfile.write(line)
webfile.close()

print("Success. ")
