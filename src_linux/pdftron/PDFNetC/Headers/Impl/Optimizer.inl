//IMAGE SETTINGS
//CONSTRUCTORS
inline ImageSettings::ImageSettings()
{
	TRN_OptimizerImageSettingsInit((TRN_OptimizerImageSettings*)this);
}

//FUNCTIONS
inline void ImageSettings::SetImageDPI(double maximum,double resampling)
{
	m_max_dpi = maximum;
	m_resample_dpi = resampling;
}

inline void ImageSettings::SetCompressionMode(enum CompressionMode mode)
{
	m_compression_mode = (enum TRN_Optimizer_ImageSettings_CompressionMode)mode;
}

inline void ImageSettings::SetDownsampleMode(enum DownsampleMode mode)
{
	m_downsample_mode = (enum TRN_Optimizer_ImageSettings_DownsampleMode)mode;
}

inline void ImageSettings::SetQuality(UInt32 quality)
{
	m_quality = quality;
}

inline void ImageSettings::ForceRecompression(bool force)
{
	m_force_recompression = force;
}

inline void ImageSettings::ForceChanges(bool force)
{
	m_force_changes = force;
}

//MONO IMAGE SETTINGS
//CONSTRUCTORS
inline MonoImageSettings::MonoImageSettings()
{
	TRN_OptimizerMonoImageSettingsInit((TRN_OptimizerMonoImageSettings*)this);
}

//FUNCTIONS
inline void MonoImageSettings::SetImageDPI(double maximum,double resampling)
{
	m_max_dpi = maximum;
	m_resample_dpi = resampling;
}

inline void MonoImageSettings::SetCompressionMode(enum CompressionMode mode)
{
	m_compression_mode = (enum TRN_Optimizer_MonoImageSettings_CompressionMode)mode;
}

inline void MonoImageSettings::SetDownsampleMode(enum DownsampleMode mode)
{
	m_downsample_mode = (enum TRN_Optimizer_MonoImageSettings_DownsampleMode)mode;
}

inline void MonoImageSettings::ForceRecompression(bool force)
{
	m_force_recompression = force;
}

inline void MonoImageSettings::ForceChanges(bool force)
{
	m_force_changes = force;
}

inline void MonoImageSettings::SetJBIG2Threshold(double jbig2_threshold)
{
	m_jbig2_threshold = jbig2_threshold / 10;
}

inline TextSettings::TextSettings()
{
	TRN_OptimizerTextSettingsInit((TRN_OptimizerTextSettings*)this);
}

inline void TextSettings::SubsetFonts(bool subset)
{
	m_subset_fonts = subset;
}


inline void TextSettings::EmbedFonts(bool embed)
{
	m_embed_fonts = embed;
}



inline OptimizerSettings::OptimizerSettings() : m_remove_custom(true)
{

}
	
inline void OptimizerSettings::SetColorImageSettings(const ImageSettings& settings)
{
	m_color_image_settings=settings;
}

inline void OptimizerSettings::SetGrayscaleImageSettings(const ImageSettings& settings)
{
	m_grayscale_image_settings=settings;
}

inline void OptimizerSettings::SetMonoImageSettings(const MonoImageSettings& settings)
{
	m_mono_image_settings=settings;
}
	
inline void OptimizerSettings::SetTextSettings(const TextSettings& settings)
{
	m_text_settings=settings;
}

inline void OptimizerSettings::RemoveCustomEntries(bool should_remove)
{
	m_remove_custom=should_remove;
}


//OPTIMIZER
inline void Optimizer::Optimize(PDFDoc& doc)
{
	OptimizerSettings settings;
	Optimizer::Optimize(doc, settings);
}

inline void Optimizer::Optimize(PDFDoc& doc, const OptimizerSettings& settings)
{
	REX(TRN_OptimizerOptimize(doc.mp_doc,
		(const TRN_OptimizerImageSettings*)&settings.m_color_image_settings,
		(const TRN_OptimizerImageSettings*)&settings.m_grayscale_image_settings,
		(const TRN_OptimizerMonoImageSettings*)&settings.m_mono_image_settings,
		(const TRN_OptimizerTextSettings*)&settings.m_text_settings,BToTB(settings.m_remove_custom)));
}
