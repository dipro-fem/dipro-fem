//Numerical methods main file
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void def_data(vector<double>&x_data,vector<double>&y_data){
    cout<<"Define dataset:\n";
    cout<<"(enter non-numeric digit for stop defining)\n";
    int n;
    string value1, value2;
    n=0;
    step: cout<<"Enter x["<<n<<"]: ";cin>>value1;
    cout<<"Enter y["<<n<<"]: ";cin>>value2;
    if(isdigit(value1[0])==true||isdigit(value2[0])==true){
        x_data.push_back(stof(value1));
        y_data.push_back(stof(value2));
        n=n+1;
        goto step;        
    }
    else {
        cout<<"End of Data Definition."<<endl;
    }

}

void print_data(vector<double>&x_data,vector<double>&y_data){
    cout<<"Data Definition:\n";
    cout<<"x\t\ty";
    for(int i=0;i<x_data.size();i++){
        cout<<"\n"<<x_data[i]<<"\t\t"<<y_data[i];
    }

}

double lagrange(double x, vector<double>&x_data,vector<double>&y_data){
    double out=0;
    int k=x_data.size()-1;
    for(int j=0;j<=k;j++){
        double out2=1;
        for(int m=0;m<=k;m++){
            if(m!=j){
                out2=out2*(x-x_data[m])/(x_data[j]-x_data[m]);
            }
        }
        out=out+out2*y_data[j];
    }
    return out;
}


int main(){
    vector<double> x_data;
    vector<double> y_data;
    def_data(x_data,y_data);
    print_data(x_data,y_data);
    cout<<"\nLagrange:"<<lagrange(2.5,x_data,y_data);

}
