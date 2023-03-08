from functools import wraps
from time import time

def runTime(f):
  @wraps(f)
  def wrap(*arg, **kw):
        ts=time()
        result=f(*arg, **kw)
        te=time()
        print('{:.10f}'.format(te-ts))
        return result
        
  return wrap


@runTime
def which_finger(num):
    if num>=1 and num<=5:
        print(num)
        return num
    if num>5:
        r=num%8 
        print(r)
        return r


which_finger(11)