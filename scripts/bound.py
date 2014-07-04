class A(object):
  @staticmethod
  def foo():
    print 'A.foo()'
  @classmethod
  def bar(cls):
    print 'A.bar(), cls =', cls
  def boo(self):
    print 'A.boo(), self =', self

#>>> from bound import A
#>>> A.foo
#<function foo at 0xb7beca74>
#>>> A.bar
#<bound method type.bar of <class 'bound.A'>>
#>>> A.boo
#<unbound method A.boo>
#>>> a = A()
#>>> a.foo
#<function foo at 0xb7beca74>
#>>> a.bar
#<bound method type.bar of <class 'bound.A'>>
#>>> a.boo
#<bound method A.boo of <bound.A object at 0xb7be9f4c>>
#>>> 
