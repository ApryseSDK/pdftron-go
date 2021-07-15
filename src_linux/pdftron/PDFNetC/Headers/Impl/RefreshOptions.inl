namespace pdftron{ namespace PDF{ 

inline RefreshOptions::RefreshOptions()
	: m_obj_set()
	, m_dict()
{
	m_dict = m_obj_set.CreateDict();
}

inline RefreshOptions::~RefreshOptions()
{
}


inline bool RefreshOptions::GetDrawBackgroundOnly()
{
	SDF::Obj found = m_dict.FindObj("DrawBackgroundOnly");
	if(found.IsValid())
	{
		return (found.GetBool());
	}
	return (true);
}

inline RefreshOptions& RefreshOptions::SetDrawBackgroundOnly(bool value)
{
	OptionsBase::PutBool(m_dict, "DrawBackgroundOnly", (value));
	return *this;
}


inline bool RefreshOptions::GetRefreshExisting()
{
	SDF::Obj found = m_dict.FindObj("RefreshExisting");
	if(found.IsValid())
	{
		return (found.GetBool());
	}
	return (true);
}

inline RefreshOptions& RefreshOptions::SetRefreshExisting(bool value)
{
	OptionsBase::PutBool(m_dict, "RefreshExisting", (value));
	return *this;
}


inline bool RefreshOptions::GetUseNonStandardRotation()
{
	SDF::Obj found = m_dict.FindObj("UseNonStandardRotation");
	if(found.IsValid())
	{
		return (found.GetBool());
	}
	return (false);
}

inline RefreshOptions& RefreshOptions::SetUseNonStandardRotation(bool value)
{
	OptionsBase::PutBool(m_dict, "UseNonStandardRotation", (value));
	return *this;
}


inline bool RefreshOptions::GetUseRoundedCorners()
{
	SDF::Obj found = m_dict.FindObj("UseRoundedCorners");
	if(found.IsValid())
	{
		return (found.GetBool());
	}
	return (false);
}

inline RefreshOptions& RefreshOptions::SetUseRoundedCorners(bool value)
{
	OptionsBase::PutBool(m_dict, "UseRoundedCorners", (value));
	return *this;
}


inline SDF::Obj& RefreshOptions::GetInternalObj()
{
	return m_dict;
}

}
}
