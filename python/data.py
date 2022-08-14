import pandas as pd
titanic_df=pd.read_csv('c:/data/train.csv')
print(titanic_df)
print(titanic_df.head(3))
print(titanic_df.tail(3))
print(titanic_df.info())
print(titanic_df.describe())
valule_counts=titanic_df['Pclass'].value_counts()
print(valule_counts)
valule_counts=titanic_df['Survived'].value_counts()
print(valule_counts)
print(titanic_df.sort_values('Fare',ascending=False))
titanic_df['Age_0']=0
print(titanic_df)
titanic_df['Age_by_10']=titanic_df['Age']*10
print(titanic_df.head(3))
titanic_df.drop(['Age_0'],axis=1,inplace=True)
print(titanic_df.columns)
print('###befor axis 0 drop####')
print(titanic_df.head(3))
titanic_df.drop([0,1,2],axis=0, inplace=True)
print(titanic_df[titanic_df['Pclass']==3].head(3))
print(titanic_df.count())
titanic_grby=titanic_df.groupby(by='Pclass')
print(titanic_grby.sum())
