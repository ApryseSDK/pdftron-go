
inline Matrix2D::Matrix2D(double a, double b, double c, double d, double h, double v) {
	TRN_Matrix2DSet(this,a,b,c,d,h,v);
}

inline Matrix2D::Matrix2D(const Common::Matrix2D& m) {
	TRN_Matrix2DCopy(&m,this);
}

inline Matrix2D& Matrix2D::operator =(const Common::Matrix2D& m) {
	TRN_Matrix2DCopy(&m,this);
	return *this;
}

inline void Matrix2D::Set(double a, double b, double c, double d, double h, double v) {
	TRN_Matrix2DSet(this,a,b,c,d,h,v);
}

inline void Matrix2D::Concat(double a, double b, double c, double d, double h, double v) {
	TRN_Matrix2DConcat(this,a,b,c,d,h,v);
}

#if !defined(SWIG)
inline Matrix2D& Matrix2D::operator*= (const Matrix2D& m) {
	Concat(m.m_a, m.m_b, m.m_c, m.m_d, m.m_h, m.m_v);
	return *this;
}

inline Matrix2D Matrix2D::operator* (const Matrix2D& m) const {
	Matrix2D result=*this;
	result*=m;
	return result;
}

inline bool Matrix2D::operator ==(const Matrix2D& m) const {
	TRN_Bool result;
	TRN_Matrix2DEquals(this,&m,&result);
	return TBToB(result);
}
#else // !defined(SWIG)
inline Matrix2D Matrix2D::Multiply(const Matrix2D& m)
{
	Concat(m.m_a, m.m_b, m.m_c, m.m_d, m.m_h, m.m_v);
	return *this;
}

inline bool Matrix2D::IsEquals(const Matrix2D& m) const
{
	TRN_Bool result;
	TRN_Matrix2DEquals(this,&m,&result);
	return TBToB(result);
}
#endif // !defined(SWIG)

inline PDF::Point Matrix2D::Mult(const PDF::Point& pt) const {
	PDF::Point result;
	TRN_Matrix2DMult(this,(double*)&(pt.x),(double*)&(pt.y));
	result.x = pt.x;
	result.y = pt.y;
	return result;
}

#ifndef SWIG
inline void Matrix2D::Mult(double& in_out_x, double& in_out_y) const {
	TRN_Matrix2DMult(this,&in_out_x,&in_out_y);
}
#endif

inline Matrix2D Matrix2D::Inverse() const {
	Matrix2D result;
	REX(TRN_Matrix2DInverse(this,&result));
	return result;
}

inline void Matrix2D::Translate (double h, double v) {
	TRN_Matrix2DTranslate(this,h,v);
}

inline void Matrix2D::PreTranslate(double h, double v) {
	TRN_Matrix2DPreTranslate(this, h, v);
}

inline void Matrix2D::PostTranslate(double h, double v) {
	TRN_Matrix2DPostTranslate(this, h, v);
}

inline void Matrix2D::Scale (double h, double v) {
	TRN_Matrix2DScale(this,h,v);
}

inline Matrix2D Matrix2D::ZeroMatrix() {
	Matrix2D result;
	TRN_Matrix2DCreateZeroMatrix(&result);
	return result;
}

inline Matrix2D Matrix2D::IdentityMatrix () {
	Matrix2D result;
	TRN_Matrix2DCreateIdentityMatrix(&result);
	return result;
}

inline Matrix2D Matrix2D::RotationMatrix (const double angle) {
	Matrix2D result;
	TRN_Matrix2DCreateRotationMatrix(angle,&result);
	return result;
}

