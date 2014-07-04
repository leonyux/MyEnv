class a(object):
  x = 1
  def i(self):
    print 'a'
  #def __init__(self):
   # a.x = a.x + 2

class b(a):
  y = 2
  def i(self):
    print 'b'
  def j(self):
    print 'bj'
  def __init__(self):
   a.__init__(self)
   self.x = b.x + 2
   #b.y = b.y + 2
  
