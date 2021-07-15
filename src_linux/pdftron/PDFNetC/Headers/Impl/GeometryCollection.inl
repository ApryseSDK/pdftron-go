inline GeometryCollection::~GeometryCollection()
{
	Destroy();
}

inline GeometryCollection::GeometryCollection(const GeometryCollection& other)
	: m_impl(other.m_impl)
	, m_owner(false)
{
	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}
}

inline void GeometryCollection::Destroy()
{
	if(m_owner)
	{
		DREX(m_impl, TRN_GeometryCollectionDestroy(m_impl));
		m_owner = false;
	}
}

inline GeometryCollection& pdftron::PDF::GeometryCollection::operator= (const GeometryCollection& other)
{
	Destroy();

	m_impl = other.m_impl;

	if(other.m_owner) {
		other.m_owner = false;
		m_owner = true;
	}

	return *this;
}

inline GeometryCollection::GeometryCollection()
	: m_impl(0)
	, m_owner(false)
{}

inline GeometryCollection::GeometryCollection(TRN_GeometryCollection impl)
	: m_impl(impl)
	, m_owner(true)
{}
inline Point GeometryCollection::SnapToNearest(double x, double y, UInt32 mode) const
{
	Point result;
	REX(TRN_GeometryCollectionSnapToNearest((TRN_GeometryCollection)m_impl, x, y, mode, (TRN_Point*)&result));
	return result;
}

inline Point GeometryCollection::SnapToNearestPixel(double x, double y, double dpi, UInt32 mode) const
{
	Point result;
	REX(TRN_GeometryCollectionSnapToNearestPixel((TRN_GeometryCollection)m_impl, x, y, dpi, mode, (TRN_Point*)&result));
	return result;
}

