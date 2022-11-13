#include "Act3_4.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <sstream>
#include <ctime>

using namespace std;

//We cout a line to give format of our programm
//Time Copmlexity: O(1)
void line(){
    cout<<"-----------------------------------------------------------------------------"<<endl;
}

//HeapSort to sort and remove the top element of the list and insert it
template<class T>
void HeapSort(DoublyLinkedList<T>& list, string order ){
    PriorityQueue<T> heapAux(list);
    list.clear();
    while (!heapAux.isEmpty()){
        if(order == "ascending"){
            list.addFirst(heapAux.remove());//we insert the element in the first posotion
        }
        if(order == "descending"){
            list.addLast(heapAux.remove());//we insert the element in the last position
        }
    }
    
}

//Function to split our string of IPs
//Time Complexity: O (n)
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

//We create our option menu
//Time Copmlexity: O(1)
void menu(){
    cout<<endl;
    line();
    cout<<"1) Print the IPs"<<endl;
    cout<<"2) Show the 5 most accesed IPs"<<endl;
    cout<<"3) Show the 5 least accesed IPs"<<endl;
    cout<<"4) Exit"<<endl;
    line();
    cout<<endl;
}


//optionMenu
void optionMenu(DoublyLinkedList<IPRegistry> &IPS_list){
    int selection;
    bool continues = true; 

    ofstream out("IPLogger.txt"); //Name of the output file with the sorted IPs data
    

    cout<<endl;


    cout<<"Welcome to the IPs verifier"<<endl<<endl;
    cout<<"You got: "<<IPS_list.getSize()<<" IPs detected"<<endl<<endl;
    while (continues){//mientras que sea verdadero
        menu();
        cout<<"Enter your option: ";cin>>selection;
        switch (selection){
            case 1:
                HeapSort(IPS_list,"descending"); //we sort the list
                IPS_list.print();
                break;
            case 2:
                HeapSort(IPS_list,"descending");//se hace un sort de la lista 
                IPS_list.printTopfive();
                break;
            case 3:
                HeapSort(IPS_list,"ascending");//se hace un sort de la lista invertido
                IPS_list.printTopfive();
                break;
            case 4:
                continues = false; //Proccess ends
                break;
            default:
                cout<<endl;
                line();
                cout<<"INVALID OTPTION"<<endl; 
                line();
                cout<<endl;
                break;
        }
    }
    cout<<endl;
    line();
    cout<<"++++ END OF THE PROGRAMM +++"<<endl;
    line();
    cout<<endl;
    
}

int main(){
    DoublyLinkedList<IPRegistry> lista;

    ifstream file("bitacora2.txt"); //we open the file txt with the ips information

    if(file.is_open()){
        string line;
        vector<string> words; //we create our vector to store the entry words
        string errorString = "";    //vector of strings to store the error message of the ips
        vector<string> ipString;

        int i =0;
        while(getline(file,line)){ //We read our file line by line
            words = split(line," "); //We split the words by spaces

            for (int i = 4; i < words.size(); i++){ 
                if(i != 4 && i != words.size()){
                    errorString= errorString+ " " + words[i]; //we get the string of the error message
                }
                else{
                    errorString += words[i];
                };
            }

            ipString = split(words[3],":");//We divide the string by :
            int tempAccessIPs; //temporal acces of IPs
            int tempAccessErrors; //temporal acces of errors
            string tempIp; //string of the temporal ip

            vector<string> errorsTemp; //vector temporal de errores
            vector<string> portsTemp; //vector temporal de puertos

            IPRegistry ip1; //struct of the temporal input ip 
            IPRegistry ip2; //struct of the temporal output ip 

            ip1.ip = ipString[0]; //we asign the ip

            if(lista.AlreadyExists(ip1)){ //if the Ip is on the list we increase the list
                
                int pos = lista.getIndex(ip1); //we get the index of the list
                int posE;
                tempIp = lista.getData(pos).ip;//we get the data of the ips
                tempAccessIPs = lista.getData(pos).access_frec; //we get the data if the frecuency that the ips were access
                tempAccessIPs++;//increment the frecuency by one


                errorsTemp = lista.getData(pos).errors; // we get the vector of errors value
                portsTemp = lista.getData(pos).ports; //we get the vector of the ports

                errorsTemp.push_back(errorString); //we insert the values into the corresponding vector
                portsTemp.push_back(ipString[1]);  //we insert the values into the corresponding vector

                ip2.ip = ipString[0];
                ip2.access_frec = tempAccessIPs;
                ip2.errors = errorsTemp;
                ip2.ports = portsTemp;
                
                
                lista.updateDataByElement(ip1,ip2); //we update the list by element
                
            }
              //In case that the list does not exist
            else{ 
                ip1.ip = ipString[0]; //we get an ip
                ip1.access_frec = 1; //base frecuency of  accessed ips
                errorsTemp.push_back(errorString); //we insert the error into the vector
                portsTemp.push_back(ipString[1]); //we insert the port of the IPs into the vector

                ip1.errors = errorsTemp;
                ip1.ports = portsTemp;
                lista.addLast(ip1); 
            }

            errorString = ""; //restart the values of the list
            words.clear(); //we clean our temporary vector

            i++;
        }
        file.close(); //close the file

        lista.sort();//sort the file

        HeapSort(lista,"descending");

        optionMenu(lista); //we call the menu again until the user hits exit


    }

    return 0;
}