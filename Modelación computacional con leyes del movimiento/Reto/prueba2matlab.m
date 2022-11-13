archivo="prueba 2.xlsx";
datos= xlsread(archivo);
M1=datos(:,1);
M2=datos(:,2);

plot(M2,M1);

trapz(M2,M1);