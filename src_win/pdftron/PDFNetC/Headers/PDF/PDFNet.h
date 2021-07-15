//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPPPDFPDFNet
#define PDFTRON_H_CPPPDFPDFNet

#include <C/PDF/TRN_PDFNet.h>
#include <Common/UString.h>
#include <Common/Iterator.h>
#include <Filters/Filter.h>

namespace pdftron { 

/** 
 * PDFNet contains global library initialization, registration, configuration,
 * and termination methods. 
 * 
 * @note there is only a single, static instance of PDFNet class. Initialization
 * and termination methods need to be called only once per application session. 
 */
class PDFNet
{
public:

	/** 
	* Initializes PDFNet library. 
	* Initialize() is usually called once, during process initialization.
	*
	* @note With the exception of SetPersistentCache and SetTempPath, it is unsafe to call any other PDFNet API without first initializing 
	* the library
	* 
	* @param license_key Optional license key used to activate the product.
	 * If the license_key is not specified or is null, the product will work in 
	 * demo mode.
	 *
	 * @exception If the license_key is invalid, the function will throw an exception.
	*/
	static void Initialize(const char* license_key = 0);

	/**
	* A switch that can be used to turn on/off JavaScript engine
	*
	* @param enable true to enable JavaScript engine, false to disable.
	*/
	static void EnableJavaScript(bool enable);

	/**
	* Test whether JavaScript is enabled
	*
	* @return true if it is enabled, false otherwise
	*/
	static bool IsJavaScriptEnabled();

#ifndef SWIG
	/** 
	 * Terminates PDFNet library.
	 * Terminate() is usually called once, when the process is terminated. 
	 * 
	 * @note it is unsafe to call any other PDFNet API after you terminate 
	 * the library.
	 */
	 static void Terminate();
#endif

	/**
	 * Sets the location of PDFNet resource file. 
	 * 
	 * @note Starting with v.4.5 PDFNet no longer requires a seperate resource file,
	 * and so this function is not required for proper PDFNet initialization. It remains
	 * available for backward compatibility.
	 * On mobile systems (iOS, Android, etc.) this method is required for proper
	 * initialization starting with version 6.0. (This helps reduce overall app size.)
	 * The function can be used on all platforms to specify a default search path for
	 * ICC profiles, fonts, and other user defined resources.
	 * 
	 * @param path - The default resource directory path.
	 * @return true if path is found, false otherwise.
	 */
	 static bool SetResourcesPath(const UString& path);

	/** 
	* @return the location of PDFNet resources folder. Empty string means 
	* that resources are located in your application folder.
	*/
	 static UString GetResourcesPath();
	 
	/**
	 * Sets the location of PDFNet resource file. 
	 * 
	 * @note Starting with v.4.5 PDFNet no longer requires a seperate resource file,
	 * and so this function is not required for proper PDFNet initialization.
	 * The function can be used on all platforms to specify search paths for
	 * ICC profiles, fonts, and other user defined resources.
	 * 
	 * @param path - The resource directory path to add to the search list.
	 */
	 static void AddResourceSearchPath(const UString& path);

	 /** 
	  * @return PDFNet version number. 
	  */
	 static double GetVersion();
	
	enum CMSType
	 {
		e_lcms,		///< Use LittleCMS (available on all supported platforms).
		e_icm,		///< Use Windows ICM2 (available only on Windows platforms).
		e_no_cms    ///< No ICC color management.
	 };

	/** 
	 * Used to set a specific Color Management System (CMS) for 
	 * use during color conversion operators, image rendering, etc.
	 * 
	 * @param t identifies the type of color management to use.
	 */
	 static void SetColorManagement(CMSType t = e_lcms);

	/** 
	 * Sets the default ICC color profile for DeviceCMYK color space. 
	 * 
	 * @note You can use this method to override default PDFNet settings.
	 * For more information on default color spaces please refer to 
	 * section 'Default Color Spaces' in Chapter 4.5.4 of PDF Reference Manual.
	 * 
	 * @exception the function will throw Exception if the ICC profile 
	 * can't be found or if it fails to open.
	 */
	 static void SetDefaultDeviceCMYKProfile(const UString& icc_filename);

	 /** 
	 * Sets the default ICC color profile for DeviceCMYK color space. 
	 * 
	 * @note You can use this method to override default PDFNet settings.
	 * For more information on default color spaces please refer to 
	 * section 'Default Color Spaces' in Chapter 4.5.4 of PDF Reference Manual.
	 * 
	 * @exception the function will throw Exception if the ICC profile 
	 * fails to open.
	 */
	 static void SetDefaultDeviceCMYKProfile(Filters::Filter stream);
	 

	/** 
	 * Sets the default ICC color profile for DeviceRGB color space. 
	 * 
	 * @note You can use this method to override default PDFNet settings.
	 * For more information on default color spaces please refer to 
	 * section 'Default Color Spaces' in Chapter 4.5.4 of PDF Reference Manual.
	 * 
	 * @exception the function will throw Exception if the ICC profile 
	 * can't be found or if it fails to open.
	 */
	 static void SetDefaultDeviceRGBProfile(const UString& icc_filename);

