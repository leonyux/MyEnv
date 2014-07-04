class A(object):
  a = 1
  def foo(self):
    print 'A.foo(), self =', self, self.a
  def bar(self):
    print 'A.bar(), self =', self
    print 'call foo():'
    self.foo()

class B(A):
  a = 2
  def foo(self):
    print 'B.foo(), self =', self, self.a
