#ifndef PDFTRON_H_CPPPDFKeyStrokeEventData
#define PDFTRON_H_CPPPDFKeyStrokeEventData

#include <C/PDF/TRN_Action.h>

namespace pdftron {
	namespace PDF {

class KeyStrokeEventData
{
public:
	KeyStrokeEventData(const UString& field_name, const UString& current_value, const UString& change, int selection_start, int selection_end);
	~KeyStrokeEventData();
	KeyStrokeEventData(const KeyStrokeEventData& data);
	KeyStrokeEventData& operator=(const KeyStrokeEventData& data);

	void Destroy();

#ifndef SWIGHIDDEN
	KeyStrokeEventData(TRN_KeyStrokeEventData impl);
	TRN_KeyStrokeEventData mp_data;
#endif 
};

	}
}

#include<Impl/KeyStrokeEventData.inl>

#endif