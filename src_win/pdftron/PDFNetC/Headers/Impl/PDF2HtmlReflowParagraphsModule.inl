inline bool PDF2HtmlReflowParagraphsModule::IsModuleAvailable()
{
	TRN_Bool result = 0;
	REX(TRN_PDF2HtmlReflowParagraphsModuleIsModuleAvailable(&result));
	return result != 0;
}

