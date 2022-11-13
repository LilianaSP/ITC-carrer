## Daniel Emilio Fuentes Portaluppi - A01708302
## Daniel Muñoz Lozano - A01721797
## Liliana Solórzano Pérez - A01641392

#Ejercicio 1
#Escribe una función que genere una secuencia aleatoria de DNA de tamaño “n”.
 n <- readline(prompt = "Escribe el tamaño del ADN: ")
 DNAbases = c("A", "T", "C", "G") #crear el vector de las bases del DNA
 
 DNAgenerator <- function(DNAbases,n){
   DNAbases = c("A", "C", "T", "G")
     return(sample(DNAbases, n, replace = TRUE))
   
 }
   dnagenerator = DNAgenerator(bases, n)
   dnagenerator
   
#Ejercicio 2
#Codifica una función que calcula el tamaño de una secuencia de DNA.
  
n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G") 

lengthDNA <- sample(DNAbases, n, replace = TRUE)

DNAsize <- function(lengthDNA){
  print("Número de bases en la secuencia: ")
  return(length(lengthDNA)/2)
}
DNAsize(lengthDNA) #presentar el resultado en la consola

#Ejercicio 3
# Crea una función que recibe una secuencia de DNA e imprime el 
#porcentaje de cada base en la secuencia
n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G")
DNAporcentaje <- sample(DNAbases, n, replace = TRUE)

percentage <- function(DNAporcentaje) {
  A <- 0
  t <- 0
  C <- 0
  G <- 0
  for(i in 1:length(DNAporcentaje)) {
    if(DNAporcentaje[i] == "A") {
      A <- A + 1
    } else if(DNAporcentaje[i] == "T") {
      t <- t + 1
    } else if(DNAporcentaje[i] == "C") {
      C <- C + 1
    } else if(DNAporcentaje[i] == "G") {
      G <- G + 1
    }
  }
  #multiplicar por 100 para quitar el punto decimal
  print("Porcentaje de Adenina en la secuencia: ")
  print((A/length(DNAporcentaje))*100)
  print("Porcentaje de Timina en la secuencia: ")
  print((t/length(DNAporcentaje))*100)
  print("Porcentaje de Citosina en la secuencia: ")
  print((C/length(DNAporcentaje))*100)
  print("Porcentaje de Guanina en la secuencia: ")
  print((G/length(DNAporcentaje))*100)
}

percentage(DNAporcentaje)

#Ejercicio 4
#Programa una función que transcribe  DNA a RNA.
#Se debe de cambiar la T por l U
n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G")
dna <- sample(DNAbases, n, replace = TRUE)

transcription <- function(dna) {
  DNA1 <- c()
  rna <- c()
  for(i in 1:length(dna)) {
    if(dna[i] == "A") {
      DNA1[i] <- "T"
    } else if(dna[i] == "T") {
      DNA1[i] <- "A"
    } else if(dna[i] == "C") {
      DNA1[i] <- "G"
    } else if(dna[i] == "G") {
      DNA1[i] <- "C"
    }
  }
  
  for(i in 1:length(DNA1)) {
    if(DNA1[i] == "A") {
      rna[i] <- "U"
    } else if(DNA1[i] == "T") {
      rna[i] <- "A"
    } else if(DNA1[i] == "C") {
      rna[i] <- "G"
    } else if(DNA1[i] == "G") {
      rna[i] <- "C"
    }
  }
  return(rna)
}

transcription(dna)

#Ejercicio 5
#Crea una función que traduce una secuencia de RNA a una secuencia de proteínas
n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G")
dna <- sample(DNAbases, n, replace = TRUE)
transcription # se llama a la función realizada anteriormente
rna <- transcription(dna)
codones <- c() #se crea el vector donde se alamcenarán los codones
i <- 1
j <- 1

