#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "drawing/GeometricTypes.h"
#include "drawing/Color.h"
#include "drawing/NormalizingTransformBuilder.h"
#include "drawing/ICanvas.h"
#include "drawing/Figure.h"
#include "drawing/Range.h"
#include <string>
#include "HelperFunctions.h"

using namespace funcdraw::drawing;

using ::testing::_;
using ::testing::Eq;
using ::testing::Truly;

namespace test
{
	class MockCanvas : public ICanvas
	{
	public:
		MOCK_METHOD2(drawLines,
			void(const MultiLine& lines, const std::vector<Color>& colors));
		MOCK_METHOD2(drawLines,
			void(const MultiLine& lines, const Color& colors));
		MOCK_METHOD2(drawLine,
			void(const Line& text, const Color& color));
	};

	class MultiLineEq
	{
		MultiLine multiLine;

	public:
		explicit MultiLineEq(const MultiLine& multiLine): multiLine(multiLine) {}

		bool operator()(const MultiLine& other) const
		{
			if (multiLine.size() != other.size())
				return false;

			for(auto i = 0; i < multiLine.size(); ++i)
			{
				if (static_cast<const std::vector<Point>&>(multiLine[i]) != static_cast<const std::vector<Point>&>(other[i]))
					return false;
			}
			return true;
		}
	};

	TEST(CanvasTest, DrawLineTest)
	{
		testing::NiceMock<MockCanvas> canvas;
		Figure figure;

		figure.addFunction(std::string("3*x"), Color::PURPLE);
		figure.addFunction([](double x) {return 100; }, Color::CYAN);
		figure.addFunction([](double x) {return -x; }, Color::GREEN);

		MultiLine multiLine, multiLine2;
		boost::geometry::read_wkt("multilinestring((-1 -3, 0 0, 1 3, 2 6),(-1 100, 0 100, 1 100, 2 100),(-1 1, 0 0, 1 -1, 2 -2))", multiLine);

		boost::geometry::transform(multiLine, multiLine2, buildNormalizingTransform(-1, 2, -3, 100));

		EXPECT_CALL(canvas,
			drawLines(
				Truly(MultiLineEq(multiLine2)),
				std::vector<Color>{ Color::PURPLE, Color::CYAN, Color::GREEN }))
			.Times(1);

		figure.draw(canvas, Range(-1, 2, 4));
	}
}
