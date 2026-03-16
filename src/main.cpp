#include <iostream>
using namespace std;
#include <cmath>

void sort(double dataset[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;

        for (int j = i; j < size; j++)
            if (dataset[j] < dataset[minIndex])
                minIndex = j;

        double tempValue = dataset[i];
        dataset[i] = dataset[minIndex];
        dataset[minIndex] = tempValue;
    }
}

int main(){
    cout<<"Descriptive Statistics Calculator\n"<<endl;
    double point[999999];
    int size;
    while(true){
        for(int i=0; i<100000; i++){
            cout<<"Enter data point (Enter -1 to stop)";
            size=i;
            cin>>point[i];
            if (point[i]==-1){
                break;
            }
        }
        break;
    }
cout<<endl;
    cout<<"Original Dataset: ";
    for(int i=0;i<size;i++){
        cout<<"["<<point[i]<<"]";
    }
    cout<<endl;

    cout<<"Sorted dataset: ";
    sort(point, size);
    for(int i=0;i<size;i++){
        cout<<"["<<point[i]<<"]";
    }
    cout<<endl;
    
    double average;
    for(int j=0;j<size;j++){
        average+=point[j];
    }
    average=average/size;
    
    double midian;
    if (size%2==1){
        midian=point[size/2];
    }else if (size%2==0){
        midian=(point[size/2]+point[size/2+1])/2;
    }

    double range;
    range=point[size-1]-point[0];

    double variance;
    for (int i=0;i<size;i++){
        variance=(point[i]-average)*(point[i]-average)/(size-1)+variance;
    }

    double modes[9999];
    int index=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(point[i]==point[j]){
                modes[index]=point[j];
                index++;
            }
        }
    }



    double std;
    std=sqrt(variance);
    cout<<endl;
    cout<<"CENTRAL TENDENCE\n";
    cout<<"Mean: "<<average<<endl;
    cout<<"Median: "<<midian<<endl;
    cout<<"Mode: ";
    if (index!=0){
        for(int i=0; i<index ;i++){
            cout<<"["<<modes[i]<<"]";
        }
    }else cout<<"None";
    cout<<endl;cout<<endl;

    
    cout<<"DISPERSION";
    cout<<"Range: "<<range<<endl;
    cout<<"Sample variance: "<<variance<<endl;
    cout<<"Sample standard deviation: "<<std<<endl;
    

}
