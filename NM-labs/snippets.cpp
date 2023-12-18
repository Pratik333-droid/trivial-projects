  #include <iostream>
  using namespace std;

  int main ()
  {
      float sum, matrix[5][5], vector[5] = {1,2,3}, vec[5];
      int i,j,n;
      cout <<"Enter n"<<endl;
      cin>>n;
      for (int i =0; i<n; i++)
      {
          for (int j =0; j<n; j++)
          {
              cin>>matrix[i][j];
          }
      }
        for (i =0; i<n; i++)
        {    
            sum = 0;
            for (j =0; j<n; j++)
            {
                // cin>>mat[i][j];
                sum += matrix[i][j] * vector[j];
                cout <<"matrix["<<i<<"]["<<j<<"]= "<< matrix[i][j] <<" * " <<vector[j]<<endl;
            }
            vec[i] = sum;
            cout <<"sum = "<<sum<<endl;
        }

        for (i =0; i<n; i++)
        cout <<vec[i]<<"  ";
      return 0;
  }
