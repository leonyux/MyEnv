class A(object):
  a = 1
  @staticmethod
  def foo(val):
    print 'foo', val
  @classmethod
  def bar(cls, val):
    print 'bar', cls, val, cls.a
  def boo(self, val):
    print 'boo', self, val, self.a

class B(A):
  a = 10
  @staticmethod
  def foo(val):
    print 'B.foo', val
  @classmethod
  def bar(cls, val):
    print 'B.bar', cls, val, cls.a
  def boo(self, val):
    print 'B.boo', self, val, self.a

