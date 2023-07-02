#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_index = 0;
}

Phonebook::~Phonebook() {}

Contact Phonebook::getContact(int index) const
{
	return this->_contacts[index];
}

int	Phonebook::getCount() const
{
	return this->_count;
}

void Phonebook::setContact(Contact contact)
{
	this->_contacts[this->_index] = contact;
	this->_index = (this->_index + 1) % 8;
	_count = (_count < 8) ? _count + 1 : _count;
	return;
}

int Phonebook::_count = 0;
