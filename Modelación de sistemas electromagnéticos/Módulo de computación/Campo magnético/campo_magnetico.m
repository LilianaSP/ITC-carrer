clc;close all;clear all;

%Longitud del cable en la coordenada c

Nx=11;
Nz=11;  
Ny=11;  
N=80;   % longitud del cable  

%Coordenadas del cable
Xw=(floor(-N/2):floor(N/2)); 
Yw=zeros(N+1,1); 
Zw=zeros(N+1,1); 

I=3;    % corriente
u0=4*pi*10^-7;   % variable fija


[X,Y,Z]=meshgrid(-5:1:5);
%-------------------------------------------------------------------------
%------------------------------------------------------------------------


for a=1:Nx  
for b=1:Ny  
for c=1:Nz
    
%-------------------------------------------------------------------------    
%-------------------------------------------------------------------------

%Obtener el radio del cable
for i=1:N-1
Rx(i)=X(a,b,c)-(0.5*(Xw(i)+Xw(i+1)));
Ry(i)=(Y(a,b,c)-(0.5*(Yw(i)+Yw(i+1))));
Rz(i)=(Z(a,b,c)-(0.5*(Zw(i)+Zw(i+1))));

%diferencial de cambio en las coordenadas
dlx(i)=Xw(i+1)-Xw(i);
dly(i)=Yw(i+1)-Yw(i);
dlz(i)=Zw(i+1)-Zw(i);
end
Rx(N)=(X(a,b,c)-0.5*(Xw(N)+1));
Ry(N)=(Y(a,b,c)-(0.5*(Yw(N)+1)));
Rz(N)=(Z(a,b,c)-(0.5*(Zw(N)+1)));
dlx(N)=-Xw(N)+1;
dly(N)=-Yw(N)+1;
dlz(N)=-Zw(N)+1;
%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

for i=1:N

Xcross(i)=(dly(i).*Rz(i))-(dlz(i).*Ry(i)); %posición inicial del cable
Ycross(i)=(dlz(i).*Rx(i))-(dlx(i).*Rz(i));
Zcross(i)=(dlx(i).*Ry(i))-(dly(i).*Rx(i));
R(i)=sqrt(Rx(i).^2+Ry(i).^2+Rz(i).^2);
end
% 
% 

%-------------------------------------------------------------------------
%--------------------------------------------------------------------------
%Fórmula del campo magnético biot savart (cable recto)
Bx1=(I*u0./(4*pi*(R.^3))).*0;
By1=(I*u0./(4*pi*(R.^3))).*Ycross;
Bz1=(I*u0./(4*pi*(R.^3))).*Zcross;
%--------------------------------------------------------------------------
%-------------------------------------------------------------------------
%Inicializamos el las variables en zeros
BX(a,b,c)=0;       
BY(a,b,c)=0;
BZ(a,b,c)=0;

%--------------------------------------------------------------------------
%--------------------------------------------------------------------------

for i=1:N   % creamos un loop de todos los elementos de la corriente    
    BX(a,b,c)=BX(a,b,c)+Bx1(i);
    BY(a,b,c)=BY(a,b,c)+By1(i);
    BZ(a,b,c)=BZ(a,b,c)+Bz1(i);
end

%-------------------------------------------------------------------------

end
end

end

%Creamos la gráfica

figure(1)

quiver3(X,Y,Z,BX,BY,BZ,2);
hold on
line([-5 5],[0 0], [0 0],'linewidth',3,'color','r');
 axis([-5 5 -5 5 -5 5])
xlabel('X-axis','fontsize',14)
ylabel('Y-axis','fontsize',14)
zlabel('Z-axis','fontsize',14)
title('Campo magnético','fontsize',14)
h=gca; 
set(h,'FontSize',14)
fh = figure(1); 
set(fh, 'color', 'white'); 

figure(2)

quiver(Y((Nx-1)/2,:,:),Z((Nx-1)/2,:,:),BY((Nx-1)/2,:,:),BZ((Nx-1)/2,:,:),2);
hold on
G1=plot(0,0,'.','markersize',6);
set(G1,'MarkerEdgeColor','r')
axis([ -5 5 -5 5])
xlabel('Y-axis','fontsize',14)
ylabel('Z-axis','fontsize',14)
title('B-field YZ plane','fontsize',14)
h=gca; 
set(h,'FontSize',14)
h = get(gca, 'ylabel');
fh = figure(2); 
set(fh, 'color', 'white'); 
%-------------------------------------------