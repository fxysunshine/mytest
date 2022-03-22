#!/usr/bin/python2.7

import sys
import os
import time
from os import listdir
from os.path import join, isfile, isdir, islink

def delDirDepthFirst(directory):
	#print directory
	for subDir in listdir(directory):
		path = join(directory, subDir)
		if islink(path):
			#print "islink"
			#print path
			os.remove(path)
		elif isdir(path):
			#print "isdir"
			delDirDepthFirst(path)
			#print path
			os.rmdir(path)
			#print "sleep 0.2"
			time.sleep(0.2)
		else:
			#print "iselse"
			#print path
			os.remove(path)

#print len(sys.argv)
#print str(sys.argv)

if len(sys.argv) < 2:
	print "need path to delete"
	sys.exit(2)

#print sys.argv[0]
#print sys.argv[1]
#print "start remove"
directory = sys.argv[1]
delDirDepthFirst(directory)

if directory != '.':
	os.rmdir(directory)
