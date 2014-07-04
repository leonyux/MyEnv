class Z(object):
  z = 'z'

class A(Z):
  a = 'a'

class B(A):
  def __getattr__(self, attr):
    print 'getattr:', attr
  def __getattribute__(self, attr):
    print 'getattribute:', attr
    raise AttributeError