	 /** 
	 * Sets the default ICC color profile for DeviceRGB color space. 
	 * 
	 * @note You can use this method to override default PDFNet settings.
	 * For more information on default color spaces please refer to 
	 * section 'Default Color Spaces' in Chapter 4.5.4 of PDF Reference Manual.
	 * 
	 * @exception the function will throw Exception if the ICC profile 
	 * fails to open.
	 */
	 static void SetDefaultDeviceRGBProfile(Filters::Filter stream);

	/** 
	 * Sets the default policy on using temporary files.
	 * 
	 * @use_disk if parameter is true then new documents are allowed to create
	 * temporary files; otherwise all document contents will be stored in memory.
	 */
	static void SetDefaultDiskCachingEnabled( bool use_disk );

	enum FlateCompressionLevel 
	{ 
		e_Z_DEFAULT_COMPRESSION = -1,
		e_Z_NO_COMPRESSION = 0,
		e_Z_BEST_SPEED = 1,
		e_Z_BEST_COMPRESSION = 9
	};
	/**
	*  Sets the default compression level for Flate (ZLib).
	*
	*	@param level An integer in range 0-9 representing the compression value to use as
	*  a default for any Flate streams (e.g used to compress content streams, PNG images, etc).
	*  The library normally uses the default compression level (Z_DEFAULT_COMPRESSION).
	*  For most images, compression values in the range 3-6 compress nearly as well as higher
	*  levels, and do so much faster. For on-line applications it may be desirable to have
	*  maximum speed Z_BEST_SPEED = 1). You can also specify no compression (Z_NO_COMPRESSION = 0).
	*
	*	@default Z_DEFAULT_COMPRESSION (-1).
	*/
	static void SetDefaultFlateCompressionLevel(int level);

	/**
	 *
	 *  Sets the default parameters for the viewer cache. Any subsequently created documents
	 *	will use these parameters.
	 *
	 *	@param max_cache_size - The maximum size, in bytes, of the entire document's page cache. Set to zero to disable the viewer cache.
	 *	@param on_disk - If set to 'true', cache will be stored on the local filesystem. If set to 'false', cache will be stored in heap memory.
	 *
	 *	@default Desktop: max_cache_size = 512 MB, on_disk = true | Mobile:  max_cache_size = 100 MB, on_disk = false
	 */
	static void SetViewerCache(size_t max_cache_size, bool on_disk);

	/**
	 * Standard character orderings. PDFNet.AddFontSubst() can be used 
	 * to associate a specific font with a given character ordering 
	 * and to override default font mapping algorithm.
	 */
	enum CharacterOrdering {
		e_Identity = 0,    ///< Generic/Unicode
		e_Japan1   = 1,    ///< Japanese
		e_Japan2   = 2,    ///< Japanese
		e_GB1      = 3,    ///< Chinese; Simplified
		e_CNS1     = 4,    ///< Chinese; Traditional
		e_Korea1   = 5     ///< Korean
	};

	/** 
	 * AddFontSubst functions can be used to create font substitutes
	 * that can override default PDFNet font selection algorithm.
	 * 
	 * AddFontSubst functions are useful in situations where referenced fonts 
	 * are not present in the document and PDFNet font substitution
	 * algorithm is not producing desired results.
	 * 
	 * AddFontSubst(fontname, fontpath) maps the given font name (i.e. 'BaseFont' 
	 * entry from the font dictionary) to a font file.
	 * 
	 * 
 	 * The following is an example of using this function to provide user 
	 * defined font substitutes:
	 *
	 * @code
	 * PDFNet::Initialize();
	 * PDFNet::SetResourcesPath("c:/myapp/resources");
	 * // Specify specific font mappings...
	 * PDFNet::AddFontSubst("MinionPro-Regular", "c:/myfonts/MinionPro-Regular.otf");
	 * PDFNet::AddFontSubst("Times-Roman", "c:/windows/fonts/times.ttf");
	 * PDFNet::AddFontSubst("Times-Italic", "c:/windows/fonts/timesi.ttf");
	 * ... 
	 * PDFDoc doc("c:/my.pdf");
	 * ...
	 * @endcode 
	 */
	 static bool AddFontSubst(const char* fontname, const UString& fontpath);
	 /**
	 * AddFontSubst functions can be used to create font substitutes
	 * that can override default PDFNet font selection algorithm.
	 *
	 * AddFontSubst functions are useful in situations where referenced fonts
	 * are not present in the document and PDFNet font substitution
	 * algorithm is not producing desired results.
	 *
	 * AddFontSubst(ordering, fontpath) maps the given character ordering (see
	 * Ordering entry in CIDSystemInfo dictionary; Section 5.6.2 in PDF Reference)
	 * to a font file. This method is less specific that the former variant of
	 * AddFontSubst, and can be used to override a range of missing fonts (or
	 * any missing font) with a predefined substitute.
	 *
	 * The following is an example of using this function to provide user
	 * defined font substitutes:
	 *
	 * @code
	 * PDFNet::Initialize();
	 * PDFNet::SetResourcesPath("c:/myapp/resources");
	 *
	 * // Specify more general font mappings...
	 * PDFNet::AddFontSubst(PDFNet::e_Identity, "c:/myfonts/arialuni.ttf");  // Arial Unicode MS
	 * PDFNet::AddFontSubst(PDFNet::e_Japan1, "c:/myfonts/KozMinProVI-Regular.otf");
	 * PDFNet::AddFontSubst(PDFNet::e_Japan2, "c:/myfonts/KozMinProVI-Regular.otf");
	 * PDFNet::AddFontSubst(PDFNet::e_Korea1, "c:/myfonts/AdobeSongStd-Light.otf");
	 * PDFNet::AddFontSubst(PDFNet::e_CNS1, "c:/myfonts/AdobeMingStd-Light.otf");
	 * PDFNet::AddFontSubst(PDFNet::e_GB1, "c:/myfonts/AdobeMyungjoStd-Medium.otf");
	 * ...
	 * PDFDoc doc("c:/my.pdf");
	 * ...
	 * @endcode
	 */
	 static bool AddFontSubst(CharacterOrdering ordering, const UString& fontpath);

