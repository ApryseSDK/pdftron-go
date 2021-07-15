#ifndef HPP_PDFTRON_PDF_LISTBOXWIDGET_INL
#define HPP_PDFTRON_PDF_LISTBOXWIDGET_INL



namespace pdftron {
	namespace PDF {
		namespace Annots {


			inline ListBoxWidget::ListBoxWidget(SDF::Obj d) : Widget(d)
			{

			}
			inline ListBoxWidget::ListBoxWidget(const Annot& annot) : Widget(annot.GetSDFObj())
			{

			}

			inline ListBoxWidget ListBoxWidget::Create(PDFDoc& doc, const Rect& pos, const UString& field_name)
			{
				TRN_Annot result;
				REX(TRN_ListBoxWidgetCreate(doc.mp_doc, (const TRN_Rect*)&pos, field_name.mp_impl, &result));
				return ListBoxWidget(result);
			}

			inline ListBoxWidget ListBoxWidget::Create(PDFDoc& doc, const Rect& pos, const Field& field)
			{
				TRN_Annot result;
				REX(TRN_ListBoxWidgetCreateWithField(doc.mp_doc, (const TRN_Rect*)&pos, (const TRN_Field*)&field, &result));
				return ListBoxWidget(result);
			}

			inline void ListBoxWidget::AddOption(const UString& value)
			{
				REX(TRN_ListBoxWidgetAddOption(mp_annot, value.mp_impl));
			}

#ifdef SWIG
			inline void ListBoxWidget::AddOptions(const std::vector<std::string>& opts)
			{
				if (opts.size() > 0)
				{
					std::vector<UString> tmp;
					tmp.reserve(opts.size());
					for (std::vector<std::string>::const_iterator it = opts.begin(); it != opts.end(); ++it)
					{
						tmp.push_back(UString(*it));
					}
					TRN_UString* tmp2 = (TRN_UString*)&tmp[0];
					REX(TRN_ListBoxWidgetAddOptions(mp_annot, tmp2, (TRN_UInt32)opts.size()));
				}
			}

			inline void ListBoxWidget::SetSelectedOptions(const std::vector<std::string>& selected_opts)
			{
				if (selected_opts.size() > 0)
				{
					std::vector<UString> tmp;
					tmp.reserve(selected_opts.size());
					for (std::vector<std::string>::const_iterator it = selected_opts.begin(); it != selected_opts.end(); ++it)
					{
						tmp.push_back(UString(*it));
					}
					TRN_UString* tmp2 = (TRN_UString*)&tmp[0];
					REX(TRN_ListBoxWidgetSetSelectedOptions(mp_annot, tmp2, (TRN_UInt32)selected_opts.size()));
				}
			}

			inline std::vector<std::string> ListBoxWidget::GetSelectedOptions()
			{
				// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
				TRN_Vector options_vec = NULL;
				REX(TRN_ListBoxWidgetGetSelectedOptions(mp_annot, (TRN_Vector*)&options_vec));

				TRN_UInt32 options_vec_size;
				TRN_VectorGetSize(options_vec, &options_vec_size);

				std::vector<std::string> result;
				for (TRN_UInt32 i = 0; i < options_vec_size; i++)
				{
					TRN_UString current_ustr = NULL;
					TRN_VectorGetAt(options_vec, i, (void**)&current_ustr);
					result.push_back(UString(current_ustr).ConvertToUtf8());
				}

				TRN_VectorDestroyKeepContents(options_vec);
				return result;
			}

			inline std::vector<std::string> ListBoxWidget::GetOptions()
			{
				// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
				TRN_Vector options_vec = NULL;
				REX(TRN_ListBoxWidgetGetOptions(mp_annot, (TRN_Vector*)&options_vec));

				TRN_UInt32 options_vec_size;
				TRN_VectorGetSize(options_vec, &options_vec_size);

				std::vector<std::string> result;
				for (TRN_UInt32 i = 0; i < options_vec_size; i++)
				{
					TRN_UString current_ustr = NULL;
					TRN_VectorGetAt(options_vec, i, (void**)&current_ustr);
					result.push_back(UString(current_ustr).ConvertToUtf8());
				}

				TRN_VectorDestroyKeepContents(options_vec);
				return result;
			}

