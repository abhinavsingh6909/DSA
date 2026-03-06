//Problem Statement: Write a program to generate Pascal's triangle. In Pascal’s triangle, each number is the sum of the two numbers directly above it

#include<iostream>
#include<vector>
using namespace std;

// Given row and col tell me element at that place 
int findElement(int row , int col){
    long long ans = 1;
    for(int i=0 ; i<col ; i++){
        ans = ans * (row-i);
        ans = ans/(i+1);
    }

    return ans;
}



//nTh row of pascal triangle

vector<int> nthRowOfPascalTriangle(int nthRow){
    vector<int> result;
    long long ans = 1;

    for(int i=1 ; i<=nthRow ; i++){
        result.push_back(ans);
        ans = ans * (nthRow-i);
        ans = ans/i;
    }

    return result;
}

int main(){

    //Given row and col tell me element at that place

    cout<<"Given row and col tell me element at that place "<<endl;
    int row;
    cout<<"Enter which row element you want: ";
    cin>>row;

    int col;
    cout<<"Enter which col element you want: ";
    cin>>col;

    int elementAtGivenRowCol = findElement(row-1,col-1);

    cout<<"element at given "<<row<<" and "<<col<<" is: "<<elementAtGivenRowCol<<endl;

cout << "============================================================" << endl;

    //Print any nth row of pascal triangle

    cout<<"Print any nth row of pascal triangle "<<endl;

    int nthRow;

    cout<<"Enter the nth Row of pascal triangle you want: ";
    cin>>nthRow;

    vector<int> result = nthRowOfPascalTriangle(nthRow);

    cout<<nthRow<<"th row of pascal triangle: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout<<endl;
cout << "============================================================" << endl;
    //Pascal triangle till nTh row
    cout<<"Pascal triangle till nTh row "<<endl;

    int nthRowForPascalTriangle;

    cout<<"Enter the nth Row till which the pascal triangle you want: ";
    cin>>nthRowForPascalTriangle;


    vector<vector<int>> finalResult;

    for(int i=1 ; i<=nthRowForPascalTriangle; i++){
        vector<int> result = nthRowOfPascalTriangle(i);
        finalResult.push_back(result);
    }

    for (int i = 0; i < finalResult.size(); i++)
    {
        for (int j = 0; j < finalResult[i].size(); j++)
        {
            cout << finalResult[i][j] << " ";
        }
        cout << endl;
    }


    
    return 0;
} 