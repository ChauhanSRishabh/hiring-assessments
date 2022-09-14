# Find perimeter of a polygon
# Coordinates of vertices are provided in (x,y) format

from math import sqrt

def getDistance(x1, y1, x2, y2):
   d =  sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))
   return d

def findPerimeter(coordinates):
   x0, y0 = coordinates[0]
   x1, y1 = x0, y0
   
   perimeter = 0

   for i in range(1, 5):
      x2, y2 = coordinates[i]
      perimeter = perimeter + getDistance(x1,y1,x2,y2)
      x1 = x2
      y1 = y2
   perimeter = perimeter + getDistance(x1,y1,x0,y0)
   return perimeter

coordinates = [(2,1), (5,1), (6, 4), (3,6), (1, 4)]
print(findPerimeter(coordinates))
