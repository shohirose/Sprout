#ifndef SPROUT_ALGORITHM_ONE_OF_HPP
#define SPROUT_ALGORITHM_ONE_OF_HPP

#include <sprout/config.hpp>
#include <sprout/iterator/operation.hpp>
#include <sprout/algorithm/find_if.hpp>

namespace sprout {
	namespace detail {
		template<typename InputIterator, typename Predicate>
		inline SPROUT_CONSTEXPR bool
		one_of_impl(InputIterator found, InputIterator last, Predicate pred) {
			return found != last
				&& NS_SSCRISK_CEL_OR_SPROUT::none_of(sprout::next(found), last, pred)
				;
		}
	}	// namespace detail
	//
	// one_of
	//
	template<typename InputIterator, typename Predicate>
	inline SPROUT_CONSTEXPR bool
	one_of(InputIterator first, InputIterator last, Predicate pred) {
		return sprout::detail::one_of_impl(
			sprout::find_if(first, last, pred), last,
			pred
			);
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_ONE_OF_HPP
