#include "MyDetector.hpp"
#include "MyStack.hpp"
#include "MyQueue.hpp"



namespace CPSC131::PalindromeDetector
{

	MyDetector::MyDetector() {}
	

	bool MyDetector::isPalindrome(std::string s)
	{
		MyQueue<char> queue;	
		MyStack<char> stack;

		for (char character : s)
		{
			if (std::isalpha(character))
			{
				character = std::tolower(character);
				stack.push(character);
				queue.enqueue(character);
			}
		}

		while (!stack.empty() && !queue.empty())
		{
			if (stack.top() != queue.front())
			{
				return false;
			}
			stack.pop();
			queue.dequeue();
		}
		return stack.empty() && queue.empty();
	}
}
