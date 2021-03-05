#pragma once

template<typename T>
class GenericValue
{

public:
	void* _next = nullptr;

	GenericValue(T inV) : val(inV) {
		std::cout << "Create instance!" << std::endl;
	}

	virtual ~GenericValue() {
		if (hasNext())
		{
			clearDescendants();
		}
		std::cout << "Destroyed instance!" << std::endl;
	}

	void clearDescendants()
	{
		if (hasNext())
		{
			GenericValue* nxt = (GenericValue*)_next;
			nxt->clearDescendants();
			delete nxt;
			_next = nullptr;
		}
	}

	T val;
	void setVal(T val) { this->val = val; }
	T getVal() { return val; };

	void* getNext() { return _next };

	template<typename _nextType>
	void setNext(GenericValue<_nextType>* nextLink)
	{
		if (nextLink == nullptr) return;
		if (_next == nullptr) {
			_next = nextLink;
		}
		else
		{
			GenericValue* it = (GenericValue*)(_next);
			while (it->_next != nullptr) { it = (GenericValue*)(it->_next); }
			it->_next = nextLink;
		}
	}
	bool hasNext() const { return _next != nullptr; }
	static GenericValue* create(T inv) { return new GenericValue(inv); }
};
