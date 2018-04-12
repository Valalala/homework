#!/usr/bin/python
# Walter Rasmussen - Spring 2018
# Prints list of unique user shells found in /etc/passwd

try: # Checks if file can be opened(permissions, etc.). 
	rfile = open( "/etc/passwd", "r") # Opens file. 
except:
	print("Could not open file.")
	quit()

used = [] # Empty list; Stores shell names that have already been printed. 

for line in rfile: # Reads file line by line. 
	try:
		col = line.split(":") # Splits line by colon delimiter. 
		if col[6] in used: # Checks the 7th column for new shell name. 
			pass
		else:	
			print(col[6])
			used.append(col[6]) # Adds shell name to list
	except:
		pass

rfile.close() # Closes file. 

