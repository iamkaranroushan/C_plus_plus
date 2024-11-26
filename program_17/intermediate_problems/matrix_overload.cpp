// Overload the * operator for a Matrix class.
// Create a Matrix class to represent a 2x2 matrix. Overload the * operator to multiply two matrices.
#include <iostream>
#include <vector>

class Matrix{
    private:
        std::vector<std::vector<int>> arr;
        int rows, cols;

    public:
        Matrix(std::initializer_list<std::initializer_list<int>> init){
            for(auto& data: init){
                arr.emplace_back(data);
            }
            rows = arr.size();
            cols = rows > 0 ? arr[0].size() : 0;
        }

        Matrix operator*(const Matrix& m){
            Matrix result({{0,0},{0,0}});
            if(rows == m.cols){
                for(int i=0; i<rows; ++i){
                    for(int j=0; j < m.cols; ++j){
                        for(int k = 0; k < cols; ++k){
                            result.arr[i][j] += arr[i][k] * m.arr[k][j];
                        }
                    }
                }
            }else{
                std::cerr << "Matrix multiplication is not possible"<< "Columns of the first matrix must be equal to rows of the second matrix." << std::endl;
                exit(1);
            }
            return result;
        }

        void show_matrix(){
            for(int i = 0; i<rows; i++){
                std::cout<<"\n";
                for(int j = 0; j<cols; j++){
                        std::cout<<arr[i][j]<<" ";
                }
            }
        }
};


int main(){
    Matrix m1({{1,2},{3,4}});
    Matrix m2({{2,3},{5,6}});
    Matrix m3 = m1*m2;

    m3.show_matrix();

    

}

//firstly: made the matrix and its little complex because i didn't know about initializer lists.
//then: operator overloading.
// overload the * operator