inline UInt64 ByteRange::GetStartOffset() const
{
	UInt64 result;
	TRN_ByteRangeGetStartOffset(this, (TRN_UInt64*) &result);   
	return result;
}

inline UInt64 ByteRange::GetEndOffset() const
{
	UInt64 result;
	TRN_ByteRangeGetEndOffset(this, (TRN_UInt64*) &result);
	return result;
}

inline UInt64 ByteRange::GetSize() const
{
	UInt64 result;
	TRN_ByteRangeGetSize(this, (TRN_UInt64*) &result);
	return result;
}

