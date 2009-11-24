/*
 *  Copyright 2008-2009 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


#include <thrust/sorting/detail/host/stable_merge_sort.h>

#include <thrust/iterator/detail/forced_iterator.h> // XXX remove this we we have a proper OMP sort

// XXX use host's merge sort implementation for now

namespace thrust
{
namespace sorting
{
namespace detail
{
namespace device
{
namespace omp
{

template<typename RandomAccessIterator,
         typename StrictWeakOrdering>
void stable_merge_sort(RandomAccessIterator first,
                       RandomAccessIterator last,
                       StrictWeakOrdering comp)
{
    thrust::sorting::detail::host::stable_merge_sort(thrust::detail::make_forced_iterator(first, thrust::host_space_tag()),
                                                     thrust::detail::make_forced_iterator(last,  thrust::host_space_tag()),
                                                     comp);
}

template<typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
void stable_merge_sort_by_key(RandomAccessIterator1 keys_begin,
                              RandomAccessIterator1 keys_end,
                              RandomAccessIterator2 values_begin,
                              StrictWeakOrdering comp)
{
    typedef typename thrust::iterator_value<RandomAccessIterator1>::type KeyType;

    thrust::sorting::detail::host::stable_merge_sort_by_key(thrust::detail::make_forced_iterator(keys_first,   thrust::host_space_tag()),
                                                            thrust::detail::make_forced_iterator(keys_last,    thrust::host_space_tag()),
                                                            thrust::detail::make_forced_iterator(values_first, thrust::host_space_tag()),
                                                            comp);
}

} // end namespace omp
} // end namespace device
} // end namespace detail
} // end namespace sorting
} // end namespace thrust
