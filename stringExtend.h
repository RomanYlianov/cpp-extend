#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<exception>

using namespace std;
namespace CppExtend
{
	class stringExtend : public string
	{
	private:

		string current;
	
	public:

		stringExtend* addBefore(char c);
		
		stringExtend* addBefore(string arg);

		stringExtend* addAfter(char c);

		stringExtend* addAfter(string arg);

		stringExtend* remove(int start);

		stringExtend* remove(int start, int len);

		stringExtend* removeBetween(int start, int end);

		stringExtend* replace(string arg1, string arg2);

		int indexOf(char c);

		int indexOf(string arg);

		int lastIndexOf(char c);

		int lastIndexOf(string arg);		

		stack<int> indexOfAny(char c);

		stack<int> indexOfAny(string arg);

		stack<int> lastIndexOfAny(char c);

		stack<int> lastIndexOfAny(string str);

		bool compare(string arg, bool isUseRegister);

		template <class T>
		stringExtend* join(char c, stack<T> values);

		stringExtend* sort(bool sortAsk, bool isCheckRegister);

		stringExtend* substring(int startIndex, int size);

		stringExtend* substringBetween(int start, int end);

		stringExtend* toUpper();

		stringExtend* toLower();

		stringExtend* toLowUpCase();

		stringExtend* toUpLowCase();

		stringExtend* reverse();

		stringExtend* fillBefore(int size, char symbol);

		stringExtend* fillAfter(int size, char symbol);

		stringExtend* supplementBefore(int size, char c);

		stringExtend* supplimentAfter(int size, char c);

		stringExtend* trim();

		char first();

		char last();

		char getMostPopularSymbol();

		stack<string> split(char delimiter);

		stack<string> split(string delimiter);	

		bool startWith(char arg);
		
		bool startWith(string arg);

		bool endWith(char c);

		bool endWith(string arg);

		void set(string s);

		string get();
	};

	stringExtend* stringExtend::addBefore(char c)
	{
		if (c == NULL)
		{
			throw invalid_argument("invalid argument " + c);
		}
		this->current = c + this->current;
		return this;
	}

	stringExtend* stringExtend::addBefore(string arg)
	{
		if (arg.empty())
			throw invalid_argument("trying to assign a empty element");
		this->current = arg + current;
		return this;
	}

	stringExtend* stringExtend::addAfter(char c)
	{
		this->current = this->current + c;
		return this;
	}

	stringExtend* stringExtend::addAfter(string arg)
	{
		this->current = current + arg;
		return this;
	}


