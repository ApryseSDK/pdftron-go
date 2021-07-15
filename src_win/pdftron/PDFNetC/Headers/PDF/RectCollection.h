#ifndef PDFTRON_H_CPPPDFRectCollection
#define PDFTRON_H_CPPPDFRectCollection

#include <PDF/Rect.h>
#include <vector>

namespace pdftron{ namespace PDF{ 

class RectCollection
{
public:
	RectCollection()
	{}
	
	void AddRect(const Rect& to_add)
	{
		AddRect(to_add.GetX1(), to_add.GetY1(), to_add.GetX2(), to_add.GetY2());
	}
	
	void AddRect(double x1, double y1, double x2, double y2)
	{
		InnerRect temp = {x1, y1, x2, y2};
		m_rects.push_back(temp);
	}
	
	Rect GetRectAt(size_t index) const
	{
		const InnerRect& found = m_rects[index];
		return Rect(found.x1, found.y1, found.x2, found.y2);
	}
	
	size_t GetNumRects() const
	{
		return m_rects.size();
	}

	void Clear()
	{
		m_rects.clear();
	}

private:
	struct InnerRect{
		double x1;
		double y1;
		double x2;
		double y2;	
	};
	std::vector<InnerRect> m_rects;
};

}
}

#endif // PDFTRON_H_CPPPDFRectCollection
