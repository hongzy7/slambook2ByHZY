#include <iostream>
#include <cmath>

#include <Eigen/Core>
#include <Eigen/Geometry>

int main(int argc, char** argv)
{
  // 旋转矩阵使用Matrix3d
  Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
  // 旋转向量使用AngleAxis
  Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));
  std::cout.precision(3);
  std::cout << "rotation matrix = \n" << rotation_vector.matrix() << std::endl;
  rotation_matrix = rotation_vector.toRotationMatrix();

  // 用AngleAxis可以进行坐标变换
  Eigen::Vector3d v(1, 0, 0);
  Eigen::Vector3d v_rotated = rotation_vector * v;
  std::cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << std::endl;
  v_rotated = rotation_matrix * v;
  std::cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << std::endl;

  //欧拉角: 可以将旋转矩阵直接转换成欧拉角
  Eigen::Vector3d eular_angles = rotation_matrix.eulerAngles(2, 1, 0);  // ZYX顺序，即roll pitch yaw顺序
  std::cout << "yaw pitch roll = " << eular_angles.transpose() << std::endl;

  //欧式变换矩阵使用Eigen::Isometry
  Eigen::Isometry3d T = Eigen::Isometry3d::Identity();  //虽然是3d，但实际上是4*4矩阵
  T.rotate(rotation_vector);                            //按照rotation_verctor进行旋转
  T.pretranslate(Eigen::Vector3d(1, 3, 4));             //把平移向量设成（1，3，4）
  std::cout << "Transform matrix = \n" << T.matrix() << std::endl;

  // 用变换矩阵进行坐标变换
  Eigen::Vector3d v_transformed = T * v;  //相当于R*V+t
  std::cout << "v transformed = " << v_transformed.transpose() << std::endl;

  //四元数
  // 可以直接把AngleAxis赋值给四元数，反之亦然
  Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
  std::cout << "quaternion from rotation vector = " << q.coeffs().transpose()
            << std::endl;                   // 注意coeffs的顺序是（x,y,z,w）w为实部，前三者为虚部
  q = Eigen::Quaterniond(rotation_matrix);  //也可以把旋转矩阵赋给它
  std::cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << std::endl;
  // 使用四元数旋转一个向量，使用重载的乘法即可
  v_rotated = q * v;
  std::cout << "(1,0,0) after rotation = " << v_rotated.transpose() << std::endl;
  std::cout << "should be equal to " << (q * Eigen::Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose()
            << std::endl;  //注意Quaternion的coeff是（x,y,z,w）

  return 0;
}