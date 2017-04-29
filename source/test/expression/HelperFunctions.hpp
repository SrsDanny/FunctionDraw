#pragma once
#include <gtest/gtest.h>
#include <memory>

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
}
