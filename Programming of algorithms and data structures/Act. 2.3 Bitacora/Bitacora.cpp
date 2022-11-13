//Tecnológico de Monterrey, Campus Guadalajara
//Programming of Data Structures and Fundamental Algorithms (Gpo 613)
//Liliana Solórzano Pérez A01641392
//Andrea Valeria Pintor Valencia A01067424 

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

//--------------------We create the functions that will be used --------------------
//This function will convert the string month of the file to an integer
int string_To_int(string month){
	//We create an array to store the months
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    //We create an integer to store the month
    int monthNumber;
    //We convert the month to a number
    for (int i = 0; i < 12; i++){
        if (months[i] == month){
            monthNumber = i + 1;
        }
    }
    //We return the month
    return monthNumber;
}

int string_To_int_IP(string IPAdress){
	//We create an array to store the ip adresses from the file
	string ip[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	int ipNumber;
	//We convert the ip adress to a number
	for (int i = 0; i < 9; i++){
		if (ip[i] == IPAdress){
			ipNumber = i + 1;
		}
	}
	//We return the ip adress
	return ipNumber;
}

//Function that will get the month from the file
string get_Month(string date){
	string month = date.substr(0, 3); //We get the month from the file that is 3 characters long
	return month; //We return the month

}

int get_Date(string date){
    string day = date.substr(4, 2); //We get the day from the file that is 2 characters long
    return stoi(day); //We return the day and use stoi to convert it to an integer
}

string get_IP(string IP_line){
	int count = 0;
	string IP_vec = "";
	for(int i = 0; i < IP_line.size(); i++){
		if(IP_line[i] == ' '){
			count++;
		}
		if(count == 3){
			IP_vec += IP_line[i];
			string_To_int_IP(IP_vec);
		}
	}
	return IP_vec;
}


string MergeDayAndMonth(string date){
	string day = date.substr(4, 2);
	if(stoi(day) < 10){
		day = day.substr(0,1);
	}
	//We get the day from the file that is 2 characters long
	string month = date.substr(0, 3); //We get the month from the file that is 3 characters long
	string dayAndMonth = month + " " + day; //We merge the day and the month
	return dayAndMonth; //We return the day and month
	
}

//--------------------Function to order the file by descending order--------------------
//We use the merge sort algorithm
void merge(vector<string> &arr, int l, int m, int r){
	//We create the variables that will be used
	int n1 = m-l+1;
	int n2 = r-m;
	//We create the temporary vectors
	vector <string> L(n1), R(n2);
	//We copy the vector into the temporary vectors
	for(int i = 0; i < n1;i++){
		L[i] = arr[l+i];
	}
	for(int j = 0; j <n2;j++){
		R[j] = arr[m+1+j];
	}
	//We create the variables that will be used
	int i=0, j=0, k=l;
	//We create the while loop to order the file
	while (i < n1 && j < n2){
		if (string_To_int(get_Month(L[i])) < string_To_int(get_Month(R[j]))){
			arr[k] = L[i];
			i++;
		}
		else if (string_To_int(get_Month(L[i])) == string_To_int(get_Month(R[j]))){
			if (get_Date(L[i]) <= get_Date(R[j])){
				arr[k] = L[i];
				i++;
			}
			else{
				arr[k] = R[j];
				j++;
			}
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	//We copy the remaining elements of L[] if there are any
	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	//We copy the remaining elements of R[] if there are any
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	//Time complexity: O(n)
}

vector<string> mergeSort(vector<string> &arr, int l, int r){
	if (l < r){
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
	return arr;
	//Time complexity: O(n log n)
}

//--------------------Function to search the data from the file--------------------
int searchDatesInRange(vector<string> &arr, string date){
	for(int i = 0; i < arr.size(); i++){
		if (MergeDayAndMonth(arr[i]) == date){
			return i;
		}
	}
	return -1;
}

int searchDatesInRange2(vector<string> &arr, string date){
	for(int i = arr.size()-1; i > 0; i--){
		if (MergeDayAndMonth(arr[i]) == date){
			return i;
		}
	}
	return -1;
}


void ShowDatesInRange(vector<string> &arr, int date1, int date2){
	for(int i = date1; i <= date2; i++){
		cout << arr[i] << endl;
	}
}

//--------------------Function to search the IP data from the file--------------------
void mergeIP(vector<string> &arr, int l, int m, int r){
	//We create the variables that will be used
	int n1 = m-l+1;
	int n2 = r-m;
	//We create the temporary vectors
	vector <string> L(n1), R(n2);
	//We copy the vector into the temporary vectors
	for(int i = 0; i < n1;i++){
		L[i] = arr[l+i];
	}
	for(int j = 0; j <n2;j++){
		R[j] = arr[m+1+j];
	}
	//We create the variables that will be used
	int i=0, j=0, k=l;
	//We create the while loop to order the file
	while (i < n1 && j < n2){
		if (stoi(get_IP(L[i])) < stoi(get_IP(R[j]))){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	//We copy the remaining elements of L[] if there are any
	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	//We copy the remaining elements of R[] if there are any
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	//Time complexity: O(n)
}


vector <string> mergeSortIP(vector<string> &arr, int l, int r){
	if (l < r){
		int m = l+(r-l)/2;
		mergeSortIP(arr, l, m);
		mergeSortIP(arr, m+1, r);
		mergeIP(arr, l, m, r);
	}
	return arr;
	//Time complexity: O(n log n)
}


void print_Vector(vector<string> &arr){
	string list_array = ""; //We create a string that will store the list of the vector
	for(int i = 0; i < arr.size(); i++){ //We loop through the vector
		cout << arr[i] << endl; //We print the element
	}
}

int main(){
    //We create the variables that will be used
    ifstream file; //We create the file
    ofstream outfile; //We create the output file

    vector <string> data; //We create the vector that will store the data from the file
    string line; //We create the string that will store the line from the file

    //--------------------We open the file and store the data in the vector--------------------
    file.open("bitacora.txt", ios::in);
    while(getline(file,line)){
        data.push_back(line); //We store the data from the file in the vector
    }
    file.close(); //We close the file
    cout << "++++ The file has been read ++++" << endl;
    
    //--------------------We order the file by descending order--------------------
    sort(data.begin() + 6, data.end()); //We sort the vector
    vector <string> Sorted_data = mergeSort(data, 0, data.size()-1); //We order the vector

    outfile.open("bitacora_sorted.txt"); //We create the output file
    for(int i = 0; i < Sorted_data.size(); i++){ //We loop through the vector
        outfile << Sorted_data[i] << endl; //We print the element
    }
    outfile.close(); //We close the output file
    cout << "++++ The file has been sorted ++++" << endl;
    print_Vector(Sorted_data); //We print the vector


    //--------------------We search the data from the file--------------------
    //We create our search menu
    int option = 0;
    cout << endl;
    cout << "++++ Search Menu ++++" << endl;
    cout << "1. Search by month" << endl;
	cout << "2. Search by day" << endl;
	cout << "3. Search in a range of dates " << endl;
	cout << "4. Search by a range of IP adresses " << endl;
	cout << "5. Exit" << endl;
	cout << "Enter an option: ";
	cin >> option;
    cout << endl;

    //We create the switch statement to search the data from the file
    switch (option){
    case 1:{
        string search_month; //We create the string that will store the month that we want to search
        cout << "Enter the month you want to search for: ";
        cin >> search_month;

        //Search by month
        int pos = 0; //We create a variable to store the position of the month
		//We create a for loop to find the position of the month
		for(int i = 0; i < Sorted_data.size(); i++){
            if (get_Month(Sorted_data[i]) == search_month){
                pos = i;
                cout << "The line is: " << Sorted_data[pos] << endl;
                
            }
        }
    break;
    }
    

    
    case 2:{
        int search_day;
        cout << "Enter the day you want to search for: ";
			cin >> search_day;

			//Search for the date
			int pos = 0; //We create a variable to store the position of the month
			for (int i = 0; i < Sorted_data.size(); i++){
                if (get_Date(Sorted_data[i]) == search_day){
                    pos = i;
                    cout << "The line is: " << Sorted_data[pos] << endl;
					//Complexity: O(n)
                    }
                }
            break;
            }
        
            
    
    case 3:{
		//--------------------Range of dates--------------------
        string startDate;
        string endDate;
		cout << "Example: Sep 5" << endl;
		//cout << "Enter the first date: ";
		//getline(cin, startDate);
		//cout << "Enter the second date: ";
		//getline(cin, endDate);
		
		startDate = "Sep 5";
		endDate = "Sep 11";
		ofstream outfileRange;

        //--------------------We search the range of data from the file--------------------
        int startIndex = searchDatesInRange(Sorted_data, startDate);
        int endIndex = searchDatesInRange2(Sorted_data, endDate);

        //--------------------We print the data from the file--------------------
        ShowDatesInRange(Sorted_data, startIndex, endIndex );

		//--------------------We print the data from the file in a new file--------------------
		outfileRange.open("bitacora_range.txt"); //We create the output file
		for(int i = startIndex; i <= endIndex; i++){ //We loop through the vector
			outfileRange << Sorted_data[i] << endl; //We print the element
			}
                }
        break;
		

	case 4:{
		//--------------------Range of IP Adresses--------------------
		ifstream fileIP;
		ofstream outfileIP;
		vector <string> IPdata; //We create the vector that will store the data from the file
		string lineIP;

			//--------------------We open the file and store the data in the vector--------------------
		fileIP.open("bitacora.txt", ios::in);
		while(getline(fileIP,lineIP)){
			IPdata.push_back(lineIP); //We store the data from the file in the vector
		}
		file.close(); //We close the file
		cout << "++++ The file has been read ++++" << endl;
		
		//--------------------We order the file by descending order to ascending order--------------------
			//---------------------------_We sort the file by IP Adress----------------------------
		//We call the function to sort by IP Adress
		vector <string> Sorted_IP_data =  mergeSortIP(IPdata, 0, IPdata.size()-1);
		print_Vector(Sorted_IP_data); //We print the vector
		cout << endl;

		outfile.open("bitacora_sortedIP.txt"); //We create the output file
    	for(int i = 0; i < IPdata.size(); i++){ //We loop through the vector
        	outfile << IPdata[i] << endl; //We print the element
			//Complexity: = O(n)
		}
		outfile.close(); //We close the output file
    
		cout << "++++ The file has been sorted by IP Adress ++++" << endl;
		print_Vector(IPdata); //We print the vector
		cout << endl;

		
		//--------------------We search the data from the file--------------------

		//string start_IP = "40.83.671.11:5551";
		//string end_IP = "382.85.124.86:4971";

		string start_IP;
		string end_IP;
		cout << "Enter the start IP Adress: ";
		cin >> start_IP;
		cout << "Enter the end IP Adress: ";
		cin >> end_IP;

		string new_start_IP = start_IP.substr(0, start_IP.find("."));
		string new_end_IP = end_IP.substr(0, end_IP.find("."));

		outfileIP.open("bitacora_IPrange.txt");

		cout << "++++ Range of the IP data ++++ " << endl;
		for (int i = 0; i < IPdata.size(); i++){
			if (stoi(get_IP(IPdata[i])) >= stoi(new_start_IP) && stoi(get_IP(IPdata[i])) <= stoi(new_end_IP)){
				cout << endl;
				cout << IPdata[i];
				outfileIP << IPdata[i] << endl; 
				//Complexity = O(n)
			}
		}
		break;
	}	
	
	
		
	
    case 5:{
        cout << "++++ The program has ended ++++" << endl;
        break;
            }
        
	}
return 0;

    }
