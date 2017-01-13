/*
 * RBDL - Rigid Body Dynamics Library
 * Copyright (c) 2011-2016 Martin Felis <martin.felis@iwr.uni-heidelberg.de>
 *
 * Licensed under the zlib license. See LICENSE for more details.
 */

#ifndef RBDL_EIGENMATH_H
#define RBDL_EIGENMATH_H

/* Exporting templated symbols is tricky when using MSVC. The following lines
 * causes the classes in this file not to be explicitly exported. Instead
 * they are already implicitly exported.
 */
#if defined(WIN32) && defined(rbdl_EXPORTS)
#define RBDL_TEMPLATE_DLLAPI
#else
#define RBDL_TEMPLATE_DLLAPI RBDL_DLLAPI
#endif

template <typename T>
class RBDL_TEMPLATE_DLLAPI Vector3_t : public Eigen::Matrix<T, 3, 1>
{
  public:
    typedef Eigen::Matrix<T, 3, 1> Base;

    template<typename OtherDerived>
      Vector3_t(const Eigen::MatrixBase<OtherDerived>& other)
      : Eigen::Vector3d(other)
      {}

    template<typename OtherDerived>
      Vector3_t& operator=(const Eigen::MatrixBase<OtherDerived>& other)
      {
        this->Base::operator=(other);
        return *this;
      }

    EIGEN_STRONG_INLINE Vector3_t()
    {}

    EIGEN_STRONG_INLINE Vector3_t(
        const double& v0, const double& v1, const double& v2
        )
    {
      Base::_check_template_params();

      (*this) << v0, v1, v2;
    }

    void set(const double& v0, const double& v1, const double& v2)
    {
      Base::_check_template_params();

      (*this) << v0, v1, v2;
    }
};

template <typename T>
class RBDL_TEMPLATE_DLLAPI Matrix3_t : public Eigen::Matrix<T, 3, 3>
{
  public:
    typedef Eigen::Matrix<T, 3, 3> Base;

    template<typename OtherDerived>
      Matrix3_t(const Eigen::MatrixBase<OtherDerived>& other)
      : Eigen::Matrix3d(other)
      {}

    template<typename OtherDerived>
      Matrix3_t& operator=(const Eigen::MatrixBase<OtherDerived>& other)
      {
        this->Base::operator=(other);
        return *this;
      }

    EIGEN_STRONG_INLINE Matrix3_t()
    {}

    EIGEN_STRONG_INLINE Matrix3_t(
        const double& m00, const double& m01, const double& m02,
        const double& m10, const double& m11, const double& m12,
        const double& m20, const double& m21, const double& m22
        )
    {
      Base::_check_template_params();

      (*this)
        << m00, m01, m02,
        m10, m11, m12,
        m20, m21, m22
          ;
    }
};

template <typename T>
class RBDL_TEMPLATE_DLLAPI Vector4_t : public Eigen::Matrix<T, 4, 1>
{
  public:
    typedef Eigen::Matrix<T, 4, 1> Base;

    template<typename OtherDerived>
      Vector4_t(const Eigen::MatrixBase<OtherDerived>& other)
      : Eigen::Vector4d(other)
      {}

    template<typename OtherDerived>
      Vector4_t& operator=(const Eigen::MatrixBase<OtherDerived>& other)
      {
        this->Base::operator=(other);
        return *this;
      }

    EIGEN_STRONG_INLINE Vector4_t()
    {}

    EIGEN_STRONG_INLINE Vector4_t(
        const double& v0, const double& v1, const double& v2, const double& v3
        )
    {
      Base::_check_template_params();

      (*this) << v0, v1, v2, v3;
    }

    void set(const double& v0, const double& v1, const double& v2, const double& v3)
    {
      Base::_check_template_params();

      (*this) << v0, v1, v2, v3;
    }
};

template <typename T>
class RBDL_TEMPLATE_DLLAPI SpatialVector_t : public Eigen::Matrix<T, 6, 1>
{
  public:
    typedef  Eigen::Matrix<T, 6, 1> Base;

    template<typename OtherDerived>
      SpatialVector_t(const Eigen::MatrixBase<OtherDerived>& other)
      : Eigen::Matrix<double, 6, 1>(other)
      {}

    template<typename OtherDerived>
      SpatialVector_t& operator=(const Eigen::MatrixBase<OtherDerived>& other)
      {
        this->Base::operator=(other);
        return *this;
      }

