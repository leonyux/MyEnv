class A(object):
# def __add__(self, other):
#   if isinstance(other, B):
#     return other.__radd__(self)
#   print 'A.__add__(): self =', self, 'other =', other
  def __radd__(self, other):
    print 'A.__radd__(): self =', self, 'other =', other

class B(object):
  def __add__(self, other):
    print 'B.__add__(): self =', self, 'other =', other
# def __radd__(self, other):
#   print 'B.__radd__(): self =', self, 'other =', other

#>>1 + b
#Traceback (most recent call last):
#  File "<stdin>", line 1, in ?
#TypeError: unsupported operand type(s) for +: 'int' and 'B'
#>>int.__add__(1, b)
#NotImplemented

