close all;
clear;
clc;
syms x

disp('Elige una de las siguientes opciones: ');
disp('1 - Simulación sin derrape');
disp('2 - Simulación con derrape');
disp('3 - Simulación con colisión entre automóviles');
opcion = input('Opción: ');

% %Puntos de la curva en matrices
px = [300,1066,1833,2600];
py = [2300,2300,800,800];
 


%Asigna los valores de los puntos a las variables 
coeficientes = polyfit(px, py,3);
a = coeficientes (1);
b = coeficientes (2);
c = coeficientes (3);
d = coeficientes (4);

y1 = 0.9927*10^-6*x^3 - 0.0039*x^2 + 3.0367*x + 1747.0415; %--> ecuación 
%de la curva

u = 1;
% Variables para los axis
pasoX = 1;
x = [px(1):pasoX:px(4)];
y = (a.*(x.^3) + b.*(x.^2) + c.*(x) + d );

maxX = max(x);
minX = min(x);

inicioX = px(1) - 200;
finalX = px(4)+ 400;
inicioY = minX - 400;
finalY = maxX + 400;

%Imprimir los coeficientes
axis([inicioX finalX inicioY finalY]); 
fprintf('Coeficientes = %4.10fx^3 %4.10fx^2 %4.10fx %4.10f \n', coeficientes);

p=(px(4)-px(1))/1;
longitud = 0;
for i=1:1:p
    
    longitud = longitud + sqrt ((y(i+1)-y(i))^2 + (x(i+1)-x(i))^2);
   

end 
longitud1= longitud/1000;
fprintf("Longitud: %f \n",longitud1);


dy = diff(y);
pos_min = find(diff(sign(dy)) == 2);
pos_max = find(diff(sign(dy)) == -2);

minim_x= x(pos_min + 2);

minim_y= y(pos_min + 2);

maxim_x= x(pos_max + 2);

maxim_y= y(pos_max + 2);

d1y_xminim = (a*3*minim_x^2) + (b*2*minim_x) + (c); % Primera derivada del polinomio
d2y_xminim = (a*6*minim_x) + (b*2); % Segunda derivada del polinomio

d1y_xmaxim = (a*3*maxim_x^2) + (b*2*maxim_x) + (c); % Primera derivada del polinomio
d2y_xmaxim = (a*6*maxim_x) + (b*2); % Segunda derivada del polinomio

Derivada1 = d1y_xminim - d1y_xmaxim;
Derivada2 = d2y_xminim - d2y_xmaxim;

radioC = (sqrt(1+(Derivada1^2))^3)/(abs(Derivada2)); % Fórmula del radio de curvatura
fprintf("Radio de curvatura: %f \n",radioC);

CirculoX = -radioC:0.1:radioC;
CirculoY = sqrt((radioC^2)-(CirculoX.^2));
diametro = 2*radioC;

puntos_min = [minim_x minim_y];
puntos_max = [maxim_x maxim_y];

coord_circulo = [minim_x (minim_y + diametro)];
coord_circulo2 = [maxim_x (maxim_y - diametro)];




for i = px(1):1:px(4)
    xtangente1 = i;
    ytangente1 = (a*(xtangente1^3)+b*(xtangente1^2)+c*(xtangente1)+d);
    m = (a*3*xtangente1^2)+(b*2*xtangente1)+(c);
    if m <= 1
        break;
    end
end

xtangente2 = px(1):1:xtangente1+(xtangente1-px(1)+130);
ytangente2 = m*xtangente2-(m*xtangente1-ytangente1);

funcion = @(x) (a.*(x.^3) + b.*(x.^2) + c.*(x) + d );
dfuncion = @(x) (a*3*x^2) + (b*2*x) + (c);
ddfuncion = @(x) (a*b*x) + (b*2);
funcionVMAX = @(r) (sqrt((r.*9.81.* u).*3.6));

u = 1;%coeficiente de arrastre de las llantas con asfalto seco

m1= 942; %masa del carro
m2 = 2000; %peso del muro de contensión
v1= 28.3333; %velocidad del carro antes del impacto, metros por segundo (102 km/h)
v2= 0; %velocidad del objeto (muro)

m1_= 942;
m2_=976; %peso aproximado de carro 2
v1_=46.6667; %168 km/h
v2_= 34.1667; %123 km/h del segundo carro

energia_perdida= ((((1/2)*(m1*v1^2))- ((1/2)*(m2*v2^2)))/1000000);
energia_perdida_autos= ((((1/2)*(m1_*v1_^2))- ((1/2)*(m2_*v2_^2)))/1000000);
fr = 0.8; %coeficiente de fricción investigado, (llantas turismo contra asfalto seco)
g= 9.81;
friccion = fr*(m1*g);
fprintf('Fricción generada: %f \n', friccion);%resultado en megajoules

if opcion == 1
    dt = 0.2;
else
    dt = 0.001;
    fprintf('Energía perdida durante la colisión contra el muro: %f \n', energia_perdida);
    %resultado en megajoules

