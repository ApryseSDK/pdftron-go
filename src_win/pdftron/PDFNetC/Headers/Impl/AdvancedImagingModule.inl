inline bool AdvancedImagingModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_AdvancedImagingModuleIsModuleAvailable(&result));
	return result != 0;
}

