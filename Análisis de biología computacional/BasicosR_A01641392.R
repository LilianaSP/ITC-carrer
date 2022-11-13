#Ejercicio 1
x = c(10,11,13,-1,6,3)
print(x)
#Se le asgina a la variable x el vector dado

#Ejercicio 2
#mean-> calcular la media
#sd-> calcular la desviación etándar
#var-> calcular la varianza
#x-> variable que contiene el vector
media = mean(x)
estandar = sd(x)
varianza = var(x)

est.x = c(media, estandar, varianza)
print(est.x)

#Ejercicio 3
#sum-> para obtener la suma de los números acumulados
secuencia = c(20:50)
media.sec = mean(20:60)
sumatoria = sum(51:91)

print(secuencia)
print(media.sec)
print(sumatoria)

# Ejercicio 4
#samle-> funciona para obtener valores aleatorios enteros.
#se escribe el valor del que se inicia, el valor hasta el que se quiere,
#los valores aleatorios que se busca que contenga el vector creado.

vector1 = sample(-100:50,10)

# Ejercicio 5
fb <- numeric(10)
fb[1] <- fb[2] <- 1

for (i in 3:10)
{
  fb[i] = fb[i-1] + fb[i-2]
}

# Ejercicio 6
min_y_max <- function(arr)
{
  mini = min(arr)
  maxi = max(arr)
  
  sprintf("El valor máximo del array es %i, mientras que el mínimo es %i.", maxi, mini)
  #sprintf("El valor mínimo del array es %i.", mini
}

a = c(10, 20, 30, 4, 50, -60)
b = c(10, 20, 30, 4, 50, -60)

min_y_max(a)
min_y_max(b)

#Ejercicio 7

multiplicacion = function(x,y)
{
  x * y
}

multiplicacion(c(10,20),c(3,4)) = resultado

print(resultado)
# se crea una función donde se multiplique x y y
# se aplica la función de multiplicación a los dos vectores que se desean multiplicar

#Ejercicio 8
cuenta = function(v,n)
{
  count = 0
  for(i in v){
    if(i == n)
      count = count + 1
  }
  count
}

print(cuenta(c(10,20,10,7,24,7,5),7))
#Ejercicio 9
termino_enesimo = function(vec,num)
{
  vec2 = seq(min(vec),max(vec), by=num)
  vec2
}

v = (1:100)
termino_enesimo(v,5) 



