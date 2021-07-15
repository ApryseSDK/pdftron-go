
inline FDFField::FDFField (SDF::Obj field_dict, SDF::Obj fdf_dict) {
	REX(TRN_FDFFieldCreate(field_dict.mp_obj,fdf_dict.mp_obj,(TRN_FDFField*)this));
}

inline FDFField::FDFField (const FDFField& p) {
	REX(TRN_FDFFieldAssign((TRN_FDFField*)this,(const TRN_FDFField*)&p));
}

inline FDFField& FDFField::operator= (const FDFField& p) {
	REX(TRN_FDFFieldAssign((TRN_FDFField*)this,(const TRN_FDFField*)&p));
	return *this;
}

inline SDF::Obj FDFField::GetValue() {
	RetObj(TRN_FDFFieldGetValue((TRN_FDFField*)this,&result));
}

inline void FDFField::SetValue(SDF::Obj value) {
	REX(TRN_FDFFieldSetValue((TRN_FDFField*)this,value.mp_obj));
}

inline UString FDFField::GetName() {
	RetStr(TRN_FDFFieldGetName((TRN_FDFField*)this,&result));
}

inline UString FDFField::GetPartialName() {
	RetStr(TRN_FDFFieldGetPartialName((TRN_FDFField*)this,&result));
}

inline SDF::Obj FDFField::GetSDFObj () const {
	RetObj(TRN_FDFFieldGetSDFObj((TRN_FDFField*)this,&result));
}

inline SDF::Obj FDFField::FindAttribute (const char* attrib) const {
	RetObj(TRN_FDFFieldFindAttribute((TRN_FDFField*)this,attrib,&result));
}

