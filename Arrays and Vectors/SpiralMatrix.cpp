#include <iostream>
#include <vector>
using namespace std;

void spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();

        int count=0;
        int total=row*col;

        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        while(count<total){
            // starting row
            for(int i=startingCol;i<=endingCol && count<total;i++){
                cout<<matrix[startingRow][i]<<" ";
                count++;
            }
            startingRow++;
            //  ending col
            for(int i=startingRow;i<=endingRow && count<total;i++){
                cout<<matrix[i][endingCol]<<" ";
                count++;
            }
            endingCol--;
            // ending row
            for(int i=endingCol;i>=startingCol && count<total;i--){
                cout<<matrix[endingRow][i]<<" ";
                count++;
            }
            endingRow--;
            // starting col
            for(int i=endingRow;i>=startingRow && count<total;i--){
                cout<<matrix[i][startingCol]<<" ";
                count++;
            }
            startingCol++;
        }
    
    }
int main()
{

    vector<vector<int>> v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    spiralOrder(v);

}