#ifndef MATRIX
#define MATRIX

class Matrix {
public:
    Matrix();
    Matrix(int width, int height, double value = 0.0);
    //~Matrix();

    void initialize(int width, int height, double value);
    void initialize(int width, int height);
    void resize(int width, int height);
    void destroy();

    void Matrix::set(const double* _data);
    void Matrix::set(Matrix* reference);
    void Matrix::setBlock(int x, int y, Matrix* reference);
    void Matrix::multiply(Matrix& b, Matrix* target);
    void Matrix::transposeMultiply(Matrix& b, Matrix* target);
    void Matrix::multiplyScalar(double scalar);
    void Matrix::subtract(Matrix& b, Matrix* target);
    void Matrix::diag(double* target);
    void Matrix::transpose(Matrix* target);
    void Matrix::print();

    double** matrix;
    double* data;
    int width;
    int height;
    int capacityWidth;
    int capacityHeight;
};

#endif 
