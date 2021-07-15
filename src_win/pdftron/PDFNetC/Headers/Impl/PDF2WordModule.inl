inline bool PDF2WordModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_PDF2WordModuleIsModuleAvailable(&result));
	return result != 0;
}

