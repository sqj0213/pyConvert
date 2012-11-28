#!/bin/env python
#coding=utf-8
import pyConvert,time,os
import ConfigParser

def convertListToDict( conf ):
    dictObj = dict()
    sectionsList = conf.sections()
    for val1 in sectionsList:
        dictObj[ val1 ] = dict( conf.items( val1 ) )
    return dictObj 

cf = ConfigParser.ConfigParser()
cf.read( "./conf/conf.ini" )
iniDict = convertListToDict( cf )




for filenames in os.walk( "./image/src" ):
    pass
fileList = filenames[2]
fileListPre = []

for filename1 in filenames[2]:
    fileListPre.append( os.path.splitext( filename1 )[0] )

#print fileList
#print fileListPre

binCMDDick = iniDict['binCmd']
b1 = time.time()
#for i in range( 0, 100 ):
for (k,v) in binCMDDick.items():
    print v
    v1 = v
    for i in range( 0, len( fileList ) ):
        v2 = v1.replace("__FILENAME__", fileList[i] )
        v2 = v2.replace("__FILENAMEPRE__", fileListPre[i] )
        os.popen(str(v2))
b2 = time.time()
print "/usr/bin/convert:"+str(b2)+"-"+str(b1)+"="+str(b2-b1)




cmdDict = iniDict['cmd']
b1 = time.time()
for (k,v) in cmdDict.items():
    print v
    v1 = v
    for i in range( 0, len( fileList ) ):
        v2 = v1.replace("__FILENAME__", fileList[i] )
        v2 = v2.replace("__FILENAMEPRE__", fileListPre[i] )
        pyConvert.pyConvert(str(v2).split(" "))
b2 = time.time()
print "pyConvert.so:"+str(b2)+"-"+str(b1)+"="+str(b2-b1)




cmdPYDict = iniDict['binPYCmd']
b1 = time.time()
for (k,v) in cmdPYDict.items():
    print v
    v1 = v
    for i in range( 0, len( fileList ) ):
        v2 = v1.replace("__FILENAME__", fileList[i] )
        v2 = v2.replace("__FILENAMEPRE__", fileListPre[i] )
        pyConvert.pyConvert(str(v2).split(" "))
b2 = time.time()
print "./pyConvert:"+str(b2)+"-"+str(b1)+"="+str(b2-b1)


cmdPYDict = iniDict['newCMD']
b1 = time.time()
for (k,v) in cmdPYDict.items():
    print v
    v1 = v
    for i in range( 0, len( fileList ) ):
        v2 = v1.replace("__FILENAME__", fileList[i] )
        v2 = v2.replace("__FILENAMEPRE__", fileListPre[i] )
        pyConvert.pyConvert(str(v2).split(" "))
b2 = time.time()
print "./convert6.5.4-10:"+str(b2)+"-"+str(b1)+"="+str(b2-b1)
