inline bool CADModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_CADModuleIsModuleAvailable(&result));
	return result != 0;
}

