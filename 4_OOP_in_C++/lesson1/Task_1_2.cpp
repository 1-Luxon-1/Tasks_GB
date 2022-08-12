#include <iostream>
#include <cstdint>

class RGBA
{
public:
	RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
	{
		m_red = (red >= 0 && red < 256) ? red : 0;
		m_green = (green >= 0 && green < 256) ? green : 0;
		m_blue = (blue >= 0 && blue < 256) ? blue : 0;
		m_alpha = (alpha >= 0 && alpha < 256) ? alpha : 0;
	}
	
	RGBA(RGBA& rgba)
	{
		m_red = rgba.m_red;
		m_green = rgba.m_green;
		m_blue = rgba.m_blue;
		m_alpha = rgba.m_alpha;
	}
 
	void print()
	{
		std::cout << "red = " << m_red << std::endl
			<< "green = " << m_green << std::endl
			<< "blue = " << m_blue << std::endl
			<< "alpha = " << m_alpha << std::endl;
	}

private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
};