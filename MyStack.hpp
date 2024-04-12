#ifndef CPSC131_MYSTACK_HPP
#define CPSC131_MYSTACK_HPP


#include <forward_list>
#include <stdexcept>



namespace CPSC131
{

	template <class T>
	class MyStack
	{
	
		public:
			
			MyStack() {}
			
			void push(const T& item)
			{
				list.push_front(item);
				size_++;
			}
			
			void pop()
			{
				if (empty())
				{
					throw std::range_error("The stack is empty.");
				}
				size_--;
				list.pop_front();
			}
			
			T& top()
			{
				if (empty())
				{
					throw std::range_error("The stack is empty.");
				}
				return list.front();
			}

			void clear()
			{
				list.clear();
				size_ = 0;
			}
			
			size_t size()
			{
				return size_;
			}
	
			bool empty()
			{
				return size_ == 0;
			}
		private:

			std::forward_list<T> list;
			size_t size_ = 0;
			
	};
}