traduce <- function(i) {
  if(i == "UUU" || i == "UUC") {
    print("Phe")
  } else if(i == "UUA" || i == "UUG" || i == "CUU" || i == "CUC" || i == "CUA" || i == "CUG") {
    print("Leu")
  } else if(i == "UCU" || i == "UCC" || i == "UCA" || i == "UCG" || i == "AGU" || i == "AGC") {
    print("Ser")
  } else if(i == "UAU" || i == "UAC") {
    print("Tyr")
  } else if(i == "UGU" || i == "UGC") {
    print("Cys")
  } else if(i == "UGG") {
    print("Trp")
  } else if(i == "CCU" || i == "CCC" || i == "CCA" || i == "CCG") {
    print("Pro")
  } else if(i == "CAU" || i == "CAC") {
    print("His")
  } else if(i == "CAA" || i == "CAG") {
    print("Gln")
  } else if(i == "CGU" || i == "CGC" || i == "CGA" || i == "CGG" || i == "AGA" || i == "AGG") {
    print("Arg")
  } else if(i == "AUU" || i == "AUC" || i == "AUA") {
    print("Ile")
  } else if(i == "AUG") {
    print("Met")
  } else if(i == "ACU" || i == "ACC" || i == "ACA" || i == "ACG") {
    print("Thr")
  } else if(i == "AAU" || i == "AAC") {
    print("Asn")
  } else if(i == "AAA" || i == "AAG") {
    print("Lys")
  } else if(i == "GUU" || i == "GUC" || i == "GUA" || i == "GUG") { 
    print("Val")
  } else if(i == "GCU" || i == "GCC" || i == "GCA" || i == "GCG") {
    print("Ala")
  } else if(i == "GAU" || i == "GAC") {
    print("Asp")
  } else if(i == "GAA" || i == "GAG") { 
    print("Glu")
  } else if(i == "GGU" || i == "GGC" || i == "GGA" || i == "GGG") {
    print("Gly")
  } else if(i == "UAA" || i == "UAG" || i == "UGA") {
    return("STOP")
  }
}

while(i < length(rna)) {
  codones[j] <- sprintf("%s%s%s", rna[i], rna[i + 1], rna[i + 2])
  j <- j + 1
  i <- i + 3
}

for(i in 1:length(codones)) {
  codon <- codones[i]
  if(traduce(codon) == "STOP") {
    print("STOP")
    break
  }
}


#Ejercicio 6
#Escribe una función que recibe una hebra directa y regresa la hebra inversa
n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G")
DNA <- sample(DNAbases, n, replace = TRUE)

invertir <- function(DNA){
  return(rev(DNA)) #usar rev para invertir la hebra de DNA
}

invertir(DNA)

#Ejercicio 7
#Escribe una función que recibe una hebra directa y obtiene la hebra complementaria

n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G")
DNA <- sample(DNAbases, n, replace = TRUE)
transcription <- function(dna) {
  DNA1 <- c()
  rna <- c()
  for(i in 1:length(dna)) {
    if(dna[i] == "A") {
      DNA1[i] <- "T"
    } else if(dna[i] == "T") {
      DNA1[i] <- "A"
    } else if(dna[i] == "C") {
      DNA1[i] <- "G"
    } else if(dna[i] == "G") {
      DNA1[i] <- "C"
    }
  }
  return(DNA1) #se lleva a cabo la función de transcription pero usa el DNA1
}
transcription(DNA)

#Ejercicio 8
# Escribe la función en R para obtener 
#la hebra complementaria inversa, desde una hebra complementaria

n <- readline(prompt = "Escribe el tamaño del ADN: ")
DNAbases = c("A", "T", "C", "G")
DNA <- sample(DNAbases, n, replace = TRUE)
transcription # se llama a la función realizada anteriormente
DNACom <- transcription(DNA)
invertir # se llama a la función realizada anteriormente
invertir <- function(DNACom){
  return(rev(DNACom))
}
invertir(DNACom)


