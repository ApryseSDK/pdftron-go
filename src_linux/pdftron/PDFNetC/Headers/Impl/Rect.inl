
inline Rect::Rect()
{
	REX(TRN_RectInit(0,0,0,0, this));
}

inline Rect::Rect (SDF::Obj rect)
{
	REX(TRN_RectAttach(this, rect.mp_obj));
}


inline Rect::Rect (double x1, double y1, double x2, double y2)
{
	REX(TRN_RectInit(x1,y1,x2,y2, this));
}


inline Rect::Rect (const Rect& rect)
{
	REX(TRN_RectAssign(this, &rect));
}


inline Rect& Rect::operator=(const Rect& rect)
{
	REX(TRN_RectAssign(this, &rect));
	return *this;
}

inline void Rect::Attach(SDF::Obj rect)
{
	REX(TRN_RectAttach(this, rect.mp_obj));
}


inline bool Rect::Update(SDF::Obj rect)
{
	TRN_Bool result;
	REX(TRN_RectUpdate(this,rect.mp_obj,&result));
	return TBToB(result);
}


#ifndef SWIG
inline void Rect::Get(double& out_x1, double& out_y1, double& out_x2, double& out_y2) const
{
	REX(TRN_RectGet(this, &out_x1,&out_y1,&out_x2,&out_y2));
}
#endif


inline void Rect::Set(double x1, double y1, double x2, double y2)
{
	REX(TRN_RectSet(this, x1,y1,x2,y2));
}


inline double Rect::Width() const
{
	double result;
	REX(TRN_RectWidth(this, &result));
	return result;
}

inline double Rect::Height() const
{
	double result;
	REX(TRN_RectHeight(this, &result));
	return result;
}
inline bool Rect::Contains(double x, double y) const
{
	TRN_Bool result;
	REX(TRN_RectContains(this, x,y,&result));
	return TBToB(result);
}

inline bool Rect::IntersectRect(const Rect& rect1, const Rect& rect2)
{
	TRN_Bool result;
	REX(TRN_RectIntersectRect(this, &rect1, &rect2, &result));
	return TBToB(result);
}

inline void Rect::Inflate(double amount)
{
	REX(TRN_RectInflate1(this, amount));
}

inline void Rect::Inflate(double x, double y)
{
	REX(TRN_RectInflate2(this, x, y));
}


inline void Rect::Normalize() {
	REX(TRN_RectNormalize(this));
}

inline double Rect::GetX1() const {
	return TRN_RectGetX1(this);
}

inline double Rect::GetY1() const {
	return TRN_RectGetY1(this);
}
 
inline double Rect::GetX2() const {
	return TRN_RectGetX2(this);
}

inline double Rect::GetY2() const {
	return TRN_RectGetY2(this);
}

inline void Rect::SetX1(double x1) {
	TRN_RectSetX1(this, x1);
}

inline void Rect::SetY1(double y1) {
	TRN_RectSetY1(this, y1);
}

inline void Rect::SetX2(double x2) {
	TRN_RectSetX2(this, x2);
}

inline void Rect::SetY2(double y2) {
	TRN_RectSetY2(this, y2);
}

