#ifndef PDFTRON_H_CPPPDFActionParameter
#define PDFTRON_H_CPPPDFActionParameter

#include <C/PDF/TRN_ActionParameter.h>
#include <SDF/Obj.h>

namespace pdftron {
	namespace PDF {

/**
 * ActionParameter is a class used to describe all the information needed to
 * execute an action. In most cases only the action itself is necessary since
 * the document can be inferred from associated SDF::Obj, however some actions
 * particularly JavaScript actions on Field or Annot objects need access to
 * the associated Field or Annot object.
 */
class ActionParameter
{
public:

	ActionParameter(const Action& action, const Field& field);
	ActionParameter(const Action& action, const Annot& annot);
	ActionParameter(const Action& action, const Page& page);
	ActionParameter(const Action& action);
	ActionParameter(const ActionParameter& action_param);
	ActionParameter& operator=(const ActionParameter& action_param);
	~ActionParameter();
	Action GetAction();
	void Destroy();

	//for xamarin use only
	static ActionParameter* CreateInternal(ptrdiff_t impl);
	ptrdiff_t GetHandleInternal();

#ifndef SWIGHIDDEN
	ActionParameter(TRN_ActionParameter impl);
	TRN_ActionParameter mp_parameter;
#endif 
};

	}
}

#include<Impl/ActionParameter.inl>

#endif