#include<PDF/Action.h>

namespace pdftron {
	namespace PDF {

inline KeyStrokeEventData::KeyStrokeEventData(const UString& field_name, const UString& current_value, const UString& change, int selection_start, int selection_end)
{
	REX(TRN_KeyStrokeEventDataCreate(field_name.mp_impl, current_value.mp_impl, change.mp_impl, selection_start, selection_end, &mp_data));
}

inline KeyStrokeEventData::~KeyStrokeEventData()
{
	DREX(mp_data, TRN_KeyStrokeEventDataDestroy(mp_data));
}

inline KeyStrokeEventData::KeyStrokeEventData(const KeyStrokeEventData& data)
{
	REX(TRN_KeyStrokeEventDataCopy(data.mp_data, &mp_data));
}

inline KeyStrokeEventData& KeyStrokeEventData::operator=(const KeyStrokeEventData& data)
{
	REX(TRN_KeyStrokeEventDataAssign(mp_data, data.mp_data));
	return *this;
}

inline void KeyStrokeEventData::Destroy()
{
	REX(TRN_KeyStrokeEventDataDestroy(mp_data));
	mp_data = 0;
}

inline KeyStrokeEventData::KeyStrokeEventData(TRN_KeyStrokeEventData impl) : mp_data(impl) {}

	}
}