def foo():
  fooa = 1
  foob = '1'
  def bar():
    bara = 2
    barb = '2'
    print "bar()'s local:", locals().keys()
    print "bar()'s global:", globals().keys()
    print "fooa:", fooa
  
  print "foo()'s local:", locals().keys()
  print "foo()'s global:", globals().keys()
  bar()


print "__main__'s local:", locals().keys()
print "__main__'s global:", globals().keys()

foo() 
