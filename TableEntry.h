#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
        std::string key;
        V value;
        
        TableEntry(std::string key, V value)
        {
        	key = this->key;
        	value = this->value;
        }
        
        TableEntry(std::string key)
        {
        	key = this->key;
        }
        
        TableEntry()
        {
        	key = "";
        }
        
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2)
        {
        	if(te1.key == te2.key)
        		return true;
        	else
        		return false;
        }
    	
    	friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2)
    	{
        	if(te1.key != te2.key)
        		return true;
        	else
        		return false;
        }
        
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te)
        {
        	out<<"Key: "<<te.key<<"\nValue: "<<te.value<<"\n";
        	return out;
        }
};

#endif