	/**
	 * Set the location of temporary folder. 
	 * 
	 * This method is provided for applications that require tight control of 
	 * the location where temporary files are created.
	 */ 
	 static void SetTempPath(const UString& temp_path);

	/**
	 * Set the location of persistent cache files. 
	 * 
	 * This method is provided for applications that require tight control of 
	 * the location where temporary files are created.
	 */ 
	 static void SetPersistentCachePath(const UString& persistent_path);

	/**
	 * Get available fonts on the system.
	 *
	 * @return A JSON list of fonts accessible to PDFNet
	 */
	static UString GetSystemFontList();

#ifndef SWIG
	/**
	 * CreateSecurityHandler is a function pointer and a factory method used to create 
	 * new instances of SecurityHandler. The function pointer is used to register a 
	 * new type of SecurityHandler with PDFNet.
	 */
	typedef TRN_PDFNetCreateSecurityHandler CreateSecurityHandler;

	/**
	 * Registers a new type of SecurityHandler. If a handler with the same name was 
	 * already registered, the new SecurityHandler will replace the old handler.
	 * 
	 * @param handler_name - SecurityHandler's document name (as it appears in Encrypt dictionary).
	 * @param factory_method -  a function pointer and a factory method used to create 
	 *    new instances of SecurityHandler.
	 */
	static void RegisterSecurityHandler(const char* handler_name, const char* gui_name, CreateSecurityHandler factory_method);

	/**
	 *	SecurityDescriptor is a class describing SecurityHandler. 
	 */
	class SecurityDescriptor : public TRN_SecHdlrInfo {
	public:
		const char* GetName() { return m_name; }
		const char* GetGuiName() { return m_gui_name; }
		CreateSecurityHandler GetCreateFunct() { return m_factory_method; }
	};

	typedef Common::Iterator<SecurityDescriptor> SecurityDescriptorIterator;

	/**
	 * @return iterator to the first SecurityDescriptor in the list of currently 
	 * registered SecurityHandler types.
	 */ 
	static SecurityDescriptorIterator GetSecHdlrInfoIterator();

	/**
	* Sets a callback function used to override the default PDFNet number serialization 
	* routine. Applications that require advanced control over PDF number processing 
	* can provide a custom handler.
	* 
	* @param WriteProc A pointer to a function that will serialize a floating-point number 
	* in PDF number format. The following parameters describe the callback function:
	*   @param num  The number to be converted to decimal.
	*   @param in_buf the buffer used to serialize the number.
	*   @param in_buf_size the size of input buffer.
	*   @return A pointer within in_buf array where the number string starts.
	*/
	static void SetNumberWriteProc(char* (*WriteProc) (double num, char *in_buf, int in_buf_size));

	/**
	* Sets a callback function used to override the default PDFNet number parsing function.
	* Applications that require advanced control over PDF number processing can
	* provide a custom handler.
	*
	* @param WriteProc A pointer to a function that will serialize a floating-point number 
	* in PDF number format. 
	*/
	static void SetNumberReadProc(TRN_Bool (*ReadProc) (const TRN_UChar *buf, double *output)); 
#endif

	//! @cond
	typedef enum _LogLevel
	{
		e_LogLevel_Off		= -1,
		e_LogLevel_Fatal	= 5,
		e_LogLevel_Error	= 4,
		e_LogLevel_Warning	= 3,
		e_LogLevel_Info		= 2,
		e_LogLevel_Trace	= 1,
		e_LogLevel_Debug	= 0
	}
	LogLevel;

	static void SetLogLevel(LogLevel level = e_LogLevel_Fatal);
	//! @endcond

   /**
	* Add PDFTron Custom Security handler
	*
	* @param custom_id The user's custom id. The id should match what was used to create PDFTronCustomSecurityHandler when encrypting the document.
	* @note calling this function is a requirement to load files encrypted with PDFTronCustomSecurityHandler.
	*/
	static void AddPDFTronCustomHandler(UInt32 custom_id);
};



#include <Impl/PDFNet.inl>

};	// namespace pdftron

#endif // PDFTRON_H_CPPPDFPDFNet
