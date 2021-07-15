
inline Date::Date ()
{
	REX(TRN_DateInit(2008,1,1,0,0,0, this));
}

inline Date::Date (SDF::Obj d)
{
	REX(TRN_DateAttach(this,d.mp_obj));
}

inline Date::Date (UInt16 year, char month, char day, char hour, char minute, char second)
{
	REX(TRN_DateInit(year,month,day,hour,minute,second, this));
}

inline Date::Date (const Date& d)
{
	REX(TRN_DateAssign(this, &d));
}

inline Date& Date::operator=(const Date& d)
{
	REX(TRN_DateAssign(this,&d));
	return *this;
}

inline bool Date::IsValid() const
{
	TRN_Bool result;
	REX(TRN_DateIsValid(this,&result));
	return TBToB(result);
}

inline void Date::SetCurrentTime()
{
	TRN_DateSetCurrentTime(this);
}

inline void Date::Attach(SDF::Obj d)
{
	REX(TRN_DateAttach(this,d.mp_obj));
}

inline bool Date::Update(SDF::Obj d)
{
	TRN_Bool result;
	REX(TRN_DateUpdate(this,d.mp_obj,&result));
	return TBToB(result);
}

inline UInt16 Date::GetYear() { 
	return TRN_DateGetYear(this);
}
#ifndef SWIG
inline char Date::GetMonth() { 
	return TRN_DateGetMonth(this);
}

inline char Date::GetDay() { 
	return TRN_DateGetDay(this);
}

inline char Date::GetHour() { 
	return TRN_DateGetHour(this);
}

inline char Date::GetMinute() { 
	return TRN_DateGetMinute(this);
}

inline char Date::GetSecond() { 
	return TRN_DateGetSecond(this);
}

inline char Date::GetUT() { 
	return TRN_DateGetUT(this);
}

inline char Date::GetUTHour() { 
	return TRN_DateGetUTHour(this);
}

inline char Date::GetUTMin() { 
	return TRN_DateGetUTMin(this);
}
#else // SWIG
inline UInt8 Date::GetMonth() { 
	return TRN_DateGetMonth(this);
}

inline UInt8 Date::GetDay() { 
	return TRN_DateGetDay(this);
}

inline UInt8 Date::GetHour() { 
	return TRN_DateGetHour(this);
}

inline UInt8 Date::GetMinute() { 
	return TRN_DateGetMinute(this);
}

inline UInt8 Date::GetSecond() { 
	return TRN_DateGetSecond(this);
}

inline UInt8 Date::GetUT() { 
	return TRN_DateGetUT(this);
}

inline UInt8 Date::GetUTHour() { 
	return TRN_DateGetUTHour(this);
}

inline UInt8 Date::GetUTMin() { 
	return TRN_DateGetUTMin(this);
}
#endif // SWIG