	stringExtend* stringExtend::remove(int start)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		string str;
		for (int i = 0; i < start; i++)
		{
			str += current[i];
		}
		current = str;
		return this;
	}

	stringExtend* stringExtend::remove(int start, int length)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (start <0 || (start + length)>current.length())
			throw invalid_argument("invalid start or (and) length arguments");
		string temp = "";
		for (int i = 0; i < current.length(); i++)
		{
			if (i<start || i>(start + length))
			{
				temp += current[i];
			}
		}
		current = temp;
		return this;
	}

	stringExtend* stringExtend::removeBetween(int start, int end)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (start <0 || (start + end)>current.length())
			throw invalid_argument("invalid start or end arguments");
		string temp = "";
		for (int i = 0; i < current.length(); i++)
		{
			if (i<start || i>(end))
			{
				temp += current[i];
			}
		}
		current = temp;
		return this;
	}

	stringExtend* stringExtend::replace(string arg1, string arg2)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg1.empty() && arg2.empty())
			throw invalid_argument("data is empty");
		string temp = "";
		int i = 0;
		while (i < current.length())
		{
			if (current[i] == arg1[0])
			{
				if (i + arg1.length() <= current.length())
				{

					bool flag = true;
					for (int j = i + 1; j < i + arg1.length(); j++)
					{
						if (current[j] != arg1[j - i])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						for (int j = 0; j < arg2.length(); j++)
						{
							temp += arg2[j];
						}
					}
					i += arg1.length() - 1;
				}

			}
			else
			{
				temp += current[i];
			}
			i++;
		}
		current = temp;
		return this;
	}

	int stringExtend::indexOf(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("c symbol is invalid");
		int result = -1;
		for (int i = 0; i < current.length(); i++)
		{
			if (current[i] == c)
			{
				result = i;
				break;
			}
		}
		return result;
	}

	int stringExtend::indexOf(string arg)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is invalid");
		int result = -1;
		for (int i = 0; i < current.length(); i++)
		{
			if (current[i] == arg[0])
			{
				if (i + arg.length() < current.length())
				{
					result = i;

					for (int j = i; j < i + arg.length(); j++)
					{

						if (arg[j - i] != current[j])
						{
							result = -1;

							break;
						}
					}
					if (result >= 0)
						break;
				}
			}
		}
		return result;
	}

	int stringExtend::lastIndexOf(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("argument c in invalid");
		int result = -1;
		for (int i = current.length() - 1; i >= 0; i--)
		{
			if (current[i] == c)
			{
				result = i;
				break;
			}
		}
		return result;
	}

	int stringExtend::lastIndexOf(string str)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (str.empty())
			throw invalid_argument("argument str is empty");
		int result = -1;
		for (int i = current.length() - 1; i >= 0; i--)
		{
			if (current[i] == str[0])
			{
				if (i + str.length() < current.length())
				{
					result = i;
					for (int j = i; j >= i - str.length(); j--)
					{
						if (current[j] != str[i - j])
						{
							result = -1;
							break;
						}
					}
					if (result >= 0)
					{
						break;
					}
				}
			}
		}
		return result;
	}

	stack<int> stringExtend::indexOfAny(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("argument c is empty");
		stack<int> res;
		for (int i = 0; i < current.length(); i++)
		{
			if (c == current[i])
			{
				res.push(i);
			}
		}
		return res;
	}

	stack<int> stringExtend::indexOfAny(string arg)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is empty");
		stack<int> res;
		for (int i = 0; i < current.length(); i++)
		{
			if (current[i] == arg[0])
			{
				if (i + arg.length() <= current.length())
				{
					bool flag = true;
					for (int j = i; j < i + arg.length(); j++)
					{
						if (current[j] != arg[j - i])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						res.push(i);
					}
				}
			}
		}
		return res;
	}

	stack<int> stringExtend::lastIndexOfAny(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("argument c is invalid");
		stack<int> res;
		for (int i=current.length() - 1; i >= 0; i--)
		{
			if (current[i] == c)
			{
				res.push(i);
			}
		}
		return res;
	}

	stack<int> stringExtend::lastIndexOfAny(string arg)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is invalid");
		stack<int> res;
		for (int i = current.length() - 1; i >= 0; i--)
		{
			if (arg[0] == current[i])
			{
				if (i - arg.length() >= 0)
				{
					bool flag = true;
					for (int j = i; j >= i - arg.length() + 1; j--)
					{
						if (current[j] != arg[i - j])
						{
							flag = false;
							break;
						}
					}
					if (flag)
						res.push(i);
				}
			}
		}
		return res;
	}

	bool stringExtend::compare(string arg, bool isUseRegister)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is invalid");
		bool flag = false;
		if (isUseRegister)
		{
			flag = current == arg;
		}
		else
		{
			if (current.length() == arg.length())
			{
				for (int i = 0; i < current.length(); i++)
				{
					if (tolower(arg[i]) != tolower(current[i]))
					{
						flag = false;
						break;
					}
				}
			}
		}
		return flag;
	}

	template <class T>
	stringExtend* stringExtend::join(char c, stack<T> values)
	{
		if (c == NULL || values.empty())
			throw invalid_argument("invalid c or (and) values");
		string temp = "";
		while (!values.empty())
		{
			T val = values.top();
			values.pop();

			string t_name = typeid(val).name();

			if (t_name == "char")
			{
				temp += (val);
				temp += c;				
			}
			else
			{
				temp += to_string(val) + c;
			}
		}
	    temp.pop_back();
		current = temp;
		return this;
	}

	stringExtend* stringExtend::sort(bool sortAsk, bool isCheckRegister)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		for (int i = 0; i < current.length() - 1; i++)
		{
			for (int j = i + 1; j < current.length(); j++)
			{
				if (isCheckRegister)
				{
					if (sortAsk)
					{
						if (current[i] > current[j])
						{
							char c = current[i];
							current[i] = current[j];
							current[j] = c;
						}
					}
					else
					{
						if (current[i] < current[j])
						{
							char c = current[i];
							current[i] = current[j];
							current[j] = c;
						}
					}
					
				}
				else
				{
					if (sortAsk)
					{
						if (tolower(current[i]) > tolower(current[j]))
						{
							char c = current[i];
							current[i] = current[j];
							current[j] = c;
						}
					}
					else
					{
						if (tolower(current[i]) < tolower(current[j]))
						{
							char c = current[i];
							current[i] = current[j];
							current[j] = c;
						}
					}
				}
				
			}
		}
		return this;
	}


	stringExtend* stringExtend::substring(int start, int size)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (start<0 || (start + size)>current.length())
			throw invalid_argument("invalid start or size arguments");
		string temp = "";
		for (int i = start; i < start + size; i++)
		{
			temp += current[i];
		}
		current = temp;
		return this;
	}

	stringExtend* stringExtend::substringBetween(int start, int end)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (start<0 || end>current.length())
			throw invalid_argument("invalid start or (and) end arguments");
		string temp = "";
		for (int i = start; i < end; i++)
		{
			temp += current[i];
		}
		current = temp;
		return this;
	}

	stringExtend* stringExtend::toLower()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		for (int i = 0; i < current.length(); i++)
		{
			current[i] = tolower(current[i]);
		}
		return this;
	}

	stringExtend* stringExtend::toUpper()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		for (int i = 0; i < current.length(); i++)
		{
			current[i] = toupper(current[i]);
		}
		return this;
	}

	stringExtend* stringExtend::toLowUpCase()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		for (int i = 0; i < current.length(); i++)
		{
			if (i % 2 == 1)
			{
				current[i] = toupper(current[i]);
			}
			else
			{
				current[i] = tolower(current[i]);
			}
		}
		return this;
	}

	stringExtend* stringExtend::toUpLowCase()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		for (int i = 0; i < current.length(); i++)
		{
			if (i % 2 == 1)
			{				
				current[i] = tolower(current[i]);
			}
			else
			{
				current[i] = toupper(current[i]);
			}
		}
		return this;
	}

	stringExtend* stringExtend::reverse()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		string temp = "";
		for (int i = current.length() - 1; i >= 0; i--)
		{
			temp += current[i];
		}
		current = temp;
		return this;
	}

	stringExtend* stringExtend::fillBefore(int size, char symbol)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (size < 0 || symbol == NULL)
			throw invalid_argument("invalid size or (and) symbol");
		for (int i = 0; i < size; i++)
		{
			current = symbol + current;
		}
		return this;
	}

	stringExtend* stringExtend::fillAfter(int size, char symbol)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (size < 0 || symbol == NULL)
			throw invalid_argument("invalid size or (and) symbol");
		for (int i = 0; i < size; i++)
		{
			current += symbol;
		}
		return this;
	}

	stringExtend* stringExtend::supplementBefore(int size, char symbol)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (size < 0 || symbol == NULL)
			throw invalid_argument("invalid size or (and) symbol");
		for (int i = 0; i < (size - current.length() + 1); i++)
		{
			current = symbol + current;
		}
		return this;
	}

	stringExtend* stringExtend::supplimentAfter(int size, char symbol)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (size < 0 || symbol == NULL)
			throw invalid_argument("invalid size or (and) symbol");
		for (int i = 0; i < (size - current.length() + 1); i++)
		{
			current += symbol;
		}
		return this;
	}

	stringExtend* stringExtend::trim()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		string temp = "";
		for (int i = 0; i < current.length(); i++)
		{
			if (current[i] != ' ')
			{
				temp += current[i];
			}
		}
		current = temp;
		return this;
	}

	char stringExtend::first()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		return current[0];
	}

	char stringExtend::last()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		return current[current.length() - 1];
	}

	char stringExtend::getMostPopularSymbol()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		int n = 0;
		char res{};		
		for (int i = 0; i < current.length(); i++)
		{
			int n1 = 0;
			for (int j = 0; j < current.length(); j++)
			{
				if (i != j)
				{
					if (current[i] == current[j])
					{
						n1++;
					}
				}
			}
			if (n1 > n)
			{
				n = n1;
				res = current[i];
			}
		}
		return res;
	}

	stack<string> stringExtend::split(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("invalid c symbol");
		stack<string> res;
		int i = 0;
		string arg = "";
		while (i<current.length())
		{

			if (current[i] == c)
			{
				res.push(arg);
				arg = "";
			}
			else
			{
				arg += current[i];
			}
			i++;
		}
		res.push(arg);
		return res;
	}

	stack<string> stringExtend::split(string arg)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is invalid");
		stack<string> res;
		string temp;
		int i = 0;
		while (i < current.length())
		{
			if (i + arg.length() < current.length())
			{
				if (current[i] == arg[0])
				{
					bool flag = true;

					for (int j = i + 1; j < i + arg.length(); j++)
					{
						if (current[i] != current[j])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						res.push(temp);
						temp = "";
						i += arg.length();
					}
				}
			}
			temp += current[i];
			i++;
		}
		res.push(temp);
		return res;
	}

	bool stringExtend::startWith(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("invalid c symbol");
		return current[0] == c;
	}

	bool stringExtend::startWith(string arg)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is invalid");
		bool flag = true;
		for (int i = 0; i < arg.length(); i++)
		{
			if (current[i] != arg[i])
			{
				flag = false;
				break;
			}
		}

		return flag;
	}

	bool stringExtend::endWith(char c)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (c == NULL)
			throw invalid_argument("invalid c symbol");
		return current[current.length() - 1] == c;
	}

	bool stringExtend::endWith(string arg)
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		if (arg.empty())
			throw invalid_argument("argument arg is invalid");
		bool flag = true;
		int i = current.length() - 1;
		int ci = 0;
		while (i>=0)
		{
			if (ci == arg.length())
			{
				if (current[i] != arg[ci])
				{
					flag = false;
					break;
				}
			}
			i--;
		}
		return flag;
	}


	void stringExtend::set(string val)
	{
		
		this->current = val;
	}

	string stringExtend::get()
	{
		if (current.empty())
			throw invalid_argument("data is empty");
		return this->current;
	}
}





