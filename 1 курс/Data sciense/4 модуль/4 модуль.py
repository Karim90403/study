#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import Perceptron
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn import neighbors
from sklearn import tree
from sklearn import svm


# In[ ]:


pd.set_option('display.max_columns',None)
url = 'https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv'
df = pd.read_csv(url, encoding='utf8')
df_filter = df[['Pclass','Sex','Age','Fare','Embarked']]
df_filter = df_filter.fillna({'Age':df_filter['Age'].mean(),
                             'Pclass' : df_filter['Pclass'].mean(),
                              'Fare':df_filter['Fare'].mean(),
                              'Embarked': df_filter['Embarked'].value_counts(sort=True).keys()[0],
                              'Sex': df_filter['Sex'].value_counts(sort=True).keys()[0]})
df_filter.loc[:, 'SexId'] = df_filter.groupby('Sex').ngroup()
df_filter.loc[:, 'EmbarkedId'] = df_filter.groupby('Embarked').ngroup()
df_filter.loc[:, 'PclassId'] = df_filter.groupby('Pclass').ngroup()
x= df_filter[['Age','PclassId','EmbarkedId','SexId','Fare']]
y = df['Survived']


# In[ ]:


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=1,stratify=y)
ppn = Perceptron(eta0 = 0.1,random_state=1)
ppn.fit(x_train,y_train)
predict = ppn.predict(x_test)
print("Персептрон")
print(accuracy_score(y_test,predict))
print(ppn.score(x_test,y_test))


# In[ ]:


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=1,stratify=y)
lr = LogisticRegression(C=0.1,random_state=1)
lr.fit(x_train,y_train)
predict= lr.predict(x_test)
print("Логистическая регрессия")
print(accuracy_score(y_test,predict))
print(lr.score(x_test,y_test))


# In[ ]:


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=1,stratify=y)
clf = svm.SVC(C = 0.1,random_state=1)
clf.fit(x_train,y_train)
predict = clf.predict(x_test)
print("Метод опорных векторов")
print(accuracy_score(y_test,predict))
print(clf.score(x_test,y_test))


# In[ ]:


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=1,stratify=y)
tr = tree.DecisionTreeClassifier(random_state=1,)
tr.fit(x_train,y_train)
predict = tr.predict(x_test)
print("Метод дерева")
print(accuracy_score(y_test,predict))
print(tr.score(x_test,y_test))


# In[ ]:


x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2,random_state=1,stratify=y)
print("Введите количество соседей для обучения")
ng = neighbors.KNeighborsClassifier(n_neighbors=int(input()))
ng.fit(x_train,y_train)
predict = ng.predict(x_test)
print("Метод обучения К ближайших соседей")
print(accuracy_score(y_test,predict))
print(ng.score(x_test,y_test))

