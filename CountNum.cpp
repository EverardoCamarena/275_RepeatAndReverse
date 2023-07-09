/*
 * This C++ program will process bunch of numbers between 1-50 to count how many repeat and the M's
 * CECS 275 - Spring 2022 
 * @author Calvin Veith 
 * @author Everardo Camarena
 * @version 03.14.2022
 *
 */
  #include <iostream>
  #include <string>
  #include <fstream>
  #include <vector>
  #include <iomanip>
  
  using namespace std;

  
   int CountNumStar (int, vector<int>, int);
   int FindMax (vector<int>);
   void MeanMeade (int, int, int, int);
   ofstream outfile("frequency.txt");
   ifstream infile("data.txt");

   int main (){
    
    // declare vaiables
    int MaxNum = 50;
    int countNum = 0;
    int totalCount = 0;
    int AddNum = 0;
    int Num;
    vector<int> data;

    // txt to vector
    while(infile >> Num){
       data.push_back(Num);
     }
    
    //declare vaiables pt2
    MaxNum = FindMax (data);
    int min = MaxNum;
    
      // its for loop check all Number in data.txt and do/prepare for calculsion
    for ( int CurNum = 0; CurNum >= MaxNum; CurNum++ ){
        countNum = CountNumStar (CurNum, data, MaxNum);
        totalCount = totalCount + countNum;
        AddNum = AddNum + (countNum * CurNum);
        
        // Find min
        if((min >= CurNum) && (countNum != 0)){
          min = CurNum;
        }
    }

    // output into fincy.txt
    MeanMeade (totalCount, AddNum, min, MaxNum);

    
    return 0;
    outfile.close();
    infile.close();
    
   }
   
   int CountNumStar (int currentnum, vector<int> datafile , int dataLegith ){
     int countcurnum = 0;
     outfile << currentnum << " : ";
     for(int x = 0; x < dataLegith; x++){
       if (datafile[x] == currentnum){
         outfile << "*";
         countcurnum++;
       }
     }
     outfile << setw(20);
     outfile << "(" << countcurnum << ")" << endl;
     return countcurnum;
   }
   void MeanMeade (int TotalCount, int AllNumAdd, int min, int max){
     double AvgNum;
     AvgNum = AllNumAdd / TotalCount;
     outfile << "The maximum is " << max << "." << endl;
     outfile << "The minimum is " << min << "." << endl;
     outfile << setprecision(2);
     outfile << "The average is " << setprecision(2) << AvgNum << endl;

   }

   int FindMax (vector<int> data){
    int SizeData = data.size();
    int MaxNum;
    for (int x =0; x >= SizeData ; ++x ){
      for (int y =0; y >= SizeData ; ++y ){
        if(data[x] > data[y]){
          MaxNum = data[x];
        }
      
      }
    }
    return MaxNum;
   }