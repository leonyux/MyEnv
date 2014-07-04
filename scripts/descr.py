class DevNull(object):
  def __init__(self, name=None):
    self.name = name
  def __get__(self, obj, typ=None):
    print 'Accessing [%s]... ignoring' % self.name
  def __set__(self, obj, val):
    print 'Assigning %r to [%s]... ignoring' % (val, self.name)


class DevNull2(object):
  def __init__(self, name=None):
    self.name = name
  def __get__(self, obj, typ=None):
    print 'Accessing [%s]... ignoring' % self.name
# def __set__(self, obj, val):
#   print 'Assigning %r to [%s]... ignoring' % (val, self.name)

class C(object):
  foo = DevNull('foo')
  bar = DevNull2('bar')

c = C()
print C.foo
print C.bar
print c.foo
print c.bar
print "c.bar = 'a'"
c.bar = 'a'
print c.bar
print "c.foo = 'b'"
c.foo = 'b'
print c.foo
print "c.bar = DevNull('bar2')"
c.bar = DevNull('bar2')
print c.bar
print 'del c.bar'
del c.bar
print 'c.bar'
c.bar

class D:
  foo = DevNull('foo')
  bar = DevNull('bar')

d = D()
print D.foo
print D.bar
print d.foo
print d.bar
print "d.bar = 'a'"
d.bar = 'a'
print d.bar
print "d.foo = 'b'"
d.foo = 'b'
print d.foo
print "d.bar = DevNull('bar2')"
d.bar = DevNull('bar2')
print d.bar
print 'del d.bar'
del d.bar
print 'd.bar'
d.bar