    EIGEN_STRONG_INLINE SpatialVector_t()
    {}

    EIGEN_STRONG_INLINE SpatialVector_t(
        const double& v0, const double& v1, const double& v2,
        const double& v3, const double& v4, const double& v5
        )
    {
      Base::_check_template_params();

      (*this) << v0, v1, v2, v3, v4, v5;
    }

    void set(
        const double& v0, const double& v1, const double& v2,
        const double& v3, const double& v4, const double& v5
        )
    {
      Base::_check_template_params();

      (*this) << v0, v1, v2, v3, v4, v5;
    }

    static SpatialVector_t<T> Zero(){
        return SpatialVector_t<T>(0., 0., 0., 0., 0., 0.);
    }
};

template <typename T>
class RBDL_TEMPLATE_DLLAPI SpatialMatrix_t : public Eigen::Matrix<T, 6, 6>
{
  public:
    typedef Eigen::Matrix<T, 6, 6> Base;

    template<typename OtherDerived>
      SpatialMatrix_t(const Eigen::MatrixBase<OtherDerived>& other)
      : Eigen::Matrix<double, 6, 6>(other)
      {}

    template<typename OtherDerived>
      SpatialMatrix_t& operator=(const Eigen::MatrixBase<OtherDerived>& other)
      {
        this->Base::operator=(other);
        return *this;
      }

    EIGEN_STRONG_INLINE SpatialMatrix_t()
    {}

    EIGEN_STRONG_INLINE SpatialMatrix_t(
        const T& m00, const T& m01, const T& m02, const T& m03, const T& m04, const T& m05,
        const T& m10, const T& m11, const T& m12, const T& m13, const T& m14, const T& m15,
        const T& m20, const T& m21, const T& m22, const T& m23, const T& m24, const T& m25,
        const T& m30, const T& m31, const T& m32, const T& m33, const T& m34, const T& m35,
        const T& m40, const T& m41, const T& m42, const T& m43, const T& m44, const T& m45,
        const T& m50, const T& m51, const T& m52, const T& m53, const T& m54, const T& m55
        )
    {
      Base::_check_template_params();

      (*this)
        << m00, m01, m02, m03, m04, m05
        , m10, m11, m12, m13, m14, m15
        , m20, m21, m22, m23, m24, m25
        , m30, m31, m32, m33, m34, m35
        , m40, m41, m42, m43, m44, m45
        , m50, m51, m52, m53, m54, m55
        ;
    }

    void set(
        const T& m00, const T& m01, const T& m02, const T& m03, const T& m04, const T& m05,
        const T& m10, const T& m11, const T& m12, const T& m13, const T& m14, const T& m15,
        const T& m20, const T& m21, const T& m22, const T& m23, const T& m24, const T& m25,
        const T& m30, const T& m31, const T& m32, const T& m33, const T& m34, const T& m35,
        const T& m40, const T& m41, const T& m42, const T& m43, const T& m44, const T& m45,
        const T& m50, const T& m51, const T& m52, const T& m53, const T& m54, const T& m55
        )
    {
      Base::_check_template_params();

      (*this)
        << m00, m01, m02, m03, m04, m05
        , m10, m11, m12, m13, m14, m15
        , m20, m21, m22, m23, m24, m25
        , m30, m31, m32, m33, m34, m35
        , m40, m41, m42, m43, m44, m45
        , m50, m51, m52, m53, m54, m55
        ;
    }

    static SpatialMatrix_t<T> Identity(){
        return SpatialMatrix_t<T>(1., 0., 0., 0., 0., 0.,
                                  0., 1., 0., 0., 0., 0.,
                                  0., 0., 1., 0., 0., 0.,
                                  0., 0., 0., 1., 0., 0.,
                                  0., 0., 0., 0., 1., 0.,
                                  0., 0., 0., 0., 0., 1.);
    }

    static SpatialMatrix_t<T> Zero(){
        return SpatialMatrix_t<T>(0., 0., 0., 0., 0., 0.,
                                  0., 0., 0., 0., 0., 0.,
                                  0., 0., 0., 0., 0., 0.,
                                  0., 0., 0., 0., 0., 0.,
                                  0., 0., 0., 0., 0., 0.,
                                  0., 0., 0., 0., 0., 0.);
    }
};

/* _RBDL_EIGENMATH_H */
#endif
