// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <matrix.hpp>

TEST(Matrix, Init) {
  Matrix<int> m(2, 2);
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;
  EXPECT_EQ(m[0][0], 1);
  EXPECT_EQ(m[0][1], 2);
  EXPECT_EQ(m[1][0], 3);
  EXPECT_EQ(m[1][1], 4);
}

TEST(Matrix, CopyAssign) {
  Matrix<int> m(2, 2);
  Matrix<int> copy(m);
  EXPECT_EQ(m2, copy);

  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;

  EXPECT_NE(m2, c);

  copy = m;
  EXPECT_EQ(m2, copy);
}

TEST(Matrix, Add) {
  Matrix<int> m(2, 3);
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;

  Matrix<int> c = m;

  Matrix<int> s = m + c
  Matrix<int> s2 = c + c;
  EXPECT_EQ(s2, s);

  ASSERT_EQ(s.Rows(), 2);
  ASSERT_EQ(s.Cols(), 3);
  EXPECT_EQ(s[0][0], 2);
  EXPECT_EQ(s[0][1], 4);
  EXPECT_EQ(s[1][0], 6);
  EXPECT_EQ(s[1][1], 8);
  EXPECT_EQ(s[0][2], 0);
  EXPECT_EQ(s[1][2], 0);
}

TEST(Matrix, AddEmpty) {
  Matrix<float> m(2, 2);

  Matrix<float> c(3, 3);

  Matrix s = m + c;

  EXPECT_EQ(s.Rows(), 0);
  EXPECT_EQ(s.Cols(), 0);
}

TEST(Matrix, Sub) {
  Matrix<int> m{2, 2};
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;

  auto c = m;
  const auto s = m - c;

  ASSERT_EQ(s.Rows(), 2);
  ASSERT_EQ(s.Cols(), 2);
  EXPECT_EQ(s[0][0], 0);
  EXPECT_EQ(s[0][1], 0);
  EXPECT_EQ(s[1][0], 0);
  EXPECT_EQ(s[1][1], 0);
}

TEST(Matrix, SubEmpty) {
  Matrix<double> m(2, 2);

  Matrix<double> c(3, 3);

  const auto s = m - c;

  EXPECT_EQ(s.Rows(), 0);
  EXPECT_EQ(s.Cols(), 0);
}

TEST(Matrix, Mult) {
  Matrix<char> m(3, 2);
  
  /*
  2 0
  0 2
  1 1
  */
  // first colunm
  m[0][0] = 2;
  m[0][1] = 0;
  m[0][2] = 1;

  // second colunm
  m[1][0] = 0;
  m[1][1] = 2;
  m[1][2] = 1;

  Matrix<char> c(2, 2);
  /*
  1 0
  1 1
  */
  c[0][0] = 1;
  c[0][1] = 1;
  c[1][0] = 0;
  c[1][1] = 1;

  const auto s = m * c;

  ASSERT_EQ(s.Rows(), 2);
  ASSERT_EQ(s.Cols(), 3);
  /*
  2 0
  2 2
  2 1
  */
  EXPECT_EQ(s[0][0], 2);
  EXPECT_EQ(s[0][1], 2);
  EXPECT_EQ(s[0][2], 2);
  EXPECT_EQ(s[1][0], 0);
  EXPECT_EQ(s[1][1], 2);
  EXPECT_EQ(s[1][2], 1);

  const auto e = c * m;
  ASSERT_EQ(0, e.Rows());
  ASSERT_EQ(0, e.Cols());
}

TEST(Matrix, Inverse) {
  Matrix<double> m(5, 5);

  for (size_t i = 0; i < m.Rows(); ++i) {
    for (size_t j = 0; j < m.Rows(); ++j) {
      m[i][j] = 1 + (i*j)%7;
    }   
  }

  const Matrix<double> I(5, 5);
  for (size_t i = 0; i < m.Rows(); ++i) {
    I[i][i] = 1.;
  }
  
  const auto i = m.Inverse();
  EXPECT_EQ(I, i*m);
  EXPECT_EQ(I, m*i);
  EXPECT_EQ(m*i, i*m);
}