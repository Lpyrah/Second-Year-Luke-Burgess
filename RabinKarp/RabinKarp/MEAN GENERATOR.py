import numpy as np
import scipy as sci
import matplotlib.pyplot as m

data1 = np.loadtxt("outputRabin.txt")
data2 = np.loadtxt("outputRabinDouble.txt")
data3 = np.loadtxt("outputRabinQuad.txt")

m.title("RabinKarp comparion of file size")
m.ylabel("Time MilliSeconds")
m.boxplot((data1,data2,data3))
m.xticks([1,2,3],['Normal','Double','Quadruple'])
m.show()
