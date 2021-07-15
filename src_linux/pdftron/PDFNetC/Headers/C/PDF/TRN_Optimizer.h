//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
#ifndef PDFTRON_H_CPDFOptimizer
#define PDFTRON_H_CPDFOptimizer

#ifdef __cplusplus
extern "C" {
#endif

#include <C/Common/TRN_Types.h>

// Image Settings

enum TRN_Optimizer_ImageSettings_CompressionMode
{
	e_Optimizer_ImageSettings_retain,
	e_Optimizer_ImageSettings_flate,
	e_Optimizer_ImageSettings_jpeg,
	e_Optimizer_ImageSettings_jpeg2000,
	e_Optimizer_ImageSettings_none
};

enum TRN_Optimizer_ImageSettings_DownsampleMode
{
	e_Optimizer_ImageSettings_off,
	e_Optimizer_ImageSettings_default
};

struct TRN_optimizerimagesettings
{
	size_t m_max_pixels;
	enum TRN_Optimizer_ImageSettings_CompressionMode m_compression_mode;
	enum TRN_Optimizer_ImageSettings_DownsampleMode m_downsample_mode;
	TRN_UInt32 m_quality;
	double m_max_dpi, m_resample_dpi;
	TRN_Bool m_force_recompression, m_force_changes;
};
typedef struct TRN_optimizerimagesettings TRN_OptimizerImageSettings;

TRN_API TRN_OptimizerImageSettingsInit(TRN_OptimizerImageSettings* result);

// Mono Image Settings

enum TRN_Optimizer_MonoImageSettings_CompressionMode
{
	e_Optimizer_MonoImageSettings_jbig2,
	e_Optimizer_MonoImageSettings_flate,
	e_Optimizer_MonoImageSettings_none,
	e_Optimizer_MonoImageSettings_ccitt
};

enum TRN_Optimizer_MonoImageSettings_DownsampleMode
{
	e_Optimizer_MonoImageSettings_off,
	e_Optimizer_MonoImageSettings_default
};

struct TRN_optimizermonoimagesettings
{
	size_t m_max_pixels;
	enum TRN_Optimizer_MonoImageSettings_CompressionMode m_compression_mode;
	enum TRN_Optimizer_MonoImageSettings_DownsampleMode m_downsample_mode;
	double m_max_dpi, m_resample_dpi, m_jbig2_threshold;
	TRN_Bool m_force_recompression, m_force_changes;
};
typedef struct TRN_optimizermonoimagesettings TRN_OptimizerMonoImageSettings;

TRN_API TRN_OptimizerMonoImageSettingsInit(TRN_OptimizerMonoImageSettings* result);


struct TRN_optimizertextsettings
{
	TRN_Bool m_subset_fonts,m_embed_fonts;
};
typedef struct TRN_optimizertextsettings TRN_OptimizerTextSettings;

TRN_API TRN_OptimizerTextSettingsInit(TRN_OptimizerTextSettings* result);

// Optimizer
TRN_API TRN_OptimizerOptimize(TRN_PDFDoc doc, const TRN_OptimizerImageSettings* color_image_settings,
							  const TRN_OptimizerImageSettings* grayscale_image_settings,
							  const TRN_OptimizerMonoImageSettings* mono_image_settings,
								const TRN_OptimizerTextSettings* text_settings,
								TRN_Bool remove_custom);

#ifdef __cplusplus
}
#endif

#endif // PDFTRON_H_CPDFOptimizer
