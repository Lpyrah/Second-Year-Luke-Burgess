import numpy as np
import scipy as sci
import matplotlib.pyplot as m

data1 = np.loadtxt("outputBoyer.txt")
data2 = np.loadtxt("outputBoyerDouble.txt")
data3 = np.loadtxt("outputBoyerQuad.txt")

m.title("BoyerMoore comparion of file size")
m.ylabel("Time MilliSeconds")
m.boxplot((data1,data2,data3))
m.xticks([1,2,3],['Normal','Double','Quadruple'])
m.show()
