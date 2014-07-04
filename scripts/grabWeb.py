#!/usr/bin/env python
'simple web graber'

from urllib import urlretrieve

def firstNonBlank(lines):
  for eachLine in lines:
    if not eachLine.strip():
      continue
    else:
      return eachLine

def firstLast(webpage):
  f = open(webpage)
  lines = f.readlines()
  f.close()
  print firstNonBlank(lines),
  lines.reverse()
  print firstNonBlank(lines),

def download(url = 'http://www',
             process = firstLast):
  try:
    retval = urlretrieve(url)[0]
  except IOError:
    retval = None
  print 'retval:%s'% retval
  if retval:
    process(retval)

if __name__ == '__main__':
  download(url = 'http://172.16.122.155')
