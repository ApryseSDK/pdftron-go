
namespace pdftron {
	namespace PDF {

inline ViewChangeCollection::ViewChangeCollection()
{
	REX(TRN_ViewChangeCollectionCreate(&mp_collection));
}

inline ViewChangeCollection::~ViewChangeCollection()
{
	DREX(mp_collection, TRN_ViewChangeCollectionDestroy(mp_collection));
}

inline void ViewChangeCollection::Destroy()
{
	REX(TRN_ViewChangeCollectionDestroy(mp_collection));
	mp_collection = 0;
}

inline ViewChangeCollection::ViewChangeCollection(const ViewChangeCollection& view_change)
{
	REX(TRN_ViewChangeCollectionCreate(&mp_collection));
	REX(TRN_ViewChangeCollectionAssign(mp_collection, view_change.mp_collection));
}

inline ViewChangeCollection& ViewChangeCollection::operator=(const ViewChangeCollection& view_change) {
	REX(TRN_ViewChangeCollectionAssign(mp_collection, view_change.mp_collection));
	return *this;
}

inline ViewChangeCollection::ViewChangeCollection(TRN_ViewChangeCollection view_change) : mp_collection(view_change){}

//for xamarin use only
inline ViewChangeCollection* ViewChangeCollection::CreateInternal(ptrdiff_t impl) {
	return new ViewChangeCollection((TRN_ViewChangeCollection)impl);
}

inline ptrdiff_t ViewChangeCollection::GetHandleInternal() {
	return (ptrdiff_t)mp_collection;
}

	}
}