end

if opcion == 3
    dt = 0.2;
    fprintf('Energía perdida durante la colisión contra otro auto: %f', energia_perdida_autos);
    %megajoules

end

figure (1);
plot (x,y);
grid on;
title ('Red Bull Ring Grand Prix', b);
xlabel ('Distancia en [m] eje x', 'FontSize',15);
ylabel ('Distancia en [m] eje y','FontSize',15);
viscircles(coord_circulo,radioC); 
viscircles(coord_circulo2,radioC); 
plot(xtangente1, ytangente1, '*b');
plot(xtangente2, ytangente2, 'Color', 'red');
axis equal;
 
Vi= 100;
hold off;

figure(2);
hold on;
set(gca,'Color','green'); %Color de fonndo (pasto)
plot(x,y, 'black', 'Linewidth',20); %Gráfica con color
plot (x+5,y+315, 'red','Linewidth',5); %Muro de contesión
plot (x-5,y-315, 'red','Linewidth',5);
plot (x,y,'--white');
axis ([inicioX, finalX, inicioY, finalY]);
title ('Red Bull Ring Grand Prix', b);
xlabel ('Distancia en [m] eje x', 'FontSize',15);
ylabel ('Distancia en [m] eje y','FontSize',15);
plot(xtangente1, ytangente1, '*b');
plot(xtangente2, ytangente2, 'Color', 'red');
grid on;
plot(minim_x,minim_y, '*b--','Linewidth',10, 'Color','r','markersize',10);
plot(maxim_x,maxim_y, '*b--','Linewidth',10, 'Color','r','markersize',10);
viscircles(coord_circulo,radioC); 
viscircles(coord_circulo2,radioC);
rectangle('Position',[900 2900 80 10]);
rectangle('Position',[2000 100 80 10]);
rectangle('Position',[300 2900 80 10]);
rectangle('Position',[2450 100 80 10]);
axis equal;
for i = px(1):1:px(4)
    dy = dfuncion(i);
    ddy = ddfuncion(i);
    Radio(i) = (sqrt(1+(dy^2))^3)/(abs(ddy));
    Vmaximo = abs((funcionVMAX(Radio(i))));
    velocidadMAX(i -px(1)+1) = Vmaximo;
   
end

for i = 1:10:length(x)-1
    carro = plot(x(i), y(i), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize',12);
    text(1500,2500,['Velocidad Máxima: ' ]);
    VelMAX = text(2600,2500, [num2str(velocidadMAX(i))]);
    text(1500,2300,['Velocidad del Carro: ' ]);
    distanciaCarro = sqrt( (y(i+10)-y(i))^2 + (x(i+10)-x(i))^2);
    
    VelocidadCarro = (distanciaCarro/ dt);
    
    Velcarro = text(2500,2300, [num2str(VelocidadCarro)]);
   
    aceleracion = ((VelocidadCarro - Vi))/(dt);
    
    Vi = VelocidadCarro;
    
    if x(i) >= 480 %El carro llega al punto de la pendiente
        if VelocidadCarro > velocidadMAX(i)
            delete(carro); %para que comience a irse el carro por la tangente
            for i = 282:1:length(xtangente2)-1
                carro = plot(xtangente2(i), ytangente2(i), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize',12);
                txt = {'COLISIÓN CON MURO'};
                text(200,1500,txt,'Color','magenta', 'FontSize', 25)
                txt1 = {'x= 783', 'y= 2905'};
                text(600,1100,txt1,'Color','magenta', 'FontSize', 25)
    
                

                pause(0.001);
                delete(carro);
                
            end
            carro = plot(xtangente2(i), ytangente2(i), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize',12);
            viscircles(coord_circulo,radioC); 
            viscircles(coord_circulo2,radioC);
            plot(minim_x,minim_y, '*b--','Linewidth',10, 'Color','r','markersize',10);
            plot(maxim_x,maxim_y, '*b--','Linewidth',10, 'Color','r','markersize',10);

            return
              
        end
        
    end

   
    if aceleracion > 0
        
        AceCarro = text(2600,2100,['+']);
        signo = text(1500,2100,['Aceleración Carro: ' ]);
 
    else 
        
        AceCarro = text(2600,2100,['-']);
        signo = text(1500,2100,['Aceleración Carro: ' ]);
        
    end
    
    pause(0.01);
    delete(carro);
    delete(VelMAX);
    delete (Velcarro);
    delete(AceCarro);
    
        if opcion == 3
                carro2 = plot(1469, 1509, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize',12);
                txt3 = {'COLISIÓN ENTRE AUTOS'};
                text(400,1200,txt3,'Color','magenta', 'FontSize', 25)
                txt4 = {'x= 1469', 'y= 1509'};
                text(700,850,txt4,'Color','magenta', 'FontSize', 25)         

        end
        
end



if opcion == 3
carro2 = plot(1469, 1509, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize',12);          
carro3 = plot(1423, 1606, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize',12);
end
hold off;






    
    

















