#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

TRN_API TRN_ActionParameterCreate(const TRN_Action action,TRN_ActionParameter *result);
TRN_API TRN_ActionParameterCreateWithField(const TRN_Action action, const TRN_Field* field, TRN_ActionParameter *result);
TRN_API TRN_ActionParameterCreateWithAnnot(const TRN_Action action, const TRN_Annot annot, TRN_ActionParameter *result);
TRN_API TRN_ActionParameterCreateWithPage(const TRN_Action action, const TRN_Page page, TRN_ActionParameter * result);
TRN_API TRN_ActionParameterDestroy(TRN_ActionParameter ap);
TRN_API TRN_ActionParameterGetAction(TRN_ActionParameter ap, TRN_Action *result);
TRN_API TRN_ActionParameterAssign(TRN_ActionParameter left, TRN_ActionParameter right);

#ifdef __cplusplus
}
#endif

