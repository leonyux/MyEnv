#!/usr/bin/env python

def counter(start_at = 0):
  count = start_at
  while True:
    val = (yield count)
    if val is not None:
      count = val
    else count += 1
