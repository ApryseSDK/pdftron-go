#include <SDF/Obj.h>
#include <PDF/Field.h>
#include <PDF/Action.h>
#include <PDF/Annots.h>
#include <PDF/Page.h>

namespace pdftron {
	namespace PDF {

inline ActionParameter::ActionParameter(const Action& action, const Field& field)
{
	REX(TRN_ActionParameterCreateWithField(action.mp_action,&(field.mp_field),&mp_parameter));
}

inline ActionParameter::ActionParameter(const Action& action, const Annot& annot)
{
	REX(TRN_ActionParameterCreateWithAnnot(action.mp_action, annot.mp_annot, &mp_parameter));
}

inline ActionParameter::ActionParameter(const Action& action, const Page& page)
{
	REX(TRN_ActionParameterCreateWithPage(action.mp_action, page.mp_page, &mp_parameter));
}

inline ActionParameter::ActionParameter(const Action& action)
{
	REX(TRN_ActionParameterCreate(action.mp_action, &mp_parameter));
}

inline ActionParameter::ActionParameter(const ActionParameter& action_param)
{
	REX(TRN_ActionParameterCreate(0,&mp_parameter));
	REX(TRN_ActionParameterAssign(mp_parameter, action_param.mp_parameter));
}

inline ActionParameter& ActionParameter::operator=(const ActionParameter& action_param) {
	REX(TRN_ActionParameterAssign(mp_parameter, action_param.mp_parameter));
	return *this;
}

inline ActionParameter::~ActionParameter()
{
	DREX(mp_parameter, TRN_ActionParameterDestroy(mp_parameter));
}

inline void ActionParameter::Destroy()
{
	REX(TRN_ActionParameterDestroy(mp_parameter));
	mp_parameter = 0;
}

inline Action ActionParameter::GetAction()
{
	TRN_Action result;
	REX(TRN_ActionParameterGetAction(mp_parameter, &result));
	return Action(result); 
}

inline ActionParameter::ActionParameter(TRN_ActionParameter impl) : mp_parameter(impl) {}

//for xamarin use only
inline ActionParameter* ActionParameter::CreateInternal(ptrdiff_t impl) {
	return new ActionParameter((TRN_ActionParameter)impl);
}

inline ptrdiff_t ActionParameter::GetHandleInternal() {
	return (ptrdiff_t)mp_parameter;
}
	}
}
