import numpy as np
import pandas as pd
# Split data into train and test formate
from sklearn.model_selection import train_test_split

from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score


student_score = pd.read_csv('data.csv')

X = student_score.iloc[ :, :-1]

y = student_score.iloc[ :, -1]

X = X.values
y = y.values.reshape((-1, 1))

# Thêm 1 cột mà các phần tử bằng 1 để tính w0 ( bias)
one = np.ones((X.shape[0], 1))
Xbar = np.concatenate((one, X), axis = 1)

X_train, X_test, y_train, y_test = train_test_split(Xbar, y, test_size = 0.2, random_state = 23)

# Linear Regression

# Tính trọng số : w =  ((X^T*X)^-1)*(X^T*y)

A = np.dot(X_train.T, X_train)

b = np.dot(X_train.T, y_train)

w = np.dot(np.linalg.pinv(A), b)

y_pred = np.dot(X_test, w)

print("y_pred")
print(y_pred)

print("y_test")
print(y_test)

# Evaluation : đánh giá 

print(r2_score(y_test, y_pred))

