import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm
#Hard code simple data set
#x = [1, 5, 1.5, 8, 1, 9]
#y = [2, 8, 1.8, 8, 0.6, 11]
#plt.scatter(x,y)
#plt.show()
X = np.array([[1,2],[5,8],[1.5,1.8],[8,8],[1,0.6],[9,11]])
y = [0,1,0,1,0,1]# line left right
clf = svm.SVC(kernel='linear', C = 1.0)# svm class clf object liner staright c losse fiittting 
clf.fit(X,y)#X data , y labels
w = clf.coef_[0]
print(w)
a = -w[0] / w[1]
xx = np.linspace(0,12)# xx,yy line coordinate array of pts
yy = a * xx - clf.intercept_[0] / w[1]
h0 = plt.plot(xx, yy, 'k-', label="Non weighted div")# plot k- starigth line
plt.scatter(X[:, 0], X[:, 1], c = y)# values input coordinates
plt.legend()# index of graph
plt.show()# to show
print("Prediction of target for 0.58,0.76 values:")
t= clf.predict([[0.58,0.76]])# random poits
print(t)
print("Prediction of target for given value")

t= clf.predict([[10.58,10.76]])
print(t)

'''
Prediction of target for 0.58,0.76 values:
[0]
Prediction of target for given value
[1]
'''