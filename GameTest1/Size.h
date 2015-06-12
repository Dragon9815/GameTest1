#ifndef SIZE_H
#define SIZE_H

class MySize
{
public:

	float	Width;
	float	Height;

	MySize() : Width(0), Height(0), m_oldWidth(0), m_oldHeight(0) {}
	MySize(float width, float height) : Width(width), Height(height), m_oldWidth(width), m_oldHeight(height) {}

	bool changed()
	{
		if (Width != m_oldWidth || Height != m_oldHeight)
		{
			m_oldWidth = Width;
			m_oldHeight = Height;
			return true;
		}

		return false;
	}

private:
	float	m_oldWidth;
	float	m_oldHeight;
};

#endif