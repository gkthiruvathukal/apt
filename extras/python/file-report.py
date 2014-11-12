import os
import sys
import string

files = {}
types = {}
p = os.popen('find %s -type f -exec file {} \;' % sys.argv[1])

for inputLine in p.readlines():
   inputLine = inputLine[:-1]
   (file, type) = string.split(inputLine,":")[0:2]
   if not types.has_key(type):
      types[type] = []
   types[type].append(file)

for type in types.keys():
   print "*",type
   for file in types[type]:
      print "\t",file
