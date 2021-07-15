#include<PDF/Action.h>

namespace pdftron {
	namespace PDF {

inline bool KeyStrokeActionResult::IsValid()
{
	TRN_Bool result;
	REX(TRN_KeyStrokeActionResultIsValid(mp_result, &result));
	return TBToB(result);
}

inline UString KeyStrokeActionResult::GetText()
{
	TRN_UString result;
	REX(TRN_KeyStrokeActionResultGetText(mp_result, &result));
	return UString(result);
}

inline KeyStrokeActionResult::KeyStrokeActionResult(){}
        
inline KeyStrokeActionResult::~KeyStrokeActionResult()
{
	DREX(mp_result, TRN_KeyStrokeActionResultDestroy(mp_result));
}

inline KeyStrokeActionResult::KeyStrokeActionResult(const KeyStrokeActionResult& action_result)
{
	REX(TRN_KeyStrokeActionResultCopy(action_result.mp_result, &mp_result));
}

inline KeyStrokeActionResult& KeyStrokeActionResult::operator=(const KeyStrokeActionResult& action_result)
{
	REX(TRN_KeyStrokeActionResultAssign(mp_result, action_result.mp_result));
	return *this;
}

inline void KeyStrokeActionResult::Destroy()
{
	REX(TRN_KeyStrokeActionResultDestroy(mp_result));
	mp_result = 0;
}

inline KeyStrokeActionResult::KeyStrokeActionResult(TRN_KeyStrokeActionResult action_result) : mp_result(action_result){}

	}
}