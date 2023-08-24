#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

int main()
{
  //声明一个2*3的float矩阵
  Eigen::Matrix<float, 2, 3> matrix_23;

  //实际上是Eigen::Matrix<double, 3, 1>
  Eigen::Vector3d v_3d;
  Eigen::Matrix<float, 3, 1> vd_3d;

  // Matrix3d实际上是 Eigen::Matrix<double, 3, 3>
  Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();  //初始化为零

  //动态大小矩阵
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
  Eigen::MatrixXd matrix_x;

  //矩阵初始化
  matrix_23 << 1, 2, 3, 4, 5, 6;
  std::cout << "matrix 2x3 from 1 to 6:\n" << matrix_23 << std::endl;
  std::cout << "print matrix 2x3: " << std::endl;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << matrix_23(i, j) << "\t";
    }
    std::cout << std::endl;
  }

  //矩阵向量相乘及类型转换
  v_3d << 3, 2, 1;
  vd_3d << 4, 5, 6;
  Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
  std::cout << "[1,2,3;4,5,6]*[3,2,1]=" << result.transpose() << std::endl;
  Eigen::Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
  std::cout << "[1,2,3;4,5,6]*[4,5,6]=" << result2.transpose() << std::endl;
  // Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;

  matrix_33 = Eigen::Matrix3d::Random();
  std::cout << "random matrix:\n" << matrix_33 << std::endl;
  std::cout << "transpose:\n" << matrix_33.transpose() << std::endl;
  std::cout << "sum:\n" << matrix_33.sum() << std::endl;
  std::cout << "trace:\n" << matrix_33.trace() << std::endl;
  std::cout << "times 10:\n" << 10 * matrix_33 << std::endl;
  std::cout << "inverse:\n" << matrix_33.inverse() << std::endl;
  std::cout << "det:\n" << matrix_33.determinant() << std::endl;
  return 0;
}