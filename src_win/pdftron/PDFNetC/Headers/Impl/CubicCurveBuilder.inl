inline CubicCurveBuilder::~CubicCurveBuilder()
{
	Destroy();
}

inline CubicCurveBuilder::CubicCurveBuilder(const CubicCurveBuilder& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void CubicCurveBuilder::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_CubicCurveBuilderDestroy(&m_impl));
		m_owner = false;
	}
}

inline CubicCurveBuilder& pdftron::PDF::CubicCurveBuilder::operator= (const CubicCurveBuilder& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline CubicCurveBuilder::CubicCurveBuilder()
	: m_impl(0)
	, m_owner(false)
{}

inline CubicCurveBuilder::CubicCurveBuilder(TRN_CubicCurveBuilder impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline UInt32 CubicCurveBuilder::NumSourcePoints()
{
	UInt32 result = 0;
	REX(TRN_CubicCurveBuilderNumSourcePoints((TRN_CubicCurveBuilder)m_impl, &result));
	return result;
}

inline void CubicCurveBuilder::AddSourcePoint(double x, double y)
{
	REX(TRN_CubicCurveBuilderAddSourcePoint((TRN_CubicCurveBuilder)m_impl, x, y));
}

inline UInt32 CubicCurveBuilder::NumCubicPoints()
{
	UInt32 result = 0;
	REX(TRN_CubicCurveBuilderNumCubicPoints((TRN_CubicCurveBuilder)m_impl, &result));
	return result;
}

inline double CubicCurveBuilder::GetCubicXCoord(UInt32 index)
{
	double result = 0;
	REX(TRN_CubicCurveBuilderGetCubicXCoord((TRN_CubicCurveBuilder)m_impl, index, &result));
	return result;
}

inline double CubicCurveBuilder::GetCubicYCoord(UInt32 index)
{
	double result = 0;
	REX(TRN_CubicCurveBuilderGetCubicYCoord((TRN_CubicCurveBuilder)m_impl, index, &result));
	return result;
}

