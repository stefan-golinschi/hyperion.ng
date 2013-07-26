
#pragma once

// STL includes
#include <ctime>
#include <string>
#include <vector>

// Local includes
#include <utils/RgbColor.h>

// Forward class declarations
namespace Json { class Value; }

/**
 * The Led structure contains the definition of the image portion used to determine a single led's
 * color.
 * <pre>
 * |--------------------image--|
 * | minX  maxX                |
 * |  |-----|maxY              |
 * |  |     |                  |
 * |  |-----|minY              |
 * |                           |
 * |                           |
 * |                           |
 * |---------------------------|
 * <endpre>
 */
struct Led
{
	/** The index of the led */
	unsigned index;

	/** The minimum vertical scan line included for this leds color */
	double minX_frac;
	/** The maximum vertical scan line included for this leds color */
	double maxX_frac;
	/** The minimum horizontal scan line included for this leds color */
	double minY_frac;
	/** The maximum horizontal scan line included for this leds color */
	double maxY_frac;
};

class LedString
{
public:
	static LedString construct(const Json::Value& ledConfig, const Json::Value& colorConfig);

	LedString();

	~LedString();

	const std::vector<Led>& leds() const;

private:
	std::vector<Led> mLeds;

public:
	/**
	 * Color adjustements per color
	 */
	struct
	{
		/** The color gradient */
		double gamma;
		/** The color offset */
		double adjust;
		/** The minimum required level for the led to turn on */
		double blacklevel;
	} red, green, blue;
};
