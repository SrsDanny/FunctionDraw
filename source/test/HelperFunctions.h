#pragma once
#include <gtest/gtest.h>
#include <memory>
#include "drawing/GeometricTypes.h"

namespace test
{
	template<typename T>
	void assertNotNull(T val)
	{
		ASSERT_NE(nullptr, val);
	}

	template<typename Derived, typename Base>
	Derived* dynamicCastAndAssertNotNull(Base base)
	{
		Derived* derived = dynamic_cast<Derived*>(base);
		assertNotNull(derived);
		return derived;
	}

	template<typename Derived, typename Base>
	std::shared_ptr<Derived> dynamicCastAndAssertNotNull(std::shared_ptr<Base> base)
	{
		std::shared_ptr<Derived> derived = std::dynamic_pointer_cast<Derived>(base);
		assertNotNull(derived);
		return derived;
	}

	inline void expectPointNear(const funcdraw::drawing::Point& lhs, const funcdraw::drawing::Point& rhs, double eps = 1e-10)
	{
		EXPECT_NEAR(lhs.x(), rhs.x(), eps);
		EXPECT_NEAR(lhs.y(), rhs.y(), eps);
	}
}

namespace boost { namespace geometry { namespace model { namespace d2
{
	inline bool operator==(const point_xy<double>& lhs, const point_xy<double>& rhs)
	{
		return lhs.x() == rhs.x() && lhs.y() == rhs.y();
	}

	inline bool operator!=(const point_xy<double>& lhs, const point_xy<double>& rhs)
	{
		return lhs.x() != rhs.x() || lhs.y() != rhs.y();
	}
}}}}
