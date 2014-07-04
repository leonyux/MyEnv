
def a():
  x = [1]
  def b(i = 0):
    y = [1]
    print x[0], y[0] 
    x[0] += i
    y[0] += i
    print x[0], y[0]
    def c(i = 0):
      print x[0], y[0]
      x[0] += i
      y[0] += i
      print x[0], y[0]
    return c
  return b



def b():
  x = [1]
  def a():
   x[0] = 2
  print x[0]
  a()
  print x[0]
