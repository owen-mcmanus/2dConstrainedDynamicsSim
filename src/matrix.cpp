#include "../include/martrix.h"
#include <bitset>
#include <iostream>


Matrix::Matrix() {
    matrix = nullptr;
    data = nullptr;
    width = height = 0;
    capacityWidth = capacityHeight = 0;
}

Matrix::Matrix(int _width, int _height, double value) {
    matrix = nullptr;
    data = nullptr;
    width = height = 0;
    capacityWidth = capacityHeight = 0;

    initialize(_width, _height, value);
}

void Matrix::initialize(int _width, int _height, double value) {
    resize(_width, _height);

    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            matrix[i][j] = value;
        }
    }
}

void Matrix::initialize(int _width, int _height) {
    resize(_width, _height);
    std::memset(data, 0, sizeof(double) * _width * _height);
}

void Matrix::resize(int _width, int _height) {
    if (width == _width && height == _height) return;
    else if (_width > capacityWidth || _height > capacityHeight) {
        destroy();

        capacityWidth = (_width > capacityWidth)
            ? _width
            : capacityWidth;

        capacityHeight = (_height > capacityHeight)
            ? _height
            : capacityHeight;

        data = new double[(size_t)capacityWidth * capacityHeight];
        matrix = new double* [capacityHeight];
    }

    height = _height;
    width = _width;

    for (int i = 0; i < height; ++i) {
        matrix[i] = &data[i * width];
    }
}

void Matrix::destroy() {
    if (matrix == nullptr) {
        return;
    }

    delete[] matrix;
    delete[] data;

    matrix = nullptr;
    data = nullptr;

    width = height = 0;
    capacityWidth = capacityHeight = 0;
}


void Matrix::set(const double* _data) {
    memcpy(data, _data, sizeof(double) * width * height);
}

void Matrix::set(Matrix* reference) {
    resize(reference->width, reference->height);

    for (int i = 0; i < reference->height; ++i) {
        for (int j = 0; j < reference->width; ++j) {
            matrix[i][j] = reference->matrix[i][j];
        }
    }
}

void Matrix::setBlock(int x, int y, Matrix* reference) {
    for (int i = 0; i < reference->height; ++i) {
        for (int j = 0; j < reference->width; ++j) {
            matrix[i+x][j+y] = reference->matrix[i][j];
        }
    }
}

void Matrix::multiply(Matrix& b, Matrix* target) {
    target->resize(b.width, height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < b.width; ++j) {
            double v = 0.0;
            for (int ii = 0; ii < width; ++ii) {
                v += matrix[i][ii] * b.matrix[ii][j];
            }

            target->matrix[i][j] = v;
        }
    }
}

void Matrix::transposeMultiply(Matrix& b, Matrix* target) {
    target->resize(b.height, height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < b.height; ++j) {
            double v = 0.0;
            for (int ii = 0; ii < width; ++ii) {
                v += matrix[i][ii] * b.matrix[j][ii];
            }

            target->matrix[i][j] = v;
        }
    }
}

void Matrix::multiplyScalar(double scalar) {
    for (int i = 0; i < height*width; ++i) {
        data[i] *= scalar;
    }
}

void Matrix::subtract(Matrix& b, Matrix* target) {
    target->resize(width, height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            target->matrix[i][j] = matrix[i][j]-b.matrix[i][j];
        }
    }
}

void Matrix::diag(double* target) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == j) {
                matrix[i][j] = target[i];
            }
        }
    }
}

void Matrix::transpose(Matrix* target) {
    target->resize(height, width);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            target->matrix[i][j] = matrix[j][i];
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
             std::cout<<matrix[i][j]<<", ";
        }
        std::cout<<std::endl;
    }
}