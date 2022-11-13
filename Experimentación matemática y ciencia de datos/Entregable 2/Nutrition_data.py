import pandas as pd 
"""we import the pandas libary with the name pd instead
# we create a variable that will contain the data of our excel file
# we have to indicate that the data is in an excel file and use the function .read
# we have to be sure that the data file and the code are in the same folder
Note: be sure that the filename is short and easy"""
data = pd.read_excel('datos_nutricionales.xlsx') 

# we use the function head to get the firts 5 register of our data sheet 
data.head()

#we use shape to get to know the total number of colums and rows 
data.shape #(rows, columns)
#Expected output value: (152, 9)

#we use columns to visualize the name of all the columns in our file 
data.columns

#with the dtypes we can get to know the data type of our dataframe
data.dtypes
"""Los principales tipos de datos son:
object: cadena de texto
int64 : número entero
float64: número con decimal
datetime64: fecha y hora"""

#function info return the complete information of our dataframe
data.info()

#function describe() is used to obtain the description and the statistics
data.describe()