			inline void ListBoxWidget::ReplaceOptions(const std::vector<std::string>& new_opts)
			{
				if (new_opts.size() > 0)
				{
					std::vector<UString> tmp;
					tmp.reserve(new_opts.size());
					for (std::vector<std::string>::const_iterator it = new_opts.begin(); it != new_opts.end(); ++it)
					{
						tmp.push_back(UString(*it));
					}
					TRN_UString* tmp2 = (TRN_UString*)&tmp[0];
					REX(TRN_ListBoxWidgetReplaceOptions(mp_annot, tmp2, (TRN_UInt32)new_opts.size()));
				}
			}

#else
			inline void ListBoxWidget::AddOptions(const std::vector<UString>& opts)
			{
				// UString class contains only a TRN_UString and no virtual functions, so an array of UStrings is also an array of TRN_UStrings
				TRN_UString* tmp = opts.size() > 0 ? (TRN_UString*)&opts[0] : NULL;
				REX(TRN_ListBoxWidgetAddOptions(mp_annot, tmp, (TRN_UInt32)opts.size()));
			}

			inline void ListBoxWidget::SetSelectedOptions(const std::vector<UString>& opts)
			{
				// UString class contains only a TRN_UString and no virtual functions, so an array of UStrings is also an array of TRN_UStrings
				TRN_UString* tmp = opts.size() > 0 ? (TRN_UString*)&opts[0] : NULL;
				REX(TRN_ListBoxWidgetSetSelectedOptions(mp_annot, tmp, (TRN_UInt32)opts.size()));
			}

			inline std::vector<UString> ListBoxWidget::GetSelectedOptions()
			{
				// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
				TRN_Vector options_vec = NULL;
				REX(TRN_ListBoxWidgetGetSelectedOptions(mp_annot, (TRN_Vector*)&options_vec));

				TRN_UInt32 options_vec_size;
				TRN_VectorGetSize(options_vec, &options_vec_size);

				std::vector<UString> result;
				for (TRN_UInt32 i = 0; i < options_vec_size; i++)
				{
					TRN_UString current_ustr = NULL;
					TRN_VectorGetAt(options_vec, i, (void**)&current_ustr);
					result.push_back(UString(current_ustr));
				}

				TRN_VectorDestroyKeepContents(options_vec);
				return result;
			}

			inline std::vector<UString> ListBoxWidget::GetOptions()
			{
				// Broadly similar to PDFDraw::GetSeparationBitmaps implementation
				TRN_Vector options_vec = NULL;
				REX(TRN_ListBoxWidgetGetOptions(mp_annot, (TRN_Vector*)&options_vec));

				TRN_UInt32 options_vec_size;
				TRN_VectorGetSize(options_vec, &options_vec_size);

				std::vector<UString> result;
				for (TRN_UInt32 i = 0; i < options_vec_size; i++)
				{
					TRN_UString current_ustr = NULL;
					TRN_VectorGetAt(options_vec, i, (void**)&current_ustr);
					result.push_back(UString(current_ustr));
				}

				TRN_VectorDestroyKeepContents(options_vec);
				return result;
			}

			inline void ListBoxWidget::ReplaceOptions(const std::vector<UString>& new_opts)
			{
				// UString class contains only a TRN_UString and no virtual functions, so an array of UStrings is also an array of TRN_UStrings
				TRN_UString* tmp = new_opts.size() > 0 ? (TRN_UString*)&new_opts[0] : NULL;
				REX(TRN_ListBoxWidgetReplaceOptions(mp_annot, tmp, (TRN_UInt32)new_opts.size()));
			}
#endif

			inline void ListBoxWidget::RemoveOption(const UString& value)
			{
				REX(TRN_ListBoxWidgetRemoveOption(mp_annot, value.mp_impl));
			}

		};// namespace Annots
	};
};

#endif
